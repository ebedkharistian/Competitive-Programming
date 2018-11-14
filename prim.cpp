#include <bits/stdc++.h>

#define DEBUG false
#define OJ_DEBUG

#define $(x) {if (DEBUG) {cout << __LINE__ << ": "; {x} cout << endl;}}
#define _(x) {cout << #x << " = " << x << " ";}

const double E = 1e-8;
const double PI = acos(-1);

using namespace std;



struct Graph {
    struct Edge {
    	int from;
        int to;
        int len;
    };

    const static int MAXNODE = 3 * 1e5 + 2;
    vector<int> g[MAXNODE];
    vector<Edge> edge;
    int n;
    void init(int nn) {
        n = nn;
        for (int i = 0; i <= n; i++)
            g[i].clear();
        edge.clear();
    }

    void add_e(int x, int y, int len) {
        g[x].push_back(edge.size());
        edge.push_back((Edge){x, y, len});
        g[y].push_back(edge.size());
        edge.push_back((Edge){y, x, len});
    }

    void show() {
    	for (int i = 0; i <= n; i++) {
    		printf("%d:", i);
    		for (int ie : g[i])
    			printf(" %d", edge[ie].to);
    		printf("\n");
    	}
    	printf("\n");
    }

    // 
    // ---- start of Minimum Spanning Tree ---
    // 
    vector<bool> added;
    vector<int> mindis; // little optimization
    void mst() {
        vector<bool>(n + 1, false).swap(added);
        vector<int>(n + 1, INT_MAX).swap(mindis);

        auto cmp = [](const Edge& a, const Edge& b) {
            return a.len > b.len;
        };
        priority_queue<Edge, vector<Edge>, decltype(cmp)> near(cmp);
        for (int i = 0; i < g[1].size(); i++) {
            const Edge& e = edge[g[1][i]];
            near.push(e);
            mindis[e.to] = e.len; // little optimization
        }
        added[1] = true;

        while (near.size()) {
            Edge cur = near.top(); near.pop();
            added[cur.to] = true;
            // add Edge cur
            for (int ie : g[cur.to]) {
                const Edge& nxe = edge[ie];
                int nx = nxe.to;
                if (!added[nx]
                 && mindis[nx] > nxe.len) { // little optimization
                    mindis[nx] = nxe.len; // little optimization
                    near.push(nxe);
                }
            }
            while (near.size() && added[near.top().to])
                near.pop();
        }
        // 
    }
    // 
    // ---- end of Minimum Spanning Tree ---
    // 
};


int main(){
	Graph GR;
	GR.init(9);
	GR.add_e(0,1, 4);
	GR.add_e(0,7, 8);
	GR.add_e(1,2, 8);
	GR.add_e(1,7, 11);
	GR.add_e(7,8, 7);
	GR.add_e(2,8, 2);
	GR.add_e(6,8, 6);
	GR.add_e(6,7, 1);
	GR.add_e(6,5, 2);
	GR.add_e(2,5, 4);
	GR.add_e(2,3, 7);
	GR.add_e(3,5, 14);
	GR.add_e(5,4, 10);
	GR.add_e(3,4, 9);


	GR.show();

}