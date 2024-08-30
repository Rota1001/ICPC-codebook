#include<bits/stdc++.h>
#define int long long 
using namespace std;
 
int n, m;
int d[100005];
int low[100005];
int cnt = 0;
vector<int> v[100005];
stack<int> st;
int scc[100005];
int now = 0;
 
void dfs(int x){
    d[x] = low[x] = ++cnt;
    st.push(x);
    for(int i : v[x]){
        if(scc[i])continue;
        if(d[i]){
            low[x] = min(low[x], d[i]);
        }else{
            dfs(i);
            low[x] = min(low[x], low[i]);
        }
    }
    if(d[x] == low[x]){
        now++;
        while(!st.empty()){
            int k = st.top();
            st.pop();
            scc[k] = now;
            if(k == x)break;
        }
    }
}
 
signed main(){
    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }
    for(int i = 1; i <= n; i++){
        if(!d[i]){
            dfs(i);
        }
    }
    cout << now << "\n";
    for(int i = 1; i <= n; i++){
        cout << scc[i] << " ";
    }
}
