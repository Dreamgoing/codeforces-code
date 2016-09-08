//
// Created by 王若璇 on 16/6/15.
//
//wa 改题
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
//const int  max_n = 1000000;
priority_queue<int ,vector<int >,greater<int > > pq;
vector<pair<string,int> > res;
//map<int,int > num;
bool remove(){
    if(pq.empty()){
        return false;
    }
    pq.pop();
    return true;

}
void showRes(){
    cout<<res.size()<<endl;
    for(int  i = 0;i<res.size();i++){
        if(res[i].first=="removeMin")
            cout<<res[i].first<<endl;
        else
            cout<<res[i].first<<" "<<res[i].second<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int  n;
    while(cin>>n){
        //memset(num,0, sizeof(num));
//        num.clear();
        res.clear();
        while (!pq.empty()){
            pq.pop();
        }
        string s;
        int  a;
        for(int  i = 0;i<n;i++){
            cin>>s;
            if(s=="insert"){
                cin>>a;

                pq.push(a);
                //cout<<s<<" "<<a<<endl;
                //string t = s+" "+to_string(a);
                res.push_back(make_pair(s,a));
            } else if(s=="removeMin"){
                if(remove()){
                    res.push_back(make_pair(s,0));
                }else{
                    res.push_back(make_pair("insert",1));
                    res.push_back(make_pair(s,0));
                    //pq.push(0);
                    //num[0]++;
                }
            } else{
                cin>>a;
                if(pq.empty()){
                    //res.push_back("insert "+to_string(a));
                    res.push_back(make_pair("insert",a));
                    pq.push(a);
                }else{
                    int  tmp = pq.top();
                    while (tmp<a&&remove()){
                        res.push_back(make_pair("removeMin",0));
                        if(pq.empty()){
                            break;
                        }
                        tmp = pq.top();
                    }
                    if(pq.empty()||tmp!=a){
                        res.push_back(make_pair("insert",a));
                        pq.push(a);
                    }
                }
                res.push_back(make_pair(s,a));
            }
        }
        showRes();

    }

    return 0;
}