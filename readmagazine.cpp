#include "readmagazine.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


magazine::magazine(string s){
    ifstream obj(s);
    string temp;
    int i=0;
    getline(obj,temp,'\n');
    while(!obj.eof()){
        getline(obj,temp,',');
        //cout<<temp<<endl;
        magazine_array[i].publication=temp;
        getline(obj,temp,'"');
        getline(obj,temp,'"');
        magazine_array[i].rank=stof(temp);
        getline(obj,temp,'"');
        getline(obj,temp,'"');
        magazine_array[i].totalPaid=stof(temp);
        getline(obj,temp,'"');
        getline(obj,temp,'"');
        magazine_array[i].wordRate=stoll(temp);
        getline(obj,temp,'"');
        getline(obj,temp,'"');
        magazine_array[i].daysToBePaid=stof(temp);
        getline(obj,temp,'"');
        getline(obj,temp,'"');
        magazine_array[i].paymentDifficulty=stof(temp);
        getline(obj,temp,'"');
        getline(obj,temp,'"');
        magazine_array[i].rank_totalPaid=stof(temp);
        getline(obj,temp,'"');
        getline(obj,temp,'"');
        magazine_array[i].rank_wordRate=stof(temp);
        getline(obj,temp,'"');
        getline(obj,temp,'"');
        magazine_array[i].rank_daysToBePaid=stof(temp);
        getline(obj,temp,'"');
        getline(obj,temp,'\n');
        magazine_array[i].rank_paymentDifficulty=stof(temp);
        i++;
    }
}
