#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include "Person.h"
#include "EMS.h"

using namespace std;

class Participant:public Person, public Event{
      char event_name;
      string e_time;
      string e_date;
      int e_fee;
      
      public:
      Participant();
      Participant(string , string , int , int , int , int , string , char , string , string , int );
      void set_Participant(string , string , int , int , int , int , string , char , string , string , int );
      void set_Participant2(int id,string en,string d, string t, string l,int );
      
	  char get_event_name();
	  string get_e_time();
	  string get_e_date();
	  int get_e_fee();
	  
      void store_data(Participant *p);
      void view_data();
      void view_t_data();
      void search_data();
      void update_data();
      void view_t_data(Participant *p);

  };
  
      Participant::Participant(){
	   }
	  Participant::Participant(string p_n, string f_n, int cnic, int co, int hno, int sno, string c, char e_n, string e_t, string e_d, int e_f) {
	  	 set_Person(p_n, f_n, cnic , co , hno , sno , c);
		   
	  	 event_name=e_n;
         e_time=e_t;
         e_date=e_d;
         e_fee=e_f;
	   }
	   
	    void Participant::set_Participant(string p_n, string f_n, int cnic, int co, int hno, int sno, string c, char e_n, string e_t, string e_d, int e_f) {
	     set_Person( p_n, f_n, cnic , co , hno , sno , c);
	  	 event_name=e_n;
         e_time=e_t;
         e_date=e_d;
         e_fee=e_f;
	    }
	    
	    char Participant::get_event_name(){
      	return event_name;
	    }
	    string Participant::get_e_time(){
      	return e_time;
	    }
	    string Participant::get_e_date(){
      	return e_date;
	    }
	    int Participant::get_e_fee(){
      	return e_fee;
	    }

	void Participant::store_data(Participant *p){
    fstream myfile;

   myfile.open("Myfile.txt", ios::app); 
	 //writing to file
	if(myfile.is_open()){                       //check if file is opened 
	myfile<<setw(8)<<p->get_N_name();
	myfile<<setw(2)<<p->get_N_f_name();
	myfile<<setw(17)<<p->get_CNIC();
	myfile<<setw(15)<<p->get_contact();
	myfile<<setw(9)<<p->get_A_House_no();
	myfile<<setw(7)<<p->get_A_Street_no();
    myfile<<setw(7)<<p->get_A_city();
	myfile<<setw(16)<<p->get_event_name();
	myfile<<setw(16)<<p->get_e_time();
	myfile<<setw(16)<<p->get_e_date();
	myfile<<setw(16)<<p->get_e_fee()<<endl;	
}

else {
	cout<<"Partcipant file not opened"<<endl;
}
myfile.close();
}

  void Participant::view_data(){
    	ifstream fin;
    	fin.open("Myfile.txt",ios::in);
    	 if (fin.is_open()){                            //check if file is opened
        	string line;
        	cout<<"\n\n                                              |       ADDRESS         |"<<endl;
        	cout<<"|     NAME     |     CNIC NO     |  CONTACT NO  | H# |  St# |   CITY    |    EVENT NAME   |   EVENT TIME  |  EVENT DATE  |  EVENT FEE  | "<<endl;
        	while(getline(fin, line)){                 //data from file is stored in variale line
        		cout<<line<<endl;                         //displaying data from file
			}}
		else{
			cout<<"file is not opened"<<endl;
		}
			fin.close(); 
 }
 
 void Participant::search_data(){
 	fstream file;
	string search,p_n,f_n,cnic,co,hno,sno,c,e_n,e_t,e_d, e_f ;
cout<<"Enter the CNIC to search record:  ";
cin>>search;
file.open("Myfile.txt",ios::in);
cout<<"Searching Data in the File..."<<endl;

while(!file.eof()){
	file>>p_n>>f_n>>cnic>>co>>hno>>sno>>c>>e_n>>e_t>>e_d>>e_f;
	if (search==cnic){
	cout<<"Your Name: "<<p_n<<" "<<f_n<<endl;
	cout<<"CNIC No: "<<cnic<<endl;
	cout<<"Contact No: "<<co<<endl;
	cout<<"H#: "<<hno;
	cout<<", St#: "<<sno;
	cout<<", City: "<<c<<endl;
	cout<<"The name of Event you Registered in: "<<e_n<<endl;
	cout<<"The Time of that Event: "<<e_t<<endl;
	cout<<"The Date of that Event: "<<e_d<<endl;
	cout<<"The Deposited Fee for the Event: "<<e_f<<endl;
	break;
	}	
}
file.close();
	  }
	   void Participant::update_data(){
	   	fstream myfile,file2;
 	string update,p_n, f_n,cnic, co,hno, sno,c,e_n,e_t,e_d,e_f ;
			 cout<<"\nEnter the CNIC to update record:  ";
			 cin>>update;
			 myfile.open("newfile.txt",ios::out|ios::app);
			 file2.open("Myfile.txt",ios::in);
			 if(!file2){
			 	cout<<"File opening error "<<endl;
			 	file2.close();
			 }
			 else{
			 
			 file2>>p_n>>f_n>>cnic>>co>>hno>>sno>>c>>e_n>>e_t>>e_d>>e_f;
			 while(!file2.eof()){
			 	if (update==cnic){
			 		cout<<"\nEnter new record: "<<endl;
	                cout<<"Enter 1st Name: ";
	                cin>>p_n;
	                cout<<"Enter last name: ";
	                cin>>f_n;
	                cout<<"CNIC No: ";
					cin>>cnic;
	                cout<<"Contact No: ";
	                cin>>co;
	                cout<<"H#: ";
					cin>>hno;
	                cout<<"St#: ";
                	cin>>sno;
	                cout<<"City: ";
					cin>>c;
	                cout<<"The name of Event you Registered in: ";
					cin>>e_n;
	                cout<<"The Time of that Event: ";
					cin>>e_t;
	                cout<<"The Date of that Event: ";
					cin>>e_d;
	                cout<<"The Deposited Fee for the Event: ";
					cin>>e_f;
									
	myfile<<setw(8)<<p_n;
	myfile<<setw(2)<<f_n;
	myfile<<setw(17)<<cnic;
	myfile<<setw(15)<<co;
	myfile<<setw(9)<<hno;
	myfile<<setw(7)<<sno;
    myfile<<setw(7)<<c;
	myfile<<setw(16)<<e_n;
	myfile<<setw(16)<<e_t;
	myfile<<setw(16)<<e_d;
	myfile<<setw(16)<<e_f<<endl;
	}
	else{
	myfile<<setw(8)<<p_n;
	myfile<<setw(2)<<f_n;
	myfile<<setw(17)<<cnic;
	myfile<<setw(15)<<co;
	myfile<<setw(9)<<hno;
	myfile<<setw(7)<<sno;
    myfile<<setw(7)<<c;
	myfile<<setw(16)<<e_n;
	myfile<<setw(16)<<e_t;
	myfile<<setw(16)<<e_d;
	myfile<<setw(16)<<e_f<<endl;
			}	 
			 file2>>p_n>>f_n>>cnic>>co>>hno>>sno>>c>>e_n>>e_t>>e_d>>e_f;
		    }}
			 myfile.close();
			 file2.close();
			 remove("Myfile.txt");
			 rename("newfile.txt","Myfile.txt");
			 cout<<"!!RECORD UPDATED SUCCESSFULLY!!";		 
	   }
	   void Participant::view_t_data(Participant *p){
	   	fstream myfile, sports, c_n;
	   		string p_n,f_n,cnic,co,hno,sno,c,e_n,e_t,e_d, e_f ;
	   		 myfile.open("Myfile.txt",ios::out|ios::app);
	   		sports.open("Sports.txt",ios::out|ios::app);
	   		 c_n.open("CulturalEvent.txt",ios::out|ios::app);
	   		 //cout<<"check 2"<<endl;
	   		 if(myfile.is_open()){		
			while (!myfile.eof())	{
				myfile>>p_n>>f_n>>cnic>>co>>hno>>sno>>c>>e_n>>e_t>>e_d>>e_f;
			
				if (e_n=="S"||"s")	{
					sports<<p->get_N_name()<<setw(2)<<p->get_N_f_name()<<endl;
				}
			else if(e_n=="C"||"c")
			{
					c_n<<p->get_N_name()<<setw(2)<<p->get_N_f_name()<<endl;
			}}	
			myfile.close();
	    sports.close();
		c_n.close();
	   }
	   else {
	   	cout<<"File opening error"<<endl;
	   }
}
				
				
				
	
	
	
	   
	   
	   
