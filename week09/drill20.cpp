#include <vector>
#include <iostream>
#include <list>
#include <array>
#include <algorithm>


template<typename T>
void increase(T& val, int x)
{
	for(auto& p:val)
	{
		p+=x;
	}
}

template<typename Iter1, typename Iter2> 
Iter2 mycopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while(f1!=e1){
		*f2 = *f1;
		++f2;
		++f1;
	}
	return f2;
}

template<typename Type>
void where_is(Type con, int x)
{
	auto p = std::find(con.begin(),con.end(),x);
	if(p!=con.end())
	{
		std::cout<<"it's in the  " << std::distance(con.begin(),p)+1
			<< ". position\n";
	}
	else std::cout<< "it doesn't contain it\n";
}

int main()
{
	std::array<int,10> a {0,1,2,3,4,5,6,7,8,9};
	std::vector<int> v {0,1,2,3,4,5,6,7,8,9};
	std::list<int> l {0,1,2,3,4,5,6,7,8,9};

	std::array<int,10> a2 = a;
	std::vector<int> v2 = v;
	std::list<int> l2 = l;

	increase(a2,2);
	increase(v2,3);
	increase(l2,5);

	mycopy(a2.begin(),a2.end(),v2.begin());
	mycopy(l2.begin(),l2.end(),a2.begin());

	where_is(v2,3);
	where_is(l2,27);
	
	return 0;
}