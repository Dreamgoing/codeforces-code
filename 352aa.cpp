//
// Created by 王若璇 on 16/5/12.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    s.clear();
    int i = 1;
    int n;
    while (s.length()<=1010){
        s+= to_string(i++);
    }
    while (cin>>n){
        cout<<s.at(n-1)<<endl;
    }
    return 0;
}

