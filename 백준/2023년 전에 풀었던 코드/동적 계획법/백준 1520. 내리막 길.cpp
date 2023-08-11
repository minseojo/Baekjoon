#include <bits/stdc++.h>
using namespace std;

int M, N;
int a[500][500];
int dp[500][500];
int dy[4] = {0,-1,0,1}; //�� �� �� �� 
int dx[4] = {1,0,-1,0};
int answer=0;

void input() {
	cin >> M >> N;
	for(int i=0; i<M; i++) {
		for(int j=0; j<N; j++) {
			cin >> a[i][j];
		}
	}
}

int solve(int y, int x) {
	if(y==M-1 && x==N-1) return 1;
	
	int &ret = dp[y][x];
	if(ret!=-1) return ret;
	ret=0; // ó���� dp[][]�� -1�� ���� �ʱ�ȭ. but, ó�� cnt�� 0�̹Ƿ� 0���� �ʱ�ȭ 
	for(int i=0; i<4; i++) {
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny<0 || nx<0 || ny>M-1 || nx>N-1) continue;
		if(a[y][x]>a[ny][nx])
			ret += solve(ny, nx);
	}
	
	return ret;
	
}

int main() {
	input();
	memset(dp, -1, sizeof(dp));
	solve(0, 0);
	
	cout << dp[0][0];
	return 0;
}
