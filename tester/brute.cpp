#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #define endl '\n'

    int n; cin >> n;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        int res = r - l + 1;
        for(int i = l; i <= r; i++) {
            int cnt = 0;
            for(int j = l; j <= r; j++) {
                if(i == j) continue;
                if(a[j] % a[i] == 0) cnt++;
            }
            res -= (cnt == r - l);
        }
        cout << res << endl;
    }

    return 0;
}