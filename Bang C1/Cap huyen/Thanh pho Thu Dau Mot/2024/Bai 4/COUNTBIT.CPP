#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxn = 1e5 + 5;

int n, a[maxn];

bool getBit(ll x, int k){
    return x & (1ll << k);
}

void solve(){
    int k = 0;
    for(int i = 1; i <= n; ++i)
        k ^= a[i];

    cout << __builtin_popcount(k);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    solve();

    return 0;
}
