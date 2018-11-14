#include <iostream>
#include <vector>

using namespace std; 

int main(){
	
	int N; 
	cin >> N;
	vector<int> data; 
	for(int i=0;i<N;i++){
		int x; cin >> x;
		data.push_back(x);
	}
	int posA, posB;
	string dirA, dirB;
	cin >> posA >> dirA; 
	cin >> posB >> dirB;


	int totalA = 0, totalB = 0;

	if(dirA == "right"){
		for(int i=posA-1; i<N;i++ ){
			if(data[i] != 0){
				totalA += data[i];
			}
		}
	}else if(dirB == "left"){
		for(int i=posA-1; i>=0;i-- ){
			cout << "test";
			if(data[i] != 0){
				totalA += data[i];
			}
		}
	}

	if(dirB == "right"){
		for(int i=posB-1; i<N;i++ ){
			if(data[i] == 0){
				totalB += 1;
			}
		}
	}else if(dirB == "left"){
		for(int i=posB-1; i>=0;i-- ){
			if(data[i] == 0){
				totalB += 1;
			}
		}
	}

	cout << totalA << " " << totalB << endl;
}