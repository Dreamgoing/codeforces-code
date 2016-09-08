//
// Created by 王若璇 on 16/6/2.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const long long max_n = 100100;
long long a[max_n];

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    long long n, h, k;
    while (~scanf("%lld%lld%lld", &n, &h, &k)) {
        long long now = 0;
        long long ans = 0;
        for (long long i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        for (long long i = 0; i < n; i++) {
            //bool flag = false;
            while (now + a[i] <= h && i < n) {
                now += a[i];
                // flag = true;
                i++;
            }

            if (i < n) {
                long long tmp = (now + a[i] - h) / k;
                if ((now + a[i] - h) % k != 0) {
                    tmp++;
                }
                //cout<<"tmp "<<tmp<<" "<<now<<endl;
                now -= tmp * k;
                now = max(now, 0LL);
                ans += tmp;
                now += a[i];
                //cout<<now<<endl;
                //now-=k;


            }

            //cout<<now<<" *"<<endl;
            //ans++;

        }
        ans += now / k;
        if (now % k > 0) {
            ans++;
        }
        printf("%lld\n", ans);
        //cout<<'\n';
    }

    return 0;
}