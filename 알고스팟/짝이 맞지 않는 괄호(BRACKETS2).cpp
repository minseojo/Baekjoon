#include <bits/stdc++.h>
using namespace std;

bool solve(const string& formula) {
	const string opening("({["), closing(")}]");
	stack<char> openStack;
	for(int i=0; i<formula.size(); i++) {
		if(opening.find(formula[i]) != -1)
			//���� ��ȣ��� ������ ���ÿ� ���� �ִ´�. 
			openStack.push(formula[i]);

		else {
			//������ ��� �ִ°�쿡�� ���� 
			if(openStack.empty()) return false;
			//���� ¦�� ���� ������ ���� 
			if(opening.find(openStack.top()) != closing.find(formula[i]))
				return false;
			//¦�� ���� ��ȣ�� ���ÿ��� ����.
			openStack.pop();
		} 
		// ������ ���� ��ȣ�� ����� ����
	}
	return openStack.empty();
}

int main() {
	int tc;
	cin >> tc;
	while(tc--) {
		string str="";
		cin >> str;
		if(solve(str)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
} 
