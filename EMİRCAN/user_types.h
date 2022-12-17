#include <iostream>
#include <fstream>
#include <new>
#include <string>
#include "course.h"
using namespace std;

namespace Usr{

    struct student{
            string username;
            string password;
            Crs::course* courses;
    };

    class prof{
        public:
            string username;
            string password;
            Crs::course* courses;
    };

    class assistant{
        public:
            string username;
            string password;
            string professor;
            Crs::course* courses;
    };



}