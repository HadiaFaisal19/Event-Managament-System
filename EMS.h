#ifndef EVENT_MANAGEMENT_H            //check if defined or not before
#define EVENT_MANAGEMENT_H            //defining headerfile
#include <iostream>                   
#include <fstream>                   //header file for input and output
#include<iomanip>  
                 
using namespace std;                 
class Event{            //creating class of Event name
private:                //cannot be accessible outside class
int ID;             //int type variable to store user ID  
string P_name;          //string type variable to store person name 
string E_name;          //string type variable to store event name 
string date;            //string type variable to store date of event
string timings;         //string type variable to store timings 
string location;        //string type variable to store location of event

//constructor
public:            //accessible outside class
Event(){
	//initializing variables
    ID = 0;
    P_name = ".";
    E_name = ".";
    date = ".";
    timings = ".";
    location =".";
}
Event(int id,string en,string d, string t, string l){
	ID=id;
	E_name=en;
	date=d;
	timings=t;
	location=l;
}
void set_Event(int id,string en,string d, string t, string l){
	ID=id;
	E_name=en;
	date=d;
	timings=t;
	location=l;
}

//mutator functions
void set_ID(int ID){
this->ID=ID;                  //using THIS pointer to point the data members of class
}
void set_name(string P_name){
this->P_name=P_name;
}
void set_E_name(string E_name){
this->E_name=E_name;
}
void set_date(string date ){
this->date=date;
}
void set_timings(string timings){
this->timings=timings;
}
void set_location(string location){
this->location=timings;
}

//accessor functions
int get_ID()const{
return ID;
}
string get_name()const{
return P_name;
}
string get_E_name()const{
return E_name;
}
string get_date()const{
return date;
}
string get_timings()const{
return timings;
}
string get_location()const{
return location;
}

//function to get data
void Enter_record(Event *E){
	    fstream myfile;
	    myfile.open("EMS.txt", ios::app);                  //writing to file
	    if(myfile.is_open()){                             //check if file is opened 	
	myfile<<setw(8)<<get_ID();    	             //displaying id into the file 
    myfile<<setw(8)<<get_E_name();              //displaying event name into the file
    myfile<<setw(8)<<get_date();         //displaying booking date into the file
    myfile<<setw(8)<<get_timings();           //displaying timings into the file
    myfile<<setw(8)<<get_location();        //displaying location of event into the file
    myfile.close();
	    }
}

//function to view data
 void view_record(){
 	
	 fstream myfile;                                   //fstream variable
        
        myfile.open("EMS.txt", ios::in);                  //reading from file
        if (myfile.is_open()){                            //check if file is opened
        	string line;
        	while(getline(myfile, line)){                 //data from file is stored in variale line
        		cout<<line<<endl;                         //displaying data from file
			}
			myfile.close(); 	


}
}

void search_record(){
 	fstream file;
	string search, id, en, d, t, l;
cout<<"Enter the CNIC to search record:  ";
cin>>search;
file.open("EMS.txt",ios::in);
cout<<"Searching Data in the File..."<<endl;

while(!file.eof()){
	file>>id>>en>>d>>t>>l;
	if (search==id){
	cout<<"CNIC No: "<<id<<endl;
	cout<<"Event Name: "<<en<<" "<<endl;
	cout<<"Event date: "<<d<<endl;
	cout<<"Event time: "<<t;
	cout<<"Event location: "<<l;
	
	break;
	}	
}
file.close();
	  }


//update record
void update_record(){
fstream myfile,file2;
 	string update, id, en, d, t, l;
			 cout<<"\nEnter the CNIC to update record:  ";
			 cin>>update;
			 myfile.open("newEMS.txt",ios::out|ios::app);
			 file2.open("EMS.txt",ios::in);
			 if(!file2){
			 	cout<<"File opening error "<<endl;
			 	file2.close();
			 }
			 else{
			 
			 file2>>id>>en>>d>>t>>l;
			 while(!file2.eof()){
			 	if (update==id){
			 		cout<<"\nEnter new record: "<<endl;
	                cout<<"EVENT ID: ";
					cin>>id;
	                cout<<"EVENT NAME: ";
	                cin>>en;
	                cout<<"EVENT DATE: ";
					cin>>d;
	                cout<<"EVENT TIMINGS: ";
                	cin>>t;
	                cout<<"EVENT LOCATION: ";
					cin>>l;
										
	myfile<<setw(8)<<id;
	myfile<<setw(17)<<en;
	myfile<<setw(15)<<d;
	myfile<<setw(9)<<t;
	myfile<<setw(7)<<l;
}
	else{
	myfile<<setw(8)<<id;
	myfile<<setw(17)<<en;
	myfile<<setw(15)<<d;
	myfile<<setw(9)<<t;
	myfile<<setw(7)<<l;
			}
				 
			 file2>>id>>en>>d>>t>>l; 	    
			}}

			 myfile.close();
			 file2.close();
			 remove("EMS.txt");
			 
			 rename("newEMS.txt","EMS.txt");
			 cout<<"!!RECORD UPDATED SUCCESSFULLY!!";

}//function
};          //class ends
#endif // if defined EVENT_MANAGEMENT_H
