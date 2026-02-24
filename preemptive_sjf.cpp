#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<pair<int,int>> p(n); // {burst,id}
    for(int i=0;i<n;i++){
        cin>>p[i].first;
        p[i].second=i+1;
    }

    sort(p.begin(),p.end());

    int time=0,total=0;
    cout<<"Gantt Chart:\n|0";

    for(int i=0;i<n;i++){
        cout<<" P"<<p[i].second<<" |";
        total+=time;
        time+=p[i].first;
        cout<<time;
    }

    cout<<"\nTotal WT: "<<total;
    cout<<"\nAvg WT: "<<(float)total/n;
}