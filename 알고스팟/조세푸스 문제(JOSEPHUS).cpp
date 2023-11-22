#include <vector>
#include <algorithm>
#include <iostream>
#include <string> 

using namespace std;

/*
 * N : �������� ���
 * K : �ڻ��ϴ� ��� ����
 */
pair<int, int> solve(int N, int K) {
	vector<int> people(N, -1);
	for (int i = 0; i < N; i++) people[i] = i + 1;
	
	int size = N;
	int dead = 0;
	
	while (size > 2) {
		people.erase(people.begin() + dead);
		size--;
		dead = (dead + K - 1) % size;
	}
	return { people[0], people[1] };
}

int main() {

	int C;
	cin >> C;

	while (C--) {
		int N, K;
		cin >> N >> K;
		pair<int, int> ans = solve(N, K);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}
