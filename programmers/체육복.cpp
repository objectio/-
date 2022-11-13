#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++) 
        {
            if (lost[i] == reserve[j])
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--;
            }
        }
    }
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (int j = 0; j < reserve.size(); j++)
    {
        for (int i = 0; i < lost.size(); i++)
        {
            if (lost[i] == reserve[j] - 1 || lost[i] == reserve[j] + 1)
            {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                j--;
            }
        }
    }
    
    answer = n - lost.size();
    
    return answer;
}