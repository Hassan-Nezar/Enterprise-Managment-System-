#ifndef AUTH_MANAGER_H
#define AUTH_MANAGER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class auth_manager {
public:
    struct login_result {
        bool success;
        std::string first_name;
        std::string last_name;
        std::string id;
        std::string role;
    };

    struct loginparser_result {
        string firstnamer;
        string lastnamer;
        string id1r; 
        string id2r;
        string passr;  
    };

    loginparser_result login_parser(string name, string id, string password);

    login_result login(string name, string id, string password);

    void logout();
};

#endif