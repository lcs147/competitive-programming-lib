#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, m; cin >> n >> m;

    map<int, set<int>> s;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            s[i + j].insert(j - i + n);
        }
    }
    for(auto &l : s) {
        cout << "line " << l.first << " : ";
        for(int c : l.second) {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}