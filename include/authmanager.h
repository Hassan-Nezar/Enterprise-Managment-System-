#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "student.h"
#include "professor.h"
#include "admin.h"
#include "fileManagement.h"

using namespace std;

class authManager
{
private:
    user *currentUser = nullptr;

public:
    // Destructor to prevent memory leaks
    ~authManager()
    {
        delete currentUser;
    }

    void studentRegister()
    {
        Student s;
        SaveToFile(s);
        cout << "\nRegistration successful! Returning to main menu...\n"
             << endl;
    }

    void profRegister()
    {
        Professor p;
        SaveToFile(p);
        cout << "\nRegistration successful! Returning to main menu...\n"
             << endl;
    }

    void adminRegister()
    {
        Admin a;
        SaveToFile(a);
        cout << "\nRegistration successful! Returning to main menu...\n"
             << endl;
    }

    void authsequence()
    {
        int mainChoice = 0;

        while (true)
        {
            cout << "=== University System ===" << endl;
            cout << "1- Register" << endl;
            cout << "2- Login" << endl;
            cout << "3- Exit" << endl;
            cout << "Choice: ";

            if (!(cin >> mainChoice))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (mainChoice == 1)
            {
                handleRegistration();
            }
            else if (mainChoice == 2)
            {
                if (handleLogin())
                {
                    // If login is successful, we break out of the auth loop
                    // to proceed to the app's main utilities
                    break;
                }
            }
            else if (mainChoice == 3)
            {
                exit(0);
            }
            else
            {
                cout << "Invalid value. Please try again." << endl;
            }
        }
    }

private:
    void handleRegistration()
    {
        int regChoice;
        cout << "\n--- Registration ---" << endl;
        cout << "1- Student\n2- Professor\n3- Admin\n4- Back" << endl;
        cout << "Choice: ";
        cin >> regChoice;

        switch (regChoice)
        {
        case 1:
            studentRegister();
            break;
        case 2:
            profRegister();
            break;
        case 3:
            adminRegister();
            break;
        case 4:
            return; // Returns to the main auth loop
        default:
            cout << "Invalid choice." << endl;
        }
    }

    bool handleLogin()
    {
        int loginType;
        int ID;
        string name;

        cout << "\n--- Login ---" << endl;
        cout << "1- Student\n2- Professor\n3- Admin\n4- Back" << endl;
        cout << "Choice: ";
        cin >> loginType;

        if (loginType == 4)
            return false;
        if (loginType < 1 || loginType > 3)
        {
            cout << "Invalid choice." << endl;
            return false;
        }

        cout << "Enter ID: ";
        cin >> ID;
        cin.ignore(1000, '\n');
        cout << "Enter Name: ";
        getline(cin, name);

        // Capture the pointer based on type
        // Note: LoginParser must return a pointer!
        switch (loginType)
        {
        case 1:
            currentUser = LoginParser<Student>("students.txt", ID);
            break;
        case 2:
            currentUser = LoginParser<Professor>("professors.txt", ID);
            break;
        case 3:
            currentUser = LoginParser<Admin>("admins.txt", ID);
            break;
        }

        if (currentUser != nullptr)
        {
            // Check if the name matches the one in the record
            if (currentUser->getName() == name)
            {
                cout << "Login Successful! Welcome, " << currentUser->getName() << endl;
                return true;
            }
            else
            {
                cout << "Credentials do not match." << endl;
                delete currentUser; // Clean up the failed login object
                currentUser = nullptr;
            }
        }
        else
        {
            cout << "User ID not found." << endl;
        }
        return false;
    }
};