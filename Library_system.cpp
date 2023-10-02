#include"readbook.h"
#include"readjournals.h"
#include"readmagazine.h"
#include<iostream>
#include<ctime>
#include<string>
using namespace std;
struct borrowed_item{
    string name;
    string title;
    string user_type;
    string date;
    string lending_period;
};
string current_time(){
    time_t now = time(0);
    char* dt = ctime(&now);
    return dt;
}


class user{
   public:
    string name,usertype,password;
   
//    public:
    user(string name,string password,string usertype){
        this->name=name;
        this->usertype=usertype;
        this->password=password;
    } 
    user(){}
            
};
class student : public user{
 public:
 student(string name,string password):user(name,password,"student"){}
 student() {
    this->usertype="student";
 }
};

class Faculty : public user{
   public: 
    Faculty(string name,string password):user(name,password,"Faculty"){}
    Faculty(){
        this->usertype="Faculty";
    }
    // user_array Faculty_array[100];
};

void put_student_info(string account, string password,student* S, int &p){
 S[p].name=account;
 S[p].password=password;
 p++;
}

int check_student_username(string account ,student* S,int p){
    bool usertaken=false;
    for(int i=0;i<=p;i++){
        if(account==S[i].name){
            usertaken=true;
        }
    }
    if(usertaken){
        return 1;
    }
    return 0;
}

int check_student(string account,string password,student* S ,int p){
  bool usertaken=false;
  for(int i=0;i<=p;i++){
    if(account==S[i].name && password==S[i].password){
        usertaken=true;
    }
  }
  if(usertaken){
    return 1;
  }
  return 0;
}

void put_faculty_info(string account, string password ,Faculty* F,int &q){
 F[q].name=account;
 F[q].password=password;
 q++;
}

int check_faculty_username(string account ,Faculty* F ){
 bool usertaken=false;
 for(int i=0;i<100;i++){
    if(account==F[i].name){
        usertaken=true;
    }
 }
 if(usertaken){
    return 1;
 }
 return 0;
}

