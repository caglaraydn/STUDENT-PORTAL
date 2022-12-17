#include <iostream>
#include <fstream>
#include <new>
#include <string>
#include "user_types.h"
using namespace std;


void userInfo(string &inputUser, string &inputPass){
    do{
    cout << "Please enter your username to login (maximum 11 characters): ";
    cin >> inputUser;
    cout << "Please enter your password to login (4-18 characters): ";
    cin >> inputPass;
    cout<<endl;
    }while(inputUser.length()>11||(inputPass.length()<4||inputPass.length()>18));
    
}


bool isInfoTrue(string inputusr, string inputpw, string savedUser, string savedPass){

    if(inputusr == savedUser && inputpw == savedPass){
        return true;
    }
    else{
        return false;
    }
    
}


void SignUp(){

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
    ofstream file("savedusers.bin", ios::binary | ios::app);
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


void LogIn(){
    
    bool login = true;
    string inputUsername;
    string inputPassword;
    int LimitUsername = 11;
    int LimitPassword = 18;
    user::student* stu;
    int studentNumber = 50;
    char p;

    ifstream file("savedusers.bin", ios::binary | ios::ate);
    if(file.is_open()){
        streampos fileSize = file.tellg();
        char* mBlock = new char[fileSize];
        file.seekg(0,ios::beg);
        file.read(mBlock, fileSize);
        file.close();

        char* temp = mBlock;
        
        stu = new user::student[studentNumber];
        for(int i = 0; i < studentNumber; i++){

            
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

        cout << "User List: " << endl;
        for(int j = 0; j < studentNumber; j++){

            cout << j+1 << ". " << "Username is " << stu[j].username << endl;
            cout << j+1 << ". " << "Password is " << stu[j].password << endl;
            cout << "XXXX" << endl;;
            
        }
        
        
        delete[] mBlock;
        
    }

    
    userInfo(inputUsername,inputPassword);
    
    while(login){

        for(int i = 0; i < studentNumber; i++){

            if(isInfoTrue(inputUsername,inputPassword,stu[i].username,stu[i].password)){
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
                        SignUp();
                        userInfo(inputUsername,inputPassword);
                        login = false;
                        cout<<"W E L C O M E !"<<endl;
                        break;
                    case 2:
                        userInfo(inputUsername,inputPassword);
                        break;
                }
            }while(op>2||op<1);
      
        }
        
    }
    
}