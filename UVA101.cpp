#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector< vector<int> > v;
vector<int> parent;



void reset(int i){
	v[i].clear();
	v[i].push_back(i);
	parent[i] = i;
}

int location(int x){
	if(parent[x] == x)
		return x;
	else 
		return parent[x] = location(parent[x]);
}

bool check(int a, int b){
	if(location(a) == location(b)){
		return true;
	}
	return false;
}

void empty(int i){
	int l = location(i);
	bool isMoving = false;
	for(int j=0;j<v[l].size();j++){
		if(isMoving)
			reset(v[l][j]);
		if(v[l][j] == i)
			isMoving = true;
	}

	int s = v[l].size() - 1;
	for(int j=s;j>=0;j--){
		if(v[l][j] == i)
			break;
		v[l].pop_back();
		
			
	}
	
}

void move(int a, int b){
	int lA = location(a);
	int lB = location(b);
	if(lA == lB){
		return;
	}
	bool isMoving = false;
	for(int j=0;j<v[lA].size();j++){
		if(v[lA][j] == a)
			isMoving = true;
		if(isMoving){
			v[lB].push_back(v[lA][j]);
			parent[v[lA][j]] = lB;
		}	
	}

	int sA = v[lA].size() - 1;
	for(int j=sA;j>=0;j--){
		v[lA].pop_back();
		if(v[lA][j] == a)
			break;
			
	}
}

void output(){
	for(int i=0;i<v.size();i++){
		cout << i << ":";
		for(int j=0;j<v[i].size();j++){
			cout << " " << v[i][j];
		}
		cout << endl;
	}
}

int main(){
	int n, a, b; 
	string s1, s2;
	cin >> n;
	v.resize(n);
	for(int i=0;i<n;i++){
		v[i].push_back(i);
		parent.push_back(i);
	}
	while(cin >> s1, s1 != "quit"){
		cin >> a >> s2 >> b;
		if(!check(a, b)){
			if(s1 == "move" && s2 == "onto"){
				empty(a);
				empty(b);
				move(a, b);
			}else if(s1 == "move" && s2 == "over"){
				empty(a);
				move(a, b);
			}else if(s1 == "pile" && s2 == "onto"){
				empty(b);
				move(a, b);
			}else if(s1 == "pile" && s2 == "over"){
				move(a, b);
			}	
		}
	}
	output();
	return 0;
	
}