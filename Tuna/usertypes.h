#include <iostream>
#include <fstream>
#include <new>
#include <string>
#include "course.h"
#pragma once
using namespace std;

namespace user{//The user namespace is used to make it easy to understand inside other functions.

    class student{//By defining two different objects within this user type, we ensured that each student has their own user name and password.
        public:
            string username;
            string password;
    };

    class prof{//By defining two different objects within this user type, we ensured that each professor has their own user name and password.
        public:
            string username;
            string password;
    };

    class assistant{//By defining two different objects within this user type, we ensured that each asistant has their own user name and password.
        public:
            string username;
            string password;
    };

}