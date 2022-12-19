#include <iostream>
#include <fstream>
#include <new>
#include <string>
#include "usertypes.h"
#include "entry.h"
#include "gpa.h"
using namespace std;

void StuSign(){

    string username;
    string password;
    string passSecond;
    
    do{
      cout<<"Please enter your username to be signed up (maximum 11 characters): ";
      cin >> username;
    }while(username.length()>11);
    do{
      cout<<"Please enter your password to be signed up (4-18 characters): ";
      cin >> password;
      cout<<"Please enter your password again: ";
      cin>> passSecond;
    }while((password.length()<4||password.length()>18)||password!=passSecond);
    cout<<"YOU HAVE SUCCESSFULLY SIGNED UP!"<<endl;
    cout<<endl;
    

    char stop = '?';
    ofstream file("stusave.bin", ios::binary | ios::app);
    if(file.is_open()){
        
        for(int i = 0; i < username.length(); i++){

            file.write((char*)&username[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));

        for(int i = 0; i < password.length(); i++){

            file.write((char*)&password[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));
        
        
        
        file.close();

    }
    
}


void StuLog(){
    
    bool login = true;
    string inputUsername;
    string inputPassword;
    int LimitUsername = 11;
    int LimitPassword = 18;
    user::student* stu;
    int stuCount = 0;
    int countStop = 0;
    char p;

    ifstream file("stusave.bin", ios::binary | ios::ate);
    if(file.is_open()){
        streampos fileSize = file.tellg();
        char* mBlock = new char[fileSize];
        file.seekg(0,ios::beg);
        file.read(mBlock, fileSize);
        file.close();

        char* temp = mBlock;
        char* tempPtr = mBlock;

        for(int i = 0; i < fileSize; i++){
            char k = *((char*)tempPtr);
            
            if(k != '?'){
                tempPtr++;
            }
            else{
                countStop++;
                tempPtr++;
            }
        }

        stuCount=countStop/2;

        stu = new user::student[stuCount];
        for(int i = 0; i < stuCount; i++){

            
            for(int u = 0; u < LimitUsername; u++){

                p = *((char*)temp);

                if(p != '?'){
                    stu[i].username += *((char*)temp);
                    temp++;

                }
                else{
                    temp++;
                    break;
                }
                
            }

            for(int s = 0; s < LimitPassword; s++){
                
                p = *((char*)temp);

                if(p != '?'){
                    stu[i].password += *((char*)temp);
                    temp++;

                }
                else{
                    temp++;
                    break;
                }
                
            }
        }
        delete[] mBlock;
    }

    
    userInfo(inputUsername,inputPassword);
    
    while(login){

        for(int i = 0; i < stuCount; i++){

            if(isInfoTrue(inputUsername,inputPassword,stu[i].username,stu[i].password)){
                cout << endl;
                cout << "WELCOME!"<<endl;
                login = false;
                short select1; //Student
                do
                {
                cout<<"Press 1: Available Courses"<<endl;
                cout<<"Press 2: My Courses"<<endl;
                cout<<"Press 3: My Grades"<<endl;
                cout<<"Press 4: GPA Calculator"<<endl;
                cout<<"Selection: ";
                cin>>select1;
                }while(select1<1||select1>4);

                switch(select1)
                {
                case 1:
                    readcourse();
                    break;
                case 2:
                    cout << 2;
                    break;
                case 3:
                    cout << 3;
                    break;
                case 4:
                    calculateGPA();
                    break;
                }
                break;
            }
        
        }

        if(login){
            short op;
            cout << "Your information is wrong, please try again!!" << endl;
            cout << "---------------------------------------------" << endl;
            cout<<"Would you like to get an account if you haven't created yet?"<<endl;
            cout<<"Select 1 for YES"<<endl;
            cout<<"Select 2 for NO"<<endl;
            cout<<"Selection: ";
            cin>>op;
            do{
                
                switch(op){
                    case 1:
                        StuSign();
                        userInfo(inputUsername,inputPassword);
                        login = false;
                        cout<<"WELCOME!"<<endl;
                        break;
                    case 2:
                        userInfo(inputUsername,inputPassword);
                        break;
                }
            }while(op>2||op<1);
      
        }
        
    }
    
}