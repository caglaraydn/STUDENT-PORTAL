#include <iostream>
#include <string>
#include <new>
using namespace std;

void calculateGPA()
{
    int course;
    cout << endl;
    cout << "How many course will you enter? : ";
    cin >> course;
    cout << endl;
    
    double* point = new double[course];
    double* credit = new double[course];
    
    for(int i=0; i<course; i++)
    {
        do{
        cout << "Course " << i+1 << " point: ";
        cin >> point[i];
        cout << "Course " << i+1 << " credit: ";
        cin >> credit[i];
        cout << endl;
        }while(point[i]<0 || point[i]>100 || credit[i]<1 || credit[i]>6);
    }
    
    double totCre = 0;
    double mult;
    double sumofmult = 0;
    
    for(int j=0; j<course; j++)
    {

        if(point[j]>89)
            point[j] = 4;
        
        else if(point[j]>84)
            point[j] = 3.5;
        
        else if(point[j]>79)
            point[j] = 3;

        else if(point[j]>74)
            point[j] = 2.5;
        
        else if(point[j]>69)
            point[j] = 2;
        
        else if(point[j]>64)
            point[j] = 1.5;
        
        else if(point[j]>59)
            point[j] = 1;
        
        else if(point[j]>49)
            point[j] = 0.5;

        else
            point[j] = 0;


        totCre += credit[j];
        mult = credit[j]*point[j];
        sumofmult += mult;
        
    }
    
    cout << "Total GPA: " << sumofmult/totCre << endl;
    
}