
struct union_find {
	vector<int> p;
	union_find(int n): p(n) {
		iota(all(p), 0);
	};
	int find(int x) {
		if(x == p[x]) return x;
		p[x] = find(p[x]);
		return p[x];
	}
	void join(int a, int b) {
		a = find(a);
		b = find(b);
		if(a == b) return;
 
		if(rand() % 2) swap(a, b);
		p[a] = b;
	}
	bool same(int a, int b) {
		a = find(a);
		b = find(b);
		return a == b;
	}
};