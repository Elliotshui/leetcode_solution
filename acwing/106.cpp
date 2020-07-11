#include <iostream>
#include <queue>
using namespace std;

int main() {
	int p; 
	cin >> p; 
	while(p--) {
		int m, seq;
		cin >> seq >> m;
		cout << seq << (m + 1) / 2;
		priority_queue<int, greater<int>> left;
		priority_queue<int> right; 		
		for(int i = 0, a; i < m; ++i) {
			cin >> a;
			if(left.empty() && right.empty()) left.push(a);
			else if(!left.empty()) {
				if(a <= left.top()) left.push(a);
				else right.push(a);
			} else {
				if(a > right.top()) right.push(a);
				else left.push(a);
			}

			if(right.size() > left.size() + 1) {
				left.push(right.top()); 
				right.pop();
			} else if(left.size() > right.size() + 1) {
				right.push(left.top());
				left.pop();
			}
			if(i % 2 == 0) {
				if(left.size() > right.size()) cout << left.top() << ' ';
				else cout << right.top() << ' ';
			}
		}
	}
	return 0;

}