const int maxn = 1e6;
vi prime(maxn + 1, 1), pr;
L(i, 2, maxn) {
    if(!prime[i]) continue;
    pr.push_back(i);
    for(int j = i + i; j <= maxn; j += i) {
        prime[j] = false;
    }
}

auto get_factors = [&](int x) {
    vi ps;
    for(int p: pr) {
        if(p * p > x) break;
        if(x % p == 0) ps.pb(p);
        while(x % p == 0) x /= p;
    }
    if(x > 1) ps.pb(x);
    return ps;
};