int check_faculty(string account,string password,Faculty* F ,int q){
 bool usertaken=false;
 for(int i=0;i<=q;i++){
    if(account==F[i].name && password==F[i].password){
        usertaken=true;
    }
 }
 if(usertaken){
    return 1;
 }
 return 0;
}
void search_book(string name,book & object){
    for(int i=0;i<110;i++){
        if(name==object.book_rows_array[i].original_title){
            int row=i/10,col=i%10;
            cout<<"Book is present at "<<row+1<<" row and "<<col+1<<" column "<<endl;
            return;
        }
    }
    cout<<"\n\nError!! Book is not present \n";
}
void search_magazine(string name,magazine & object){
    char s='"';
    name=s+name+s;
    for(int i=0;i<110;i++){
        if(name==object.magazine_array[i].publication){
            int row=i/10,col=i%10;
            cout<<"Magazine is present at "<<row+1<<" row and "<<col+1<<" column "<<endl;
            return;
        }
    }
    cout<<"\n\nError!! Magazine is not available \n";
}
void Borrow_book(string name,book & object){//borrowed_item &borrowed_item_record
   
    for(int i=0;i<110;i++){
        // std::cout<<i<<" "<<object.book_rows_array[i].original_title<<endl;
        if(name==object.book_rows_array[i].original_title){
            if(object.book_rows_array[i].books_count!=0){
                object.book_rows_array[i].books_count-=1;
                //object.borrowed_time[i]=current_time();
                // borrowed_item_record[i].title=name;
                // borrowed_item_record[i].name=


                // borrowed(borrowed_item_record,usertype,k,username,name)

               std:: cout<<"\n\n Book borrowed Successfully \n";
               std:: cout<<"\n\nBook is issued on date and time at :"<<current_time()<<endl;
                

                return;
            }
        }
    }
    std::cout<<"\n\n Error!! Book not available\n ";
}
void Return_book(string name,book & object){
    for(int i=0;i<110;i++){
        if(name==object.book_rows_array[i].original_title){
            object.book_rows_array[i].books_count+=1;
            //object.borrowed_time[i]={0};
           std:: cout<<"\n\n Book returned successfully \n";
           std:: cout<<"\n\nBook returned on date and time at :"<<current_time()<<endl;
        }
    }
}
void Borrow_magazine(string name,magazine & object){
    char s='"';
    name = s+name+s;
    for(int i=0;i<85;i++){
        // std::cout<<i<<" "<<object.magazine_array[i].publication<<endl;
        if(name==object.magazine_array[i].publication && object.isborrowed[i]==0){
            object.isborrowed[i]=1;
           // object.borrowed_time[i]=current_time();
            std::cout<<"\n\n Magazine borrowed successfully \n";
            std::cout<<"\n\nMagazine issued on date and time at :"<<current_time()<<endl;
            return;
        }
    }
    std::cout<<"\n\n Error!! Magazine is not available \n";
}
void Return_magazine(string name,magazine & object){
    char s='"';
    name = s+name+s;  
 for(int i=0;i<85;i++){
    if(name==object.magazine_array[i].publication){
        object.isborrowed[i]=0;
        //object.borrowed_time[i]={0};
        std::cout<<"\n\nMagazine return Successfully \n";
        std::cout<<"\n\nMagazine return on date and time at :"<<current_time()<<endl;
    }
 }
}
string which_lib(int i){
    if(i%5==0||i%5==4){
        return "IIIT Delhi";
    }
    else if(i%5==1){
        return "IIIT Hyderabad";
    }
    else if(i%5==2){
        return "IIIT Bangalore";
    }
    return "IIIT Allahbad";
}
void Borrow_journals(string name,journal & object){
    for(int i=0;i<100;i++){
        // std::cout<<i<<" "<<object.journal_array[i]<<endl;
        if(name==object.journal_array[i] && object.isborrowed[i]==0 ){
            object.isborrowed[i]=1;
            //object.borrowed_time[i]=current_time();
            std::cout<<"\n\n Journal Borrowed Successfully \n";
            std::cout<<"\n\n journal issued on date and time at :"<<current_time()<<endl;
            return;
        }
    }
    system("cls");
    std::cout<<"\n\nError!! that journal is not available \n";
    
}
void find_in_other_lib(string name,string item,book & book_object,magazine & magazine_object){
        if(item=="book"){
        for(int i=0;i<110;i++){
            if(name==book_object.book_rows_array[i].original_title){
                int row=i/10;
                int col=i%10;
                string s=which_lib(i);
                cout<<"\n\nBook is in the "<<s<<" college library at row "<<row+1<<" and column "<<col+1<<endl;
            }
        }
    }
    else if(item=="magazine"){
        for(int i=0;i<110;i++){
            if(name==magazine_object.magazine_array[i].publication){
                string s=which_lib(i);
                int row=i/10;
                int col=i%10;
                cout<<"\n\nMagazine is in the "<<s<<" college library at row "<<row+1<<" and column "<<col+1<<endl;              
            }
        }
    }
}
void Borrow_from_other_lib(string name,string item,book & book_object,magazine & magazine_object){
    if(item=="book"){
        for(int i=0;i<110;i++){
            cout<<i<<" "<<book_object.book_rows_array[i].original_title<<endl;
            if(name==book_object.book_rows_array[i].original_title){
                string s=which_lib(i);
                if(s=="IIIT Delhi"){
                    cout<<"\n\nBook Successfully issued\n";
                    cout<<"\n\nBook is in "<<s<<endl;
                    cout<<"\n\nBook is issued on date and time at :"<<current_time()<<endl;
                    return;
                }
                else{
                    std::cout<<"\n\nBook is in "<<s<<endl;
                    std::cout<<"\n\nIt will take 7 days of delay \n";
                    return;
                }
            }
        }
    }
    else if(item=="magazine"){
        for(int i=0;i<110;i++){
            if(name==magazine_object.magazine_array[i].publication){
                string s=which_lib(i);
                if(s=="IIIT Delhi"){
                    cout<<"\n\nMagazine Successfully issued\n";
                    cout<<"\n\nMagazine is issued on date and time at :"<<current_time()<<endl;
                }
                else{
                    cout<<"\n\nIt will take 7 days of delay\n";
                }
            }
        }
    }


}
struct trackofrequest_journal{
 string publication;
 int count;
};
void Record_of_purchase(journal journal_object){
    int y=0;
    for(int i=0;i<110;i++){
        if(journal_object.count[i]!=0){
            cout<<"\n\nJournal "<<journal_object.journal_array[i]<<" is Subscribed "<<endl;
            y++;
        }
         if(y==3){
                return;
            }
    }
    cout<<"\n\nThere is no request for journal which you want subscription \n";
}

