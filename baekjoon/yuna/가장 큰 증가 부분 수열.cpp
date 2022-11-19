#include <iostream>
using namespace std;

int main() {
	int n, res = 0;
	int a[1001] = { 0 };
	int dp[1001] = { 0 };

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && dp[i] < dp[j] + a[i]) {
				dp[i] = dp[j] + a[i];
			}
		}
		res = max(dp[i], res);
	}

	cout << res << endl;

	return 0;
}