#include "user.h"
#include <fstream>

class Admin : public user {
    private:
        int privilege;
        string privatekey;
        double salary;

    public:
        Admin(string n, int id, double s, string p, int pr){
            user::u_name = n;
            user::u_id =  id;
            salary =s;
            privatekey = p;
            privilege = pr;
        }
        Admin(){
            cout<<"please enter the following values one by one and write the bio in one line: 1- name 2- id 3- private key 4- salary 5- bio"<<endl;
            cin>>u_name;
            cin>>u_id;
            cin>>privatekey;
            cin>>salary;
            cin.ignore(1000, '\n');
            getline(cin, u_bio);
        }
        void Display() const override{
            user::Display();
            cout << "Privilege: " << privilege << endl;
            cout << "Private key:     " << privatekey << endl;
            cout<<"\n--------------------"<<endl;

        }
};