#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <string>
#include "user.h"
#include "student.h"
#include "professor.h"
#include "admin.h"
void SaveToFile(const Student &s)
{
    ofstream outFile("students.txt", ios::app);

    if (outFile.is_open())
    {
        // Format: ID|Name|SchoolYear|College|Major|Nationality|GPA|Bio
        outFile << s.getId() << "|"
                << s.getName() << "|"
                << s.getSchoolYear() << "|"
                << s.getCollege() << "|"
                << s.getMajor() << "|"
                << s.getNationality() << "|"
                << s.getGpa() << "|"
                << s.getBio() << endl;

        outFile.close();
    }
    else
    {
        cerr << "Error: Could not open students.txt" << endl;
    }
}
void SaveToFile(const Professor &p)
{
    ofstream outFile("professors.txt", ios::app);

    if (outFile.is_open())
    {
        // Format: ID|Name|Rank|Department|Nationality|Salary|Bio
        // We put each professor on exactly one line
        outFile << p.getId() << "|"
                << p.getName() << "|"
                << p.getRank() << "|"
                << p.getDepartment() << "|"
                << p.getNationality() << "|"
                << p.getSalary() << "|"
                << p.getBio() << endl;

        outFile.close();
    }
    else
    {
        cerr << "Error: Could not open professors.txt" << endl;
    }
}
void SaveToFile(const Admin &a)
{
    // Keeping data consistent in admins.txt
    ofstream outFile("admins.txt", ios::app);

    if (outFile.is_open())
    {
        // Format: ID|Name|Privilege|Salary|PrivateKey|Bio
        outFile << a.getId() << "|"
                << a.getName() << "|"
                << a.getPrivilege() << "|"
                << a.getSalary() << "|"
                << a.getPrivateKey() << "|"
                << a.getBio() << endl;

        outFile.close();
    }
    else
    {
        cerr << "Error: Could not open admins.txt" << endl;
    }
}


template <typename T>
user* LoginParser(string filename, long long searchID) {
    ifstream inFile(filename);
    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string idStr;
        
        // Peek at the ID first
        getline(ss, idStr, '|'); 
        if (stoll(idStr) == searchID) {
            // 1. Create a blank object of type T (Student, Admin, or Prof)
            T* newUser = new T(); 
            
            // 2. Reset the stream to the beginning of the line
            ss.clear();
            ss.str(line); 
            
            // 3. Let the object "load itself" using its specific logic
            newUser->loadFromStream(ss); 
            
            return newUser;
        }
    }
    return nullptr;
}