#include<bits/stdc++.h>

#define MAXN 1001
using namespace std;

int n;
int a[MAXN];

int dp[MAXN][100 * MAXN];

int f(int i, int M) {
    if (i == n + 1 && M == 0) return 1;
    if (i == n + 1 && M != 0) return 0;
    if (dp[i][M] != -1) return dp[i][M];
    if (M >= a[i]) return dp[i][M] = (f(i + 1, M) | f(i + 1, M - a[i]));
    else return dp[i][M] = f(i + 1, M);
}

int main() {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < 100 * MAXN; ++j) {
            dp[i][j] = -1;
        }
    }
    if (f(0, sum / 2) == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
