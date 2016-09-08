//
// Created by 王若璇 on 16/8/29.
//
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;
const int max_n = 600;
typedef long long ll;
ll a[max_n][max_n];
pair<int,int> pos;
int n;
bool cheak(ll x){
    ll tmpsum = 0;
    for(int i = 1;i<=n;i++){
        tmpsum = 0;
        for(int j = 1;j<=n;j++){
            tmpsum+=a[i][j];
        }
        if(tmpsum!=x){
            return false;
        }
    }
    for(int i = 1;i<=n;i++){
        tmpsum = 0;
        for(int j = 1;j<=n;j++){
            tmpsum+=a[j][i];
        }
        if(tmpsum!=x){
            return false;
        }
    }
    tmpsum = 0;
    for(int i = 1;i<=n;i++){
        tmpsum+=a[i][i];
    }
    if(tmpsum!=x){
        return false;
    }
    tmpsum = 0;
    for(int i =1;i<=n;i++){
        tmpsum+=a[i][n-i+1];
    }
    if(tmpsum!=x){
        return false;
    }
    return true;
}
ll solve(){
    if(n==1){
        return 1;
    }
    int tmppos;
    ll sum = 0;
    ll sumx = 0;
    for(int i = 1;i<=n;i++){
        if(i!=pos.first){
            tmppos = i;
            break;
        }
    }
    for(int i = 1;i<=n;i++){
        sum+=a[tmppos][i];
        sumx+=a[pos.first][i];
    }
    ll re = sum-sumx;
    a[pos.first][pos.second] = re;
    if(re>0&&cheak(sum)){
        return re;
    } else{
        return -1;
    }


}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>n){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                cin>>a[i][j];
                if(a[i][j]==0){
                    pos.first = i;
                    pos.second = j;
                }
            }
        }
        cout<<solve()<<endl;
    }
    return 0;
}