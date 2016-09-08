//
// Created by 王若璇 on 16/3/29.
//
//wrong answer please debug it
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
void solve(int n,int d,int h){
    if(d>2*h||d<h||(d==h&&h==1&&n!=2)){
        cout<<-1<<endl;
        return;
    } else if(d==h&&h>1){
        int pos;
        for(pos = 2;pos<2+h;pos++){
            cout<<pos-1<<" "<<pos<<endl;
        }
        for(;pos<=n;pos++){
            cout<<2<<" "<<pos<<endl;
        }

    } else{
        int tmp = d-h;
        int pos;
        for(pos = 2;pos<2+h;pos++){
            cout<<pos-1<<" "<<pos<<endl;
        }
        for(int cnt = 0;cnt<tmp;cnt++){
            if(cnt==0){
                cout<<1<<" "<<pos<<endl;
                pos++;
            } else{
                cout<<(pos-1)<<" "<<pos<<endl;
                pos++;
            }
        }
        for(;pos<=n;pos++){
            cout<<1<<" "<<pos<<endl;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d,h;
    while (cin>>n>>d>>h){
        solve(n,d,h);
    }
    return 0;
}
