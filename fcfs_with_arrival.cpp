#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id, at, bt, wt;
};

bool compare(Process a, Process b) {
    return a.at < b.at;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);

    for(int i = 0; i < n; i++) {
        p[i].id = i+1;
        cout << "Arrival & Burst time of P" << i+1 << ": ";
        cin >> p[i].at >> p[i].bt;
    }

    sort(p.begin(), p.end(), compare);

    int time = 0, totalWT = 0, idle = 0;

    cout << "\nGantt Chart:\n|";

    vector<int> timeline;
    timeline.push_back(0);

    for(int i = 0; i < n; i++) {

        if(time < p[i].at) {
            cout << " Idle |";
            idle += p[i].at - time;
            time = p[i].at;
            timeline.push_back(time);
        }

        p[i].wt = time - p[i].at;
        totalWT += p[i].wt;

        cout << " P" << p[i].id << " |";

        time += p[i].bt;
        timeline.push_back(time);
    }

    cout << "\n";

    for(int t : timeline)
        cout << t << "    ";

    cout << "\n\nTotal Waiting Time: " << totalWT;
    cout << "\nAverage Waiting Time: " << (float)totalWT/n;
    cout << "\nIdle Time: " << idle;

    return 0;
}