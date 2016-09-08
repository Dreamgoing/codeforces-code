//
// Created by 王若璇 on 16/5/12.
//
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
const int max_n = 100100;
const double eps = 1e-7;
pair<long long,long long> bottles[max_n];
pair<long long,long long> a,b,t;
vector<pair<double ,int> >resa;
vector<pair<double ,int> >resb;
bool vis[max_n];
double getDis(pair<long long,long long> a,pair<long long,long long> b){
    return sqrt(1.*(a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>a.first>>a.second>>b.first>>b.second>>t.first>>t.second){
        long long n;
        //scanf("%lld",&n);
        resa.clear();
        resb.clear();
        cin>>n;
        double disa = 1e10;
        double disb = 1e10;
        double ans = 0;
        long long posa = -1;
        long long posb = -1;
        for(long long i = 0;i<n;i++){
            //scanf("%lld%lld",&bottles[i].first,&bottles[i].second);
            cin>>bottles[i].first>>bottles[i].second;
            double bt = getDis(bottles[i],t);
            ans += bt;
            double tmpa = getDis(bottles[i],a);
            resa.push_back(make_pair(tmpa-bt,i));
            double tmpb = getDis(bottles[i],b);
            resb.push_back(make_pair(tmpb-bt,i));
        }
        ans = ans*2;
        //prlong longf("%.12lf\n",ans);
        double res = 1e20;
        sort(resa.begin(),resa.end());
        sort(resb.begin(),resb.end());
        if(n==1){
            ans = ans + min(resa[0].first,resb[0].first);
        }else{
            if(resa[0].second!=resb[0].second){
                ans = min(min(ans+resa[0].first+resb[0].first,ans+resa[0].first),ans+resb[0].first);
            } else{
                ans = min(ans+resa[1].first+resb[0].first,min(ans+resa[0].first+resb[1].first,min(ans+resa[0].first,ans+resb[0].first)));
            }
        };

        printf("%.12lf\n",ans);



    }

    return 0;
}

