/*
 * @author yuna
 * 2022-11-17 문제 오답 해결
 * 오답 원인: student 범위 문제
 */

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool positive(int i) {
    return i >= 0;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n + 2, 0);

    //도난당한 학생이 여벌의 체육복을 가지고 있는 경우가 있음
    for (int i : lost) {
        student[i]--;
    }
    for (int i : reserve) {
        student[i]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (student[i] < 0) {   //체육복이 없는 경우
            if (student[i - 1] == 1) {
                student[i]++;
                student[i - 1]--;
            }
            else if (student[i + 1] == 1) {
                student[i]++;
                student[i + 1]--;
            }
        }

    }

    answer = count_if(student.begin() + 1, student.end() - 1, positive);

    return answer;
}