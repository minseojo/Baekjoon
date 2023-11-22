#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;
void hanoi (int n, int from, int mid, int to) {
    if (n == 1) {
        answer.push_back({from, to});
    } else {
        hanoi(n-1, from, to, mid);
        answer.push_back({from, to});
        hanoi(n-1, mid, from, to);
    }
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 2, 3);
    return answer;
}