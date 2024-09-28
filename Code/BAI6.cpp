#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int MAXN = 1e6 + 6;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int BASE = 1e6;

int n, m, Hash[MAXN], pw[MAXN];
// n so phan tu cua mang A
// m so phan tu cua mang B
int a[MAXN], b[MAXN];

// ham tinh ma hash trong doan [L, R] cua mang A
int get(int l, int r) {
	return (Hash[r] - Hash[l - 1] * pw[r - l + 1] + MOD * MOD) % MOD;
}

void solve() {
	cin >> n >> m;

    int lim = max(n, m);
	pw[0] = 1;
	for (int i = 1; i <= lim; i++) pw[i] = pw[i - 1] * BASE % MOD;

    // nhap mang A
    for (int i = 1; i <= n; i++) cin >> a[i];

    // nhap mang B
    for (int i = 1; i <= m; i++) cin >> b[i];

    if (m > n) {
    // Neu do dai mang B > do dai mang A -> bo qua
        return;
    }

    // code la ma hash cua ca mang B
	int code = 0;
	for (int i = 1; i <= m; i++) code = (code * BASE + b[i]) % MOD;

    // Khoi tao mang Hash cho mang A
	for (int i = 1; i <= n; i++) Hash[i] = (Hash[i - 1] * BASE + a[i]) % MOD;
	
    // Tim cac vi tri 
	for (int i = m; i <= n; i++) if (get(i - m + 1, i) == code) cout << i - m + 1 << ' ';
}

#define TASK ""
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int ntest = 1;
    //cin >> ntest;
    while (ntest--) solve();

    return 0;
}
