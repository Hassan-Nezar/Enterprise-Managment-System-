#include <iostream>
#include "include/authmanager.h"
#include <string>
#include <fstream>
using namespace std;

string name;
string pass;
int choice1;
int main() {

    authManager session = authManager();
    session.authsequence();
    return 0;
}