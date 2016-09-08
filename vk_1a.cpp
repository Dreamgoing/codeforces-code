//
// Created by 王若璇 on 16/3/29.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_n  = 100;
int p[max_n];
int t[max_n];
int n,c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin>>n>>c){
        for(int i = 0;i<n;i++){
            cin>>p[i];
        }
        for(int i = 0;i<n;i++){
            cin>>t[i];
        }
        int resa = 0;
        int resb = 0;
        int tmpt = 0;
        for(int i = 0;i<n;i++){
            tmpt += t[i];
            resa+=max(p[i]-tmpt*c,0);
        }
        tmpt = 0;
        for(int i = n-1;i>=0;i--){
            tmpt +=t[i];
            resb+=max(p[i]-tmpt*c,0);
        }
        if(resa>resb){
            cout<<"Limak"<<endl;
        } else if(resa<resb){
            cout<<"Radewoosh"<<endl;
        } else{
            cout<<"Tie"<<endl;
        }

    }

    return 0;
}
