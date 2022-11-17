/*
 * @author yuna
 * 2022-11-17 ���� ���� �ذ�
 * ���� ����: student ���� ����
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

    //�������� �л��� ������ ü������ ������ �ִ� ��찡 ����
    for (int i : lost) {
        student[i]--;
    }
    for (int i : reserve) {
        student[i]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (student[i] < 0) {   //ü������ ���� ���
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