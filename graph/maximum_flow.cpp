#include<bits/stdc++.h>
#define int long long 
using namespace std;

int n, m;
int c[505][505];
vector<int> v[505];
int d[505];
int ans = 0;
int head[505];

int dfs(int x, int flow){
    if(x == n){
        return flow;
    }
    int ret = 0;
    for(int i = head[x]; i < v[x].size(); i++){
        head[x] = i;
        int y = v[x][i];
        if(!c[x][y] || d[y] != d[x] + 1){
            continue;
        }
        int k = dfs(y, min(flow, c[x][y]));
        flow -= k;
        c[x][y] -= k;
        c[y][x] += k;
        ret += k;
    }
    return ret;
}

int bfs(){
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i : v[now]){
            if(i == 1 || d[i] || !c[now][i]){
                continue;
            }
            d[i] = d[now] + 1;
            q.push(i);
        }
    }
    return d[n];
}

signed main(){
    cin >> n >> m;
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        if(c[x][y]){
            c[x][y] += z;
        }else{
            c[x][y] = z;
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }
    while(bfs()){
        memset(head, 0, sizeof(head));
        ans += dfs(1, 0x3f3f3f3f);
    }
    cout << ans;
}