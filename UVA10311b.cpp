#include <bitset>
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

ll _sieve_size;
bitset<100000050> bs;
vi primes;

const int MAX = 100000000;  // 10^8
const int LMT =     10000;  // sqrt(MAX)
 
int _c[(MAX>>6)+1];
 
#define IsComp(n)  (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
 
void sieve() {
    for (int i = 3; i <= LMT; i += 2)
        if (!IsComp(i))
            for (int j = i*i; j <= MAX; j += i+i)
                SetComp(j);
 
    primes.push_back(2);
    for (int i=3; i <= MAX; i += 2)
        if (!IsComp(i))
            primes.push_back(i);
}
 
bool isPrime(int n) {
    if (n < 2 || n % 2 == 0) return false;
    return ! IsComp(n);
}

int main(){
	sieve();
	int N;
	while(cin >> N){
        if(N % 2 == 1){
			int x = N - 2;
			if( isPrime(x) && x != 2){
				if(x > 2){
					printf("%d is the sum of %d and %d.\n", N, 2, x);	
				}else{
					printf("%d is the sum of %d and %d.\n", N, x, 2);	
				}
			}else{
				printf("%d is not the sum of two primes!\n", N);	
			}
		}else{
			ii match = make_pair(-1, -100000000); 
			vi::iterator it; 
			for(it = lower_bound(primes.begin(), primes.end(), N/2); it != --primes.begin(); it--){
				int M = (*it);
                if(M > N) break;
				ii tmp;
				if( isPrime(N - M) ){
					tmp = make_pair(M, N-M);
                    if(tmp.second == tmp.first) continue;
					if( abs(match.second - match.first) > abs(tmp.second - tmp.first) ){
						match = tmp;
						break;
					}
				}
			}
			if(match.first != -1){
				if(match.first < match.second)
					printf("%d is the sum of %d and %d.\n", N, match.first, match.second);
				else
					printf("%d is the sum of %d and %d.\n", N, match.second, match.first);
			}else{
				printf("%d is not the sum of two primes!\n", N);	
			}
		}

	}
	return 0;
}