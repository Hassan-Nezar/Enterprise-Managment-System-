#pragma once
#include <iostream>
#include "student.h"
#include "professor.h"
#include <fstream>
#include "admin.h"
#include "fileManagement.h"
using namespace std;
class authManager{
    private:
        int type;
    public:
        void setType(int t){
            type = t;
        }
        void studentAuth(){
           
           Student student1 = Student();
           SaveToFile(student1);

        }
        void profAuth(){
            Professor prof1 = Professor();
            SaveToFile(prof1);
        }
        void adminAuth(){
            Admin admin1 = Admin();
            SaveToFile(admin1);
        }
        void authsequence(){
            cout<< "Wilkommen"<<endl;
        cout<< "s'il vous plait, enter the credentials"<<endl<<"type 1 student 2 professor 3 admin"<<endl;
        cin>>type;
        if(type==1){
            studentAuth();
        // student obj initiator
        }else if (type==2)
        {
            profAuth();

        //prof object initiator  
        }
        else if (type==3)
        {
            adminAuth();
        //admin object initiator
        }
        }
};