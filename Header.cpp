#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
int cdiv(int a, int b) { return a / b + ((a ^ b) > 0 && a % b); }
int fdiv(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }
bool ckmin(auto& a, auto b){ return b < a ? a = b, true : false; }
bool ckmax(auto& a, auto b){ return b > a ? a = b, true : false; }
auto vec(auto elem, size_t sz, auto... dim) {
    if constexpr (sizeof...(dim) == 0) return vector(sz, elem);
    else return vector(sz, vec(elem, dim...));
}
 
const auto ES = "", SEP = " ";
template<class T> auto &operator>>(istream& is, vector<T> &c) { for (auto &x : c) is >> x; return is; }
template<class T> auto &operator<<(ostream& os, vector<T> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
template<class T> auto &operator<<(ostream& os, set<T> const &c) { auto sep = ES; for (auto x : c) os << sep << x, sep = SEP; return os; }
 
template<class... A> void in(A &...a) { ((cin >> a), ...); }
template<class... A> void print(A const&... a) { ((cout << a), ...); }
template<class... A> void out(A const&... a) { auto sep = ES; ((cout << sep << a, sep = SEP), ...); cout << '\n'; }
 
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
 
#define cond(c, t, f) ((c) ? (t) : (f))
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define sz(a) ((int) (a).size())
#define pb emplace_back
#define vi vector <int>
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
 
using db = long double;
using pii = pair<int, int>;
 
#ifdef LOCAL
#include "../cp-lib/helpers/debug.cpp"
#else
#define debug(...)
#endif
 
void solve() {
    
}
 
signed main() {
    fastio;
 
    int t = 1;
    // in(t);
    L(i, 0, t - 1) solve();
    
    return 0;
}