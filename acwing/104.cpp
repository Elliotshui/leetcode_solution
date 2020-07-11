#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> pos;

int main() {

	cin >> n;
	for(int i = 1, p; i <= n; ++i) {
		cin >> p;
		pos.push_back(p);
	}
	sort(pos.begin(), pos.end());
	long long res = 0;
	for(int i = 0, j = pos.size() - 1; i < j; ++i, --j) {
		res += pos[j] - pos[i];
	}
	cout << pos << endl;
	return 0;
}