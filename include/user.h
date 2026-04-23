#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class user {
    protected:
        string u_name;
        long long u_id;
        string u_bio;
        
    public:

       string getName() const { return u_name; }
        int getId() const { return u_id; }
        string getBio() const { return u_bio; }
        virtual void Display() const {
            cout<<"\n--------------------"<<endl;
            cout<< "user: "<<u_name << " ID: "<<u_id<< " \nbio: \n"<< u_bio;
        };
        void virtual loadFromStream(stringstream& ss){

        }

          
};

