//
// Created by 王若璇 on 16/5/17.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long a,b,c;
    while (cin>>a>>b>>c){
        if(c==0){
            if(a==b){
                cout<<"YES"<<endl;
            } else{
                cout<<"NO"<<endl;
            }
            continue;
        }
        long long t1 = (b-a)/c;
        long long t2 = (b-a)%c;
        if(t2!=0){
            cout<<"NO"<<endl;
        } else{
            if(t1+1>0){
                cout<<"YES"<<endl;
            } else{
                cout<<"NO"<<endl;
            }
        }

    }
    return 0;
}