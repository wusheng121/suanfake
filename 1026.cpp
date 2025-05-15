#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 21;
long long dp[MAXN][MAXN];
int nums[MAXN];
long long solve(int N, int K) {
	long long sum[MAXN] = { 0 };
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + nums[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= min(i - 1, K); j++) {
			if (j == 0) {
				dp[i][0] = sum[i];
			}
			else {
				for (int k = j; k <= i; k++) {
					long long temp = sum[i] - sum[k - 1];
					if (k - 1 >= j - 1) {
						dp[i][j] = max(dp[i][j], dp[k - 1][j - 1] * temp);
					}
				}
			}
		}
	}
	return dp[N][K];
}
int main() {
	int m;
	cin >> m;
	while (m--) {
		int N, K;
		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			cin >> nums[i];
		}
		memset(dp, 0, sizeof(dp));
		cout << solve(N, K) << endl;
	}
	return 0;
}