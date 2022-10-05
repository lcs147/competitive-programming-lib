// The Tower of Hanoi game consists of three stacks (left, middle and right) and n round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom.
// The goal is to move all the disks to the right stack using the middle stack. On each move you can move the uppermost disk from a stack to another stack. In addition, it is not allowed to place a larger disk on a smaller disk.
// Your task is to find a solution that minimizes the number of moves.
// 1 ≤ n ≤ 16

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;

vector<pair<char, char>> operator + (const vector<pair<char, char>> a, const vector<pair<char, char>> b) {
    vector<pair<char, char>> res = a;
    res.insert(res.end(), all(b));
    return res;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #define endl '\n'

    int n; cin >> n;

    auto f = [&](auto self, int x, char bg, char en, char md) -> vector<pair<char, char>> {
        if(x == 1) return {{bg, en}};
        if(x == 2) return {{bg, md}, {bg, en}, {md, en}};
        auto step1 = self(self, x - 1, bg, md, en);
        vector<pair<char, char>> step2 = {{bg, en}};
        auto step3 = self(self, x - 1, md, en, bg);
        return step1 + step2 + step3;
    };

    auto res = f(f, n, '1', '3', '2');
    cout << res.size() << endl;
    for(auto [a, b] : res) cout << a << " " << b << endl;

    return 0;
}