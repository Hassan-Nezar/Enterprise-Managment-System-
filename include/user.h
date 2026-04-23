#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class user {
    protected:
        string u_name;
        int u_id;
        int u_age;
        string u_bio;
        int maxCapacity;
        
    public:
       string Get_user(){
            return u_name;
        };
        void Set_user(string c){
            u_name = c;
        };
        double Get_user_age(){
            return u_age;
        };
        virtual void Display() const {
            cout<<"\n--------------------"<<endl;
            cout<< "user: "<<u_name << " ID: "<<u_id<< " age: "<<u_age<<" \nbio: \n"<< u_bio;
        };

          
};

