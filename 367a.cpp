//
// Created by 王若璇 on 16/8/12.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
int main(){
    double a,b;
    while (cin>>a>>b){
        int n;
        cin>>n;
        double res = 1e10;
        for(int i = 0;i<n;i++){
            double x,y,v;
            cin>>x>>y>>v;
            res = min(res,sqrt((x-a)*(x-a)+(y-b)*(y-b))/v);
        }
        printf("%.10lf\n",res);

    }
    return 0;
}
