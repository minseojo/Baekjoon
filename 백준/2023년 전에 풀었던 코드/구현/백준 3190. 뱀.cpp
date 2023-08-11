#include <bits/stdc++.h>
using namespace std;

int N, K, L;
int board[101][101]; // (1,1) ~ (100,100)  0�� ��ĭ, 1�� ���, 2�� �ڱ��ڽ� 
char t_time[10001]; //�ʿ� ���� ȸ������
int dy[4] = {0,1,0,-1}; //�����»� 
int dx[4] = {1,0,-1,0};
int dir; // (0~3) ������� �����»�
int snakeBody[101][101]; // ���� �� ����- �� �ڱ��ڽ��� �ε�ĥ ��� üũ 
queue<pair<int, int> > snake;
 	
void Input() {
	cin >> N >> K ;
	
	memset(board, 0, sizeof(board));
	
	int y, x;
	for(int i=0; i<K; i++) {
		cin >> y >> x;
		board[y][x] = 1;
	}
	
	cin >> L;
	int t;
	char d;
	for(int i=0; i<L; i++) {
		cin >> t >> d;
		t_time[t] = d;
	}
}

void Solve() {
	snake.push({1, 1}); // 1,1 ���� 
	visited[1][1] = true;
	int time = 0;
	dir = 0;
	int py, px, ny, nx;
	while(1) {
		time++;
		py = snake.front().first; // ���� 
		px = snake.front().second;
		ny = snake.back().first + dy[dir]; //���� - ������ �տ� ���� 
		nx = snake.back().second + dx[dir];
		snake.push({ny, nx});
		
		if(t_time[time] == 'D') {
			dir++;
			if(dir == 4) dir = 0;
		} else if(t_time[time] == 'L'){
			dir--;
			if(dir == -1) dir = 3;
		}

		if(ny<1 || nx<1 || ny>N || nx>N) break; //�� �浹 
		
		if(board[ny][nx] == 1){ // ����Ա� 
			board[ny][nx] = 0;
		} else { 
			if(visited[ny][nx] == true) break;
			visited[py][px] = false; 
			snake.pop();
		}
		
		visited[ny][nx] = true;
	}
	
	cout << time; 
}

int main() {
	Input();
	Solve();
	return 0;
} 
