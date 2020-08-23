// Problem Code: LEBOMBS

#include <iostream>
#include <string>

using namespace std;

int littleElephantAndBombs(string S){
	int exploded = 0;
	bool first = true;
	if(S[0] == '1'){
		exploded += (S.length() == 1) ? 1 : 2;
		first = false;
	}
	for(int i=1 ; i<S.length()-1 ; i++){
		if(first && S[i] == '1'){
			exploded += 3;
			first = false;
		}else if(S[i] == '1')
			exploded++;
		else{
			if(!first && S[i+1] == '1')
				exploded--;
			first = true;
		}
	}
	if(first && S[S.length()-1] == '1')
		exploded += 2;
	return S.size() - exploded;
}

int main(){
	int T, N;
	string S;
	cin >> T;
	while(T--){
		cin >> N >> S;
		cout << littleElephantAndBombs(S) << endl;
	}
	return 0;
}