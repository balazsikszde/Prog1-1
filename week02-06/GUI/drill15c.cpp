#include "std_lib_facilities.h"

struct Person{
	Person(){}
	Person(string first_name,string second_name, int age);
	string first_name(){return fn;}
	string second_name() {return sn;}
	int age() {return a;} 
private:
	string fn;
	string sn;
	int a;
};

Person::Person(string first_name,string second_name,  int age)
:fn{first_name},sn{second_name},a{age}
{
	if (age<0 || age>150) error("invalid age.");

	string name = first_name+second_name;
	for(char c:name)
	{
		switch(c){case ';':case ':':case '"':case '\'':case '[':case ']':case '*':case '&'
		:case '^':case '%':case '$':case '#':case '@':case '!':error("invalid name");}
	}
}

istream& operator>>(istream& is, Person& p)
{
	string first_name;
	string second_name;
	int age;
	is >> first_name >> second_name >> age;

	if(!is) error("input error...");

	p = Person(first_name,second_name,age);
	return is;
}

ostream& operator<<(ostream& os, Person& p)
{
	return os << p.first_name() << " " << p.second_name() << ", " << p.age();
}

int main()
{
	Person p1;
	//p1.name="Goofy";
	//p1.age=63;
	cout << "Goofy, 63\n";
	vector<Person> ppl;
	for (int i = 0; i < 2; ++i)
	{
		Person p;
		cout << "Person, age\n";
		cin >> p;
		ppl.push_back(p);
	}

	for (int i = 0; i < 2; ++i)
	{
		cout << ppl[i] << endl;
	}
	return 0;
}