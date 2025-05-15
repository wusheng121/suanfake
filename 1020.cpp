#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int matrixChainOrder(const vector<int>& dims, int N) {
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int l = 2; l <= N; l++) {
        for (int i = 0; i < N - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + dims[i] * dims[k + 1] * dims[j + 1];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }
    return dp[0][N - 1];
}

int main() {
    int M;
    cin >> M;  
    while (M--) {
        int N;
        cin >> N;  
        vector<int> dims(N + 1);
        for (int i = 0; i < N; i++) {
            int r, c;
            cin >> r >> c;
            if (i == 0) dims[i] = r;
            dims[i + 1] = c;
        }

        cout << matrixChainOrder(dims, N) << endl;
    }
    return 0;
}
