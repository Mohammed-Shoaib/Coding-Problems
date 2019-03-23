#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector< vector<bool> > graph(vector< pair<string, string> > &adj) {
    string student, course;
    map<string, int> courses;
    map<string, vector<string> > students;
    
    sort(adj.begin(), adj.end(), [](pair<string, string> l, pair<string, string> r) {
        return l.second < r.second;
    });
    
    for (int i = 0, j = 0; i < adj.size(); i++) {
        student = adj[i].first;
        course = adj[i].second;
        students[student].push_back(course);
        if (courses.find(course) == courses.end()) {
            courses[course] = j;
            j++;
        }
    }
    
    vector< vector<bool> > matrix(courses.size(), vector<bool>(courses.size()));
    
    for (auto student: students) {
        for (int i = 0; i < student.second.size() - 1; i++)
            for (int j = i + 1; j < student.second.size(); j++) {
                matrix[courses[student.second[i]]][courses[student.second[j]]] = true;
                matrix[courses[student.second[j]]][courses[student.second[i]]] = true;
            }
    }
    return matrix;
}

int main() {
    freopen("graph.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    int P;
    while (cin >> P && P) {
        vector< pair<string, string> > adj(P);
        vector< vector<bool> > matrix;
        for (int i = 0; i < P; i++)
            cin >> adj[i].first >> adj[i].second;
        matrix = graph(adj);
        for (int j, i = 0; i < matrix.size(); i++) {
            for (j = 0; j < matrix[i].size() - 1; j++)
                cout << matrix[i][j] << " ";
            cout << matrix[i][j] << endl;
        }
        cout << endl;
    }
    
    return 0;
}
