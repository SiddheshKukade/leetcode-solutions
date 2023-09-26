#include <iostream>
#include <bits/stdc++.h>
#define ppi pair<int, int>
using namespace std;
 
class Compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        
        if (a.first == b.first)
            return a.second
                   > b.second; 
        return a.first
               < b.first; 
    }
};
 
int main() {
//code
int t;
cin>>t;
for(int k=0;k<t;k++){
    int n;
    cin>>n;
    vector<int>vec;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[vec[i]]++;
    }
    priority_queue<ppi, vector<ppi>, Compare> pq;
    
    for(auto it:mp){
        pq.push({it.second,it.first});
    }
    
    
    
    
    while(!pq.empty()){
       int p=pq.top().second;
       int  ch=pq.top().first;
        pq.pop();
        for(int i=0;i<ch;i++){
            cout<<p<<" ";
        }
    }
    cout<<endl;
    
}
return 0;
}
