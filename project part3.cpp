#include <iostream>
#include <string>
#include "Participant.h"
#include "EMS.h" 
using namespace std;

int main(){
	int choice;
	Event E;                  //creating  object of Event
	Participant p;            //creating  object of Participant
cout<<"\n\n                ***************************!!! MENU !!!*************************************"<<endl;
    cout<<"\n                                          1. EVENT RECORDS"<<endl;
    cout<<"                                            2. REGISTER AS PARTICIPANT "<<endl;
    cout<<"                                            3. GET COMPLETE FILE OF EVENT PARTICIPANTS "<<endl;
    cout<<"                                            4-EXIT "<<endl;
    cout<<"                                                             Select an Option to Continue..."<<endl;
    cout<<"                                             CHOICE: ";
	cin>>choice;
	
	while (choice!=4){
	switch(choice){
	case 1:{
				int n, opt, Id;
                                                       	    //creating menu
	cout<<"\n\n                ********************!!! EVENT MANAGEMENT SYSTEM !!!*************************"<<endl;
	cout<<"\n\n                ***************************!!! MENU !!!*************************************"<<endl;
    cout<<"\n                                             1-BOOK EVENT"<<endl;
    cout<<"                                             2-VIEW CURRENT RECORDS"<<endl;
    cout<<"                                             3-SEARCH RECORDS"<<endl;
    cout<<"                                             4-UPDATE RECORDS"<<endl;
    cout<<"                                             5-EXIT"<<endl;
    cout<<"                                                        Select an Option to Continue..."<<endl;
    cout<<"                                             CHOICE: ";
	cin>>opt;
	system ("cls");            //function to clear screen
	Event E;                  //creating  object of Event
	
	while (opt!=5){           //loop will not exit until user enter 5
		switch (opt){	
		case 1:      //if opt ==1
		{	
		cout<<"\nENTER RECORD "<<endl;
 int ID;
 string E_name, date, timings, location;

cout<<"ENTER EVENT ID NO. : ";
cin>>ID;

cout<<"ENTER NAME OF THE EVENT: ";
cin>>E_name;

cout<<"ENTER THE DATE ON WHICH YOU WANT TO BOOK THE EVENT: ";
cin>>date;

cout<<"ENTER TIME OF THE EVENT: ";
cin>>timings;

cout<<"ENTER LOCATION OF THE EVENT:  ";
cin>>location;
	
	E.set_Event(ID, E_name, date, timings, location);
	E.Enter_record(&E);		
	    system("cls");              //function to clear screen
	    break;
}        
		case 2:           //if opt ==2
		{						
		    E.view_record();    
        break;
}    
		case 3:            //if opt ==3
		{	
		    E.search_record();      //function to display searched record
	    break;
}
		case 4:       //if opt ==4
		{
			E.update_record();                             	
		    break;
}
    default:
    	cout<<"invalid choice...! "<<endl;

}//switch 2
	cout<<"\n\n                ***************************!!! MENU !!!*************************************"<<endl;
    cout<<"\n                                             1-BOOK EVENT"<<endl;
    cout<<"                                             2-VIEW CURRENT RECORDS"<<endl;
    cout<<"                                             3-SEARCH RECORDS"<<endl;
    cout<<"                                             4-UPDATE RECORDS"<<endl;
    cout<<"                                             5-EXIT"<<endl;
    cout<<"                                                        Select an Option to Continue..."<<endl;
    cout<<"                                             CHOICE: ";
	cin>>opt;
}//while 2
}//case 1

    case 2:{
    	int opt;

cout<<"\n\n                ********************!!! EVENT MANAGEMENT SYSTEM !!!*************************"<<endl;
cout<<"\n\n                ***************************!!! MENU !!!*************************************"<<endl;
    cout<<"\n                                             1-REGISTER FOR EVENT"<<endl;
    cout<<"                                             2-VIEW CURRENT RECORDS"<<endl;
    cout<<"                                             3-SEARCH RECORDS"<<endl;
    cout<<"                                             4-UPDATE RECORDS"<<endl;
    cout<<"                                             5-EXIT "<<endl;
    cout<<"                                                        Select an Option to Continue..."<<endl;
    cout<<"                                             CHOICE: ";
    cin>>opt;   
    while(opt!=5){
    switch (opt){
   
    case 1:{  
string name, fname, city, e_time, e_date;
char e_name;
int Cnic, Contact, h,st,fee;
cout<<"Enter Your 1st Name: ";
cin>>name;
cout<<"Enter Your last Name: ";
cin>>fname;
cout<<"Enter CNIC No: ";
cin>>Cnic;
cout<<"Enter Contact No: ";
cin>>Contact;
cout<<"Enter Address: ";
cout<<"H#: ";cin>>h;
cout<<"St#: ";cin>>st;
cout<<"City: ";cin>>city;
cout<<"Choose one: "<<endl;
cout<<"C. CULTURAL NIGHT "<<endl;
cout<<"S. SPORTS FESTIVAL "<<endl;
cin>>e_name;
cout<<"Enter Time of that Event: ";
cin>>e_time;
cout<<"Enter Date of that Event: ";
cin>>e_date;
cout<<"Enter Deposited Fee for the Event: ";
cin>>fee;

p.set_Participant(name,fname,Cnic,Contact, h, st, city,e_name,e_time,e_date,fee);
p.store_data(&p);
p.view_t_data(&p);
break;
}
case 2:{
p.view_data();
break;
}
case 3:{
p.search_data();
break;
}
case 4:{
p.update_data();
break;
}
default:
cout<<"option not available ";
}
	cout<<"\n\n                ********************!!! EVENT MANAGEMENT SYSTEM !!!*************************"<<endl;
	cout<<"\n\n                ***************************!!! MENU !!!*************************************"<<endl;
    cout<<"\n                                             1-BOOK EVENT"<<endl;
    cout<<"                                             2-VIEW CURRENT RECORDS"<<endl;
    cout<<"                                             3-SEARCH RECORDS"<<endl;
    cout<<"                                             4-UPDATE RECORDS"<<endl;
    cout<<"                                             5-EXIT"<<endl;
    cout<<"                                                        Select an Option to Continue..."<<endl;
    cout<<"                                             CHOICE: ";
	cin>>opt;
}

	break; 
	}//case 2
	
	case 3:{
		p.view_t_data();
	break;
	}
    default:
    	cout<<"INVALID CHOICE! "<<endl;
    }//switch main
cout<<"\n\n                ***************************!!! MENU !!!*************************************"<<endl;
    cout<<"\n                                          1. EVENT RECORDS"<<endl;
    cout<<"                                            2. REGISTER AS PARTICIPANT "<<endl;
    cout<<"                                            3. GET COMPLETE FILE OF EVENT PARTICIPANTS "<<endl;
    cout<<"                                            4-EXIT "<<endl;
    cout<<"                                                             Select an Option to Continue..."<<endl;
    cout<<"                                             CHOICE: ";
	cin>>choice;
}//while main

return 0;
}
