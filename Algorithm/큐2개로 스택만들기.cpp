#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> sub_queue; 
queue<int> main_queue;
vector<int> answer;

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int num;
		cin >> num;
		sub_queue.push(num);
	}
}

void solve() {
	while(1) {
		//���Ṯ 
		if(answer.size()==n) break;

		//����ť�� �ִ°� ����ť�� �ű��
		while(!sub_queue.empty()) {
			main_queue.push(sub_queue.front());
			sub_queue.pop();
		}
		
		// ���ο� 1���� ���ܳ��� �ٽ� ����ť�� �ֱ� 
		while(main_queue.size()!=1) {
			sub_queue.push(main_queue.front());
			main_queue.pop();
		}
		
		// ����ť�� ������ 1�� �ٸ� ����ҿ� �����س���
		int front = main_queue.front();
		answer.push_back(front);
		main_queue.pop();
	}	
} 
void print() {
	//��� 
	for(auto it : answer) {
		cout << it << " ";
	}	
}
int main() {	
	input();
	solve();
	print();
	return 0; 
}
