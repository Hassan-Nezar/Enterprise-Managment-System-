#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class course {
    private:
        string c_name;
        int c_id;
        int c_hrs;
        double c_grade;
        int maxCapacity;
        
    public:
       string Get_course(){
            return c_name;
        };
        void Set_course(string c){
            c_name = c;
        };
        double Get_course_grade(){
            return c_grade;
        };
        void Display(){
            cout<< "Course: "<<c_name << " ID: "<<c_id<< " Credit Hours: "<<c_hrs<<" Student grade: "<< c_grade;
        };

          
};

#endif