void student_display(journal & journal_object,magazine & magazine_object,book & book_object)
{

	system("cls");
	cout << "\n**************************************************************************\n";
	cout << "                         LIBRARY MANAGEMENT SYSTEM                          \n";
	cout << "                             STUDENT MENU PAGE                              \n";
	cout << "\n**************************************************************************\n\n";
	cout << "\t\t1. Search Book\n";
	cout << "\t\t2. Borrow journals\n";
    cout << "\t\t3. search Magazine\n";
	cout << "\t\t4. Borrow Book\n";
	cout << "\t\t5. Return Book\n";
    cout << "\t\t6. Borrow Magazine\n";
    cout << "\t\t7. Return Magazine\n";
    std::cout<<"\t\t8. Borrow from other libraray \n";
    std::cout<<"\t\t9. Find in other libraray \n";
    std::cout<<"\t\t10. Record for purchase of the new journals, books or magazines \n";
    std::cout << "\t\t11. Exit\n";
	cout << endl;
	cout << "Please Enter Your Above Choice : ";
	int chose;
    string name;
	cin >> chose;
	switch (chose)
	{
	case 1:
		 std::cout<<"\n\nEnter the original title of the book which you want to search for \n";
         std::cin.clear();
         std::cin.sync();
         std::getline(std::cin,name);
         search_book(name,book_object);
		break;
	case 2:
        cout<<"\n\nEnter the name of the journal which you want to borrowed\n ";
        cin.clear();
        cin.sync();
        getline(cin,name);
		Borrow_journals(name,journal_object);
		break;
	case 3:
		    std:: cout<<"\n\nEnter the name of the magazine which you want to search for \n";
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin,name);
            search_magazine(name,magazine_object);
		break;
	case 4:
        cout<<"\n\nEnter the original title  of the book you want to borrowed\n";
        cin.clear();
        cin.sync();
        getline(cin,name);
		Borrow_book(name,book_object);
		break;
    case 5:
        cout<<"\n\nEnter the Original title of the book you want to returned \n";
        cin.clear();
        cin.sync();    
        getline(cin,name);
		Return_book(name,book_object);
		break;    
    case 6:
        cout<<"\n\n Enter the publication name of the magazine you want to borrowed \n";
        cin.clear();
        cin.sync();
        getline(cin,name);
		Borrow_magazine(name,magazine_object);
		break;
	case 7:
        cout<<"\n\n Enter the publication name of the magazine you want to returned \n";
        cin.clear();
        cin.sync();
        getline(cin,name);
		Return_magazine(name,magazine_object);
		break;
    case 8:
        cout<<"\t\t1.Borrow Book from other library if it is not available in our college\n";
        cout<<"\t\t2.Borrow Magazine from other library if it is not available in our college\n";
        cout<<"\nEnter the choice from above\n";
        int c;
        cin>>c;
        if(c==1){
            cout<<"\n\nEnter the original title of the book you want to search for \n";
            string book_name;
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin,book_name);
            Borrow_from_other_lib(book_name,"book",book_object,magazine_object);
        }
        else if(c==2){
            cout<<"\n\nEnter the publication name of the magazinre you want to search for\n";
            string magazine_name;
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin,magazine_name);
            Borrow_from_other_lib(magazine_name,"magazine",book_object,magazine_object);
        }
        else{
            cout<<"\n\nError!! Invalid choice \n";
        }
        
        break;
    case 9:
        cout<<"\t\t1.Find Book from other library if it is not available in our college\n";
        cout<<"\t\t2.Find Magazine from other library if it is not available in our college\n";
        cout<<"\nEnter the choice from above\n";
        int t;
        cin>>t;
        if(t==1){
            cout<<"\n\nEnter the original title of the book you want to search for \n";
            string book_name;
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin,book_name);
            find_in_other_lib(book_name,"book",book_object,magazine_object);
        }
        else if(t==2){
            cout<<"\n\nEnter the publication name of the magazinre you want to search for\n";
            string magazine_name;
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin,magazine_name);
            find_in_other_lib(magazine_name,"magazine",book_object,magazine_object);
        }
        else{
            cout<<"\n\nError!! Invalid choice \n";
        }
        break;
    case 10:
            cout<<"\n\nEnter the number i.e how many journal you want to request\n";
            int m;
            cin>>m;
            cout<<"\n\nEnter the publication name of journal which you want to request for subscription \n";
            for(int i=0;i<m;i++){
                cin.clear();
                cin.sync();
                getline(cin,name);
                for(int j=0;j<110;j++){
                    if(name==journal_object.journal_array[j]){
                        journal_object.count[j]++;
                    }
                }
            }
            
            Record_of_purchase(journal_object);
            cout<<"\n\nThese are the respective journal which is subscribed based on the requests and budget institute have \n";
            break;    
    case 11:
		
        //system("clr");
        cout<<"\n\n EXIT\n";
        break;
	}
}

