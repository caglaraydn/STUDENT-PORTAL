#include <iostream>
#include <fstream>
#include <new>
#include <string>
#include "user_types.h"

using namespace std;
    
bool isInfoTrue(string inputusr, string inputpw, string realUsr, string realPw){

    if(inputusr == realUsr && inputpw == realPw){
        return true;
    }
    else{
        return false;
    }
    
}

void askForInfo(string &inputUsr, string &inputPw){
    do{
    cout << "Please enter your username to login (maximum 11 characters): ";
    cin >> inputUsr;
    cout << "Please enter your password to login (4-18 characters):";
    cin >> inputPw;
    cout<<endl;
    }while(inputUsr.length()>11||(inputPw.length()<4||inputPw.length()>18));
    
}

int Register(){

    //string testpw = "ABCDEFG"; 
    //string testusr = "CAGLAR";

    string username;
    string password;
    string repassword;
    
    do{
      cout<<"Please enter your username to be signed up (maximum 11 characters): ";
      cin >> username;
      cout << endl;
      cout<<"Please enter your password to be signed up (4-18 characters): ";
      cin >> password;
      cout << endl;
      cout<<"Please enter your password again: ";
      cin>> repassword;
      cout << endl;
    }while(username.length()>11||(password.length()<4||password.length()>18)||password!=repassword);
    cout<<"YOU HAVE SUCCESSFULLY SIGNED UP!"<<endl;
    cout<<endl;
    
    char stop = '?';
    
    
    ofstream file("binarytest.bin", ios::binary | ios::app);
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
    
    return 0;
}


int LogIn(){
    
    bool login = true;
    string inputUsername;
    string inputPassword;
    Usr::student* stu;
    int studentNumber = 3;
    char p = 'a';

    ifstream file("binarytest.bin", ios::binary | ios::ate);
    if(file.is_open()){
        streampos fileSize = file.tellg();
        char* mBlock = new char[fileSize];
        file.seekg(0,ios::beg);

        file.read(mBlock, fileSize);
        file.close();

        char* tempPtr = mBlock;
        
        stu = new Usr::student[studentNumber];
        for(int i = 0; i < studentNumber; i++){

            
            for(int u = 0; u < 50; u++){

                p = *((char*)tempPtr);

                if(p != '?'){
                    //cout << *((char*)tempPtr);
                    stu[i].username += *((char*)tempPtr);
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
                    stu[i].password += *((char*)tempPtr);
                    tempPtr++;

                }
                else{
                    tempPtr++;
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

    
    askForInfo(inputUsername,inputPassword);
    
    while(login){

        for(int i = 0; i < studentNumber; i++){

            if(isInfoTrue(inputUsername,inputPassword,stu[i].username,stu[i].password)){
                cout << endl;
                cout << " W E L C O M E ! ";
                login = false;
                break;
            }
        
        }

        if(login){
            short yesno;
            cout << "Your information is wrong, please try again!!" << endl;
            cout << "---------------------------------------------" << endl;
            cout<<"Would you like to get an account if you haven't created yet?"<<endl;
            cout<<"Press 1 for YES"<<endl;
            cout<<"Press 2 for NO"<<endl;
            cin>>yesno;
            do{
                
                switch(yesno){
                    case 1:
                        Register();
                        askForInfo(inputUsername,inputPassword);
                        login = false;
                        cout<<"W E L C O M E !";
                        break;
                    case 2:
                        askForInfo(inputUsername,inputPassword);
                        break;
                }
            }while(yesno>2||yesno<1);
      
        }
        
    }
    
    return 0;
}


