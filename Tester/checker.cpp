#include <bits/stdc++.h>
#define int long long
using namespace std;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

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
#include "../../cp-lib/helpers/debug.cpp"
#else
#define debug(...)
#endif


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    #define endl '\n'
    
    int n, x; cin >> n >> x;
    vi a(n);
    for(int &x: a) cin >> x;

    vi ret(n);
    for(int &x: ret) cin >> x;
    
    L(i, 0, sz(ret) - 2) {
        if(ret[i] + ret[i + 1] == x) {
            cout << "bad" << endl;
            return 1;
        }
    }
 
    return 0;
}