#include <iostream>
#include <fstream>
#include <new>
#include <string>
#include "course.h"
#pragma once
using namespace std;

namespace user{

    class student{
        public:
            string username;
            string password;
    };

    class prof{
        public:
            string username;
            string password;
    };

    class assistant{
        public:
            string username;
            string password;
            string professor;
    };

}