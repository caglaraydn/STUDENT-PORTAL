#include <iostream>
#include <fstream>
#include <string>
using namespace std;


namespace crs{

    class course{
        public:
            string courseName;
            string profName;
            string profSurname;
            string courseCredit;
    };

}



void opencourse(){

    string courseName;
    string courseCredit;
    string profName;
    string profSurname;

    do{
    cout << "Please enter a course name (Maximum 10 characters): ";
    cin >> courseName;
    cout << endl;
    }while(courseName.length()<1 || courseName.length()>25);

    do{
    cout << "Please enter the prof name (Maximum 10 characters): ";
    cin >> profName;
    cout << "Please enter the prof surname (Maximum 10 characters): ";
    cin >> profSurname;
    cout << endl;
    }while(profName.length()<1 || profName.length()>10 || profSurname.length()<1 || profSurname.length()>10);

    do{
    cout << "Please enter the credit of the course (Between 1-6): ";
    cin >> courseCredit;
    }while(courseCredit.length()!=1);
    
    char stop = '?';
    
    
    ofstream file("Course.bin", ios::binary | ios::app);
    if(file.is_open()){
        
        for(int i = 0; i < courseName.length(); i++){

            file.write((char*)&courseName[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));

        for(int i = 0; i < profName.length(); i++){

            file.write((char*)&profName[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));

        for(int i = 0; i < profSurname.length(); i++){

            file.write((char*)&profSurname[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));

        for(int i = 0; i < courseCredit.length(); i++){

            file.write((char*)&courseCredit[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));
        
        file.close();

    }

}



void readcourse()
{
    crs::course* sbj;
    int NumofCourse = 6;
    const int LimitofCourseName = 25;
    const int LimitofprofName = 10;
    const int LimitofprofSurname = 10;
    const int LimitofCourseCredit = 1;
    char temp;
    
    ifstream file("Course.bin", ios::binary | ios::ate);
    if(file.is_open())
    {
        streampos fileSize = file.tellg();
        char* cBrick = new char[fileSize];
        file.seekg(0,ios::beg);
        file.read(cBrick, fileSize);
        file.close();
        
        char* c = cBrick;
        sbj = new crs::course[NumofCourse];
        
        for(int i=0; i<NumofCourse; i++)
        {
            
            for(int j=0; j<LimitofCourseName; j++)
            {
                temp = *((char*)c);

                if(temp != '?')
                {
                    sbj[i].courseName += *((char*)c);
                    c++;
                }
                else
                {
                    c++;
                    break;
                }
            }
            
            for(int j=0; j<LimitofprofName; j++)
            {
                temp = *((char*)c);
                
                if(temp != '?')
                {
                    sbj[i].profName += *((char*)c);
                    c++;
                }
                else
                {
                    c++;
                    break;
                }
            }

            for(int j=0; j<LimitofprofSurname; j++)
            {
                temp = *((char*)c);
                
                if(temp != '?')
                {
                    sbj[i].profSurname += *((char*)c);
                    c++;
                }
                else
                {
                    c++;
                    break;
                }
            }
            
            for(int j=0; j<LimitofCourseCredit; j++)
            {
                temp = *((char*)c);

                if(temp != '?')
                {
                    sbj[i].courseCredit += *((char*)c);
                    c++;
                }
                else
                {
                    c++;
                    break;
                }
            }
            
        }
        delete[] cBrick;
    }
    else
    {
        cout << "Couldn't open the file";
    }

    for(int i=0; i<NumofCourse; i++)
    {
        cout << sbj[i].courseName << " " << sbj[i].profName << " " << sbj[i].profSurname << " " << sbj[i].courseCredit << endl;
    }
}