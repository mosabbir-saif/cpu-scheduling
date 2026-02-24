#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,tq;
    cin>>n;

    vector<int> bt(n),rt(n),ct(n);
    for(int i=0;i<n;i++){
        cin>>bt[i];
        rt[i]=bt[i];
    }

    cin>>tq;

    int time=0,total=0,complete=0;
    cout<<"Gantt Chart:\n|0";

    while(complete<n){
        for(int i=0;i<n;i++){
            if(rt[i]>0){
                int exec=min(tq,rt[i]);
                cout<<" P"<<i+1<<" |";
                time+=exec;
                rt[i]-=exec;
                cout<<time;

                if(rt[i]==0){
                    complete++;
                    ct[i]=time;
                    total+=ct[i]-bt[i];
                }
            }
        }
    }

    cout<<"\nTotal WT: "<<total;
    cout<<"\nAvg WT: "<<(float)total/n;
}