#include <iostream>
#include <unordered_map>
using namespace std;

int n, m;
const int N = 200020;
int b[N], c[N];
unordered_map<int, int> cnt;	


int main() {
	cin >> n;
	for(int i = 1, a; i <= n; ++i) {
		cin >> a;
		if(cnt.count(a) == 0) cnt[a] = 0;
		cnt[a]++;
	}
	cin >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> b[i];
		if(cnt.count(b[i]) > 0) b[i] = cnt[b[i]];
		else b[i] = 0;
	}
	for(int i = 1; i <= m; ++i) {
		cin >> c[i];
		if(cnt.count(c[i] > 0)) c[i] = cnt[c[i]];
		else c[i] = 0;
	}
	
	int maxcnt = 0;
	for(int i = 1; i <= m; ++i) {
		if(b[i] > maxcnt) maxcnt = b[i];
	}
	int maxcnt2 = 0;
	for(int i = 1; i <= m; ++i) {
		if(b[i] == maxcnt && c[i] > maxcnt2) maxcnt2 = c[i];
	}
	for(int i = 1; i <= m; ++i) {
		if(b[i] == maxcnt && c[i] == maxcnt2) {
			cout << i << endl;
			return 0;
		} 
	}
}