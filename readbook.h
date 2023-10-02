#ifndef readbook_h
#define readbook_h
#include<string>
using namespace std;

class book{
    
       
    public:
     struct bookrow{
        int book_id , books_count ;                                                                                  
        long long  goodreads_book_id,  best_book_id ,work_id ,isbn , isbn13,ratings_count ,work_ratings_count ,work_text_reviews_count ,ratings_1 ,ratings_2 ,ratings_3 ,ratings_4 ,ratings_5 ;
        float average_rating ,original_publication_year; 
        string authors,original_title ,title ,language_code ,image_url ,small_image_url;                                                                                                                                                                                                                      
        };
    
    struct bookrow book_rows_array[110];
    //string borrowed_time[110];
    book(string );
};
#endif