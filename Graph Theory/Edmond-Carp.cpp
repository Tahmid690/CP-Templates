#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e18;

struct Edge {
    int v, rev, cap;
};

class MaxFlow {
    int n;
    vector<vector<Edge>> adj;
    vector<int> parent, parentEdge;

public:
    MaxFlow(int n): n(n), adj(n) {}

    void addEdge(int u, int v, int cap) {
        adj[u].push_back({v, (int)adj[v].size(), cap});
        adj[v].push_back({u, (int)adj[u].size() - 1, 0});
    }

    int bfs(int s, int t) {
        parent.assign(n, -1);
        parentEdge.assign(n, -1);
        queue<int> q;
        q.push(s);
        parent[s] = s;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < adj[u].size(); ++i) {
                Edge &e = adj[u][i];
                if (parent[e.v] == -1 && e.cap > 0) {
                    parent[e.v] = u;
                    parentEdge[e.v] = i;
                    if (e.v == t) return true;
                    q.push(e.v);
                }
            }
        }
        return false;
    }

    int edmondsKarp(int s, int t) {
        int maxFlow = 0;
        while (bfs(s, t)) {
            int flow = INF;
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                Edge &e = adj[u][parentEdge[v]];
                flow = min(flow, e.cap);
            }
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                Edge &e = adj[u][parentEdge[v]];
                e.cap -= flow;
                adj[e.v][e.rev].cap += flow;
            }
            maxFlow += flow;
        }
        return maxFlow;
    }
};

signed main() {
    int n,m;
    cin >> n >> m;
    MaxFlow mf(n+1);
    while(m--){
        int u,v,c;
        cin >> u >> v >> c;
        mf.addEdge(u,v,c);
    }
    cout << mf.edmondsKarp(1,n) << endl;

    

}
