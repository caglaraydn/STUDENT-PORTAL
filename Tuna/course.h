#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace crs{//Sets namespace for course.
    struct course{//Sets a struct for course with 4 objects.
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
            
            if(k != '!'){
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

                if(temp != '!')
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

    ifstream entryfile("course.bin",ios::binary|ios::app); //Open course.bin file that includes courses' data to copy with read mode

    char stop = '!';
    string filex = sbj[crselect].courseName;//Sets the filename to course name.
    filex += ".bin";//Adds ".bin" to filename.
    ofstream newfile(filex, ios::binary | ios::app);//Makes a new file for selected courses and put the usernames inside them.
    for(int i=0; i<user.length(); i++)
    {
        newfile.write((char*)&user[i], sizeof(char));
    }
    newfile.write((char*)&stop, sizeof(char));
    newfile.close();
    

    string filename = user;//Sets the filename to username from main.
    filename += ".bin";//Adds ".bin" to filename.
    ofstream outfile(filename, ios::binary | ios::app);//Makes a new file for selected users and put the course data inside them.
    string line;
    if(entryfile&&outfile){
        while(getline(entryfile, line)){//Getline gets all the lines on entryfile to line. If the stream is ready for more operations it sets to 1 so the loop continues.
            outfile << sbj[crselect].courseName<<"!";
            outfile << sbj[crselect].profName<<"!";
            outfile << sbj[crselect].profSurname<<"!";
            outfile << sbj[crselect].courseCredit<<"!";
        }
        cout << "The course has been selected! \n";
    }
    else {
        cout<<"Cannot read File";
    }
    entryfile.close();
    outfile.close();
}


void seecourses(string user)//Let's students see their selected courses.
{
    short NumofCourse = 0;
    short countStop = 0;
    crs::course* temporary;//Sets a temporary array.
    char temp;
    string filename = user;//Sets the filename to username from main.
    filename += ".bin";//Adds ".bin" to filename.

    ifstream file(filename, ios::binary | ios::ate);//Opens the student named file and makes a new char array that contains everything inside the file.
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
            
            if(k != '!'){
                tempPtr++;
            }
            else{
                countStop++;
                tempPtr++;
            }
        }

        NumofCourse=countStop/4; /*For each course data in the array we add 4 exclamation mark. So that the total of the exclamation mark 
        divided by 4 gives us the number of course.*/     

        temporary = new crs::course[NumofCourse]; //this is the dynamic array that storage each courses' data
        
        for(int i=0; i<NumofCourse; i++)
        {
            
            for(int j=0; j<25; j++)//Sets the course name.
            {
                temp = *((char*)c);

                if(temp != '!')
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
            
            for(int j=0; j<10; j++)//Sets the prof name.
            {
                temp = *((char*)c);
                
                if(temp != '!')
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

            for(int j=0; j<10; j++)//Sets the prof surname.
            {
                temp = *((char*)c);
                
                if(temp != '!')
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
            
            for(int j=0; j<2; j++)//Sets the course credit.
            {
                temp = *((char*)c);

                if(temp != '!')
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

    //Prints the courses that the student takes.
    cout<<endl;
    cout<<"My Courses:"<<endl;

    for(int i=0; i<NumofCourse; i++)
    {
        cout << endl;
        cout <<i+1<<". "<<"Course name: " << temporary[i].courseName << endl;
        cout <<i+1<<". "<< "Professor: " << temporary[i].profName << " " << temporary[i].profSurname << endl;
        cout <<i+1<<". "<< "Course credit: " << temporary[i].courseCredit << endl;
    }

}


void opencourse(bool anothercrs){//This function allows profs to open a course.

    string courseName;
    string courseCredit;
    string profName;
    string profSurname;

    //Gets coursename.
    do{
        cout << "Please enter a course name (Maximum 10 characters): ";
        cin >> courseName;
        cout << endl;
    }while(courseName.length()<1 || courseName.length()>25);

    //Gets profs full name.
    do{
        cout << "Please enter the prof name (Maximum 10 characters): ";
        cin >> profName;
        cout << "Please enter the prof surname (Maximum 10 characters): ";
        cin >> profSurname;
        cout << endl;
    }while(profName.length()<1 || profName.length()>10 || profSurname.length()<1 || profSurname.length()>10);

    //Gets course credit.
    do{
        cout << "Please enter the credit of the course: ";
        cin >> courseCredit;
    }while(courseCredit.length()!=1);
    
    char stop = '!'; //Variable for seperating objects of the struct course in the file.
    
    ofstream file("course.bin", ios::binary | ios::app);//Opens a file for saving every course created by the profs.
    if(file.is_open()){
        
        for(int i = 0; i < courseName.length(); i++){//Saves the name.

            file.write((char*)&courseName[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));

        for(int i = 0; i < profName.length(); i++){//Saves the prof name.

            file.write((char*)&profName[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));

        for(int i = 0; i < profSurname.length(); i++){//Saves the prof surname.

            file.write((char*)&profSurname[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));

        for(int i = 0; i < courseCredit.length(); i++){//Saves the credit.

            file.write((char*)&courseCredit[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));
        
        file.close();

    }
    
    //We set the anothercrs true in the beginning. It lets prof to save more then 1 courses.
    if(anothercrs){
        short yesno;
        do{
            cout << "---------------------------------------------" << endl;
            cout<<"Would you like to add another course?"<<endl;
            cout<<"Press 1 for YES"<<endl;
            cout<<"Press 2 for NO"<<endl;
            cout<<"Selection: ";
            cin>>yesno;
            cout<<endl;
            switch(yesno){
                case 1:
                    opencourse(anothercrs);//Lets the prof open a course.    
                    break;

                case 2:
                    anothercrs=false;//Sets the value pf anothercrs false so it doesn't repeat.
                    break;
            }
        }while(yesno>2||yesno<1);
      
    }

}


int readcourse(bool boolselectcrs, short person, string user)//This function lets students and profs to see the formerly open courses.
{
    int NumofCourse = 0;//Counts courses.
    int countStop = 0;//Variable for counting exclamation marks.
    crs::course* sbj;//Makes a dynamic sbj array of class student.
    char temp;
    
    //Opens the file "course.bin" and puts already saved course info to formerly defined array sbj for printing the info to student and profs.
    ifstream file("course.bin", ios::binary | ios::ate);
    if(file.is_open())
    {
        streampos fileSize = file.tellg();
        char* cBrick = new char[fileSize];//Allocate a char array of file size.
        file.seekg(0,ios::beg);
        file.read(cBrick, fileSize);
        file.close();
        
        char* c = cBrick;
        char* tempPtr = cBrick;

        for(int i = 0; i < fileSize; i++){//Counts the exclamation marks.
            char k = *((char*)tempPtr);
            
            if(k != '!'){
                tempPtr++;
            }
            else{
                countStop++;
                tempPtr++;
            }
        }

        NumofCourse=countStop/4; /*For each course data in the array we add 4 question mark. So that the total of the question mark 
        divided by 4 gives us the number of course.*/     

        sbj = new crs::course[NumofCourse]; //This is the dynamic array that storage each courses data.
        
        for(int i=0; i<NumofCourse; i++)
        {
            
            for(int j=0; j<25; j++)//Sets course name.
            {
                temp = *((char*)c);

                if(temp != '!')
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
            
            for(int j=0; j<10; j++)//Sets prof name.
            {
                temp = *((char*)c);
                
                if(temp != '!')
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

            for(int j=0; j<10; j++)//Sets the prof surname.
            {
                temp = *((char*)c);
                
                if(temp != '!')
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
            
            for(int j=0; j<2; j++)//Sets the course credit.
            {
                temp = *((char*)c);

                if(temp != '!')
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
        delete[] cBrick;//Deallacote heap memory by deleting cBrick.
    }

    //If there isn't any course available it will print out this.
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



    // if the person is a student can see this on the terminal.
    if(person==1){//This section asks person whether they want to select a course or not.
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
                            gotocourseselection(sbj,rcrselect,user);//If they want to select a course. This function will let them select the course they want.
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
