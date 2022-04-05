vector<vector<int>> adj;
vector<bool> vis;
vector<int> sz, dad, lvl;
int size(int u, int p) {
    sz[u] = 1;
    for(int v: adj[u]) if(v != p && !vis[v]) sz[u] += size(v, u);
    return sz[u];
}
int centroid(int u, int p, int n){
    for(int v: adj[u]) if(v != p && sz[v] > n/2 && !vis[v]) return centroid(v, u, n);
    return u;
}
void build_centroid(int u, int p, int depth){
    int n = size(u, p);
    int c = centroid(u, p, n);
    lvl[c] = depth;
    dad[c] = p;
    vis[c] = 1;
    for(int v : adj[c]) if(!vis[v]) build_centroid(v, c, depth + 1);
}