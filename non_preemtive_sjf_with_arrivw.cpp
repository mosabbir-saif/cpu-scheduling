#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> at(n),bt(n),done(n,0);
    for(int i=0;i<n;i++)
        cin>>at[i]>>bt[i];

    int time=0,total=0,idle=0,completed=0;
    cout<<"Gantt Chart:\n|0";

    while(completed<n){
        int idx=-1,minm=INT_MAX;

        for(int i=0;i<n;i++)
            if(at[i]<=time && !done[i] && bt[i]<minm){
                minm=bt[i];
                idx=i;
            }

        if(idx==-1){
            time++;
            idle++;
            continue;
        }

        cout<<" P"<<idx+1<<" |";
        total+=time-at[idx];
        time+=bt[idx];
        done[idx]=1;
        completed++;
        cout<<time;
    }

    cout<<"\nTotal WT: "<<total;
    cout<<"\nAvg WT: "<<(float)total/n;
    cout<<"\nIdle: "<<idle;
}