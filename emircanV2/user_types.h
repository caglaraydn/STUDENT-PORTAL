#include <iostream>
#include <fstream>
#include <new>
#include <string>
#include "course.h"
using namespace std;

namespace Usr{

    class student{
        public:
            string username;
            string password;
            crs::course* courses;
    };

    class prof{
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