#ifndef Name_h
#define Name_h
#include <iostream>
#include <string>

using namespace std;

class Name{
	private:
		string name;
		string f_name;
		
	public:
	    Name();
		Name(string n, string fn);
		
		string get_name();
		
		string get_f_name();
		void set_Name(string n, string fn);	
		void display();
		
};
		Name::Name(){
			name="";
		   f_name="";
		   
		}
		
		Name::Name(string n, string fn){
			name=n;
			f_name=fn;
		}
		void Name::set_Name(string n, string fn){
			name=n;
			f_name=fn;
		}
		string Name::get_name(){
			return name;
		}
		string Name::get_f_name(){
			return f_name;
		}
		void Name::display(){
			cout<<"Participant's Name: "<<name<<" "<<f_name<<endl;
		}
#endif
