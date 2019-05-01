/*
Problem Statement: https://www.hackerrank.com/challenges/classes-objects/problem
*/

class Student {
private:
    vector<int> scores = vector<int>(5);
public:
    void input() {
        for (int i = 0; i < scores.size(); i++)
            cin >> scores[i];
    }

    int calculateTotalScore() {
        int sum = 0;
        for (int score: scores)
            sum += score;
        return sum;
    }
};