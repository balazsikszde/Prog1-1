#include <iostream>

class B1 {
public:
	void f() const { std::cout << "B1::f()\n"; }
	virtual void vf() const { std::cout << "B1::vf()\n"; }
};

struct D1 : B1 {

	void vf() const override { std::cout << "D1::vf()\n"; };
};

int main()
{
	B1 B1;

	B1.f();
	B1.vf();
 
 	D1 D1;

 	D1.f();
 	D1.vf();

 	B1& bref {D1};

 	bref.f();
 	bref.vf();



	return 0;
}