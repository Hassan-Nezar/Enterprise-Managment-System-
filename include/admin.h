#pragma once

#include "user.h"
#include <fstream>

class Admin : public user
{
private:
    int privilege;
    string privatekey;
    double salary;

public:
    // Getters for Admin-specific variables
    int getPrivilege() const
    {
        return privilege;
    }

    double getSalary() const
    {
        return salary;
    }

    // Returning string by const reference to avoid unnecessary copying
    const string &getPrivateKey() const
    {
        return privatekey;
    }

    // Inherited getters from the 'user' base class
    // (Include these if they aren't already accessible in user.h)
    string getName() const { return u_name; }
    int getId() const { return u_id; }
    string getBio() const { return u_bio; }
    Admin(string n, int id, double s, string p, int pr)
    {
        user::u_name = n;
        user::u_id = id;
        salary = s;
        privatekey = p;
        privilege = pr;
    }
    Admin()
    {
        cout << "1- Name: ";
        cin.ignore(1000, '\n');
        getline(cin, u_name);
        cout << "2- ID: ";
        cin >> u_id;
        cout << "3- Private Key: ";
        cin >> privatekey;
        cout << "4- Salary: ";
        cin >> salary;
        cout << "5- Privilege Level: ";
        cin >> privilege; // Added this!

        cin.ignore(1000, '\n'); // Clean buffer for the bio
        cout << "6- Bio: ";
        getline(cin, u_bio);
    }
    void Display() const override
    {
        user::Display();
        cout << "Privilege: " << privilege << endl;
        cout << "Private key:     " << privatekey << endl;
        cout << "\n--------------------" << endl;
    }
    void loadFromStream(stringstream& ss) override {
    string idStr, privStr, salStr;
    getline(ss, idStr, '|'); u_id = stoll(idStr);
    getline(ss, u_name, '|');
    getline(ss, privStr, '|'); privilege = stoi(privStr);
    getline(ss, salStr, '|'); salary = stod(salStr);
    getline(ss, privatekey, '|');
    getline(ss, u_bio);
}
};
