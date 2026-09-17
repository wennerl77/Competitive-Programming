// https://neps.academy/br/exercise/1086

#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<vector<pair<int, int>>> v(n);

    for (int i = 0; i < n; i++) {
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;

        v[i].push_back({a, f});
        v[i].push_back({b, d});
        v[i].push_back({c, e});
    }

    int ans = INT_MIN;

    for (int esc = 1; esc <= 6; esc++) {
        int atual = esc;
        int somaAtual = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (v[i][j].first == atual || v[i][j].second == atual) {
                    atual = atual ^ v[i][j].first ^ v[i][j].second;
                    if (v[i][j].first != 6 && v[i][j].second != 6) somaAtual += 6;
                    else if (v[i][j].first != 5 && v[i][j].second != 5) somaAtual += 5;
                    else somaAtual += 4;
                }
            }
        }

        ans = max (ans, somaAtual);
    }

    cout << ans;


    return 0;
}