#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int cdiv(int a, int b) { return a / b + ((a ^ b) > 0 && a % b); }
int fdiv(int a, int b) { return a / b - ((a ^ b) < 0 && a % b); }
bool ckmin(int& a, int b){ return b < a ? a = b, true : false; }
bool ckmax(int& a, int b){ return b > a ? a = b, true : false; }
auto vec(auto elem, size_t sz, auto... dim) {
    if constexpr (sizeof...(dim) == 0) return vector(sz, elem);
    else return vector(sz, vec(elem, dim...));
}

#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
 
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
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #define endl '\n'

    int t; cin >> t;
    while(t--) {

    }
    return 0;
}