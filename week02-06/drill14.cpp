#include <iostream>
#include "../std_lib_facilities.h"

class B1 {
public:
 	void f() { cout << "B::f()\n"; }
	virtual void vf() { cout << "B::vf()\n"; }
	virtual void pvf() { cout << "B::pvf()\n"; }
	//virtual void pvf() = 0;
};

class D1: public B1 {
public:
	void vf() override { cout << "D1::f()\n"; }
	//void f() { cout << "D1::f\n"; }
};

class D2 : public D1 {
public:
	void pvf() override { cout << "D2::pvf()\n"; }
};

class B2{
public:
	virtual void pvf() = 0;
};

class D21 : public B2{
public:
	string s = "string";
	virtual void pvf() override { cout << s << endl; };
};

class D22 : public B2{
public:
	int x = 20;
	virtual void pvf() override { cout << x << endl; };
};

void f(B2& b)
{
	b.pvf();
}

int main()
{
    B1 b;
	b.f();
	b.vf();
	//b.pvf();

	D1 d;
	d.f();
	d.vf();
	//d.pvf();

	D2 dd;
	dd.f();
	dd.vf();
	dd.pvf();

	B1& bref {d};
	bref.vf();
	bref.f();

	D21 dd21;
	D22 dd22;

	f(dd21);
	f(dd22);

	return 0;
}