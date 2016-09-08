//
// Created by 王若璇 on 16/3/31.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
using namespace std;
const int max_n = 100100;
struct P{
    string name;
    int point;
    P(){
        name = " ";
        point = -1;
    }
    bool operator<(const P& a)const {
        return point>a.point;
    }
    bool operator ==(const P& a)const {
        return point==a.point;
    }
};
vector<P> v[max_n];

bool flag[max_n];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while (cin>>n>>m){
        for(int i = 0;i<=m;i++){
            v[i].clear();
        }
        P tmp;
        memset(flag,0, sizeof(flag));
        int id;
        for(int i = 0;i<n;i++){
            cin>>tmp.name>>id>>tmp.point;
            v[id].push_back(tmp);
            if(v[id].size()==4){
                sort(v[id].begin(),v[id].end());
                v[id].pop_back();
                flag[id] = true;
            }

        }
        for(int i = 1;i<=m;i++){
            if(v[i].size()==2){
                cout<<v[i][0].name<<" "<<v[i][1].name<<endl;
            } else{
                if(!flag[i]){
                    sort(v[i].begin(),v[i].end());
                }
                if(v[i][1].point==v[i][2].point){
                    cout<<"?"<<endl;
                } else{
                    cout<<v[i][0].name<<" "<<v[i][1].name<<endl;
                }
            }

        }

    }

    return 0;
}

