#include<iostream>
#include<vector>
using namespace std;
int maxest(vector<int>& a) {
	vector<int>dp;
	vector<int>b;
	for (int x : a) {
		b.push_back(-x);
	}
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
int result(vector<int>& a) {
	int n = a.size();
	//int current = a[0];
	vector<int>systems;
	for (int i = 0; i < n; i++) {
		bool flag = false;
		
		for (int j = 0; j < systems.size(); j++) {
			if (a[i] <= systems[j]) {
				systems[j] = a[i];
				flag = true;
				break;
			}
		}
		if (!flag) {
			systems.push_back(a[i]);
		}
	}
	return systems.size();
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
		int res = result(a);
		cout << max << ' ' << res << endl;
	}
}