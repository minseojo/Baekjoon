#include <bits/stdc++.h>
using namespace std;

long long h[1000111];
long long ret;

int solve(long long left, long long right) {
	//���ڰ� 1���� ��� 
	if (left == right) {
		return h[left];
	}
	long long mid = (left + right) / 2;
	//����, ������ ���� 
	long long ret = max(solve(left, mid), solve(mid+1, right));

	long long low = mid;
	long long high = mid+1;
	long long height = min(h[low], h[high]);
	
	//�߰��κп� ��ģ ��� 
	ret = std::max(ret, height*2);
	
	//�������� �� ĭ�� Ȯ��
	//�̶� ����, ������ �� �� ū ������ Ȯ���Ѵ�.
	while (left < low || high < right) {
		//���������� Ȯ�� 
		if (high < right && (low == left || h[low-1] < h[high+1])) {
			high++;
			height = min(height, h[high]);
		}
		//�������� Ȯ�� 
		else {
			low--;
			height = min(height, h[low]);
		}
		// Ȯ���� �� �簢���� ���� 
		ret = max(ret, height * (high - low + 1));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	while (1) {
		cin >> n;
		if(n==0) break; 
		for (int i=0; i < n; i++) {
			cin >> h[i];
		}
		cout << solve(0, n-1) << "\n";
		memset(h, 0, sizeof(h));
	}
	return 0;
}
