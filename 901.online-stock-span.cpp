/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
public:
    vector<int> spans;
    vector<int> prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int j = spans.size() - 1;
        while(j >= 0 && prices[j] <= price) {
            j = j - spans[j];
        }
        spans.push_back(spans.size() - j);
        prices.push_back(price);
        return spans.back();
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

