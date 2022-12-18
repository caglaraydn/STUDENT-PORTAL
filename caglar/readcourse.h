#include <iostream>
#include <fstream>
#include <new>
#include <string>
#include "user_types.h"
#pragma once
using namespace std;

namespace slctcrs{


string askForCode(string &courseCode){
    
    
    cout << "Write the code of a course" << endl;
    cin >> courseCode;

    return courseCode;
}

bool isCodeTrue(string inputCode, string realCode){

    if(inputCode == realCode){
        return true;
    }
    else{
        return false;
    }

}


void selectCourse(int index){


    Crs::course* crs;
    int numberOfCourses;
    char p;
    char c;
    int countStop = 0;
    string code;
    Usr::student* stu;
    bool select = true;


    ifstream file("courses.bin", ios::binary | ios::ate);
    if(file.is_open()){
        streampos fileSize = file.tellg();
        char* mBlock = new char[fileSize];
        file.seekg(0,ios::beg);

        file.read(mBlock, fileSize);
        file.close();


        char* tempPtr = mBlock;
        char* tempPtr2 = mBlock;

        for(int i = 0; i < fileSize; i++){
            c = *((char*)tempPtr2);
            
            if(c != '?'){
                tempPtr2++;
            }
            else{
                countStop++;
                tempPtr2++;
            }
        }

        numberOfCourses = countStop/3;    
        
        crs = new Crs::course[numberOfCourses];
        for(int i = 0; i < numberOfCourses; i++){

            
            for(int u = 0; u < 50; u++){

                p = *((char*)tempPtr);

                if(p != '?'){
                    //cout << *((char*)tempPtr);
                    crs[i].name += *((char*)tempPtr);
                    tempPtr++;

                }
                else{
                    tempPtr++;
                    break;
                }
                
            }

            for(int s = 0; s < 50; s++){
                
                p = *((char*)tempPtr);

                if(p != '?'){
                    //cout << *((char*)tempPtr);
                    crs[i].professor += *((char*)tempPtr);
                    tempPtr++;

                }
                else{
                    tempPtr++;
                    break;
                }
                
            }

            for(int c = 0; c < 50; c++){
                
                p = *((char*)tempPtr);

                if(p != '?'){
                    //cout << *((char*)tempPtr);
                    crs[i].code += *((char*)tempPtr);
                    tempPtr++;

                }
                else{
                    tempPtr++;
                    break;
                }
                
            }
        }
    }

    cout << endl;
    cout << "There are " << numberOfCourses << " courses available" << endl << endl;    
        
    for(int i = 0; i < numberOfCourses; i++){
        cout << "Course Name: " << crs[i].name << endl;
        cout << "Course Professor: " << crs[i].professor << endl;
        cout << "Course Code: " << crs[i].code << endl << endl;

    }

    

   
     

          


    askForCode(code);


    while(select){

        for(int i = 0; i < numberOfCourses; i++){

            if(isCodeTrue(code,crs[i].code)){
                 cout << endl;
                    //cout << crs[i].code << endl;
                    stu[index].courses[0] = crs[i];

                    cout << stu[index].courses[0].code;

                    select = false;
                    break;
                }

            }

            if(select){
                cout << "You entered an invalid course code" << endl;
                askForCode(code);
            }
        }
        
    }    
}
    
    
