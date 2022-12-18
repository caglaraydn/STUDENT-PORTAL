#include <iostream>
#include "asistantentry.h"
#include "profentry.h"
#include "studententry.h"
#include "gpa.h"
using namespace std;

int main()
{
  bool anothercrs=true;
  cout<<"***************************************"<<endl;
  cout<<"*    WELCOME TO THE STUDENT PORTAL    *"<<endl;
  cout<<"***************************************"<<endl;
  cout<<endl;
  short person;
  short op1;
  short op2;
  short op3;
  
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
        case 1://eğer kullanıcı login yaparsa
            StuLog();
            break;
        
        case 2://eğer kullanıcı signup yaparsa
            StuSign(); //ilk önce kaydolacak
            StuLog(); //sonra tekrardan login ekranından giriş yapcak
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
        case 1://eğer kullanıcı login yaparsa
            AsistLog();
            break;
        
        case 2://eğer kullanıcı signup yaparsa
            AsistSign(); //ilk önce kaydolacak
            AsistLog(); //sonra tekrardan login ekranından giriş yapcak
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
        case 1://eğer kullanıcı login yaparsa
            ProfLog();
            break;
        
        case 2://eğer kullanıcı signup yaparsa
            ProfSign(); //ilk önce kaydolacak
            ProfLog(); //sonra tekrardan login ekranından giriş yapcak
            break;
    }
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
        readcourse();
        break;
      case 2:
        cout << 2;
        break;
      case 3:
        cout << 3;
        break;
      case 4:
        calculateGPA();
        break;
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
        break;
      case 2:
        cout << 2;
        break;
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
        opencourse(anothercrs);
        break;
      case 2:
        readcourse();
        break;
      case 3:
        cout << 3;
        break;
    }
  }
    return 0;
}