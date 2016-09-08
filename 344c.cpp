#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 200100;

int a[N];
int t[N], r[N];
vector <int> u, v, ans;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= m; i ++) {
        scanf("%d %d", t + i, r + i);
    }
    int f = 0;
    for (int i = m; i; i --) {
        if (r[i] > f) {
            u.push_back(t[i]);
            v.push_back(r[i]);
            f = r[i];
        }
    }
    reverse(u.begin(), u.end());
    reverse(v.begin(), v.end());
    for (int i = n - 1; i >= v[0]; i --)
        ans.push_back(a[i]);
    sort(a, a + v[0]);
    int l = 0, r = v[0] - 1;
    v.push_back(0);
    for (int i = 0; i < v.size(); i ++) {
        int cnt = v[i] - v[i + 1];
        for (int j = 0; j < cnt; j ++) {
            if (u[i] == 1) ans.push_back(a[r--]);
            else ans.push_back(a[l++]);
        }
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans)
        printf("%d ", x);
    puts("");
    return 0;
}