void Faculty_display(journal & journal_object,magazine & magazine_object,book & book_object){
    system("cls");
        std::cout << "\n**************************************************************************\n";
        std::cout << "                         LIBRARY MANAGEMENT SYSTEM                          \n";
        std::cout << "                             FACULTY MENU PAGE                              \n";
        std::cout << "\n**************************************************************************\n\n";
        std::cout << "\t\t1. Search Book\n";
        std::cout << "\t\t2. Borrow journals\n";
        std::cout << "\t\t3. search Magazine\n";
        std::cout << "\t\t4. Borrow Book\n";
        std:: cout << "\t\t5. Return Book\n";
        std::cout << "\t\t6. Borrow Magazine\n";
        std::cout << "\t\t7. Return Magazine\n";
        std::cout<<"\t\t8. Borrow from other libraray \n";
        std::cout<<"\t\t9. Find in other libraray \n";
        std::cout<<"\t\t10. Record for purchase of the new journals, books or magazines \n";
        std::cout << "\t\t11. Exit\n";
        std:: cout << endl;
        std::cout << "Please Enter Your Above Choice : ";
        int chose;
        string name;
        std::cin >> chose;
        switch (chose)
        {
        case 1:
            std::cout<<"\n\nEnter the original title of the book which you want to search for \n";
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin,name);
            search_book(name,book_object);
            break;
        case 2:
           std:: cout<<"\n\nEnter the name of the journal which you want to borrowed \n ";
           std:: cin.clear();
           std:: cin.sync();
            // std::cout<<"boorow 1"<<endl;
            std::getline(std::cin,name);
            // std::cout<<"boro2"<<endl;
            Borrow_journals(name,journal_object);
            // std::cout<<"boro3"<<endl;
            break;
        case 3:
            std:: cout<<"\n\nEnter the name of the magazine which you want to search for \n";
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin,name);
            search_magazine(name,magazine_object);
            break;
        case 4:
            std::cout<<"\n\nEnter the original title  of the book you want to borrowed\n";
           std:: cin.clear();
           std:: cin.sync();
           std:: getline(std::cin,name);
            Borrow_book(name,book_object);
            break;
        case 5:
            std::cout<<"\n\nEnter the Original title of the book you want to returned \n";
            std::cin.clear();
            std::cin.sync();            
            std::getline(std::cin,name);
            Return_book(name,book_object);
            break;    
        case 6:
        std::    cout<<"\n\n Enter the publication name of the magazine you want to borrowed \n";
        std::    cin.clear();
        std::    cin.sync();            
        std::    getline(std::cin,name);
            Borrow_magazine(name,magazine_object);
            break;
        case 7:
         std::   cout<<"\n\n Enter the publication name of the magazine you want to returned \n";
        std::cin.clear();
        std::cin.sync();
        std::getline(std::cin,name);
            Return_magazine(name,magazine_object);
            break;
       
        //void Borrow_from_other_lib(string name,string item,book & book_object,magazine & magazine_object)
        case 8:
            cout<<"\t\t1.Borrow Book from other library if it is not available in our college\n";
            cout<<"\t\t2.Borrow Magazine from other library if it is not available in our college\n";
            cout<<"\nEnter the choice from above\n";
            int u;
            cin>>u;
            if(u==1){
                cout<<"\n\nEnter the original title of the book you want to search for \n";
                string book_name;
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin,book_name);
                Borrow_from_other_lib(book_name,"book",book_object,magazine_object);
            }
            else if(u==2){
                cout<<"\n\nEnter the publication name of the magazinre you want to search for\n";
                string magazine_name;
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin,magazine_name);
                Borrow_from_other_lib(magazine_name,"magazine",book_object,magazine_object);
            }
            else{
                cout<<"\n\nError!! Invalid choice \n";
            }
            
            break;
        case 9:
            cout<<"\t\t1.Find Book from other library if it is not available in our college\n";
            cout<<"\t\t2.Find Magazine from other library if it is not available in our college\n";
            cout<<"\nEnter the choice from above\n";
            int t;
            cin>>t;
            if(t==1){
                cout<<"\n\nEnter the original title of the book you want to search for \n";
                string book_name;
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin,book_name);
                find_in_other_lib(book_name,"book",book_object,magazine_object);
            }
            else if(t==2){
                cout<<"\n\nEnter the publication name of the magazinre you want to search for\n";
                string magazine_name;
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin,magazine_name);
                find_in_other_lib(magazine_name,"magazine",book_object,magazine_object);
            }
            else{
                cout<<"\n\nError!! Invalid choice \n";
            }
            break;
        case 10:
            cout<<"\n\nEnter the number i.e how many journal you want to request\n";
            int m;
            cin>>m;
            cout<<"\n\nEnter the publication name of journal which you want to request for subscription \n";
            for(int i=0;i<m;i++){
                cin.clear();
                cin.sync();
                getline(cin,name);
                for(int j=0;j<110;j++){
                    if(name==journal_object.journal_array[j]){
                        journal_object.count[j]++;
                    }
                }
            }
            
            Record_of_purchase(journal_object);
            cout<<"\n\nThese are the respective journal which is subscribed based on the requests and budget institute have \n";
            break;
         case 11:
            //system("clr");
        std::    cout<<"\n\nEXIT\n";
            break;    
        } 

}

