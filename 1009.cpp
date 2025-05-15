#include<iostream>
#include<vector>
using namespace std;
int maxest(vector<int>& a) {
	vector<int>b;
	for (int x : a) {
		b.push_back(-x);
	}
	vector<int>dp;
	for (int x : b) {
		auto it = lower_bound(dp.begin(), dp.end(), x);
		if (it == dp.end()) {
			dp.push_back(x);
		}
		else {
			*it = x;
		}
	}
	return dp.size();
}
int main() {
	int M;
	cin >> M;
	while (M--) {
		int N;
		cin >> N;
		vector<int>a(N);
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		int max = maxest(a);
		cout << max << endl;
	}
}