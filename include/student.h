#include "user.h"
#include <fstream>


class Student : public user {
    private:
        int gpa;
        string nationality;
        string major;
        string college;
        int schoolyear;
    public:
        Student(int g,int id, string n, string m, string c, string nat, string b, int s){
            user::u_name = n;
            user::u_id =  id;
            user::u_bio = b;
            major = m;
            college = c;
            gpa = g;
            nationality = nat;
            schoolyear = s;
        }
        Student(){
            cout<<"please enter the following values one by one and write the bio in one line: 1- name 2- school year (number) 3- id 4- college 5-major 6- nationality 7- gpa 8- bio"<<endl;
            cin>>u_name;
            cin>>schoolyear;
            cin>>u_id;
            cin>>college;
            cin>>major;
            cin>>nationality;
            cin>>gpa;
            cin.ignore(1000, '\n');
            getline(cin, u_bio);
        }
        void Display() const override{
            user::Display();
            cout << "School Year: " << schoolyear << endl;
            cout << "College:     " << college << endl;
            cout << "Major:       " << major << endl;
            cout << "Nationality: " << nationality << endl;
            cout << "GPA:         " << gpa << endl;
            cout<<"\n--------------------"<<endl;

        }
};