#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
const int MAXN = 10001;

int main() {
	int m;
	cin >> m;
	while (m--) {
		int n;
		int ans = 0;
		cin >> n;
		vector<int>ones, zeros;
		for (int i = 0; i < 2 * n; i++) {
			int temp;
			cin >> temp;
			if(temp == 1)
				ones.push_back(i);
			else
				zeros.push_back(i);
		}
		for (int i = 0; i < n; i++) {
			ans += abs(ones[i] - zeros[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
