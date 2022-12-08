auto cmod = [&](int &x, int mod) {
    x = (x % mod + mod) % mod;
};