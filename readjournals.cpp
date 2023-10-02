#include"readjournals.h"
#include<iostream>
#include<fstream>

using namespace std;


journal::journal(string s){
    ifstream journal_object(s);
    string temp;
    int i=0;
    while(!journal_object.eof()){
        getline(journal_object,temp,'\n');
        journal_array[i++]=temp;
    }
}
