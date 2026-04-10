#include <iostream>
#include <string>
#include "include/auth_manager.h"
using namespace std;



int main() {
    auth_manager auth;
    auto result = auth.login("hassan nezar", "00000001", "hassan123");
}