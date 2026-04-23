#include "user.h"
#include <fstream>

class Professor : public user {
    private:
        int rank;
        string nationality;
        string department;
        double salary;

    public:
        Professor(int g,int id, string n, string m, string c, string nat, string b, int s){
            user::u_name = n;
            user::u_id =  id;
            user::u_bio = b;
        }
        Professor(){
            cout<<"please enter the following values one by one and write the bio in one line: 1- name 2- id 3- department 4- salary 5- bio"<<endl;
            cin>>u_name;
            cin>>u_id;
            cin.ignore(1000, '\n');
            getline(cin, department);
            cin>>salary;
            cin.ignore(1000, '\n');
            getline(cin, u_bio);
        }
        void Display() const override{
            user::Display();
            cout << "rank: " << rank << endl;
            cout << "Department:     " << department << endl;
            cout << "Nationality: " << nationality << endl;
            cout << "salary:         " << salary << endl;
            cout<<"\n--------------------"<<endl;

        }
};