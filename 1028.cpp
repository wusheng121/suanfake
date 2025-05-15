#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
const int MAXN = 505;
int edges[MAXN][MAXN];

int solve(int n, int s, int t) {
    vector<int>dist(n + 1, INT_MAX);
    dist[s] = 0;
    vector<bool>visited(n + 1, false);
    for (int i = 0; i < n; i++) {
        int u = -1;
        int m = INT_MAX;
        for (int j = 1; j <= n; j++) {
            if (visited[j] == false && dist[j] < m) {
                m = dist[j];
                u = j;
            }
        }
        if (u == -1)
            break;
        else
            visited[u] = true;
        for (int v = 1; v <= n; v++) {
            if (visited[v] == false && edges[u][v] + dist[u] < dist[v] && edges[u][v] != INT_MAX) {
				dist[v] = edges[u][v] + dist[u];
            }
        }
    }
    return dist[t] == INT_MAX ? -1 : dist[t];
}
int main() {
    int m;
    cin >> m;
    while (m--) {
        int n, e, s, t;
        cin >> n >> e >> s >> t;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                edges[i][j] = INT_MAX;
            }
        }
        for (int i = 0; i < e; i++) {
			int start, end, value;
			cin >> start >> end >> value;
			edges[start][end] = min(edges[start][end], value);
            edges[end][start] = min(edges[end][start], value);
        }
		cout << solve(n, s, t) << endl;
    }
    return 0;
}
