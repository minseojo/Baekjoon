#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int V, E;
vector<pair<int, int> > graph[10001]; // cost, destination 
bool visited[10001];

void input() {
	cin >> V >> E;
	
	int A, B, C;
	for(int i=0; i<E; i++) {
		cin >> A >> B >> C;
		graph[A].push_back({C, B});
		graph[B].push_back({C, A});
	}
}

int prim() {
	int answer = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> pq;
	pq.push({0, 1}); // ���=0, ���۳��=1, ���������� ��� ��带 �����Ƿ� ��� �����ص� ���� 
	
	while(!pq.empty()) {
		int now_cost = pq.top().first;
		int now_node = pq.top().second;
		pq.pop();
		
		if(visited[now_node]) continue;
		visited[now_node] = true;

		answer += now_cost;

		for(int i=0; i < graph[now_node].size(); i++) {
			int next_cost = graph[now_node][i].first;
			int next_node = graph[now_node][i].second;
			if(!visited[next_node]) {
				pq.push({next_cost, next_node});
			}
		}
	}	 
	
	return answer;
}

int main() {
	input();
	cout << prim();
	return 0;
} 
