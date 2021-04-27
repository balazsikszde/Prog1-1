#include <vector>
#include <iostream>

template<typename Iterator, typename Predicate>
Iterator find(Iterator first, Iterator last, Predicate pred)
{
	while(first != last && !pred(*first)) ++first;

	return first;
}

class Larger_than{
	int v;
public:
	Larger_than(int vv): v{vv} {}
	bool operator()(int x) const { return x < v;}
}

bool odd(int x){ return x%2; }
bool larger_than_42(int x){ Larger_than(42)}


int main()
{
	std::vector<int> v;
	int a;

	while(std::cin >> a) v.push_back(a);

	auto p = find(v.begin(), v.end(), [&](int e) { return e > x;});

	if (p != v.end())
		std::cout << "Megtalaltuk\n";
	else
		std::cout << "Nem talaltuk meg\n";

	return 0;
}
