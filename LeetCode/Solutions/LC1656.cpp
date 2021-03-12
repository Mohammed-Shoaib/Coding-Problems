/*
Problem Statement: https://leetcode.com/problems/design-an-ordered-stream/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|-------------------|------|-------|
| Operations        | Time | Space |
|-------------------|------|-------|
| OrderedStream(n)  | O(n) | O(1)  |
| insert(id, value) | O(n) | O(n)  |
|-------------------|------|-------|
*/

class OrderedStream {
private:
	int pos;
	vector<string> arr;
public:
	OrderedStream(int n): pos(0), arr(n) {}
	
	vector<string> insert(int id, string value) {
		arr[id - 1] = value;
		vector<string> chunk;
		while (pos < arr.size() && !arr[pos].empty())
			chunk.push_back(arr[pos++]);
		return chunk;
	}
};