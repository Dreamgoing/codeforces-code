#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while (cin>>n>>m){
        int l = 1,r = n;
        for(int i = 0;i<m;i++){
            int x,y;
            cin>>x>>y;
            l = max(l,min(x,y));
            r = min(r,max(x,y));
        }
        cout<<max(0,r-l)<<endl;
    }
    return 0;
}