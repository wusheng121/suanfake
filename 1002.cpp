#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
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
		sort(a.begin(), a.end());
		cout << a[1] << endl;
	}
}