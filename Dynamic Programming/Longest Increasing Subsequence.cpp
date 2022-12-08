// use upper_bound for longest non-decreasing
auto lis = [](vector<int> &a) {
    vector<int> st;
    for(int x : a) {
        auto it = lower_bound(all(st), x);
        if(it == st.end()) st.push_back(x);
        else *it = x;
    }
    return st.size();
};