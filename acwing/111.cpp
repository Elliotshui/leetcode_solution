#include <iostream>
#include <cstring>
#include <priority_queue>
using namespace std;

class cow {
public:
	int a, b, idx, fidx;	
	bool operator < (const cow& c) const {
		return a < cow.a || (a == cow.a && b < cow.b);
	}
}
class fence {
public:
	int idx, ft;
	fence(int i, int f) : idx(i), ft(f) {}
	bool operator < (const fence& f) const {
		return ft < f.ft;
	}
}
const int N = 50050;

cow cows[N];

int main() {

	int n; 
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> cows[i].a >> cows[i].b;
		cows[i].idx = i;
	}
	sort(cows, cows + n);

	int next_fidx = 0;
	priority_queue<fence> fences;
	for(int i = 0; i < n; ++i) {
		if(fences.empty() || cows[i].b <= fences.top().ft) {
			next_fidx++;
			fences.push(fence(next_fidx, cows[i].b));
			cows[i].fidx = next_fidx;
		} else {
			cows[i].fidx = fences.top().idx;
			fences.pop();
			fences.push(fence(cows[i].fidx, cows[i].b));
		}
	}
	cout << next_fidx << endl;
	for(int i = 0; i < n; ++i) {
		cout << cows[i].fidx << endl;
	}
}