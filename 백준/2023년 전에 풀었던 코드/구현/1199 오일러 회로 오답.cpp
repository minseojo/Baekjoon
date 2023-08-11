#include <bits/stdc++.h>
using namespace std;

int n;
int a[1111][1111];
int degree[1111];
int nxt[1111];

vector<int> v;

void dfs(int idx) {
    for (int &i=nxt[idx]; i<n; i++) {  // int i=0; i<n; i++ �̶� ���� �ٸ��� �𸣰��� 
        while(a[idx][i]!=0) {
            a[idx][i]-=1;
            a[i][idx]-=1;
            dfs(i);            
        }
    }
    
	cout << idx+1 << " ";
    return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin >> n;
    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            degree[i]+=a[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        if (degree[i]%2==1) {  // => ���Ϸ� Ʈ����
            cout << -1 << "\n"; //���Ϸ� ȸ�ΰ� �Ǳ� ���ؼ��� ������ ������ ������ �������ϹǷ� ��� ¦����. 
            exit(0);
        }
    }
	for(int i=0; i<n; i++) nxt[i]=0;
    dfs(0);
    return 0;
}
