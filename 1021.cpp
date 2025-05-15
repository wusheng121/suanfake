#include<iostream>
#include<vector>
using namespace std;
vector<int>price(10001, 0);
int solve(vector<int>& price, int n) {
	//vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
	/*vector<int>price(n+1, 0);
	for (int i = 0; i < l.size(); i++) {
		if(l[i] <= n)
			price[l[i]] = p[i];
	}*/
	/*for (int length = 1; length <= n; length++) {
		for (int i = 0; i <= n -length + 1; i++) {
			int j = i + length - 1;
			dp[i][j] = price[length];
			for (int k = i; k <= j; k++) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	return dp[0][n-1];*/
	if (n == 0)
		return 0;
	vector<int>dp(n + 1, 0);
	for (int length = 1; length <= n; length++) {
		if (price[length] == 0)
			continue;
		for(int i = length; i <= n; i++) {
			dp[i] = max(dp[i], dp[i - length] + price[length]);
		}
	}
	return dp[n];
}
int main() {
	int m;
	cin >> m;
	while (m--) {
		int n, k;
		cin >> n >> k;
		/*vector<int>l(k), p(k);
		for (int i = 0; i < k; i++) {
			cin >> l[i] >> p[i];
		}*/
		int l, p;
		price.assign(n + 1, 0);
		for (int i = 0; i < k; i++) {
			cin >> l >> p;
			if (l <= n)
				price[l] = p;
		}
		cout << solve(price, n) << endl;
	}
	return 0;
}