void Faculty_login(journal & journal_object,magazine & magazine_object,book & book_object){
    Faculty_display(journal_object,magazine_object,book_object);
}

void student_login(journal & journal_object,magazine & magazine_object,book & book_object){
    student_display(journal_object,magazine_object,book_object);
}
    
void firstpage(student* S, Faculty* F,int &p,int &q,journal & journal_object,magazine & magazine_object,book & book_object){
    std::	cout << "\n**************************************************************************\n";
    std::		cout << "                     WELCOME TO LIBRARY MANAGEMENT SYSTEM                   \n";
	std::	cout << "                                  MAIN MENU                                 \n";
		std::cout << "\n**************************************************************************\n\n";
        std::cout << "\t\t1. Faculty" << endl;
		std::cout << "\t\t2. Student" << endl;
		std::cout << "\t\t3. Exit" << endl;
		std::cout << "\nPlease Enter Your Above Choice : ";
        int n;
        std::cin>>n;
        if(n==1){
            system("cls");
           std:: cout << "\n**************************************************************************\n";
		std::	cout << "                         LIBRARY MANAGEMENT SYSTEM                          \n";
		std::	cout << "                                 FACULTY PAGE                                 \n";
		std::	cout << "\n**************************************************************************\n\n";
		std::	cout << "\t\t1. Faculty Login" << endl;
			std::cout << "\t\t2. Faculty Register" << endl;
			std::cout << "\t\t3. Back to Main Menu" << endl;
			std::cout << "\t\t4. Exit" << endl;
			std::cout << "\n Please Enter Your Above Choice : ";

			int c;
			std::cin >> c;
            if (c == 1)
			{
				//system("cls");
				std::cout << "\n**************************************************************************\n";
				std::cout << "                         LIBRARY MANAGEMENT SYSTEM                          \n";
				std::cout << "                             FACULTY LOGIN PAGE                               \n";
				std::cout << "\n**************************************************************************\n\n";
				string account, password ;
				std::cout << "\t\t Enter Your Username : ";
				std::cin >> account;
				std::cout << "\t\t Enter Your Password : ";
               std:: cin>>password;
				int r=check_faculty(account,password,F,q);
                if(r==1){
                    // std::cout<<"1"<<endl;
                    Faculty_login(journal_object,magazine_object,book_object);
                    // std::cout<<"2"<<endl;
                }
                else{
                    cout<<"\n\n ERROR!!INVALID USERNAME OR PASSWORD "<<endl;
                    cout<<"TRY AGAIN "<<endl;
                    firstpage(S,F,p,q,journal_object,magazine_object,book_object);
                }
                
			}
            else if(c==2){
               // system("cls");
                std::cout << "\n**************************************************************************\n";
				std::cout << "                         LIBRARY MANAGEMENT SYSTEM                          \n";
				std::cout << "                          FACULTY REGISTRATION PAGE                           \n";
				std::cout << "\n**************************************************************************\n\n";
                string account, password = "";
				std::cout << "\t\t Enter Your Username : ";
				std::cin >> account;
				std::cout << "\t\t Enter Your Password : ";
				std::cin>>password;
                int r=check_faculty_username(account,F);
                if(r==0){
                    cout<<"Registration successful"<<endl;
                    put_faculty_info(account,password,F,q);
                    system("cls");
                    firstpage(S,F,p,q,journal_object,magazine_object,book_object);
                }
                else{
                    cout<<"\n\n ERROR! Username already taken "<<endl;
                    cout<<"\n\n Try Again "<<endl;
                    firstpage(S,F,p,q,journal_object,magazine_object,book_object);
                }

            }
            else if(c==3){
                firstpage(S,F,p,q,journal_object,magazine_object,book_object);
            }
            else if(c==4){
                exit(0);
            }
            else{
                //system("cls");
                std::cout<<"\n\n Error!! Invalid choice , Please try again ";
                firstpage(S,F,p,q,journal_object,magazine_object,book_object);
            }
            
        }
        else if (n == 2)
		{
			//system("cls");
			std::cout << "\n**************************************************************************\n";
			std::cout << "                         LIBRARY MANAGEMENT SYSTEM                          \n";
			std::cout << "                                STUDENT PAGE                                \n";
			std::cout << "\n**************************************************************************\n\n";
			std::cout << "\t\t1. Student Login" << endl;
			std::cout << "\t\t2. Student Register" << endl;
			std::cout << "\t\t3. Back to Main Menu" << endl;
			std::cout << "\t\t4. Exit" << endl;
			std::cout << "\n Please Enter Your Above Choice : ";

			int c;
			std::cin >> c;
			if (c == 1)
			{
				system("cls");
				std::cout << "\n**************************************************************************\n";
				std::cout << "                         LIBRARY MANAGEMENT SYSTEM                          \n";
				std::cout << "                            STUDENT LOGIN PAGE                              \n";
				std::cout << "\n**************************************************************************\n\n";
				std::string account, password = "";
				std::cout << "\t\t Enter Your Username : ";
				std::cin >> account;
				std::cout << "\t\t Enter Your Password : ";
				std::cin>>password;
                int r=check_student(account,password,S,p);
                if(r==1){
                    student_login(journal_object,magazine_object,book_object);
                }
                else{
                   std:: cout<<"\n\n ERROR!! Invalid username or password "<<endl;
                    std::cout<<"\n\n Try Again "<<endl;
                    firstpage(S,F,p,q,journal_object,magazine_object,book_object);
                }
                
                
			}
			else if (c == 2)
			{
				system("cls");
			std::	cout << "\n**************************************************************************\n";
				std::cout << "                         LIBRARY MANAGEMENT SYSTEM                          \n";
				std::cout << "                         STUDENT REGISTRATION PAGE                           \n";
				std::cout << "\n**************************************************************************\n\n";
				string account, password = "";
				std::cout << "\t\t Enter Your Username : ";
				std::cin >> account;
				std::cout << "\t\t Enter Your Password : ";
                std::cin>>password;
                int r=check_student_username(account,S,p);
                if(r==0){
                    put_student_info(account,password,S,p);
                    std::cout<<"\n\n Student registration successful ";
                    system("cls");
                    firstpage(S,F,p,q,journal_object,magazine_object,book_object);
                }
                else{
                    // system("clr");
                    std::cout<<"\n\n Error!! Invalid Username or Password "<<endl;
                    std::cout<<"\n\nTry Again"<<endl;
                    firstpage(S,F,p,q,journal_object,magazine_object,book_object);
                }
               

			}
			else if (c == 3)
			{
				firstpage(S,F,p,q,journal_object,magazine_object,book_object);
			}
			else if (c == 4)
			{
				exit(0);
			}
			else
			{

				system("cls");
			std::	cout << "\n\n Error!!: Invalid Choice. Please Try Again...Press Enter to Continue : ";
				firstpage(S,F,p,q,journal_object,magazine_object,book_object);
			}
		}
        else if (n == 3)
		{
			exit(0);
		}
		else
		{
			system("cls");
			std::cout << "\n\n Error!!: Invalid Choice. Please Try Again...Press Enter to Continue : ";
			firstpage(S,F,p,q,journal_object,magazine_object,book_object);
		}
}

int main(){  
  student* S = new student[100];
  Faculty* F = new Faculty[100];
//   int k=0;
//   struct borrowed_item borrowed_item_record[100];
  journal journal_object("journals.csv");
  magazine magazine_object("magazine.csv");
  book book_object("book.csv");


  int p=0,q=0;

  firstpage(S,F,p,q,journal_object,magazine_object,book_object);

  return 0;
}