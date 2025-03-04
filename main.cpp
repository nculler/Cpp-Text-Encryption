#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <cctype>
#include <string>

using namespace std;


int main(int argc, char* argv[]){
    
    bool encrypt = false;
    bool decrypt = false;
    bool num = false;
    bool input = false;
    bool output = false;
    bool error = false;
    string inputFile;
    string outputFile;
    string text;
    int key = 0;
    
    for (int i = 0; i < argc; i++){
        //cout << argv[i] << endl;
        if (strcmp(argv[i],"-e") == 0){
            encrypt = true;
           // cout << "encrypt true" << endl;
        }
        
        if (strcmp(argv[i],"-d") == 0){
            decrypt = true;
           // cout << "decrypt true" << endl;
        }
        
        if (strcmp(argv[i],"-k") == 0){
            num = true;
            key = stoi(argv[i+1]);
           // cout << "key true" << endl;
           // cout << key << endl;
            if (key < 0){
                error = true;
               // cout << error << endl;
                cout << "Key is not valid" << endl;
            }
        }
        
        if (strcmp(argv[i],"-i") == 0){
            input = true;
            inputFile = argv[i+1];
          //  cout << "input file true" << endl;
           // cout << inputFile << endl;
        }
        
        if (strcmp(argv[i],"-o") == 0){
            output = true;
            outputFile = argv[i+1];
           // cout << "output file true" << endl;
           // cout << outputFile << endl;
        }
    }
    
    ifstream ifile;
    ifile.open(inputFile);
    
    ofstream ofile;
    ofile.open(outputFile);
    
    if (num == false){
        error = true;
    }
    
    if (encrypt == true && decrypt == true){
        error = true;
    }
    
    if (!ifile.is_open()){
        error = true;
        cout << "filestream is bad" << endl;
    }
    
    if (error == false){
        
        
        if (encrypt){
            while(!ifile.eof() && ifile.is_open()){
                int eIndex;
                getline(ifile, text);
                cout << text << endl;
                
                for (int i = 0; i < text.size(); i++){
                    char eText;
                    eIndex = text[i];
                    if(isalpha(text[i])){
                        int correction = 26;
                        eIndex = eIndex + key;
                        
                        if(isupper(text[i])){
                            while (eIndex > 'Z'){
                                eIndex = eIndex - correction;
                            } 
                        }
                        
                        else {
                            while (eIndex > 'z'){
                                eIndex = eIndex - correction;
                            }
                        }
                        
                    }
                    eText = eIndex;
                    ofile << eText;
                }
            }
        }
        
        if (decrypt){
            while(!ifile.eof() && ifile.is_open()){
                int eIndex;
                getline(ifile, text);
                cout << text << endl;
                
                for (int i = 0; i < text.size(); i++){
                    char eText;
                    eIndex = text[i];
                    if(isalpha(text[i])){
                        int correction = 26;
                        eIndex = eIndex - key;
                        
                        if(isupper(text[i])){
                            while (eIndex < 'A'){
                                eIndex = eIndex + correction;
                            } 
                        }
                        
                        else {
                            while (eIndex < 'a'){
                                eIndex = eIndex + correction;
                            }
                        }
                        
                    }
                    eText = eIndex;
                    ofile << eText;
                }
            }
        }
    
    }
    
    else {
        cout << "Error detected, program ending" << endl;
    }
    
    ifile.close();
    ofile.close();
    
    return 0;
}