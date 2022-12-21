#include <iostream>
#include <fstream>
#include <new>
#include <string>
#pragma once
using namespace std;


void userInfo(string &inputUser, string &inputPass){//Gets the user info.
    do{
    cout << "Please enter your username to login (maximum 11 characters): ";
    cin >> inputUser;
    cout << "Please enter your password to login (4-18 characters): ";
    cin >> inputPass;
    cout<<endl;
    }while(inputUser.length()>11||(inputPass.length()<4||inputPass.length()>18));
    
}


bool isInfoTrue(string inputusr, string inputpw, string savedUser, string savedPass){//Checks the user info. 

    if(inputusr == savedUser && inputpw == savedPass){
        return true;
    }
    else{
        return false;
    }
    
}
