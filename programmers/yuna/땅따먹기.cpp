#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int dp[100001][4] = { 0 };

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for (int i = 0; i < land[0].size(); i++) {
        dp[0][i] = land[0][i];
    }

    for (int i = 1; i < land.size(); i++) {
        for (int j = 0; j < 4; j++) {
            int max_index = 0;
            int max = 0;
            for (int k = 0; k < 4; k++) {
                if (j != k && dp[i - 1][k] > max) {
                    max = dp[i - 1][k];
                    max_index = k;
                }
            }
            dp[i][j] = dp[i - 1][max_index] + land[i][j];
            if (dp[i][j] > answer) {
                answer = dp[i][j];
                //cout << i << " : " << j << " = " << answer << endl;
            }
        }
    }

    return answer;
}