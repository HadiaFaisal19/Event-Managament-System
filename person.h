#ifndef Person_H
#define Person_H
#include <iostream>
#include <string>
#include "address.h"
#include "name.h"

using namespace std;

class Person{
  private:
  int CNIC;
  int contact;
  Name N;
  Address A;
 
  public:
  Person();
  Person(string , string , int ,int ,int  ,int ,string );
  void set_Person(string , string , int ,int ,int ,int ,string );
  int get_CNIC(){
  	return CNIC;
  }
   int get_contact(){
  	return contact;
  }
  	int get_A_House_no(){
		return A.get_House_no();
}
	int get_A_Street_no(){
			return A.get_Street_no();
		}
		string get_A_city(){
			return A.get_city();
		}
	  	string get_N_name(){
			return N.get_name();
		}
		string get_N_f_name(){
			return N.get_f_name();
		}
  void write_person();
};
    Person::Person(){
	}
    Person::Person(string n, string f_n, int cnic ,int con ,int hno ,int sno ,string c){
    CNIC =cnic;
    contact=con;
    N.set_Name(n,f_n);
    A.set_address(hno, sno, c);	
	}
	
    void Person::set_Person(string n, string f_n, int cnic ,int con ,int hno ,int sno ,string c){
    CNIC =cnic;
    contact=con;
    N.set_Name(n,f_n);
    A.set_address(hno, sno, c);
}

void Person::write_person(){
	  cout<<"!!!  PERSONAL DETAILS  !!! "<<endl;
	  N.display();
	  cout<<"CNIC: "<<CNIC<<endl;
	  cout<<"Contact No.: "<<contact<<endl;
	  A.get_address();
  }
 
#endif
 
  
     
  

