#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int n = 10;
	vector<int> v(n+1);

	for(int i=1;i<=n;i++){
		v[i] = i+1;
	}

	int root = 1;
	int selectedNode = root;
	printf("v[%d] = %d\n", selectedNode, v[selectedNode]);

	//go left
	selectedNode = (selectedNode << 1);
	printf("v[%d] = %d\n", selectedNode, v[selectedNode]);
	//go right
	selectedNode = (selectedNode << 1) + 1;
	printf("v[%d] = %d\n", selectedNode, v[selectedNode]);

	// go to parent
	selectedNode = (selectedNode >> 1);
	printf("v[%d] = %d\n", selectedNode, v[selectedNode]);

}