#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<tuple<int,int,int>> p; // pr,bt,id
    for(int i=0;i<n;i++){
        int bt,pr;
        cin>>bt>>pr;
        p.push_back({pr,bt,i+1});
    }

    sort(p.begin(),p.end());

    int time=0,total=0;
    cout<<"Gantt Chart:\n|0";

    for(auto x:p){
        int pr,bt,id;
        tie(pr,bt,id)=x;

        cout<<" P"<<id<<" |";
        total+=time;
        time+=bt;
        cout<<time;
    }

    cout<<"\nTotal WT: "<<total;
    cout<<"\nAvg WT: "<<(float)total/n;
}