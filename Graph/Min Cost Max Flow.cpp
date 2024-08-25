 
#include <ext/pb_ds/priority_queue.hpp> 
struct MCMF {
	struct edge {
		int from, to, rev;
		int cap, cost, flow;
	};
    
	int N;
	vector<vector<edge>> ed;
	vector<int> seen;
	vector<int> dist, pi;
	vector<edge*> par;
    const int oo = numeric_limits<int>::max() / 4;
 
	MCMF(int N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}
 
	void addEdge(int from, int to, int cap, int cost) {
		if (from == to) return;
		ed[from].push_back(edge{ from,to, (int) size(ed[to]),cap,cost,0 });
		ed[to].push_back(edge{ to,from, (int) size(ed[from])-1,0,-cost,0 });
	}
 
	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), oo);
		dist[s] = 0; int di;
 
		__gnu_pbds::priority_queue<pair<int, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({ 0, s });
 
		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (edge& e : ed[s]) if (!seen[e.to]) {
				int val = di - pi[e.to] + e.cost;
				if (e.cap - e.flow > 0 && val < dist[e.to]) {
					dist[e.to] = val;
					par[e.to] = &e;
					if (its[e.to] == q.end())
						its[e.to] = q.push({ -dist[e.to], e.to });
					else
						q.modify(its[e.to], { -dist[e.to], e.to });
				}
			}
		}
		for(int i = 0; i < N; i++) pi[i] = min(pi[i] + dist[i], oo);
	}
 
	pair<int, int> maxflow(int s, int t) {
		int totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			int fl = oo;
			for (edge* x = par[t]; x; x = par[x->from])
				fl = min(fl, x->cap - x->flow);
 
			totflow += fl;
			for (edge* x = par[t]; x; x = par[x->from]) {
				x->flow += fl;
				ed[x->to][x->rev].flow -= fl;
			}
		}
		for(int i = 0; i < N; i++) for(edge& e : ed[i]) totcost += e.cost * e.flow;
		return {totflow, totcost/2};
	}
 
	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), oo); pi[s] = 0;
		int it = N, ch = 1; int v;
		while (ch-- && it--)
			for(int i = 0; i < N; i++) if (pi[i] != oo)
			  for (edge& e : ed[i]) if (e.cap)
				  if ((v = pi[i] + e.cost) < pi[e.to])
					  pi[e.to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};