/*	void Participant::show_data(Participant *p){
	fstream myfile, Pfile, Efile;
		
	myfile.open("cfile.txt", ios::app);  
	Efile.open("EMS.txt",ios::app) ; 
	Pfile.open("Myfile.txt",ios::app) ; 
	string
	if(Pfile.is_open()) {
		
	}
	           
	if(myfile.is_open()){                       //check if file is opened 
	myfile<<setw(8)<<p->get_N_name();
	myfile<<setw(2)<<p->get_N_f_name();
	myfile<<setw(17)<<p->get_CNIC();

	myfile<<setw(16)<<p->get_event_name();

	myfile<<setw(16)<<p->get_ID()<<endl;

}
else {
	cout<<"File not opened"<<endl;
}
	myfile.close();
}

  void Participant::view_t_data(){
    	ifstream fin;
    	fin.open("cfile.txt",ios::in);
    	 if (fin.is_open()){                            //check if file is opened
        	string line;
        	cout<<"\n\n                                              |       ADDRESS         |"<<endl;
        	cout<<"|     NAME     |     CNIC NO     |    EVENT NAME   |   "<<endl;
        	while(getline(fin, line)){                 //data from file is stored in variale line
        		cout<<line<<endl;                         //displaying data from file
			}}
		else{
			cout<<"file is not opened"<<endl;
		}
			fin.close(); 
 }
*/	   
//#endif
