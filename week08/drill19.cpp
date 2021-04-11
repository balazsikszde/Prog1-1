#include "../std_lib_facilities.h"

template<class T> struct S {
	T val;
};

S::S():T(){};

int main()
{
	S<int> vi {0,1,2,3,4};
	S<char> vc {'a','b','c','d'};
	S<double> vd {0.1,0.2,0.3,0.4};
	S<string> vs {"alma", "banan","cica","derelye"};
	S<<vector>int> vvi {{0,1,2,3},{4,5,6,7},{8,9,10,11}};

	return 0;
}