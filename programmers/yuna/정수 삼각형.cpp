#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[501][501] = { 0 };
    /*
    * // 정확성 테스트는 통과했으나, 효율성 테스트는 통과하지 못함
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            int max = 0;
            int max_index = 0;
            for (int k = 0; k < triangle[i - 1].size(); k++) {
                if ((j == k || j == k + 1) && dp[i - 1][k] > max) {
                    max = dp[i - 1][k];
                    max_index = k;
                }
            }
            dp[i][j] = dp[i - 1][max_index] + triangle[i][j];
            if (dp[i][j] > answer) {
                answer = dp[i][j];
            }
        }
    }
    */

    // 효율성 테스트 통과한 풀이
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); i++) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j < triangle[i].size(); j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            //printf("%d : %d = %d\n", i, j, dp[i][j]);
            answer = max(dp[i][j], answer);
        }
    }
    
    return answer;
}