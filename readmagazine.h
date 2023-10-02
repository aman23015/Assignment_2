#ifndef readmagazine_h
#define readmagazine_h
#include<string>
using namespace std;
class magazine{
    public:
    struct magazine_row{
        string publication;
        float rank,totalPaid,daysToBePaid,paymentDifficulty,rank_totalPaid,rank_wordRate,rank_daysToBePaid,rank_paymentDifficulty;
        long long wordRate;
    };
    // public:
        struct magazine_row magazine_array[85];
        //string borrowed_time[85];
        bool isborrowed[85]={0};
        magazine(string);
};

#endif