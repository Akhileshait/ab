#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int v){
     queue<int> q;
     bool vis[v+1]={0};
     q.push(1);
     vis[1]=1;
     while(!q.empty()){
          int k=q.front();
          q.pop();
          cout<<k<<" ";

          for(int i=0; i<adj[k].size(); ++i){
               if(vis[adj[k][i]]){
                    continue;
               }
               vis[adj[k][i]]=1;
               q.push(adj[k][i]);
          }

     }
}

bool f=0;

void dfs(vector<int> adj[], int v, int vis[]){
     if(vis[v]){
          return;
     }
     vis[v]=1;
     cout<<v<<" ";
     f=1;
     for(int i=0; i<adj[v].size(); ++i){
          dfs(adj, adj[v][i], vis);
     }
}

int main(){
     int n;
     cout<<"Enter the number of vertex in the graph: ";
     cin>>n;
     vector<int> adj[n+1];
     for(int i=1; i<=n; ++i){
          int k;
          cin>>k;
          while(k){
               int v;
               cin>>v;
               adj[i].push_back(v);
               k--;
          }
     }
     cout<<"The BFS Traversal is: ";
     bfs(adj, n);
     cout<<endl;
     cout<<"The DFS Traversal is: ";
     int vis[n+1]={0};
     int ct=0;
     for(int i=1; i<=n; ++i){
          dfs(adj, i, vis);
          if(f)ct++;
          f=0;
     }
     cout<<endl;

     cout<<"The number of connected commponents: "<<ct;

}    