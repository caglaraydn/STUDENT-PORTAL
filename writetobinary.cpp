#include <iostream>
#include <fstream>
#include <new>
#include <string>
using namespace std;

int main(){

    //string testpw = "ABCDEFG"; 
    //string testusr = "CAGLAR";

    string username;
    string password;

    cout << "Username: ";
    cin >> username;
    cout << endl;
    cout << "Password: ";
    cin >> password;
    
    char stop = '?';
    
    
    ofstream file("binarytest.bin", ios::binary | ios::app);
    if(file.is_open()){
        
        for(int i = 0; i < username.length(); i++){

            file.write((char*)&username[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));

        for(int i = 0; i < password.length(); i++){

            file.write((char*)&password[i], sizeof(char));
            
        }
        file.write((char*)&stop, sizeof(char));
        
        
        
        file.close();

    }
    
    
    
    
    
    return 0;
}