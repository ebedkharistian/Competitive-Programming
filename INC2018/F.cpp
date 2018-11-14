#include<iostream>
#include<vector>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;

int main(){
    int num, query;
    vector< set<char> > people;
    cin>>num>>query;
    cin.ignore();
    for(int i=0;i<num;i++){
        string name;
        getline(cin,name);
        set<char> initial;
        string token;
        istringstream ss(name);
        while(getline(ss,token,' ')){
            initial.insert(token.at(0));
            //cout<<token.at(0);
        }
        people.push_back(initial);
    }
    for(int i=0;i<query;i++){
        string x;
        cin>>x;
        vector<char> charData; 
        for(int j=0;j<x.length(); j++){
            charData.push_back(x[j]);
        }
        sort(charData.begin(), charData.end());
        bool found = false;
        do{
            bool isCorrect = true;
            vector< set<char> > new_(people);

            for(long i=0; i<charData.size();i++){
                //loop vector
                for(int j=0; j<new_.size();j++){

                    if(find(new_.at(j).begin(),new_.at(j).end(),charData.at(i))==new_.at(j).end()){
                        isCorrect=false;
                    } else{
                        new_.erase(new_.begin()+j);

                        isCorrect=true;
                        break;
                    }
                }
                if(!isCorrect){
                    break;
                }
            }
            if(isCorrect){
                cout<<"YES"<<endl;
                found = true;
                break;
            } else{
                continue;
                
            }
        }while(next_permutation(charData.begin(), charData.end()));
        if(!found)
            cout<<"NO"<<endl;
        

    }
}