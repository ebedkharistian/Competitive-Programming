#include <iostream>
#include <string> 

using namespace std; 

template <typename T>
inline T const& Max(T const& a, T const& b){
	return a > b ? a : b; 
}

int main(){
	int i = 39; 
	int j = 20; 
	cout << "Max(i, j) = " << Max(i, j) << endl;

	double a = 48.67;
	double b = 50.32;
	cout << "Max(a, b) = " << Max(a, b) << endl;

	string s1 = "Hello";
	string s2 = "World";
	cout << "Max(s1, s2) = " << Max(s1, s2) << endl;

	return 0;
}