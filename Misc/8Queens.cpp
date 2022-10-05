// Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.
// How many possible ways are there to place the queens?
// Input:
// ........
// ........
// ..*.....
// ........
// ........
// .....**.
// ...*....
// ........

// Output:
// 65

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #define endl '\n'

    vector<string> tab(8);
    for(string &s : tab) cin >> s;

    vector<bool> hl(8), hc(8), hdp(16), hds(16);
    auto upt = [&](int l, int c, bool val) {
        hl[l] = hc[c] = val;
        hdp[c - l + 8] = val;
        hds[c + l] = val;
    };
    auto check = [&](int l, int c) {
        return hl[l] || hc[c] || hds[c + l] || hdp[c - l + 8] || tab[l][c] == '*';
    };

    auto solve = [&](auto self, int l, int c, int cnt) {
        if(c == 8) c = 0, l++;
        
        if(cnt == 0) return 1ll;
        if(l == 8) return 0ll;

        int res = self(self, l, c + 1, cnt);

        if(!check(l, c)) {
            upt(l, c, 1);
            res += self(self, l, c + 1, cnt - 1);
            upt(l, c, 0);
        }

        return res;
    };

    int res = solve(solve, 0, 0, 8);
    cout << res << endl;
    return 0;
}