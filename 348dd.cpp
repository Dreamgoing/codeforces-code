//
// Created by 王若璇 on 16/4/25.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int max_n = 1000100;
int n,q;
int a[max_n];
void init(){
    a[0] = 0;
    for(int i = 1;i<=n;i++){
        a[i] = i;
    }
}
void solveSwap(){
    for(int i = 1;i<=n/2;i++){
        swap(a[2*i],a[2*i-1]);
    }
}
void solveCycle(int c){
    int step = (c%n+n)%n;
    int tmp[max_n];
    for(int i = 1;i<=step;i++){
        tmp[i] = a[n-step+i];
    }
    for(int i = n;i>=step+1;i--){
        a[i] = a[i-step];
    }
    for(int i = 1;i<=step;i++){
        a[i] = tmp[i];
    }
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    while (~scanf("%d%d",&n,&q)){
        init();
        int op,x;
        int now = 0;
        for(int i = 0;i<q;i++){
            scanf("%d",&op);
            if(op==2){
                solveCycle(now);
                now = 0;
                solveSwap();
            } else{
                scanf("%d",&x);
                now+=x;
            }
        }
        solveCycle(now);
        for(int i = 1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }

    return 0;
}