#include "../std_lib_facilities.h"

template<typename T> struct S {
	explicit S(T vv = 0) : val{vv} {};
	S& operator=(const T&);
	T& get();
	const T& get() const;
	void set(T new_val) { val=new_val; };
private:
	T val;
	T new_val;
};

template<typename T> T& S<T>::get()
{
	return val;
}

template<typename T> const T& S<T>::get() const
{
	return val;
}

template<typename T> void read_val(T& v)
{
	cin >> v;
}

template<typename T> S<T>& S<T>::operator=(const T& new_val)
{
	val = new_val;
	return *this;
}

template<typename T> ostream& operator<<(ostream& os, vector<T>& v)
{
    os << "{";
    for(int i = 0; i < v.size(); ++i){
        os << v[i] << (i < v.size() -1 ? ", " : " ");
    }
    os << "}\n";

    return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if(ch != '{'){
        is.unget();
        return is;
    }

    for(T val; is >> val;){
        v.push_back(val);
        is >> ch;
        if ( ch != ',') break;
    }

    return is;
}

int main()
{
	S<int> iv {20};
	S<char> cv {'B'};
	S<double> fv {3.14};
	S<string> sv {"cat"};
	S<vector<int>> vv {vector<int>{1,2,3}};

	cout<< iv.get() << endl;
	cout<< cv.get() << endl;
	cout<< fv.get() << endl;
	cout<< sv.get() << endl;
	for (auto& a : vv.get())
        cout << a << ' ';
    cout << '\n';

    
    iv.set(20);
    cout << iv.get() << endl;

    iv = 25;
    cout << iv.get() << endl;

    cout << "int: ";
    int ii;
    read_val(ii);
    S<int> si2 {ii};
    cout << "char: ";
    char cc;
    read_val(cc);
    S<char> sc2 {cc};
    cout << "double: ";
    double dd;
    read_val(dd);
    S<double> sd2 {dd};
    cout << "tring: ";
    string ss;
    read_val(ss);
    S<string> s2 {ss};
    cout << "S<int> read: " << si2.get() << '\n';
    cout << "S<char> read: " << sc2.get() << '\n';
    cout << "S<double> read: " << sd2.get() << '\n';
    cout << "S<string> read: " << s2.get() << '\n';
    

    cout << "Vector<int>: (format: { val1, val2, val3 }) ";
    vector<int> v2;
    read_val(v2);
    S<vector<int>> v3 {v2};

    cout << "S<vector<int>> read: " << v3.get();
	return 0;
}