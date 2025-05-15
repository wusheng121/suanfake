#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct activity {
    int start;
    int end;
    int value;
};

const int MAXN = 10001;
activity aa[MAXN];
int dp[MAXN];
int p[MAXN];

bool cmp(const activity& a, const activity& b) {
    return a.end < b.end;
}

int search(int n, int target) {
    int left = 1;
    int right = n;
    int res = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (aa[mid].end <= target) {
            left = mid + 1;
            res = mid;
        }
        else {
            right = mid - 1;
        }
    }
    return res;
}

int solve(int N) {
    sort(aa + 1, aa + N + 1, cmp);
    for (int i = 1; i <= N; i++) {
		p[i] = search(i - 1, aa[i].start);
    }
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        dp[i] = max(dp[i - 1], dp[p[i]] + aa[i].value);
    }
    return dp[N];
}


int main() {
    int m;
    cin >> m;
    while (m--) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> aa[i].start >> aa[i].end >> aa[i].value;
        }
        cout << solve(N) << endl;
    }
    return 0;
}
