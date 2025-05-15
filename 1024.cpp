#include<iostream>
#include<vector>
#include<limits>
#include<iomanip>
using namespace std;

const int MAXN = 505;
double e[MAXN][MAXN];
double w[MAXN][MAXN];
int main() {
	int m;
	cin >> m;
	while (m--) {
		int n;
		cin >> n;
		vector<int>value(n);
		for (int i = 0; i < n; i++) {
			cin >> value[i];
		}
		vector<double>p(n + 1), q(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> p[i];
		}
		for (int i = 0; i <= n; i++) {
			cin >> q[i];
		}
		for (int i = 1; i <= n+1; i++) {
			e[i][i - 1] = 0;
			w[i][i - 1] = q[i - 1];
		}
		for (int length = 1; length <= n; length++) {
			for (int i = 1; i <= n - length + 1; i++) {
				int j = i + length - 1;
				e[i][j] = TMP_MAX;
				w[i][j] = w[i][j - 1] + p[j] + q[j];
				for (int r = i; r <= j; r++) {
					double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
					e[i][j] = min(e[i][j], t);
					//cout << i<<' '<<j<<' '<<e[i][j]<<w[i][j]<< endl;
				}
			}
		}
		cout << fixed << setprecision(6) << e[1][n] << endl;
	}
	return 0;
}