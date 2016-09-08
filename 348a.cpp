//
// Created by 王若璇 on 16/4/25.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
const int max_n = 1000000;
const int inf = 0x3f3f3f3f;
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        int res = 0;
        int d = n/3;
        int r = n%3;
        res = 2*d;
        res+=r>0?1:0;
        cout<<res<<endl;

    }
    return 0;
}

