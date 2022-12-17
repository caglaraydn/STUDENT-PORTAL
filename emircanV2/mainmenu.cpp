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
cout<<"Selection: ";
cin>>person;
cout<<endl;
}while(person<1||person>3);

switch(person){
    
    case 1://profesör için
    do{
        cout<<"Please select the operation"<<endl;
        cout<<"Press 1: for login"<<endl;
        cout<<"Press 2: for sign up"<<endl;
        cout<<"Selection: ";
        cin>>operation;
        cout<<endl;
    }while(operation<1||operation>2);
    break;

    case 2://ta için
    do{
        cout<<"Please select the operation"<<endl;
        cout<<"Press 1: for login"<<endl;
        cout<<"Press 2: for sign up"<<endl;
        cout<<"Selection: ";
        cin>>operation;
        cout<<endl;
    }while(operation<1||operation>2);
    break;

    case 3://öğrenci için
    do{
        cout<<"Please select the operation"<<endl;
        cout<<"Press 1: for login"<<endl;
        cout<<"Press 2: for sign up"<<endl;
        cout<<"Selection: ";
        cin>>operation;
        cout<<endl;
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


/*if(person == 3)
  {
    short select3; //Student
    do
    {
      cout<<"Press 1: Available Courses"<<endl;
      cout<<"Press 2: My Courses"<<endl;
      cout<<"Press 3: My Grades"<<endl;
      cout<<"Press 3: GPA Calculator"<<endl;
      cout<<"Selection: ";
      cin>>select3;
    }while(select3<1||select3>4);

    switch(select3)
    {
      case 1:
        cout << 1;
      case 2:
        cout << 2;
      case 3:
        cout << 3;
      case 4:
        cout << 4;
    }
  }

  if (person == 2)
  {
    short select2; //T.A
    do
    {
      cout<<"Press 1: Change Notes"<<endl;
      cout<<"Press 2: My Courses"<<endl;
      cout<<"Selection: ";
      cin>>select2;
    }while(select2<1||select2>2);

    switch(select2)
    {
      case 1:
        cout << 1;
      case 2:
        cout << 2;
    }
  }*/
  
  if (person == 1)
  {
    short select1; //Prof
    do
    {
        cout<<endl;
        cout<<"Press 1: Open Courses"<<endl;
        cout<<"Press 2: Courses"<<endl;
        cout<<"Press 3: Student Grades"<<endl;
        cout<<"Selection: ";
        cin>>select1;
    }while(select1<1||select1>3);

    switch(select1)
    {
      case 1:
        opencourse();
      case 2:
        readcourse();
      case 3:
        cout << 3;
    }
  }


}