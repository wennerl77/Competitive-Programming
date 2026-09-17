#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAXN = 1e4+10;
const ll MOD = 1e9+7;
ll dp[MAXN];

ll fim (ll x) {
    if (x < 0) return 0;
    if (dp[x] != 0) return dp[x];
    
    dp[x] += 1 * fim(x - 1) + 4 * fim(x - 2) + 2 * fim(x - 3);

    dp[x] %= MOD;
    
    return dp[x];
}

int main () {
    dp[0] = dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;

    ll n;
    cin >> n;
    cout << fim(n);
    return 0;
}