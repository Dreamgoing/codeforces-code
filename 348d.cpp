//
// Created by 王若璇 on 16/4/25.
//
//modify code TLE
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
void solveSwapEven(){
    for(int i = 1;i<=n/2;i++){
        swap(a[2*i],a[2*i-1]);
    }
}
void sovleSwapOdd(){
    for(int i = 2;i<=n-2;i+=2){
        swap(a[i],a[i+1]);
    }
    swap(a[1],a[n]);
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
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    while (~scanf("%d%d",&n,&q)){
       // init();
        int op,x;
        int odd= 0,even =0 ;
        for(int i = 0;i<q;i++){
            scanf("%d",&op);
            if(op==2){
                if(even%2==1){
                    even = (even+1)%n;
                    odd = (n+(odd-1)%n)%n;
                } else{
                    even = (n+(even-1)%n)%n;
                    odd = (odd+1)%n;
                }

            } else{
                scanf("%d",&x);
                odd = (n+(odd+x)%n)%n;
                even = (n+(even+x)%n)%n;

            }

        }

        for(int i = 1;i<=n;i++){
            int pos = 0;
            if(i%2==1){
                pos = (i+odd)%n == 0?n:(i+odd)%n;
            } else{
                pos = (i+even)%n == 0?n:(i+even)%n;
            }
            a[pos] = i;
        }
        for(int i = 1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }

    return 0;
}
