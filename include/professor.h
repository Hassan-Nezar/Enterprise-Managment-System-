#pragma once

#include "user.h"
#include <fstream>

class Professor : public user
{
private:
    int rank;
    string nationality;
    string department;
    double salary;

public:
    // Getters for Professor-specific variables
    int getRank() const
    {
        return rank;
    }

    const string &getNationality() const
    {
        return nationality;
    }

    const string &getDepartment() const
    {
        return department;
    }

    double getSalary() const
    {
        return salary;
    }

    // Inherited getters from user (if not already in user.h)
    string getName() const { return u_name; }
    int getId() const { return u_id; }
    string getBio() const { return u_bio; }
    // Assuming 'r' is rank, 'dept' is department, etc.
    Professor(int r, int id, string n, string dept, string nat, string b, double s)
    {
        u_name = n;
        u_id = id;
        u_bio = b;
        rank = r;
        department = dept;
        nationality = nat;
        salary = s;
    }
    Professor()
    {
        cin.ignore(1000, '\n');
        cout << "1- Name: ";
        getline(cin, u_bio);
        cout << "2- ID: ";
        cin >> u_id;

        // 1. Clear the buffer after u_id so department doesn't skip
        cin.ignore(1000, '\n');

        cout << "3- Department: ";
        getline(cin, department);

        cout << "4- Salary: ";
        cin >> salary;

        // 2. Clear the buffer after salary so bio doesn't skip
        cin.ignore(1000, '\n');

        cout << "5- Bio: ";
        getline(cin, u_bio);
    }
    void Display() const override
    {
        user::Display();
        cout << "rank: " << rank << endl;
        cout << "Department:     " << department << endl;
        cout << "Nationality: " << nationality << endl;
        cout << "salary:         " << salary << endl;
    cout << "\n--------------------" << endl;
    }
    void loadFromStream(stringstream& ss) override {
    string idStr, salStr, rankStr;
    getline(ss, idStr, '|'); u_id = stoll(idStr);
    getline(ss, u_name, '|');
    getline(ss, rankStr, '|'); rank = stoi(rankStr);
    getline(ss, department, '|');
    getline(ss, nationality, '|');
    getline(ss, salStr, '|'); salary = stod(salStr);
    getline(ss, u_bio);
}
};

