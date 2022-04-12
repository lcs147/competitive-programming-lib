#include <bits/stdc++.h>
#define int long long
using namespace std;
template <class T> vector<T> create(size_t size, T initialValue) { return vector<T>(size, initialValue); }
template <class T, class... Args> auto create(size_t head, Args&&... tail) { auto inner = create<T>(tail...); return vector<decltype(inner)>(head, inner); }

void solve() {
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #define endl '\n'

    int t = 1;
    // cin >> t;
    while(t--)
        solve();

    return 0;
}