#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
	
	int n, m, x;
	cin >> n >> m;
	vi 	A, B, taxi;
	vii C(n+m, make_pair(100000000,-1));
	vi D(m);
	for(int i=0;i<n+m;i++){
		cin >> x; A.push_back(x);

	}
	for(int i=0;i<n+m;i++){
		cin >> x; B.push_back(x);
		if(x == 1){
			taxi.push_back(i);
		}
	}

	vi::iterator it;
    int iter = 0;
	for(it = taxi.begin(); it != taxi.end(); it++){
		// go left
		int pos = (*it);
		int dist = 1;
		for(int i=pos-1; i>=0;i--){
			if(B[i] == 0){
				if(C[i].first > dist){
					C[i].first = dist;
					dist++;
					D[iter]++;
                    if(C[i].second != -1){   
						D[C[i].second]--;
                    }
                    C[i].second = iter;
				}else{
					break; // stop
				}
			}else{
				break;
			}
		}
		// go right
		dist = 1;
		for(int i=pos+1; i<n+m;i++){
			if(B[i] == 0){
				if(C[i].first > dist){
					C[i].first = dist;
					dist++;
					D[iter]++;
                    if(C[i].second != -1){   
						D[C[i].second]--;
                    }
                    C[i].second = iter;
				}else{
					break; // stop
				}
			}else{
				break;
			}
		}
        iter++;
	}
	for(int i=0;i<m;i++){
		if(i) cout << " " << D[i];
		else cout << D[i];
	}
	cout << endl;

}