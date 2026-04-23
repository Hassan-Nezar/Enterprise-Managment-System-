#pragma once

#include <fstream>
#include "user.h"

class Student : public user
{
private:
    int gpa;
    string nationality;
    string major;
    string college;
    int schoolyear;

public:
    // Getters for Student-specific variables
    int getGpa() const { return gpa; }
    string getNationality() const { return nationality; }
    string getMajor() const { return major; }
    string getCollege() const { return college; }
    int getSchoolYear() const { return schoolyear; }

    // Since Student inherits from user, you may also need these
    // if they aren't already defined in user.h
    string getName() const { return u_name; }
    int getId() const { return u_id; }
    string getBio() const { return u_bio; }
    Student(int g, int id, string n, string m, string c, string nat, string b, int s)
    {
        user::u_name = n;
        user::u_id = id;
        user::u_bio = b;
        major = m;
        college = c;
        gpa = g;
        nationality = nat;
        schoolyear = s;
    }
    Student()
    {
        cout << "Enter Name: ";
        cin.ignore(1000, '\n');
        getline(cin, u_name);

        cout << "Enter School Year: ";
        cin >> schoolyear;

        cout << "Enter ID: ";
        cin >> u_id;

        cout << "Enter College: ";
        cin.ignore(); // Clear newline from u_id
        getline(cin, college);

        cout << "Enter Major: ";
        getline(cin, major);

        cout << "Enter Nationality: ";
        getline(cin, nationality);

        cout << "Enter GPA: ";
        cin >> gpa;

        cin.ignore(1000, '\n');

        cout << "Enter Bio: ";
        getline(cin, u_bio);
    }
    void Display() const override
    {
        user::Display();
        cout << "School Year: " << schoolyear << endl;
        cout << "College:     " << college << endl;
        cout << "Major:       " << major << endl;
        cout << "Nationality: " << nationality << endl;
        cout << "GPA:         " << gpa << endl;
        cout << "\n--------------------" << endl;
    }
    void loadFromStream(stringstream& ss) override {
    string idStr, yearStr, gpaStr;
    getline(ss, idStr, '|'); u_id = stoll(idStr);
    getline(ss, u_name, '|');
    getline(ss, yearStr, '|'); schoolyear = stoi(yearStr);
    getline(ss, college, '|');
    getline(ss, major, '|');
    getline(ss, nationality, '|');
    getline(ss, gpaStr, '|'); gpa = stod(gpaStr);
    getline(ss, u_bio);
}
};

