#include<iostream>
#include<vector>
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
		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j < i+2; j++) {
				if (a[i] > a[j]) {
					swap(a[i], a[j]);
				}
			}
			/*for (int i = 0; i < n; i++) {
				cout << a[i] << ' ';
			}
			cout << endl;*/
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << endl;
	}
}