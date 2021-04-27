#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <list>

//1
struct Item{
	std::string name;
	int itemid;
	double value;
};

struct Compare_by_name{
	bool operator()(const Item& a, const Item& b) const 
		{ return a.name < b.name; } //std::string operator<
};

bool Compare_by_id(const Item& a,const Item& b)
	{ return a.itemid < b.itemid; }

bool Compare_by_value_desc(const Item& a,const Item& b)
	{ return a.value > b.value; }

template<typename T>
void my_print(T v)
{
	for(const auto& p : v)
	{
		std::cout<< p.name << ' ' << p.itemid << ' ' << p.value << std::endl;
	}
}

struct Name_Is{
	bool operator()(const Item& a)
	{ return a.name==name; }
	Name_Is(const std::string& n):name{n} {}
private:
	std::string name;
};
struct ID_Is{
	bool operator()(const Item& a)
	{ return a.itemid==id; }
	ID_Is(const int& x):id{x} {}
private:
	int id;
};

template<typename T>
void erase_by_name(T& v, std::string n)
{
	v.erase(std::find_if(v.begin(),v.end(),Name_Is(n)));
}
template<typename T>
void erase_by_id(T& v, int id)
{
	v.erase(std::find_if(v.begin(),v.end(),ID_Is(id)));
}

int main()
{
	std::ifstream ifs {"items.txt"};
	std::vector<Item> vi;

	std::string n;
	int iid;
	double val;

	while(ifs >> n >> iid >> val)
	{
		vi.push_back(Item{n,iid,val});
	}

	std::cout<< "Before sorting:\n";
	my_print(vi);

	//2
	std::cout<< "\nSorted by name:\n";
	std::sort(vi.begin(), vi.end(), Compare_by_name());
	my_print(vi);

	//3
	std::cout<< "\nSorted by iid:\n";
	std::sort(vi.begin(), vi.end(),Compare_by_id);
	my_print(vi);
	
	//4
	std::cout<< "\nSorted by value decreasing:\n";
	std::sort(vi.begin(),vi.end(),[] (const Item& a, const Item& b) { return a.value > b.value; });
	//std::sort(vi.begin(),vi.end(),Compare_by_value_desc);
	my_print(vi);

	//5
	std::cout<< "\nAfter adding and removing:\n";
	//vi.push_back(Item{"horse shoe",99,12.34});
	//vi.push_back(Item{"Canon S400",9988,499.95});
	vi.insert(vi.begin(),Item{"horse shoe",99,12.34});
	vi.insert(vi.begin()+2,Item{"Canon S400",9988,499.95});

	//6
	std::cout<< "\nAfter removing by names\n";
	erase_by_name(vi,"Towel");
	erase_by_name(vi,"Book");

	//7
	std::cout<< "\nList after removing by ids\n";
	erase_by_id(vi,2);
	erase_by_id(vi,987);

	my_print(vi);

	//LIST (8)
	std::ifstream ifs2 {"items.txt"};
	std::list<Item> li;

	std::string n2;
	int iid2;
	double val2;

	while(ifs2 >> n2 >> iid2 >> val2)
	{
		li.push_back(Item{n2,iid2,val2});
	}

	std::cout<< "\nList sorted by name:\n";
	li.sort(Compare_by_name());
	my_print(li);

	std::cout<< "\nSorted by iid:\n";
	li.sort(Compare_by_id);
	my_print(li);
	
	std::cout<< "\nList sorted by value decreasing:\n";
	li.sort([] (const Item& a, const Item& b) { return a.value > b.value; });
	//li.sort(vi.begin(),vi.end(),Compare_by_value_desc);
	my_print(li);

	std::cout<< "\nList after adding\n";
	//li.push_back(Item{"horse shoe",99,12.34});
	//li.push_back(Item{"Canon S400",9988,499.95});
	auto it = li.begin();
	++it;
	li.insert(li.begin(),Item{"horse shoe",99,12.34});
	li.insert(it,Item{"Canon S400",9988,499.95});
	my_print(li);

	std::cout<< "\nList after removing by names\n";
	erase_by_name(li,"Towel");
	erase_by_name(li,"Book");
	my_print(li);

	std::cout<< "\nList after removing by ids\n";
	erase_by_id(li,2);
	erase_by_id(li,987);
	my_print(li);

	return 0;
}