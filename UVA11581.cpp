#include <iostream>
#include <cstdio>

using namespace std;

int g[3][3];

int x[] = {-1, 0, 0, 1};
int y[] = {0, 1, -1, 0};

void f(){
	int h[3][3];

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			int tmp = 0;
			for(int k=0; k<4; k++){
				int I = (i + y[k]);
				int J = (j + x[k]); 
				if(0 <= I && I <= 2 && 0 <= J && J <= 2){
				  	tmp += g[I][J];
				}
			}
			h[i][j] = tmp % 2;
		}	
	}

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			g[i][j] = h[i][j];
		}
	}
}

bool isZero(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(g[i][j] == 1) return false;
		}
	}
	return true;
}

int main(){
	int TC;
	scanf("%d\n", &TC);
	while(TC--){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				scanf("%1d", &g[i][j]);
			}
		}
		int ans = -1;
		while(!isZero()){
			f();
			ans++;
		}
		cout << ans << endl;
	}
}