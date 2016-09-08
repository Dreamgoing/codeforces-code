//
// Created by 王若璇 on 16/4/25.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int max_n = 110;
int a[max_n][max_n];
int n,m,q;
void located(int x,int y,int c){
    a[x][y] = c;
}
void rowCycle(int r){
    int tmp = a[r][m];
    for(int i = m;i>=2;i--){
        a[r][i] = a[r][i-1];
    }
    a[r][1] = tmp;
}
void columnCycle(int c){
    int tmp = a[n][c];
    for(int i = n;i>=2;i--){
        a[i][c] = a[i-1][c];
    }
    a[1][c] = tmp;
}
struct Op{
    int op;
    int shift;
    int x,y,v;
    Op(){};
    Op(int _op,int _shift){
        op = _op;
        shift = _shift;
        x = y = v = -1;
    }
    Op(int _op,int _x,int _y,int _v){
        op = _op;
        x = _x;
        y = _y;
        v = _v;
    }

};
stack<Op> ss;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin>>n>>m>>q){
        memset(a,0, sizeof(a));
        int op,x,y,v;
        while (!ss.empty()){
            ss.pop();
        }
        for(int i = 0;i<q;i++){
            cin>>op;
            if(op==1||op==2){
                cin>>x;
                ss.push(Op(op,x));
            } else{
                cin>>x>>y>>v;
                ss.push(Op(op,x,y,v));
            }
        }
        while (!ss.empty()){
            Op now = ss.top();
            ss.pop();
            if(now.op==1){
                rowCycle(now.shift);
            } else if(now.op==2){
                columnCycle(now.shift);
            } else{
                located(now.x,now.y,now.v);
               // cout<<a[now.x][now.y]<<endl;
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<'\n';
        }

    }
    return 0;
}
