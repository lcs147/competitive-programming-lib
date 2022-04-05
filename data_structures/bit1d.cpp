struct bit1d {
    vector<int> fenw;
    fenwick(int n){
        fenw.assign(n + 1, 0); // default value
    }
    int add(int a, int b) {
        return a + b;
    }
    void update(int l, int r, int v) {
        update(l, v);
        update(r + 1, -v);
    }
    void update(int x, int v) {
	    for(; x < fenw.size(); x |= (x + 1)) {
            fenw[x] = add(fenw[x], v);
        }
    }
    int query(int x) {  
        int sum = 0;
        for(; x >= 0; x = (x & (x + 1)) - 1) sum = add(sum, fenw[x]);
        return sum;
    }
};