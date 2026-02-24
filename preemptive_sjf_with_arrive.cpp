#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> at(n),bt(n),rt(n),ct(n);
    for(int i=0;i<n;i++){
        cin>>at[i]>>bt[i];
        rt[i]=bt[i];
    }

    int time=0,complete=0,total=0,idle=0;
    cout<<"Gantt Chart:\n|0";

    while(complete<n){
        int idx=-1,minm=INT_MAX;

        for(int i=0;i<n;i++)
            if(at[i]<=time && rt[i]>0 && rt[i]<minm){
                minm=rt[i];
                idx=i;
            }

        if(idx==-1){
            time++;
            idle++;
            continue;
        }

        cout<<" P"<<idx+1<<" |";
        rt[idx]--;
        time++;

        if(rt[idx]==0){
            complete++;
            ct[idx]=time;
            total+=ct[idx]-bt[idx]-at[idx];
        }

        cout<<time;
    }

    cout<<"\nTotal WT: "<<total;
    cout<<"\nAvg WT: "<<(float)total/n;
    cout<<"\nIdle: "<<idle;
}