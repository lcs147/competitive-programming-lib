// A Gray code is a list of all 2n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
// Your task is to create a Gray code for a given length n.
// 1 ≤ n ≤ 16

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #define endl '\n'

    int n; cin >> n;

    auto expand = [&](vector<string> &v, string x) {
        for(auto &s : v) {
            s = x + s;
        }
        return v;
    };
    auto f = [&](auto self, int x) -> vector<string> {
        if(x == 1) return {"0", "1"};
        
        auto left = self(self, x - 1);
        auto right = left;
        reverse(all(right));

        auto res = expand(left, "0");
        auto tmp = expand(right, "1");
        
        res.insert(res.end(), all(tmp));
        return res;
    };
    auto res = f(f, n);
    for(string &s : res) cout << s << endl;

    return 0;
}