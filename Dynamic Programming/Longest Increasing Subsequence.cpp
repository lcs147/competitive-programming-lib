// use upper_bound for longest non-decreasing
// use lower_bound for longest increasing

// only size
auto lis = [](vector<int> &a) {
    vector<int> st;
    for(int x : a) {
        auto it = lower_bound(all(st), x);
        if(it == st.end()) st.push_back(x);
        else *it = x;
    }
    return st.size();
};


// elements part of lis
auto lis = [](vector<int> &a) {
    vector<int> st, dad(sz(a), -1), cur(sz(a), -1);
    L(i, 0, sz(a) - 1) {
        auto x = a[i];
        auto it = upper_bound(all(st), x);
        int id = it - st.begin();
        
        if(it == st.end()) st.push_back(x);
        else *it = x;
        cur[id] = i;

        if(id == 0) dad[i] = -1;
        else dad[i] = cur[id - 1];
    }

    vi res;
    int id = cur[sz(st) - 1];
    while(id != -1) {
        res.pb(id);
        id = dad[id];
    }
    reverse(all(res));

    return res;
};