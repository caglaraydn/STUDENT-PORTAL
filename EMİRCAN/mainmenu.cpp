#include <iostream>
#include <fstream>
#include <new>
#include <string>
#include "binarytest.h"
using namespace std;

int main(){

cout<<endl;
cout<<"***************************************"<<endl;
cout<<"*****WELCOME TO THE STUDENT PORTAL*****"<<endl;
cout<<"***************************************"<<endl;
cout<<endl;

short person;
short operation;

do{
cout<<"Press 1: if you are a professor"<<endl;
cout<<"Press 2: if you are a teaching assistant"<<endl;
cout<<"Press 3: if you are a student"<<endl;
cin>>person;
}while(person<1||person>3);

switch(person){
    
    case 1://profesör için
    do{
        cout<<"Please select the operation"<<endl;
        cout<<"Press 1: for login"<<endl;
        cout<<"Press 2: for sign up"<<endl;
        cin>>operation;
    }while(operation<1||operation>2);
    break;

    case 2://ta için
    do{
        cout<<"Please select the operation"<<endl;
        cout<<"Press 1: for login"<<endl;
        cout<<"Press 2: for sign up"<<endl;
        cin>>operation;
    }while(operation<1||operation>2);
    break;

    case 3://öğrenci için
    do{
        cout<<"Please select the operation"<<endl;
        cout<<"Press 1: for login"<<endl;
        cout<<"Press 2: for sign up"<<endl;
        cin>>operation;
    }while(operation<1||operation>2);
    break;
    }

switch(operation){
        case 1://eğer kullanıcı login yaparsa
            LogIn();
        break;
        
        case 2://eğer kullanıcı signup yaparsa
            Register(); //ilk önce kaydolacak
            LogIn(); //sonra tekrardan login ekranından giriş yapcak
        break;
    }

}