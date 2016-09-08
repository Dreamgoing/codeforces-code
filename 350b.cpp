//
// Created by 王若璇 on 16/5/6.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const long long max_n = 100100;
long long a[max_n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,k;
    while (cin>>n>>k){
        for(long long i = 0;i<n;i++){
            cin>>a[i];
        }
        long long pos = 0;
        for(long long i = 1;i<=n;i++){
            if(i*(i+1)/2>=k){
                pos = i;
                break;
            }
        }
        long long tmpk = k;
        //cout<<tmpk<<" ("<<endl;
        tmpk-=((pos-1)*pos)/2;
        //cout<<tmpk<<")"<<endl;
        tmpk--;
        long long respos = (tmpk+n)%n;
        cout<<a[respos]<<endl;
    }

    return 0;
}

