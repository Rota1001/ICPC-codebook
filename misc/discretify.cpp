#include<bits/stdc++.h>
#define int long long
using namespace std;

int n;
int a[200005];
vector<int> v;

signed main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < n; i++){
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }

}