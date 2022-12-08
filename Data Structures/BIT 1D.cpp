
struct bit1d {
    vector<int> fenw;
    bit1d(int n){
        fenw.assign(n + 1, 0); // default value
    }
    int add(int a, int b) {
        return a + b;
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
    
    void update(int l, int r, int v) { // se usar esse n usa o debaixo
        update(l, v);
        update(r + 1, -v);
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

// range update -> adiciona na struct, so da se, op([l,r]) == op(l,n) - op(r+1,n)
// faz update em um indice e retorna a soma do prefixo escolhido em log
// range query (a, b), point update(x, +1)
// bit.query(b) - bit.query(a-1);
// bit.update(x, +1);