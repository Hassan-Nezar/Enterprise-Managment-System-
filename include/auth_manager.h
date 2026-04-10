#ifndef AUTH_MANAGER_H
#define AUTH_MANAGER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class auth_manager {
public:

    struct result_loginparser {
        string firstnamer;
        string lastnamer;
        string id1r; 
        string id2r;  
    };

    result_loginparser login_parser(string name, string id);

    void accounts_parser();

    void login(string name, string id);

    void logout();
};

#endif