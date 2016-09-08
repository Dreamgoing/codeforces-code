//
// Created by 王若璇 on 16/3/7.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const long long max_n = 200200;
pair<long long,long long> p[max_n];
map<long long,long long> x;
map<long long,long long> y;
map<pair<long long,long long>,long long> isexist;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    isexist.clear();
    long long n;
    while (cin>>n){
        x.clear();
        y.clear();
        isexist.clear();
        long long same = 0;
        for(long long i = 0;i<n;i++){
            cin>>p[i].first>>p[i].second;
            x[p[i].first]++;
            y[p[i].second]++;
            isexist[p[i]]++;
        }
        long long ans = 0;
        for(map<long long,long long>::iterator it = x.begin();it!=x.end();++it){
            long long tmp = it->second;
            ans+=(tmp-1)*tmp/2;
        }
        for(map<long long,long long>::iterator it = y.begin();it!=y.end();++it){
            long long tmp = it->second;
            ans+=(tmp-1)*tmp/2;
        }
        for(map<pair<long long,long long>,long long>::iterator it = isexist.begin();it!=isexist.end();++it){
            long long tmp = it->second;
            ans-=(tmp-1)*tmp/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
