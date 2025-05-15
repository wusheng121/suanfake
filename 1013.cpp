#include<iostream>
#include<vector>
using namespace std;
//int temp[50010];
int solve(vector<int>&a,int l,int r) {
	if (l >= r) return 0;
	int n = a.size();
	vector<int>temp(n);
	int res = 0;
	int mid = (l + r) / 2;
	res = solve(a, l, mid) + solve(a, mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
			res += mid - i + 1;
		}
	}
	while (i <= mid) {
		temp[k++] = a[i++];
	}
	while (j <= r) {
		temp[k++] = a[j++];
	}
	for (int i = l,j = 0; i <= r; i++,j++) {
		a[i] = temp[j];
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
		res = solve(a, 0, n - 1);
		cout << res << endl;
	}
	return 0;
}