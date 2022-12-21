#include <iostream>
#include <fstream>
#include <new>
#include <string>
#include "usertypes.h"
#include "entry.h"
#pragma once
using namespace std;

void ProfSign(){//Within the ProfSign function, we get the username and the password with the code written here and save it in a file.

    string username;//Variable for setting the username.
    string password;//Variable for setting the password.
    string passSecond;//Variable for checking password for the second time.
    
    //Gets the username and the password from the user.
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
    

    char stop = '!';//Variable for seperating username and password in the file.
    ofstream file("profsave.bin", ios::binary | ios::app);//Opens a new file called "profsave.bin" and saves the username and password for professors.
    if(file.is_open()){
        
        for(int i = 0; i < username.length(); i++){//Saves username.

            file.write((char*)&username[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));//Seperating char.

        for(int i = 0; i < password.length(); i++){//Saves password.

            file.write((char*)&password[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));//Seperating char.
        
        file.close();

    }
    
}

//With the ProfLog function, we compare the username and password we receive from the user with the previously created file and enable the user to proceed to the next stage.
void ProfLog(){
    
    bool login = true;//Variable used to open a new account if you cannot log in with the username and password.
    string inputUsername;
    string inputPassword;
    int LimitUsername = 11;
    int LimitPassword = 18;
    user::prof* prof;//Makes a dynamic prof array of class prof.
    int profCount = 0;//Counts profs.
    int countStop = 0;//Variable for counting exclamation marks.
    char p;//Variable for checking exclamation marks.

    //Opens the file "profsave.bin" and puts already saved username and passwords to formerly defined array prof for checking the input username and password.
    ifstream file("profsave.bin", ios::binary | ios::ate);
    if(file.is_open()){
        streampos fileSize = file.tellg();
        char* mBlock = new char[fileSize];//Allocate a char array of file size.
        file.seekg(0,ios::beg);
        file.read(mBlock, fileSize);
        file.close();

        char* temp = mBlock;
        char* tempPtr = mBlock;

        for(int i = 0; i < fileSize; i++){//This checks how many exclamation marks are there in the file.
            char k = *((char*)tempPtr);
            
            if(k != '!'){
                tempPtr++;
            }
            else{
                countStop++;
                tempPtr++;
            }
        }

        profCount=countStop/2;//The reason we divide by 2 is to use 1 exclamation point for each username and password.
  
        prof = new user::prof[profCount];//This creates a dynamic array to save data in the file to individual spots of the array.
        for(int i = 0; i < profCount; i++){//Loop for setting individual spots of the array for each professors.

            
            for(int u = 0; u < LimitUsername; u++){//Sets username.

                p = *((char*)temp);

                if(p != '!'){
                    prof[i].username += *((char*)temp);
                    temp++;

                }
                else{
                    temp++;
                    break;
                }
                
            }

            for(int s = 0; s < LimitPassword; s++){//Sets password.
                
                p = *((char*)temp);

                if(p != '!'){
                    prof[i].password += *((char*)temp);
                    temp++;

                }
                else{
                    temp++;
                    break;
                }
                
            }
        }
        delete[] mBlock;//Deallacote heap memory by deleting mBlock.
    }

    
    userInfo(inputUsername,inputPassword);//Gets the user info.
    
    while(login){

        for(int i = 0; i < profCount; i++){//For every professors saved in to prof array checks whether the input info is correct or not.

            if(isInfoTrue(inputUsername,inputPassword,prof[i].username,prof[i].password)){//Checks the user info. 
                cout << endl;
                cout << "WELCOME!";
                login = false;//If the info is correct sets login to false so system let the user in.
                break;
            }
        
        }

        if(login){//If the info is incorrect asks the user whether they want to sign up or try log in again.
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
                        ProfSign();
                        userInfo(inputUsername,inputPassword);
                        login = false;//If the info is correct sets login to false so system let the user in.
                        cout<<"WELCOME!";
                        break;
                    case 2:
                        userInfo(inputUsername,inputPassword);
                        break;
                }
            }while(op>2||op<1);
      
        }
        
    }
    
}