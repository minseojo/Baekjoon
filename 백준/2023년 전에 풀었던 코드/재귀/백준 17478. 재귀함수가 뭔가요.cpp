#include <bits/stdc++.h>
using namespace std;

int n;

void printUnderBar(int line) {
	for(int i=0; i<line; i++)
		cout << "____";
}

void solve(int pos) {
	if(pos==0) cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;
	if(pos==n) {
		printUnderBar(pos);
		cout << "\"����Լ��� ������?\"" << endl;
		printUnderBar(pos);
		cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;
		printUnderBar(pos);	
		cout << "��� �亯�Ͽ���." << endl;
		return;
	}
	printUnderBar(pos);
	cout << "\"����Լ��� ������?\"" << endl;
	printUnderBar(pos);
	cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;
	printUnderBar(pos);
	cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << endl;
	printUnderBar(pos);
	cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << endl;
	solve(pos+1);
	printUnderBar(pos);
	cout << "��� �亯�Ͽ���." << endl;
} 
int main() {
	cin >> n;
	solve(0);
	
	return 0;
}
