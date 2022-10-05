int inv(int a, int m) {
	if (a == 1) return 1;
	return inv(m % a, m) * (m - m / a) % m;
}

vector<int> fat(1, 1), ifat(1, 1);
int C(int n, int k) {
    if(k > n || k < 0) return 0;
    while(n > fat.size() - 1) {
        fat.push_back(fat.back() * fat.size() % mod);
        ifat.push_back(inv(fat.back(), mod));
    }
    return fat[n] * ifat[k] % mod * ifat[n - k] % mod;
}