#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
long long toNumber(string s, int start, int end) {
	long long num = 0;
	for (int i = start; i <= end; i++) {
		num = num * 10 + (s[i] - '0');
	}
	return num;
}
int main() {
	int M;
	cin >> M;
	while (M--) {
		int N, K;
		string s;
		cin >> N >> K >> s;
		vector<vector<long long>>dp(N + 1, vector<long long>(K + 1, 0));
		for (int i = 0; i <= N; i++) {
			dp[i][0] = toNumber(s, 0, i - 1);
		}
		for (int k = 1; k <= K; k++) {
			for (int i = k + 1; i <= N; i++) {
				for (int j = k; j < i; j++) {
					dp[i][k] = max(dp[i][k], dp[j][k - 1] * toNumber(s, j, i - 1));
				}
			}
		}
		cout << dp[N][K] << endl;
	}
	return 0;
}