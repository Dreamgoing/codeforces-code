//
// Created by 王若璇 on 16/5/17.
//
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long n,a,b,c,d;
bool isLim(long long x){
    return x>=1&&x<=n;
}
bool ok(long long x){
    long long x3 = a+x-d;
    long long x4 = x+a+b-c-d;
    long long x2 = x+b-c;
    return isLim(x3)&&isLim(x4)&&isLim(x2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin>>n>>a>>b>>c>>d){
        long long num = 0;
        for(long long i = 1;i<=n;i++){
            if(ok(i)){
                num++;
            }
        }
        long long ans = num*n;
        cout<<ans<<endl;

    }
    return 0;
}