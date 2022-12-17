#include <iostream>
#include "entry.h"
#include "gpa.h"
using namespace std;

int main()
{
  cout<<"***************************************"<<endl;
  cout<<"*    WELCOME TO THE STUDENT PORTAL    *"<<endl;
  cout<<"***************************************"<<endl;
  cout<<endl;
  short person;
  short operation;
    
  do{
  cout<<"Select 1 for Student"<<endl;
  cout<<"Select 2 for Teaching Assistant"<<endl;
  cout<<"Select 3 for Professor"<<endl;
  cout<<"Selection: ";
  cin>>person;
  cout<<endl;
  }while(person<1||person>3);

  switch(person)
  {
    case 1://Student
    do{
      cout<<"Select your operation"<<endl;
      cout<<"Select 1 for Log in"<<endl;
      cout<<"Select 2 for Sign up"<<endl;
      cout<<"Selection: ";
      cin>>operation;
      cout<<endl;
    }while(operation<1||operation>2);
    break;

    case 2://T.A 
    do{
      cout<<"Select your operation"<<endl;
      cout<<"Select 1 for Log in"<<endl;
      cout<<"Select 2 for Sign up"<<endl;
      cout<<"Selection: ";
      cin>>operation;
      cout<<endl;
    }while(operation<1||operation>2);
    break;

    case 3://Prof
    do{
      cout<<"Select your operation"<<endl;
      cout<<"Select 1 for Log in"<<endl;
      cout<<"Select 2 for Sign up"<<endl;
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
            SignUp(); //ilk önce kaydolacak
            LogIn(); //sonra tekrardan login ekranından giriş yapcak
            break;
    }


if(person == 1)
  {
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
        cout << 1;
      case 2:
        cout << 2;
      case 3:
        cout << 3;
      case 4:
        calculateGPA();
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
  }
  
  if (person == 3)
  {
    short select3; //Prof
    do
    {
      cout<<"Press 1: Open Courses"<<endl;
      cout<<"Press 2: Courses"<<endl;
      cout<<"Press 3: Student Grades"<<endl;
      cout<<"Selection: ";
      cin>>select3;
    }while(select3<1||select3>3);

    switch(select3)
    {
      case 1:
        cout << 1;
      case 2:
        cout << 2;
      case 3:
        cout << 3;
    }
  }
    return 0;
}