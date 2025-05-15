#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool panduan(vector<int>& a,int begin,int end) {
	for (int i = begin + 1; i < end; i++) {
		if (a[i] < a[i - 1]) {
			return false;
		}
	}
	return true;
}
int largest(vector<int>& a) {
	//int m = 1;
	//int n = a.size();
	//vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
	//for (int len = 1; len <= n; len++) {
	//	for (int i = 0; i < n - len + 1; i++) {
	//		int j = i + len - 1;
	//		/*if (panduan(a, i, j)) {
	//			dp[i][j] = len;
	//		}
	//		else {
	//			dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
	//		}*/
	//		if (a[j] >= a[j - 1]) {
	//			dp[i][j] = dp[i][j - 1] + 1;
	//		}
	//		else {
	//			dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
	//		}
	//	}
	//}
	//return dp[0][n - 1];
	vector<int>tail;
	for (int num : a) {
		auto it = upper_bound(tail.begin(), tail.end(), num);
		if (it == tail.end()) {
			tail.push_back(num);
		}
		else {
			*it = num;
		}
	}
	return tail.size();
}
int main() {
	int m;
	cin >> m;
	while (m--) {
		int n;
		cin >> n;
		vector<int>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << largest(a) << endl;
	}
}