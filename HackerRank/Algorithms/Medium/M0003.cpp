/*
Problem Statement: https://www.hackerrank.com/challenges/extra-long-factorials/problem
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BigInt{
private:
	string s;
public:
	BigInt(string s){
		this->s = s;
	}
	
	void add(string m){
		s = add(s, m);
	}
	
	void multiply(string m){
		s = multiply(s, m);
	}
	
	string add(vector<string> results){
		string sum;
		for(int i=0 ; i<results.size() ; i++)
			sum = add(sum, results[i]);
		return sum;
	}
	
	string add(string n, string m){
		int carry, i;
		carry = i = 0;
		reverse(n.begin(), n.end());
		reverse(m.begin(), m.end());
		if(n.length() < m.length()){
			string temp = n;
			n = m;
			m = temp;
		}
		for(i=0 ; i<m.length() ; i++){
			int sum = (m[i] - '0') + (n[i] - '0') + carry;
			n[i] = (sum%10 + '0');
			carry = sum/10;
		}
		while(carry){
			if(i == n.length()){
				n.append(to_string(carry));
				break;
			}
			int sum = (n[i] - '0') + carry;
			n[i] = (sum%10 + '0');
			carry = sum/10;
			i++;
		}
		return string(n.rbegin(), n.rend());
	}
	
	string multiply(string n, string m){
		vector<string> results(m.length());
		reverse(n.begin(), n.end());
		reverse(m.begin(), m.end());
		for(int i=0 ; i<m.length() ; i++){
			int carry = 0;
			for(int j=0 ; j<n.length() ; j++){
				int prod = (m[i] - '0') * (n[j] - '0') + carry;
				results[i].append(to_string(prod%10));
				carry = prod/10;
			}
			if(carry)
				results[i].append(to_string(carry));
			results[i] = string(i, '0') + results[i];
		}
		for(int i=0 ; i<results.size() ; i++)
			reverse(results[i].begin(), results[i].end());
		return add(results);
	}
	
	friend ostream& operator<<(ostream& os, const BigInt& b){
		os<<b.s;
		return os;
	}
};

void extraLongFactorials(int n) {
	BigInt prod("1");
	for(int i=n ; i>0 ; i--){
		string m = to_string(i);
		prod.multiply(m);
	}
	cout<<prod;
}

int main()
{
	int n;
	cin>>n;
	extraLongFactorials(n);
	return 0;
}
