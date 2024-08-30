#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> v[100005];
int dis[100005];
 
void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    bitset<100005> vis;
    while(!pq.empty()){
        pair<int, int> now = pq.top();
        pq.pop();
        if(vis[now.second]){
            continue;
        }
        vis[now.second] = 1;
        for(auto [u, w]: v[now.second]){
            if(vis[u]){
                continue;
            }
            if(now.first + w < dis[u]){
                dis[u] = now.first + w;
                pq.push({dis[u], u});
            }
        }
    }
}
