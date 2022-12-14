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
            crs::course* courses;
    };

    class professor{
        public:
            string username;
            string password;
            crs::course* courses;
    };

    class assistant{
        public:
            string username;
            string password;
            string professor;
            crs::course* courses;
    };

}