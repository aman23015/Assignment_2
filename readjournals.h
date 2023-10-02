#ifndef readjournals_h
#define readjournals_h
#include<iostream>
#include<string>
// using namespace std;
class journal{
    public:
        std::string journal_array[110];
        bool isborrowed[110]={0};
        //std::string borrowed_time[110];

        journal(std::string);  
};
#endif