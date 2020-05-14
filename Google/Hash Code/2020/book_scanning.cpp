#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

/*
B  - the number of different books
L  - the number of libraries
D  - the number of days
S  - the scores of individual books
N  - the number of books in library i
T  - the number of days for signup for library i
M  - the number of books that can be shipped for library i
ID - the id books for library i
Y  - the id of scanning the library
K  - the book id for scanning from library i
*/

// global variables
int B, L, D;
double w1, w2, w3;
unordered_map<int, int> score;
unordered_map<int, bool> done, ldone;
int S[100000], N[100000], T[100000], M[100000];

void sort_books(int l, vector<vector<int>>& ID) {
	sort(ID[l].begin(), ID[l].end(), [](int& l, int& r) {
		return score[l] < score[r];
	});
}

int sort_libraries(vector<vector<int>>& ID) {
	pair<int, int> library;
	vector<pair<double, int>> libraries;

	for (int i = 0; i < L; i++) 
		if (!ldone.count(i)) {
			long long s = 0;
			for (int j = 0; j < ID[i].size(); j++)
				if (!done.count(ID[i][j]))
					s += score[ID[i][j]];
			library.first = w1 * (1.0 / T[i]) + w2 * M[i] + w3 * s;
			library.second = i;
			libraries.push_back(library);
		}
	
	if (libraries.empty())
		return -1;

	sort(libraries.rbegin(), libraries.rend());
	ldone[libraries.front().second] = true;
	return libraries.front().second;
}

void book_scanning(vector<vector<int>>& ID) {
	int l;
	long long s = 0;
	vector<int> Y;
	vector<vector<int>> K;
	
	// initialize book score in map for fast-lookup
	for (int i = 0; i < B; i++)
		score[i] = S[i];
	
	// consider libraries as long as we have enough days
	while (D > 0) {
		l = sort_libraries(ID);
		if (l == -1)
			break;
		D -= T[l];
		int d = D;
		vector<int> b;
		sort_books(l, ID);
		
		while (!ID[l].empty()) {
			int book = ID[l].back();
			if (!done.count(book)) {
				done[book] = true;
				b.push_back(book);
				s += score[book];
			}
			ID[l].pop_back();
		}

		if (!b.empty()) {
			Y.push_back(l);
			K.push_back(b);
		}
	}

	// output solution
	cout << Y.size() << endl;
	for (int i = 0; i < Y.size(); i++) {
		cout << Y[i] << " " << K[i].size() << endl;
		for (int j = 0; j < K[i].size(); j++)
			cout << K[i][j] << " ";
		cout << endl;
	}
}

int main(int argc, char **argv) {
	// fast input & output
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// file input & output
	string f = argv[1];
	w1 = stod(argv[2]);	// signup
	w2 = stod(argv[3]);	// shipping
	w3 = stod(argv[4]);	// score of books
	freopen((f + ".in").c_str(), "r", stdin);
	freopen((f + ".out").c_str(), "w", stdout);

	cin >> B >> L >> D;
	vector<vector<int>> ID(L);
	
	for (int i = 0; i < B; i++)
		cin >> S[i];
	
	for (int i = 0; i < L; i++) {
		cin >> N[i] >> T[i] >> M[i];
		ID[i] = vector<int>(N[i]);
		for (int j = 0; j < N[i]; j++)
			cin >> ID[i][j];
	}

	book_scanning(ID);

	return 0;
}