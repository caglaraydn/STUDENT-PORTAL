#include <iostream>
#include "asistantentry.h"
#include "profentry.h"
#include "studententry.h"
#include "gpa.h"
using namespace std;

int main()
{
  cout<<"***************************************"<<endl;
  cout<<"*    WELCOME TO THE STUDENT PORTAL    *"<<endl;
  cout<<"***************************************"<<endl;
  cout<<endl;
  short person;
  short op1;
  short op2;
  short op3;
  bool anothercrs=true;
  bool boolselectcrs=true;
  string username;
  
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
      cin>>op1;
      cout<<endl;
    }while(op1<1||op1>2);
    switch(op1){
        case 1://If user Log in
            StuLog();
            break;
        
        case 2://If user Sign Up
            do{//We asked student username on main because we needed username to be a universal variable.
              cout<<"Please enter your username to be signed up (maximum 11 characters): ";
              cin >> username;
            }while(username.length()>11);
            StuSign(username); //First Sign Up
            StuLog(); //Then Log In
            break;
    }
    break;

    case 2://T.A 
    do{
      cout<<"Select your operation"<<endl;
      cout<<"Select 1 for Log in"<<endl;
      cout<<"Select 2 for Sign up"<<endl;
      cout<<"Selection: ";
      cin>>op2;
      cout<<endl;
    }while(op2<1||op2>2);
    switch(op2){
        case 1://If user Log in
            AsistLog();
            break;
        
        case 2://If user Sign Up
            AsistSign(); //First Sign Up
            AsistLog(); //Then Log In
            break;
    }
    break;

    case 3://Prof
    do{
      cout<<"Select your operation"<<endl;
      cout<<"Select 1 for Log in"<<endl;
      cout<<"Select 2 for Sign up"<<endl;
      cout<<"Selection: ";
      cin>>op3;
      cout<<endl;
    }while(op3<1||op3>2);
    switch(op3){
        case 1://If user Log in
            ProfLog();
            break;
        
        case 2://If user Sign Up
            ProfSign(); //First Sign Up
            ProfLog(); //Then Log In
            break;
    }
    break;
  }

  if(person == 1)
  {
    short select1; //Student
    do
    {
      cout<<endl;
      cout<<endl;
      cout<<"Press 1: Available Courses"<<endl;
      cout<<"Press 2: My Courses"<<endl;
      cout<<"Press 3: GPA Calculator"<<endl;
      cout<<"Press 4: Exit"<<endl;
      cout<<"Selection: ";
      cin>>select1;
      switch(select1)
      {
        case 1:
          readcourse(boolselectcrs,person,username);//Shows all the courses.
          break;
        case 2:
          seecourses(username);//Shows selected courses.
          break;
        case 3:
          calculateGPA();//Lets user calculate gpa.
          break;
        case 4:
          cout<<"See you later.";//Exit
          break;
      }
    }while(select1 != 4);

  }

  if (person == 2)
  {
    short select2; //T.A
    do
    {
      cout<<endl;
      cout<<endl;
      cout<<"Press 1: My Courses"<<endl;
      cout<<"Press 2: Exit"<<endl;
      cout<<"Selection: ";
      cin>>select2;
      switch(select2)
      {
        case 1:
          cout << 1;//We couldn't manage the do this one.
          break;
        case 2:
          cout<<"See you later.";//Exit
          break;
      }
    }while(select2 != 2);

  }
  
  if (person == 3)
  {
    short select3; //Prof
    do
    {
      cout<<endl;
      cout<<endl;
      cout<<"Press 1: Open Courses"<<endl;
      cout<<"Press 2: Courses"<<endl;
      cout<<"Press 3: Exit"<<endl;
      cout<<"Selection: ";
      cin>>select3;
      switch(select3)
      {
        case 1:
          opencourse(anothercrs);//Let's profs open courses.
          break;
        case 2:
          readcourse(boolselectcrs,person,username);//Shows the list of opened courses to profs.
          break;
        case 3:
          cout<<"See you later.";//Exit
          break;
      }
    }while(select3 != 3);
  }
    return 0;
}