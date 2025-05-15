#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
const int MAXN = 505;
int edges[MAXN][MAXN];
int solve(int n) {
	vector<bool>visited(n + 1, false);
	int ans = 0;
	visited[1] = true;
	for (int i = 0; i < n; i++) {
		int m = INT_MAX;
		int u = -1;
		int v = -1;
		for (int j = 1; j <= n; j++) {
			if (visited[j] == true) {
				for (int k = 1; k <= n; k++) {
					if (visited[k] == false && edges[j][k] < m) {
						m = edges[j][k];
						u = j;
						v = k;
					}
				}
			}
		}
		if (u == -1 || v == -1)
			break;
		else{
			ans += m;
			visited[v] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false)
			return -1;
	}
	return ans;
}
int main() {
    int m;
    cin >> m;
    while (m--) {
        int n, e;
        cin >> n >> e;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				edges[i][j] = INT_MAX;
			}
		}
        for (int i = 0; i < e; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			edges[u][v] = min(edges[u][v], w);
			edges[v][u] = min(edges[v][u], w);
        }
		cout << solve(n) << endl;
    }
    return 0;
}
