#include <iostream>
#include <string>
#include <vector>
using namespace std;

void test() {
	//字符串的遍历
	string str("abcdefgh");

	string::iterator it = str.begin();
	while (it != str.end()) {
		cout << *it << " ";
		//*it = '1';
		++it;
	}
	cout << endl;

	string::reverse_iterator rit = str.rbegin();
	while (rit != str.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	string::const_iterator cit = str.cbegin();
	while (cit != str.cend()) {
		cout << *cit << " ";
		++cit;
	}
	cout << endl;

	string::const_reverse_iterator crit = str.crbegin();
	while (crit != str.crend()) {
		cout << *crit << " ";
		++crit;
	}
	cout << endl;
	for (int i = 0; i < str.size(); ++i) {
		cout << str[i] << " ";
	}
	cout << endl;

	for (auto& ch : str) {
		cout << ch << " ";
	}
	cout << endl;
}
class Date {
public:
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cout, const Date& d);
	Date(int year = 2020, int month = 3,int day = 0)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	//拷贝构造
	Date(const Date& d)
		:_year(d._year)
		,_month(d._month)
		,_day(d._day)
	{}
	~Date() {

	}
	void Display();
private:
	int _year;
	int _month;
	int _day;
	static int cnt;
};
//静态变量初始化
int Date::cnt = 0;
void Date::Display() {
	cout << _year << "-" << _month << "-" << _day << endl;
}
ostream& operator<<(ostream& _cout, const Date& d) {
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}
istream& operator>>(istream& _cin, const Date& d) {
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}
void test2() {
	Date d(2020,6,4);
	d.Display();
	cout << d;

}
template <class T>
void swap( T& left,  T& right) {
	T tmp = left;
	left = right;
	right = tmp;
}
void test3() {
	int a = 0, b = 5;
	char c = 'x', d = 'y';
	//swap(a, b);
	//swap(a, c);//不是同一类型
	swap<int>(a, c);
	//swap(c, d);
	cout << a << " " << c << endl;
	//cout << c << " " << d << endl;
}
template <class T1,class T2>
void swap( T1& left,  T2& right) {
	T1 tmp = left;
	left = right;
	right = tmp;
}
void test4() {
	int a = 97, b = 2;
	char c = 's', d = 'g';
	swap(a, c);
	cout << a <<" "<< c << endl;
}
int main() {
	test3();
	return 0;
}