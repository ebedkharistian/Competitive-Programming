#include <iostream>
#include <set> 
#include <algorithm>
#include <sstream>

using namespace std;

int main(){
    int n;
    while(cin >> n, n != 0){
        multiset<int> siA, siB;
        int cost = 0;
        cin.ignore();
        for(int i=0;i<n;i++){
            multiset<int> si;
            string s;

            getline(cin, s);
            istringstream iss(s);
            int data;
            while(iss >> data){
                si.insert(data);
            }

            if(i == 0){
                int Min = (*si.begin());
                int Max = (*si.rbegin());
                cost += Max - Min;
                // update
                si.erase(si.find(Max));
                si.erase(si.find(Min));
                siA = si;
            }else{
                siB = si;
                for(set<int>::iterator it = siA.begin(); it != siA.end(); it++){
                    si.insert( (*it) );
                }
                int Min = (*si.begin());
                int Max = (*si.rbegin());
                cost += Max - Min;
                // update
                if(siA.find(Max)!= siA.end()) siA.erase(siA.find(Max));
                else if(siB.find(Max)!= siB.end()) siB.erase(siB.find(Max));

                if(siA.find(Min)!= siA.end()) siA.erase(siA.find(Min));
                else if(siB.find(Min)!= siB.end()) siB.erase(siB.find(Min));

                siA = siB;
            }
        }

        cout << cost << endl;
    }
}