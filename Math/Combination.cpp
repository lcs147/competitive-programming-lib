
const int mod = 1e9 + 7;
int inv(int a, const int m = mod) {
	if (a == 1) return 1;
	return inv(m % a, m) * (m - m / a) % m;
}
vi fat, ifat;
void init(int maxn) {
    fat.assign(maxn + 1, 1);
    ifat.assign(maxn + 1, 1);
    L(i, 1, maxn) fat[i] = fat[i - 1] * i % mod;
    ifat[maxn] = inv(fat[maxn]);
    R(i, maxn, 1) ifat[i - 1] = ifat[i] * i % mod;
}
int C(int n, int k) {
    if(k > n || k < 0) return 0;
    assert(n < sz(fat));
    return fat[n] * ifat[k] % mod * ifat[n - k] % mod;
}