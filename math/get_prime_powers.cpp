auto get_pots = [&](int x) {
    vector<pair<int, int>> res;
    while(x > 1) {
        int p = lp[x];
        int cnt = 0;
        while(x % p == 0) {
            cnt++;
            x /= p;
        }
        res.emplace_back(p, cnt);
    }
    return res;
};