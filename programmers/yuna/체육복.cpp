#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool positive(int i) {
    return i >= 0;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n, 0);

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.begin());

    //도난당한 학생이 여벌의 체육복을 가지고 있는 경우가 있음
    for (int i : lost) {
        student[i]--;
    }
    for (int i : reserve) {
        student[i]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (student[i] < 0) {   //체육복이 없는 경우
            if (i != 0 && student[i - 1] == 1) {
                student[i]++;
                student[i - 1]--;
            }
            else if (i != n-1 && student[i+1] == 1) {
                student[i]++;
                student[i + 1]--;
            }
        }
        
    }

    answer = count_if(student.begin(), student.end(), positive);

    return answer;
}