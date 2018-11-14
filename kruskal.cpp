#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;





class UFDS {
private:
	vector<int> p, rank, setSizes;
	int numSets;
public:
	UFDS(int N) {
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
		setSizes.assign(N, 1);
	}
	int findSet(int i) {
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		cout << "union " << i << " " << j << endl;
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				setSizes[findSet(x)] += setSizes[findSet(y)];
				p[y] = x;
			} else {
				setSizes[findSet(y)] += setSizes[findSet(x)];
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
			numSets--;
		}
	}
	int setSize(int i) {
		return setSizes[findSet(i)];
	}
	int numDisjointSets() {
		return numSets;
	}
};


// kruskal


int main(){


	int E = 6;
	int V = 5;
    int u,v,w;
    

	vector< pair<int, ii> > EdgeList; 
	for(int i = 0; i < E; i++){
			scanf("%d %d %d", &u, &v, &w);
			EdgeList.push_back( make_pair(w, ii(u,v)) );
	}

	sort(EdgeList.begin(), EdgeList.end());
    
    vector< pair<int, ii> >::iterator it;
    for(it = EdgeList.begin(); it != EdgeList.end(); it++){
         cout << (*it).first << " " << (*it).second.first << " " << (*it).second.second << endl;
    }

	int mst_cost = 0;
	UFDS UF(V);

	for(int i=0; i<E; i++){
		pair<int, ii> front = EdgeList[i];
        cout << front.first << endl;
		if(!UF.isSameSet(front.second.first, front.second.second)){
			mst_cost += front.first;
			UF.unionSet(front.second.first, front.second.second);
		}
	}

	printf("MST cost = %d", mst_cost);
	return 0;


}