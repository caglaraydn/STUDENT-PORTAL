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


void gotocourseselection(crs::course* sbj, short crselect){
    ifstream ini_file("Course.bin",ios::binary|ios::app); //open Course.bin file that includes courses' data to copy with read mode
    
    ofstream out_file("SelectedCourse.bin",ios::binary|ios::app); /*open SelectedCourse.bin file that will 
                                                                    include selected course data with write mode*/
    string line;
    if(ini_file&&out_file){
        while(getline(ini_file, line)){
            out_file << sbj[crselect].courseName<<"?";
            out_file << sbj[crselect].profName<<"?";
            out_file << sbj[crselect].profSurname<<"?";
            out_file << sbj[crselect].courseCredit<<"?";
        }
        cout << "The course has been selected! \n";
    }
    else {
        cout<<"Cannot read File";
    }
    ini_file.close();
    out_file.close();
}


void opencourse(bool anothercrs){

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
        cout << "Please enter the credit of the course: ";
        cin >> courseCredit;
    }while(courseCredit.length()!=1);
    
    char stop = '?'; //we will separate the strings thanks to by adding "?" mark at the end of each string
    
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
    
    //while anothercrs is true than execute this code
    if(anothercrs){
        short yesno;
        do{
            //cout << "Your information is wrong, please try again!!" << endl;
            cout << "---------------------------------------------" << endl;
            cout<<"Would you like to add another course?"<<endl;
            cout<<"Press 1 for YES"<<endl;
            cout<<"Press 2 for NO"<<endl;
            cout<<"Selection: ";
            cin>>yesno;
            cout<<endl;
            switch(yesno){
                case 1:
                    opencourse(anothercrs);       
                    break;

                case 2:
                    anothercrs=false;
                    break;
            }
        }while(yesno>2||yesno<1);
      
    }

}


int readcourse(bool boolselectcrs, short person)
{
    crs::course* sbj;
    int NumofCourse = 0;
    int countStop = 0;
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
        char* tempPtr = cBrick;

        for(int i = 0; i < fileSize; i++){
            char k = *((char*)tempPtr);
            
            if(k != '?'){
                tempPtr++;
            }
            else{
                countStop++;
                tempPtr++;
            }
        }

        NumofCourse=countStop/4; /*For each course data in the array we add 4 question mark. So that the total of the question mark 
        divided by 4 gives us the number of course.*/     

        sbj = new crs::course[NumofCourse]; //this is the dynamic array that storage each courses' data
        
        for(int i=0; i<NumofCourse; i++)
        {
            
            for(int j=0; j<25; j++)
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
            
            for(int j=0; j<10; j++)
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

            for(int j=0; j<10; j++)
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
            
            for(int j=0; j<2; j++)
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
        cout<<endl;
        cout << "There is no course available!"<<endl;
        return 0;
    }

    cout<<endl;
    cout<<"THE COURSES ARE:"<<endl;
    cout<<endl; 

    for(int i=0; i<NumofCourse; i++)
    {
        cout << endl;
        cout <<i+1<<". "<<"Course name: " << sbj[i].courseName << endl;
        cout <<i+1<<". "<< "Professor: " << sbj[i].profName << " " << sbj[i].profSurname << endl;
        cout <<i+1<<". "<< "Course credit: " << sbj[i].courseCredit << endl;
    }



    // if the person is a student or teaching assistant can see this on the terminal.
    if(person==1||person==2){
        short crselect;
        short yesno;
            do{
                cout<<endl;
                cout<<"Would you like to select course?"<<endl;
                cout<<"Press 1 for YES"<<endl;
                cout<<"Press 2 for NO"<<endl;
                cout<<"Selection:";
                cin>>yesno;
                    switch(yesno){
                        case 1:
                            do{
                            cout<<endl;
                            cout<<"Please enter the number of course to select: ";
                            cin>>crselect;
                            short rcrselect=crselect-1;
                            gotocourseselection(sbj,rcrselect);
                            }while(crselect<1||crselect>20);
                            break;
                    
                        case 2:
                            boolselectcrs=false;
                            break;
                    }
            }while(yesno<1||yesno>2||boolselectcrs);
    }
    return 0;
}
