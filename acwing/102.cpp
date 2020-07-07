#include <iostream>
using namespace std;

int N = 100010;
double cow[N];
double sum[N];
int n, f;

bool check(double avg) {
	for(int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + cow[i] - avg;
	double mins = 0;
	for(int i = 0, j = f; j <= n; i++, j++) {
		mins = min(mins, sum[i]);
		if(sum[j] >= mins) return true;
	}
	return false;
}

int main() {
	cin >> n >> f;
	for(int i = 1; i <= n; ++i) cin >> cow[i];
	double l = 0, r = 2000;
	while(r - l > 1e-5) {
		double m = (l + r) / 2;
		if(check(m)) l = m;
		else r = m;
	}	
	cout << int(r * 1000) << endl;
}