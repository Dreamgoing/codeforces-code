//
// Created by 王若璇 on 16/5/5.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const double pi = acos(-1.);
const int uplimit = 1000;
const double eps = 1e-6;
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int d,h,v,e;
    while (cin>>d>>h>>v>>e){
        double t = 1.*h/(v/(pi*d*d/4)-e);
        if(e>1.*v/(pi*d*d/4)){
            cout<<"NO"<<endl;
        } else{
            cout<<"YES"<<endl;
            printf("%.12lf\n",t);

        }
    }


    return 0;
}