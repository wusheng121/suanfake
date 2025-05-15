#include<iostream>
#include<vector>
using namespace std;
//vector<vector<int>>dp(505, vector<int>(105, 0));
void bag(vector<int>& s,vector<int>& v,int n,int c) {
	//int n = s.size();
	int size = 0, value = 0;
	//for (int i = 0; i <= c; i++) {
	//	dp[0][i] = 0;
	//	//dp[i][0] = 0;
	//}
	vector<vector<int>>dp(n + 1, vector<int>(c + 1, -1));//-1标志对应的容量大小未装满
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= c; j++) {
			dp[i][j] = dp[i - 1][j];
			if (s[i-1] <= j && dp[i-1][j - s[i-1]] != -1) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - s[i-1]] + v[i-1]);
			}
		}
	}
	if (dp[n][c] != -1) {
		cout << dp[n][c] << endl;
	}
	else {
		cout << 0 << endl;
	}
}
int main() {
	int m;
	cin >> m;
	while (m--) {
		int n, c;
		cin >> n >> c;
		vector<int>s(n);
		vector<int>v(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i] >> v[i];
		}
		bag(s, v, n, c);
	}
	return 0;
}