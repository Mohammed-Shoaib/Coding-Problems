/*
Problem Statement: https://leetcode.com/problems/iterator-for-combination/
*/

class CombinationIterator {
private:
	int n;
	string s;
	vector<int> pos;
public:
    CombinationIterator(string characters, int combinationLength) {
		n = characters.length();
        s = characters;
		pos = vector<int>(combinationLength, -1);
    }

	void increment() {
		int i = pos.size() - 1;

		if (pos[i] == -1) {
			// If first time, create combination
			for (int i = 0; i < pos.size(); i++)
				pos[i] = i;
			return;
		}

		// find the position which can be incremented
		for (int j = 0; i > 0 && n - pos[i] - j == 1; j++)
			i--;
		
		// increment position
		pos[i]++;

		// get next combination
		for (int j = i + 1; j < pos.size(); j++)
			pos[j] = pos[j - 1] + 1;
	}
    
    string next() {
		string comb = "";
		increment();	// get next combination of positions
		for (int i = 0; i < pos.size(); i++)	// assign characters at position to string
			comb += s[pos[i]];
		return comb;
    }
    
    bool hasNext() {
		// check if the first position can be incremented further
        return (pos[0] != n - pos.size());
    }
};