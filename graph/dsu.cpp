int n;
int fa[100005];
int rk[100005];

void init(){
    for(int i = 1; i <= n; i++){
        fa[i] = i;
        rk[i] = 1;
    }
}

int find(int x){
    if(x == fa[x]){
        return x;
    }
    return fa[x] = find(fa[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(rk[x] <= rk[y]){
        fa[x] = y;
    }else{
        fa[y] = x;
    }
    if(rk[x] == rk[y]){
        rk[y]++;
    }
}