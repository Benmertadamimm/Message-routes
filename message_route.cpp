#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"
#define ci const int
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ci MAXN = 1e5;
vector<int> adj[MAXN + 1];
vector<int> parent(MAXN + 1, -1);
vector<int> dist(MAXN + 1, -1);

int32_t main() {
    fast();
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    queue<int> q;
    q.push(1);
    dist[1] = 1;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << dist[n] << endl;
    vector<int> path;
    int cur = n;
    while (cur != -1) {
        path.pb(cur);
        cur = parent[cur];
    }
    reverse(path.begin(), path.end());

    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}
