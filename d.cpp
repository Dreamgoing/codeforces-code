//
// Created by 王若璇 on 16/8/25.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
ll a00,a01,a10,a11;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin>>a00>>a01>>a10>>a11){
        bool flag = false;
        ll num0 = (ll)sqrt(2*a00)+1;
        ll num1 = (ll)sqrt(2*a11)+1;
        if(num0*(num0-1)!=a00||num1*(num1-1)!=a11){
            flag = true;
        }
        if(!flag){

        }
    }
    return 0;
}