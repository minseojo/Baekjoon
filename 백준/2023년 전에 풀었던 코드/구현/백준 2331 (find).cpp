/*
auto it = find(v.begin(), v.end(), ã����) 
if(it==v.end()) ...   ��ã�� ��� 
else ... ã�� ��� 
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
	int a, p;
	cin >> a >> p;
	
	v.push_back(a); // ó���� �־���� 
	long long sum=0, answer=0;
	while(1) {
		bool flag=false;
		if(a==0) {
			auto it =find(v.begin(), v.end(), sum);
			if(it==v.end()) {				
				v.push_back(sum);
				a=sum;	
				sum=0;
			} else {
				flag=true;
			}
		}
		if(flag) break;
		sum+=pow(a%10, p);
		a/=10;
	}
	
	for(int i=0; i<v.size(); i++) {
		if(v.at(i)==sum) cout << i;
	}
}


/*  �Ǵ�  �Ʒ� �ڵ�� 100���� ������ �˻� => �޸� ���� => find�� �̿�. 

#include <bits/stdc++.h>
using namespace std;

long long arr[1000000];
vector<int> v;

int main() {
	long long a, p;
	cin >> a >> p;
	
	v.push_back(a);
	long long cnt=0, index=0;
	long long sum=0;
	while(1) {
		bool flag=false;
		if(a==0) {
			v.push_back(sum);
			a=sum;	
			sum=0;
			cnt++;
			if(cnt%100==0) {
				for(int i=0; i<v.size(); i++) {
					if(flag) break;
					for(int j=i+1; j<v.size(); j++) {
						if(v.at(i)==v.at(j)) {
							index=v.at(j);
							flag=true;
							break;
						}
					}
				}
			}
		}
		if(flag) break;
		sum+=pow(a%10, p);
		a/=10;
	}
	
	for(int i=0; i<v.size(); i++) {
		if(index==v.at(i)) {
			cout << i;
			return 0;
		}
	}
} 
*/
