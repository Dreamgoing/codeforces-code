//
// Created by 王若璇 on 16/3/31.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int max_n = 1010;
const int di[4] = {1,2,3,4};
struct Point{
    int x,y;
}p[max_n];
vector<Point> v;
int getDir(Point a,Point b){
    int x,y;
    x = b.x-a.x;
    y = b.y-a.y;
    if(x==0&&y>0){
        return 1;
    } else if(x==0&&y<0){
        return 3;
    } else if(y==0&&x>0){
        return 2;
    } else if(y==0&&x<0){
        return 4;
    }
    return 0;
}
int getDid(int d){
    for(int i = 0;i<4;i++){
        if(di[i]==d){
            return i;
        }
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin>>n){
        for(int i = 0;i<=n;i++){
            cin>>p[i].x>>p[i].y;
        }
        int pos = 0;
        int nowd = di[0];
        int nowsea = di[1];
        Point tmp = p[0];
        int tmpd = 0;
        int ans = 0;
        for(int i = 2;i<=n;i++){
            tmpd = getDir(p[i-1],p[i]);
            //cout<<"x "<<p[i-1].x<<" y "<<p[i-1].y<<endl;
            //cout<<tmpd<<" * "<<nowsea;
            if(tmpd!=nowsea){
                ans++;
              //  cout<<" true ";
            }
            nowsea = di[(getDid(tmpd)+1)%4];
            //cout<<" "<<nowsea<<endl;

        }
        cout<<ans<<endl;

    }

    return 0;
}

