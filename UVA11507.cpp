#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	while(cin >> n, n){
		string move, direction;
		
		int isZ = 0, isY = 0;
		direction = "+x";
		for(int j=1;j<n;j++){
			cin >> move;	
			int z = 0, y = 0;
			

			if(move == "+z")
				z++;
			else if(move == "-z")
				z--;
			else if(move == "+y")
				y++;
			else if(move == "-y")
				y--;
			
			if(direction == "+x"){
				if(z == 1){
					direction = "+z";
				}else if(z == -1){
					direction = "-z";
				}else if(y == 1){
					direction = "+y";
				}else if(y == -1){
					direction = "-y";
				}
			}else if(direction == "-x"){
				if(z == 1){
					direction = "-z";
				}else if(z == -1){
					direction = "+z";
				}else if(y == 1){
					direction = "-y";
				}else if(y == -1){
					direction = "+y";
				}
			}else if(direction == "+z"){
				if(z == 1){
					direction = "-x";
				}else if(z == -1){
					direction = "+x";
				}
			}else if(direction == "-z"){
				if(z == 1){
					direction = "+x";
				}else if(z == -1){
					direction = "-x";
				}
			}else if(direction == "+y"){
				if(y == 1){
					direction = "-x";
				}else if(y == -1){
					direction = "+x";
				}
			}else if(direction == "-y"){
				if(y == 1){
					direction = "+x";
				}else if(y == -1){
					direction = "-x";
				}
			}


		}
		cout << direction << endl;
		

	}
	return 0;
}