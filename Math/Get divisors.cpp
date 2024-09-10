
auto get_divs = [](int x) {
    vector<int> divs;
    for(int d = 1; d * d <= x; d++) {
        if(x % d == 0) {
            divs.push_back(d);
            if(d != x / d) divs.push_back(x / d);
        }
    }
    return divs;
};

