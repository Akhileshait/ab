
//Minimum spanning 

#include<bits/stdc++.h>
using namespace std;


int primsalgo(int V, vector<vector<int>> adj[]){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push({0,1});
        
        int sum = 0;
        vector<bool>vis(V, false);
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second;
            
            if(vis[node]) continue;
            
            vis[node] = true;
            sum += wt;
            
            for(auto &v:adj[node]){
                int child = v[0], child_wt = v[1];
                pq.push({child_wt, child});
            }
        }
        return sum;
}

 

int main(){
     int n;
     cout<<"Enter the number of vertex in the graph: ";
     cin>>n;
     vector<vector<int>> adj[n+1];
     for(int i=1; i<=n; ++i){
          int k;
          cin>>k;
          while(k){
               int v, w;
               cin>>v;
               cin>>w;
               vector<int> arr(2);
               arr[0]=v;
               arr[1]=w;
               adj[i].push_back(arr);
               k--;
          }
     }
     cout<<"The weight mst using prim's is: "<<primsalgo(n, adj);
     

}    