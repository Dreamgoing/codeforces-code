//
// Created by 王若璇 on 16/5/6.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;
const int max_n = 200200;
int a[max_n];
map<int,int> num;
struct Movie{
    int a,b;
    int anum,bnum;
    int id;
    Movie(){}
    Movie(int _a,int _b){
        this->a = _a;
        this->b = _b;
        this->anum = 0;
        this->bnum = 0;
    }
    bool operator<(const Movie& m)const{
        if(anum!=m.anum){
            return anum<m.anum;
        } else{
            return bnum<m.bnum;
        }
    }
}movies[max_n];
pair<int,int> tmp[max_n];
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,m;
    while (~scanf("%d",&n)){
        num.clear();
        for(int i = 0;i<n;i++){
            scanf("%d",&a[i]);
            if(num.count(a[i])==0){
                num[a[i]] = 1;
            } else{
                num[a[i]]++;
            }
        }
        cin>>m;
        for(int i = 0;i<m;i++){
            scanf("%d",&tmp[i].first);
        }
        Movie ans = movies[0];
        int pos = 0;
        int bc=0,cc=0;
        for(int i = 0;i<m;i++){
            scanf("%d",&tmp[i].second);
            /*movies[i].a = tmp[i].first;
            movies[i].b = tmp[i].second;
            movies[i].anum = num[tmp[i].first];
            movies[i].bnum = num[tmp[i].second];
            //cout<<num[b]<<" *"<<endl;
            movies[i].id = i+1;
            ans = max(movies[i],ans);*/
            if(num[tmp[i].first]>bc||num[tmp[i].first]==bc&&num[tmp[i].second]>cc){
                bc = num[tmp[i].first];
                cc = num[tmp[i].second];
                pos = i;
            }

        }
        printf("%d\n",pos+1);
        //cout<<ans.id<<endl;

    }
    return 0;
}