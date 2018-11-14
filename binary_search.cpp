#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main(){
	vi data = {1, 3, 5, 8, 10};
	if( binary_search(data.begin(), data.end(), 5) ){
		cout << "Found" << endl;
	}else{
		cout << "Not Found" << endl;
	}
	

}