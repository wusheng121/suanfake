#include <iostream>
#include <vector>
#include<string>
using namespace std;
int longest(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>>dp(n1, vector<int>(n2, 0));
    if (s1[0] == s2[0]) {
        dp[0][0] = 1;
    }
    for (int i = 1; i < n1; i++) {
		if (s1[i] == s2[0]) {
			dp[i][0] = 1;
		}
		else {
			dp[i][0] = dp[i - 1][0];
		}
    }
	for (int j = 1; j < n2; j++) {
		if (s1[0] == s2[j]) {
			dp[0][j] = 1;
		}
		else {
			dp[0][j] = dp[0][j - 1];
		}
	}
    for (int i = 1; i < n1; i++) {
        for(int j = 1; j < n2; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n1 - 1][n2 - 1];
}
int main() {
    int M;
    cin >> M;
    while (M--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << longest(s1, s2) << endl;
    }
    return 0;
}
