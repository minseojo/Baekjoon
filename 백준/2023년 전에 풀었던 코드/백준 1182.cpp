#include <bits/stdc++.h>
using namespace std;

int arr[1000011];
int n, s, answer=0;

void dfs(int sum, int index) {
	if(index==n) { // �� ������ ������ �ߺ��� �� ���� 
		if(sum==s) answer++;
		return;
	}
	
	dfs(arr[index]+sum, index+1);
	dfs(sum, index+1);
}

int main() {
	cin >> n >> s;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	if(s==0) answer--;  // s�� 0�� �ΰ�� �����  ������ ������ �߰��ϹǷ� �ϳ��� �A��
	  
	dfs(0,0);
		
	cout << answer;
}
