#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include "user.h"
#include "student.h"
#include "professor.h"
#include "admin.h"
void SaveToFile(Student s)
{
    ofstream outFile("students.txt", ios::app);
    if (outFile.is_open())
    {
        outFile << "Name:      " << s.getName() << endl;
        outFile << "ID:        " << s.getId() << endl;
        outFile << "School Year: " << s.getSchoolYear() << endl;
        outFile << "College:     " << s.getCollege() << endl;
        outFile << "Major:       " << s.getMajor() << endl;
        outFile << "Nationality: " << s.getNationality() << endl;
        outFile << "GPA:         " << s.getGpa() << endl;
        outFile << "\n--------------------" << endl;
    }
}
void SaveToFile(const Professor &p)
{
    // This correctly targets the professors.txt file
    ofstream outFile("professors.txt", ios::app);

    if (outFile.is_open())
    {
        outFile << "--- Professor Record ---" << endl;
        outFile << "Name:        " << p.getName() << endl;
        outFile << "ID:          " << p.getId() << endl;
        outFile << "Rank:        " << p.getRank() << endl;
        outFile << "Department:  " << p.getDepartment() << endl;
        outFile << "Nationality: " << p.getNationality() << endl;
        outFile << "Salary:      " << p.getSalary() << endl;
        outFile << "Bio:         " << p.getBio() << endl;
        outFile << "------------------------" << endl;

        outFile.close();
    }
    else
    {
        cerr << "Error: Could not open professors.txt" << endl;
    }
}
void SaveToFile(const Admin &a)
{
    ofstream outFile("admins.txt", ios::app);

    if (outFile.is_open())
    {
        outFile << "--- Admin Record ---" << endl;
        outFile << "Name:          " << a.getName() << endl;
        outFile << "ID:            " << a.getId() << endl;
        outFile << "Privilege:     " << a.getPrivilege() << endl;
        outFile << "Salary:        " << a.getSalary() << endl;
        outFile << "Private Key:   " << a.getPrivateKey() << endl; // Added ()
        outFile << "Bio:           " << a.getBio() << endl;        // Added ()
        outFile << "--------------------" << endl;

        outFile.close();
    }
    else
    {
        cerr << "Error: Could not open admins.txt" << endl;
    }
}
