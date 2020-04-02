/*
Problem Statement: https://leetcode.com/problems/get-watched-videos-by-your-friends/
*/

class Solution {
public:
    vector<string> watchedVideosByFriends(vector< vector<string> >& watchedVideos, vector< vector<int> >& friends, int id, int level) {
		int size, n = friends.size();
		queue<int> q;
		vector<string> movies;
		vector<bool> visited(n);
		set< pair<int, string> > s;
		unordered_map<string, int> m;

		level++;
		q.push(id);
		visited[id] = true;

		while (level-- && !q.empty()) {
			size = q.size();
			while (size--) {
				id = q.front();
				q.pop();
				for (string& movie: watchedVideos[id])
					if (level == 0)
						m[movie]++;
				for (int v: friends[id])
					if (!visited[v]) {
						q.push(v);
						visited[v] = true;
					}
			}
		}
		transform(m.begin(), m.end(), inserter(s, s.end()), [](auto& p) { return make_pair(p.second, p.first); });
		transform(s.begin(), s.end(), back_inserter(movies), [](auto& p) { return p.second; });

		return movies;
    }
};