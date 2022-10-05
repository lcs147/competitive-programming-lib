
const int mod = 1e9 + 7;
struct mint {
    int val;
    mint(): val(0){}
    mint(int x){ x %= mod; if(x < 0) x += mod; val = x;}
    mint& operator += (mint oth){ val += oth.val; if(val >= mod) val -= mod; return *this; }
    mint& operator -= (mint oth){ val -= oth.val; if(val < 0) val += mod; return *this; }
    mint& operator *= (mint oth){ val = ((int)val) * oth.val % mod; return *this; }
    mint& operator /= (mint oth){ return *this *= oth.inverse(); }
    mint& operator ^= (int oth){ return *this = cpow(*this, oth); }
    mint operator + (mint oth) const { return mint(*this) += oth; }
    mint operator - (mint oth) const { return mint(*this) -= oth; }
    mint operator * (mint oth) const { return mint(*this) *= oth; }
    mint operator / (mint oth) const { return mint(*this) /= oth; }
    mint operator ^ (long long oth) const { return mint(*this) ^= oth; }
    bool operator < (mint oth) const { return val < oth.val; }
    bool operator > (mint oth) const { return val > oth.val; }
    bool operator <= (mint oth) const { return val <= oth.val; }
    bool operator >= (mint oth) const { return val >= oth.val; }
    bool operator == (mint oth) const { return val == oth.val; }
    bool operator != (mint oth) const { return val != oth.val; }
    mint cpow(mint a, int b) const { mint r = 1; for(; b; a *= a, b >>= 1) if(b&1) r *= a; return r; }
    mint inverse() const {
        int a = val, b = mod, u = 1, v = 0;
        while(b){
            int t = a/b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        if(u < 0)
            u += mod;
        return u;
    }
};
mint mintobj;