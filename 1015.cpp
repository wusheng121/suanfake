#include<iostream>
#include<vector>
using namespace std;
vector<int> v(1000000, 0);
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, h;
		cin >> a >> b >> h;
		for (int j = a; j < b; j++) {
			v[j] = max(v[j], h);
		}
	}
	if (v[0] != 0) {
		cout << 0 << " " << v[0] << endl;
	}
	for (int i = 1; i < 1000000; i++) {
		if (v[i] != v[i - 1]) {
			cout << i << " " << v[i] << endl;
		}
	}
}