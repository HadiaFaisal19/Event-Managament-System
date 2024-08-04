#ifndef ADDRESS_H            //checsk if defined or not before
#define ADDRESS_H 
#include <iostream>                   //header file for input and output
#include <fstream>                    //header file for file handling
#include <string>                     //header file for string
using namespace std;

class Address{
	int House_no;
	int Street_no;
	string city;
	
	public:
		Address();
		Address( int , int , string );
		void set_address( int , int , string );
		void get_address();
		
		int get_House_no();
		
		int get_Street_no();
		
		string get_city();
		
};
    Address::Address(){
    	House_no=0;
    	Street_no=0;
    	city=" ";
	}
    Address::Address(int h, int s, string c){
    	House_no =h;
    	Street_no=s;
    	city=c;
	}
	void Address::set_address(int h, int s, string c){
    	House_no =h;
    	Street_no=s;
    	city=c;
	}
	int Address::get_House_no(){
			return House_no ;
		}
	int Address::get_Street_no(){
		    return Street_no;
	}	
	string Address::get_city(){
		    return city;
	}
		
	void Address::get_address(){
	cout<<"Address:  H#: "<<House_no<<", St#: "<<Street_no<<", City: "<<city<<". "<<endl;
	}
	
	#endif // if defined ADDRESS_H 
