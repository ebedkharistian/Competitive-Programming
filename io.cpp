#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;
int main(){
	int a;
	string s;

	cin >> a;
	cin.ignore();
	getline(cin, s); 

	cout << a << endl; 
	cout << s << endl;
	return 0;
}