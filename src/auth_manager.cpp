#include "../include/auth_manager.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//creating a struct with the data we want to return in login_parser() function:
auth_manager::loginparser_result auth_manager::login_parser(string name, string id, string password) {
    
    string first_name_construct = ""; //stores first name seperatley
    string last_name_construct = ""; //stores last name seperatley
    vector<char> first_name; //a vector of the characters making up the first name
    vector<char> last_name; //a vector of the characters making up the last name
    
    string id_1_construct = ""; //stores first 4 digits of id seperatley
    string id_2_construct = ""; //stores last 4 digits of id seperatley
    vector<char> id_1; //a vector to store the first 4 digits
    vector<char> id_2; //a vector to store the last 4 digits

    int name_length = name.length(); //stores length of inputted name
    bool whitespace_status = false; //stores state of presence of whitespace, to see whether to store first or last name

    // part the name into vector first_name and vector second_name
    for(int character = 0; character < name_length; character++) { 
        if (name.at(character) != ' ' && !whitespace_status) {
            first_name.push_back(name.at(character));
        } else if (name.at(character) != ' ' && whitespace_status) {
            last_name.push_back(name.at(character));
        } else {
            whitespace_status = true;
        } 
    } //end of for loop

    int firstname_length = first_name.size();
    int lastname_length = last_name.size();
    
    //construct first name:
    for (int character = 0; character < firstname_length; character++) {
        first_name_construct += first_name.at(character);
    }
    //construct last name:<
    for (int character = 0; character < lastname_length; character++) {
        last_name_construct += last_name.at(character);
    }

    //seperate id:
    int id_length = id.length();
    for (int digit = 0; digit < id_length; digit++) {
        if (digit < 4) {
            id_1.push_back(id.at(digit));
        }else {
            id_2.push_back(id.at(digit));
        }
    } //end of for loop

    //construct id_1/2:
    for(int digit = 0; digit < 4; digit++) {
        id_1_construct += id_1.at(digit);
        id_2_construct += id_2.at(digit);
    }
     
    //using a struct (created in auth_manager.h) to return multiple items
    loginparser_result r;
    r.firstnamer = first_name_construct;
    r.lastnamer = last_name_construct;
    r.id1r = id_1_construct;
    r.id2r = id_2_construct;
    r.passr = password;

    return r;
}
//--------------------------------------------------------------------------------




auth_manager::login_result auth_manager::login(string name, string id, string password) {
    loginparser_result parsed = login_parser(name, id, password); //calling login_parser to parse the input
    
    string fn, ln, ident, pass, pos; //to store file read: fn means first name, ln means last name, ident means id/identification, pass means password, pos means position/role
    bool info_check = false; //variable to check if input is true


    //an id starting with 0000 is an admin accounts and read happens in admin.txt file
    if (parsed.id1r == "0000"){
        pos = "Admin";
        ifstream file("program_files/admin.txt");
        
        while (file >> fn >> ln >> ident >> pass) {
            if (parsed.firstnamer == fn && parsed.lastnamer == ln && ((parsed.id1r + parsed.id2r) == ident) && parsed.passr == pass){
               info_check = true;
               cout << "Login is successful" << endl;
               break;
            }
                
        }
    } else if (parsed.id1r == "9999") { //an id starting with 9999 is a professor account and read happens in professor.txt file
        pos = "Professor"; 
        ifstream file("program_files/professor.txt");
       
        while (file >> fn >> ln >> ident >> pass) {
            if (parsed.firstnamer == fn && parsed.lastnamer == ln && ((parsed.id1r + parsed.id2r) == ident) && parsed.passr == pass){
               info_check = true;
               cout << "Login is successful" << endl;
               break;
            }
                
        }
    } else { //this is for student accounts which start with the 4 digits 2025, 2022, etc. which notate their batch
        pos = "Student";
        ifstream file("program_files/student.txt");
       
        while (file >> fn >> ln >> ident >> pass) {
            if (parsed.firstnamer == fn && parsed.lastnamer == ln && ((parsed.id1r + parsed.id2r) == ident) && parsed.passr == pass){
               info_check = true;
               cout << "Login is successful" << endl;
               break;
            }
                
        }
    }
    
    //final check to see if login was successfull or not
    if (info_check == true) {
        cout << "Login is successful, welcome " << parsed.firstnamer << "!" << endl;
    } else {
        cout << "Login was unsuccessful." << endl;
    }

    //using struct to return multiple values:
    if (info_check == true) {
        login_result r;
        r.first_name = fn;
        r.last_name = ln;
        r.id = ident;
        r.role = pos;
        r.success = info_check;

        return r;
    } else {
        login_result r;
        r.success = info_check;
        return r;
    }
    
    
}

void auth_manager::logout() {
    
}