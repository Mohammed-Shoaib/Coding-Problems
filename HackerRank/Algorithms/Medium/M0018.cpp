/*
Problem Code: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float median(int d, vector<int> &freq) {
	int m, n, i, count;
	m = count = 0;
	for (i = 0; count < d / 2 + 1; i++) {
		count += freq[i];
		if (!m && count >= d / 2)
			m = i;
	}
	n = i - 1;
	if (d & 1)
		m = n;
	return (m + n) / 2.0;
}

int activityNotifications(int d, vector<int> &expenditure) {
	int notifications = 0;
	vector<int> freq(201);

	for (int i = 0; i < d; i++)
		freq[expenditure[i]]++;

	for (int i = 0, j = d; j < expenditure.size(); i++, j++) {
		if (expenditure[j] >= 2 * median(d, freq))
			notifications++;
		freq[expenditure[i]]--;
		freq[expenditure[j]]++;
	}
	
	return notifications;
}

int main() {
	int n, d;
	cin >> n >> d;
	vector<int> expenditure(n);
	for (int i = 0; i < n; i++)
		cin >> expenditure[i];
	cout << activityNotifications(d, expenditure);
	return 0;
}