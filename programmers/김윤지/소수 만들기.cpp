#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = -1;
    vector<int> sums;
    
    for (int i = 0; i < nums.size(); i++)
        for (int j = i + 1; j < nums.size(); j++)
            for (int k = j + 1; k < nums.size(); k++) {
                int sum = nums[i] + nums[j] + nums[k];
                sums.push_back(sum);
            }
    
    for (int i = 0; i < sums.size(); i++)
        for (int j = 2; j < sums[i]; j++)
            if (sums[i] % j == 0) {
                sums.erase(sums.begin() + i);
                i--;
            }

    answer = sums.size();
    return answer;
}