#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a) {
	int n = a.size();
	int res = INT_MIN;
	/*vector<vector<int>>dp(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		dp[i][i] = a[i];
	}
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i < n - len + 1; i++) {
			int j = len + i - 1;
			dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j]);
		}
	}for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			res = max(res, dp[i][j]);
		}
	}*/
	int current = 0;
	for (int i = 0; i < n; i++) {
		current = max(a[i], current + a[i]);
		res = max(res, current);
	}
	return res;
}
int main() {
	int M;
	cin >> M;
	while (M--) {
		int n;
		int res = 0;
		cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		res = solve(a);
		cout << res << endl;
	}
	return 0;
}