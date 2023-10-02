#include "readbook.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;


book::book(string s){
    ifstream bookobject(s);
    int i=0;
    string bk_id,gb_id,bb_id,wk_id,b_count,ibn,ibn_13,op_yr,av_rating,r_count,w_count,w_t_count,r_1,r_2,r_3,r_4,r_5;
    string temp,temp1;
    getline(bookobject,temp,'\n');
    while(!bookobject.eof()){
        getline(bookobject,bk_id,',');
        book_rows_array[i].book_id=stoi(bk_id);
        getline(bookobject,gb_id,',');
        book_rows_array[i].goodreads_book_id=stoll(gb_id);
        getline(bookobject,bb_id,',');
        book_rows_array[i].best_book_id=stoll(bb_id);
        getline(bookobject,wk_id,',');
        book_rows_array[i].work_id=stoll(wk_id);
        getline(bookobject,b_count,',');
        book_rows_array[i].books_count=stoi(b_count);
        getline(bookobject,ibn,',');
        book_rows_array[i].isbn=stoll(ibn);
        getline(bookobject,ibn_13,',');
        book_rows_array[i].isbn13=stoll(ibn_13);
        getline(bookobject,temp1,',');
        book_rows_array[i].authors=temp1;
        if(temp1[0]=='"'){
            getline(bookobject,temp1,'"');
            book_rows_array[i].authors=book_rows_array[i].authors + temp1;
            getline(bookobject,temp1,',');
        }
        getline(bookobject,op_yr,',');
        book_rows_array[i].original_publication_year=stof(op_yr);
        getline(bookobject,temp,',');
        book_rows_array[i].original_title=temp;
         if(temp[0]=='"'){
            getline(bookobject,temp,'"');
            book_rows_array[i].original_title=book_rows_array[i].original_title + temp;
            getline(bookobject,temp,',');
        }
         
        getline(bookobject,temp,',');
         book_rows_array[i].title=temp;   
         if(temp[0]=='"'){
            getline(bookobject,temp,'"');
            book_rows_array[i].title=book_rows_array[i].title + temp;
            getline(bookobject,temp,',');
        }
        //cout<<book_rows_array[i].title<<endl;
        getline(bookobject,book_rows_array[i].language_code,',');
        //cout<<book_rows_array[i].language_code<<endl;
        getline(bookobject,av_rating,',');
              //cout<<av_rating<<endl;
        book_rows_array[i].average_rating=stof(av_rating);
        getline(bookobject,r_count,',');
        book_rows_array[i].ratings_count=stoll(r_count);   
        getline(bookobject,w_count,',');
        book_rows_array[i].work_ratings_count=stoll(w_count);
        getline(bookobject,w_t_count,',');
        book_rows_array[i].work_text_reviews_count=stoll(w_t_count);   
        getline(bookobject,r_1,',');
        book_rows_array[i].ratings_1=stoll(r_1);                                                                                                                                                                                                                
        getline(bookobject,r_2,',');
        book_rows_array[i].ratings_2=stoll(r_2); 
        getline(bookobject,r_3,',');
        book_rows_array[i].ratings_3=stoll(r_3); 
        getline(bookobject,r_4,',');
        book_rows_array[i].ratings_4=stoll(r_4); 
        getline(bookobject,r_5,',');
        book_rows_array[i].ratings_5=stoll(r_5); 
        getline(bookobject,book_rows_array[i].image_url,',');
        getline(bookobject,book_rows_array[i].small_image_url,'\n');
        i++;
    }
}
