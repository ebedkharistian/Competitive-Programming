#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool comp(ii a, ii b){
    return a.second > b.second;
}

int main()
{
    vii data = {make_pair(21, 100), make_pair(32, 200), make_pair(54, 300), make_pair(12, 400), make_pair(90, 500)};
    for(vii::iterator it = data.begin(); it != data.end(); it++){
        cout << (*it).first << "," << (*it).second << " ";
    }
    cout << endl;
    
    sort(data.begin(), data.end(), comp);
    
    for(vii::iterator it = data.begin(); it != data.end(); it++){
        cout << (*it).first << "," << (*it).second << " ";
    }
    cout << endl;
    return 0;
}