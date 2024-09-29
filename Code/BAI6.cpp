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

    // code la ma hash cua ca mang A
	int code = 0;
	for (int i = 1; i <= n; i++) code = (code * BASE + a[i] + MOD * MOD) % MOD;

    // Khoi tao mang Hash cho mang B
	for (int i = 1; i <= m; i++) Hash[i] = (Hash[i - 1] * BASE + b[i]) % MOD;

    // Tim cac vi tri 
    vector<int> pos;
	for (int i = n; i <= m; i++) if (get(i - n + 1, i) == code) {
        pos.push_back(i - n + 1);
    }

    cout << pos.size() << '\n';

    for (int x : pos) cout << x << ' ';
}

#define TASK ""
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int ntest = 1;
    //cin >> ntest;
    while (ntest--) solve();

    return 0;
}
