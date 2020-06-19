/*
Problem Statement: https://leetcode.com/problems/validate-ip-address/
*/

class Solution {
public:
	string validIPAddress(string IP) {
		string token;
		vector<string> g4, g8;
		istringstream ss(IP);

		// split by '.' for IPv4
		while (getline(ss, token, '.'))
			g4.push_back(token);
		if (!IP.empty() && IP.back() == '.')
			g4.push_back(string());
		
		// reset stringstream
		ss.clear();
		ss.str(IP);

		// split by ':' for IPv6
		while (getline(ss, token, ':'))
			g8.push_back(token);
		if (!IP.empty() && IP.back() == ':')
			g8.push_back(string());
		
		// call matching function
		if (g4.size() == 4)
			return ipv4(g4);
		else if (g8.size() == 8)
			return ipv6(g8);
		else
			return "Neither";
	}

	string ipv4(vector<string>& groups) {
		bool valid = true;
		for (string g: groups) {
			valid &= (g.length() && g.length() <= 3);
			valid &= std::all_of(g.begin(), g.end(), ::isdigit);
			if (g.length() > 1)
				valid &= g[0] != '0';
			if (valid)
				valid &= stoi(g) < 256;
			if (!valid)
				return "Neither";
		}
		return "IPv4";
	}

	string ipv6(vector<string>& groups) {
		bool valid = true;
		for (string& g: groups) {
			valid &= (g.length() && g.length() <= 4);
			valid &= all_of(g.begin(), g.end(), [](char& c) {
				return ::isdigit(c) || (tolower(c) >= 'a' && tolower(c) <= 'f');
			});
			if (!valid)
				return "Neither";
		}
		return "IPv6";
	}
};