#include <iostream>
using namespace std;

int main() {
    long a, b, p;
    cin >> a >> b >> p;
    long res = 0;
    while(b) {
        if(b & 1) res = (res + a) % p;
        a = (a * 2) % p;
        b >>= 1;
    }
    cout << res << endl;
    return 0;
}