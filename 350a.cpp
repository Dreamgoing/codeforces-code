//
// Created by 王若璇 on 16/5/6.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_n = 1000100;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){


        int max_ans=0;
        if(n>=2){
            max_ans+=2;
        } else{
            max_ans+=n;
        }

        max_ans += 2 * ((n - 2) / 7);
        //cout<<max_ans<<endl;
        int min_ans = 2*(n/7);
        int rem = (n-2)%7;
        //cout<<rem<<endl;
        if(rem==6){
            max_ans+=1;
        }
        int remm = n%7;
        if(remm == 6){
            min_ans+=1;
        }

        cout<<min_ans<<" "<<max_ans<<endl;

    }

    return 0;
}