#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

template<typename T>
void my_print(T out)
{
	for(const auto p : out)
	{
		std::cout << p << "\n";
	}
}

template<typename T>
double my_sum(T in)
{
	double sum=0;
	for(int i=0; i < in.size(); ++i)
	{
		sum+=in[i];
	}
	return sum;
}

template<typename T>
double my_mean(T in)
{
	double sum=0;
	int i=0;
	for(;i < in.size(); ++i)
	{
		sum+=in[i];
	}
	return sum/i;
}

int main()
{

	//1
	std::ifstream ifs {"floating.txt"};
	std::vector<double> vd;
	double d;
	while(ifs >> d)
	{
		vd.push_back(d);
	}

	//2
	my_print(vd);

	//3
	std::vector<int> vi(vd.size());

	//4
	std::copy(vd.begin(),vd.end(),vi.begin());
	for(int i=0; i < vd.size(); ++i)
	{
		std::cout << vd[i] << "\t" <<vi[i] <<"\n";
	}

	//5
	std::cout<< "The sum of vd is: " << my_sum(vd) << "\n";

	//6
	std::cout<< "The difference between the 2 sums is: " << my_sum(vd)-my_sum(vi) << "\n";

	//7
	std::reverse(vd.begin(),vd.end());
	my_print(vd);

	//8
	std::cout << "The mean value of vd is: " << my_mean(vd) << "\n";

	//9
	std::vector<double> vd2;
	double mean = my_mean(vd);
	for(const auto& p : vd)
	{
		if(p < mean)
		{
			vd2.push_back(p);
		}
	}
	std::cout << "vd2: " << "\n";
	my_print(vd2);

	//10
	std::sort(vd.begin(),vd.end());
	std::cout << "After sorting: " << "\n";
	my_print(vd);

	return 0;
}