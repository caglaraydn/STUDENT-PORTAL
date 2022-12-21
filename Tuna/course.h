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

/*void asistsee(crs::course* sbj, short crselect, string user)
{
    short numofStu = 0;
    crs::course* temporary;
    char temp;
    string filex = sbj[crselect].courseName;
    filex += ".bin";

    ifstream file(filex, ios::binary | ios::ate);
    if(file.is_open())
    {
        streampos fileSize = file.tellg();
        char* memoryBlock = new char[fileSize];
        file.seekg(0,ios::beg);
        file.read(memoryBlock, fileSize);
        file.close();
        
        char* c = memoryBlock;
        char* tempPtr = memoryBlock;

        for(int i = 0; i < fileSize; i++){
            char k = *((char*)tempPtr);
            
            if(k != '?'){
                tempPtr++;
            }
            else{
                numofStu++;
                tempPtr++;
            }
        }

        temporary = new crs::course[numofStu]; //this is the dynamic array that storage each courses' data
        
        for(int i=0; i<numofStu; i++)
        {
            
            for(int j=0; j<25; j++)
            {
                temp = *((char*)c);

                if(temp != '?')
                {
                    temporary[i].courseName += *((char*)c);
                    c++;
                }
                else
                {
                    c++;
                    break;
                }
            }
        }
        for(int i=0; i<numofStu; i++)
        {
            cout << temporary[i].courseName << "\t";
        }
    }
}*/


void gotocourseselection(crs::course* sbj, short crselect, string user){

    ifstream entryfile("Course.bin",ios::binary|ios::app); //open Course.bin file that includes courses' data to copy with read mode
    



    
    char stop = '?';
    string filex = sbj[crselect].courseName;
    filex += ".bin";
    ofstream newfile(filex, ios::binary | ios::app);
    for(int i=0; i<user.length(); i++)
    {
        newfile.write((char*)&user[i], sizeof(char));
    }
    newfile.write((char*)&stop, sizeof(char));
    newfile.close();
    



    string filename = user;
    filename += ".bin";
    ofstream outfile(filename, ios::binary | ios::app);
    string line;
    if(entryfile&&outfile){
        while(getline(entryfile, line)){
            outfile << sbj[crselect].courseName<<"?";
            outfile << sbj[crselect].profName<<"?";
            outfile << sbj[crselect].profSurname<<"?";
            outfile << sbj[crselect].courseCredit<<"?";
        }
        cout << "The course has been selected! \n";
    }
    else {
        cout<<"Cannot read File";
    }
    entryfile.close();
    outfile.close();
}


void seecourses(string user)
{
    short NumofCourse = 0;
    short countStop = 0;
    crs::course* temporary;
    char temp;
    string filename = user;
    filename += ".bin";

    ifstream file(filename, ios::binary | ios::ate);
    if(file.is_open())
    {
        streampos fileSize = file.tellg();
        char* memoryBlock = new char[fileSize];
        file.seekg(0,ios::beg);
        file.read(memoryBlock, fileSize);
        file.close();
        
        char* c = memoryBlock;
        char* tempPtr = memoryBlock;

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

        temporary = new crs::course[NumofCourse]; //this is the dynamic array that storage each courses' data
        
        for(int i=0; i<NumofCourse; i++)
        {
            
            for(int j=0; j<25; j++)
            {
                temp = *((char*)c);

                if(temp != '?')
                {
                    temporary[i].courseName += *((char*)c);
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
                    temporary[i].profName += *((char*)c);
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
                    temporary[i].profSurname += *((char*)c);
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
                    temporary[i].courseCredit += *((char*)c);
                    c++;
                }
                else
                {
                    c++;
                    break;
                }
            }
            
        }
        delete[] memoryBlock;
    }
    else
    {
        cout<<"Can't open the file or it doesn't exist"<<endl;
    }

    cout<<endl;
    cout<<"THE COURSES ARE:"<<endl;

    for(int i=0; i<NumofCourse; i++)
    {
        cout << endl;
        cout <<i+1<<". "<<"Course name: " << temporary[i].courseName << endl;
        cout <<i+1<<". "<< "Professor: " << temporary[i].profName << " " << temporary[i].profSurname << endl;
        cout <<i+1<<". "<< "Course credit: " << temporary[i].courseCredit << endl;
    }

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


int readcourse(bool boolselectcrs, short person, string user)
{
    int NumofCourse = 0;
    int countStop = 0;
    char temp;
    crs::course* sbj;
    
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
                            gotocourseselection(sbj,rcrselect,user);
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
