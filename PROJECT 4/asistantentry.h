#include <iostream>
#include <fstream>
#include <new>
#include <string>
#include "usertypes.h"
#include "entry.h"
#pragma once
using namespace std;

void AsistSign(){

    string username;
    string password;
    string passSecond;
    
    do{
      cout<<"Please enter your username to be signed up (maximum 11 characters): ";
      cin >> username;
      cout<<"Please enter your password to be signed up (4-18 characters): ";
      cin >> password;
      cout<<"Please enter your password again: ";
      cin>> passSecond;
    }while(username.length()>11||(password.length()<4||password.length()>18)||password!=passSecond);
    cout<<"YOU HAVE SUCCESSFULLY SIGNED UP!"<<endl;
    cout<<endl;
    

    char stop = '?';
    ofstream file("asistsave.bin", ios::binary | ios::app);
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


void AsistLog(){
    
    bool login = true;
    string inputUsername;
    string inputPassword;
    int LimitUsername = 11;
    int LimitPassword = 18;
    user::assistant* ast;
    int asistCount = 0;
    int countStop = 0;
    char p;

    ifstream file("asistsave.bin", ios::binary | ios::ate);
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

        asistCount=countStop/2;

        ast = new user::assistant[asistCount];
        for(int i = 0; i < asistCount; i++){

            
            for(int u = 0; u < LimitUsername; u++){

                p = *((char*)temp);

                if(p != '?'){
                    ast[i].username += *((char*)temp);
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
                    ast[i].password += *((char*)temp);
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

        for(int i = 0; i < asistCount; i++){

            if(isInfoTrue(inputUsername,inputPassword,ast[i].username,ast[i].password)){
                cout << endl;
                cout << "WELCOME!"<<endl;
                login = false;
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
                        AsistSign();
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