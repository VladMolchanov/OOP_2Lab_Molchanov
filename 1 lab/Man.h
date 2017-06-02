#include <iostream>
using namespace std;

class Man {
	string name;
	string surname;
	int age;
public:
	Man ();
	Man ( string , string , int );
	Man (Man &);
	void set ( string , string , int );
	void getName ();
	void getSurname ();
	void getAge ();
	void getAllData ();
	void recordData ();
	friend ostream &operator<<(ostream &, Man);
	friend istream &operator>>(istream &, Man &);
	~Man ();
	};
