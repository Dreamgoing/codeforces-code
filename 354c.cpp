//
// Created by 王若璇 on 16/5/26.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int a,b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    while (cin>>n>>k){
        string s;
        int cnt = 0;
        int rs = 0;
        a = 0;
        b= 0;
        cin>>s;
        for(int i = 0;i<n;i++){
            if(s[i]=='a'){
                a++;
            } else{
                b++;
            }
            while (a>k&&b>k){
                if(s[cnt]=='a'){
                    a--;
                } else{
                    b--;
                }
                cnt++;
            }
            rs = max(rs,i-cnt+1);
        }
        cout<<rs<<endl;


    }
    return 0;
}


