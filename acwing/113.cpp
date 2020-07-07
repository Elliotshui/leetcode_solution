// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> res;
        res.push_back(1);
        for(int i = 2; i <= N; ++i) {
            int l = 0, r = res.size();
            while(l < r) {
                int m = (l + r) / 2;
                if(compare(i, res[m])) r = m;
                else l = m + 1;
            }
            res.insert(res.begin() + l, i);
        }
        return res;
    }
};