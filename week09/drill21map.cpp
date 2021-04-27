#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

template <typename T>
void printmap(T map){
	for(const auto& p : map)
	{
		std::cout<< p.first << ' ' << p.second << std::endl;
	}
}
//5
void input_msi(std::map<std::string,int>& map)
{
	std::string input1;
	int input2;
	std::cout << "Please input name,value pairs (input q twice to stop):\n";
	while(std::cin >> input1 >> input2 && input1!="q")
	{
		map[input1]=input2;
	}
}

int main()
{
	//1
	std::ifstream ifs {"map.txt"};
	//2
	std::string n;
	int val;
	std::map<std::string,int> msi;
	while(ifs >> n >> val)
	{
		msi[n]=val;
	}
	//3
	printmap(msi);
	//4
	msi.erase(msi.begin(),msi.end());
	//6
	input_msi(msi);
	//7
	printmap(msi);
	//8
	int sum=0;
	for(const auto& p : msi)
	{
		sum+=p.second;
	}
	std::cout << "The sum of the values is: " << sum << std::endl;
	//9
	std::map<int,std::string> mis;
	//10
	for(const auto& p : msi)
	{
		mis[p.second]=p.first;
	}
	//11
	printmap(mis);
	return 0;
}