#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef long long ll;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int lcm(int a, int b) { return a * (b/gcd(a,b)) ; }

int main(){
	int T;
	cin >> T;
	while(T--){
		ll G, L;
		cin >> G >> L; 
		if(L % G == 0){
			cout << G << L << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
	
	return 0;
}