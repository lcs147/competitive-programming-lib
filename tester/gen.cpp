#include <bits/stdc++.h>
#define int long long
using namespace std;
int rand(int l, int r) {
    return l + rand() % (r - l + 1);
}
signed main(signed argc, char **argv){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #define endl '\n'

    srand(atoi(argv[1]));

    int n = rand(1, 5);
    cout << n << endl;
    for(int i = 0; i < n; i++) cout << rand(1, 10) << " ";
    cout << endl;

    int q = 1;
    cout << q << endl;
    while(q--) {
        int l = rand(1, n);
        int r = rand(l, n);
        cout << l << " " << r << endl;
    }

    return 0;
}