#include "auth_manager.h"

//creating a struct with the data we want to return in login_parser() function:
auth_manager::result_loginparser auth_manager::login_parser(string name, string id) {
    
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

    for(int character = 0; character <= name_length; character++) { 
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
    for (int character = 0; character <lastname_length; character++) {
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
    
    result_loginparser r;
    r.firstnamer = first_name_construct;
    r.lastnamer = last_name_construct;
    r.id1r = id_1_construct;
    r.id2r = id_2_construct; 

    return r;
}
//--------------------------------------------------------------------------------


void auth_manager::accounts_parser(){

}

void auth_manager::login(string name, string id) {
    ifstream file("program_files/accounts.txt");
    
    string first_name;
    string last_name;
    string id_store;

}

void auth_manager::logout() {
    
}