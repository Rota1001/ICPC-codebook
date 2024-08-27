#include<bits/stdc++.h>
using namespace std;

int n;
int st[200005][21];

void init(){
    for(int j = 1; j < 21; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r){
    int s = __lg(r - l + 1);
    return min(st[l][s], st[r - (1 << s) + 1][s]);
}