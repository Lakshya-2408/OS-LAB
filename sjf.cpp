#include<bits/stdc++.h>
using namespace std;
typedef struct process{
    pair<int,int>stbt;
    int ct=0,tat=0,wt=0;
    int pid;
}p;
void find(vector<p>&arr,int n){
    arr[0].ct = arr[0].stbt.first + arr[0].stbt.second;
    int c = arr[0].ct;
    for(int i = 1; i < n; i++){
        if(c >= arr[i].stbt.first){
            arr[i].ct = c + arr[i].stbt.second;
        }
        else {
            arr[i].ct = arr[i].stbt.first + arr[i].stbt.second;
            
        }
        c = arr[i].ct;
    }
    for(int i = 0; i < n; i++){
        arr[i].tat = arr[i].ct - arr[i].stbt.first;
    }
    for(int i = 0; i < n; i++){
        arr[i].wt = arr[i].tat - arr[i].stbt.second;
    }
}

int main(){
    int n;
    cout<<"Enter no. of processes- ";
    cin>>n;
    vector<p>processes(n);
    for(int i=0;i<n;i++){
        cout<<"Enter start and burst time of process ",i+1,"-";
        int st,bt;
        cin>>st>>bt;
        processes[i].stbt.first=st;
        processes[i].stbt.second=bt;
        processes[i].pid=i+1;
    }
    sort(processes.begin(), processes.end(), [](const p &a, const p &b) {
        if (a.stbt.first == b.stbt.first)
            return a.stbt.second < b.stbt.second; // burst time
        return a.stbt.first < b.stbt.first; // arrival time
    });
    find(processes,n);
    cout<<"PID\tArrival\tBurst\tcompletetion\tturn around time\twait\n";
    for(int i=0;i<n;i++){
        cout<<processes[i].pid<<"\t"<<processes[i].stbt.first<<"\t"<<processes[i].stbt.second<<"\t"<<processes[i].ct<<"\t"<<processes[i].tat<<"\t"<<processes[i].wt<<"\n";   
    }

}