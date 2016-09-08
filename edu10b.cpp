//
// Created by 王若璇 on 16/3/27.
//
#include <iostream>
#include <cstdio>
#include<algorithm>
#include <cstring>
using namespace std;
const int max_n = 1000000;
int a[max_n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        memset(a,0, sizeof(a));
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        sort(a,a+n);
        int l = 0;
        int r = n-1;
        for(int i = 0;i<n;i++){
            if(i%2==0){
                cout<<a[l++]<<" ";
            } else{
                cout<<a[r--]<<" ";
            }

        }
        cout<<'\n';


    }
    return 0;
}
