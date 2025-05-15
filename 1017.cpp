#include<iostream>
#include<vector>
using namespace std;
int temp[50010];
int merge(vector<int>& a, int l, int r) {
	int res = 0;
	if (l >= r) {
		return res;
	}
	int n = a.size();
	int mid = (l + r) >> 1;
	
	res += merge(a, l, mid) + merge(a, mid + 1, r);
	int i = l, k = 0, j = mid + 1;
	while (i <= mid && j <= r) {
		if (a[i] > a[j]) {
			temp[k++] = a[j++];
			res += mid - i + 1;
		}
		else {
			temp[k++] = a[i++];
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= r) {
		temp[k++] = a[j++];
	}
	for (int i = 0, j = l; i < k; i++, j++) {
		a[j] = temp[i];
	}
	return res;
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
		int res = merge(a, 0, n - 1);
		cout << res << endl;
	}
}