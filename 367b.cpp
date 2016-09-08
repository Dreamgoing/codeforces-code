//
// Created by 王若璇 on 16/8/12.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
const int max_n = 100100;
int a[max_n];
int mm[max_n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        int m;
        cin>>m;
        sort(a,a+n);
        for(int i = 0;i<m;i++){
            cin>>mm[i];
            int p = upper_bound(a,a+n,mm[i])-a;
            //cout<<mm[i]<<" "<<p<<endl;
            cout<<p<<endl;
        }


    }

    return 0;
}

