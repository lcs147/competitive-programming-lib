
// update
map<int, int> conv;
auto compress = [&]() {
	int cnt = 0;
	for(auto &[l, r, id] : rng) conv[l], conv[r];
	for(auto &x : conv) x.second = cnt++;
	for(auto &[l, r, id] : rng) l = conv[l], r = conv[r];
};
//original value of a[i] can be obtained through conv[a[i]]

// v2 -> faster
vector<int> d = a;
sort(d.begin(), d.end());
d.resize(unique(d.begin(), d.end()) - d.begin());
for (int i = 0; i < n; ++i) {
  a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
}
//original value of a[i] can be obtained through d[a[i]]
//can use map instead of lowerbound if annoying -> to implement eventually


// v3 -> faster, but no obvious reverse
int compress(auto &a) {
    int n = a.size();
    vector<pair<int, int>> pairs(n);
    for(int i = 0; i < n; ++i) {
        pairs[i] = {a[i], i};
    }
    sort(pairs.begin(), pairs.end());
    int nxt = 0;
    for(int i = 0; i < n; ++i) {
        if(i > 0 && pairs[i-1].first != pairs[i].first) nxt++;
        a[pairs[i].second] = nxt;
    }
    return nxt;
}