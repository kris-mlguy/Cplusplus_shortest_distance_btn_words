// Created by Krishnan Parameswaran

// Given two words and a group of words in a text file, 
// find the shortest distance between the two words in terms of number of words

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream myFile;
    string myPath = "words.txt" ;
    myFile.open(myPath);
    if (!myFile) {
    cerr << "Unable to open file words.txt";
    exit(1);   
    }
    
    char output[100][100];
    int n = 0;
    if (myFile.is_open()) {
        while (!myFile.eof()) {
            myFile >> output[n];
            cout << output[n] << '\t';
            n++;
        }
    }
    
    myFile.close();
    
    string word1, word2;
    cout << "\nEnter the first word: " << endl;
    cin >> word1;
    cout << "Enter the second word: " << endl;
    cin >> word2;
    
    int k=0;
    
    for (int i=0; i<n; i++){
        if (output[i] == word1){
            for (int j=i+1; j<n; j++){
                if (output[j] == word1){
                    k=0;
                }
                if (output[j] == word2){
                    cout << "The shortest distance is " << k << " word/s" << endl;
                    exit(1);
                }else{
                    k++;
                }
                
            }
            
            cout << "The second word is not found after first word in the text file, please try again" << endl;
            exit(1);
        }
    }
    
    cout << "The first word is not found in the text file, check the spelling and try again" << endl;
    
    return 0;
}