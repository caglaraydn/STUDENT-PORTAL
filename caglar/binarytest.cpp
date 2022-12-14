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
    
    cout << "Username: ";
    cin >> inputUsr;
    cout << "Password: ";
    cin >> inputPw;
    
}

int main(){
    
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
                cout << "WELCOME " << stu[i].username;
                login = false;
                break;
            }
        
        }

        if(login){
            cout << "Your information is wrong, please try again!!" << endl;
            cout << "---------------------------------------------" << endl;
            askForInfo(inputUsername,inputPassword);
        }
            
            
        
        
    }
    
    
    return 0;
}




    
    
    
    



