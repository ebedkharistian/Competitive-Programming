// Masih TLE
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

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set(); // all 1
	bs[0] = bs[1] = 0;
	for(ll i=2; i<= _sieve_size; i++) if(bs[i]){
		for(ll j=i*i; j<= _sieve_size; j+= i) bs[j] = 0;
		primes.push_back( (int)i);
	}
}

bool isPrime(ll N){
    if(N < 0) return false;
	if(N <= _sieve_size) return bs[N];
	for(int i=0; i< (int) primes.size(); i++){
		if( N % primes[i] == 0) return false;
	}
	return true;
}

int main(){
	sieve(100000000);
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