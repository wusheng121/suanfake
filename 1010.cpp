#include<iostream>
#include<vector>
using namespace std;
void mid(vector<int>a, int x) {
	int n = a.size();
	int l = 0;
	int r = n - 1;
	int father = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] == x) {
			cout << "success, father is "<<father << endl;
			return;
		}
		else if (a[mid] < x) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
		father = a[mid];
		mid = (l + r) / 2;
	}
	cout << "not found, father is " << father << endl;
	return;
}
int main() {
	int M;
	cin >> M;
	while (M--) {
		int n, x;
		cin >> n >> x;
		vector<int>a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		mid(a, x);
	}
	return 0;
}