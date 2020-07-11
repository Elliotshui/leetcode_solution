#include <iostream>
#include <math.h>
using namespace std;

typedef pair<double, double>  pdd;

const int N = 1010;
pdd segs[N];

int main() {
	int n, d;
	cin >> n >> d;
	for(int i = 0, x, y; i < n; ++i) {
		cin >> x >> y;
		if(y > d) {
			cout << -1 << endl;
			return 0;
		}
		segs[i].first = (double)x - sqrt(d * d - y * y);
		segs[i].second = (double)x + sqrt(d * d - y * y);
	}
	sort(segs, segs + n);
	int cnt = 0;
	pdd seg = segs[0];
	for(int i = 1; i < n; ++i) {
		if(segs[i].first <= seg.second) seg.second = segs[i].first;
		else {
			cnt++;
			seg = segs[i];
		}
	}
	cout << cnt << endl;
	return 0;
}