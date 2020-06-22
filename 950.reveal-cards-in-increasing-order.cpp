/*
 * @lc app=leetcode id=950 lang=cpp
 *
 * [950] Reveal Cards In Increasing Order
 */

// @lc code=start
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int i = 0, j = 0;
        vector<int> res(deck.size(), 0);
        vector<bool> placed(deck.size(), false);
        while(i < deck.size()) {
            if(placed[j] == false) {
                res[j] = deck[i];
                i++;
                placed[j] = true;
            }
            if(i == deck.size()) break;
            while(placed[j] == true) j = (j + 1) % deck.size();
            j = (j + 1) % deck.size();
            while(placed[j] == true) j = (j + 1) % deck.size();
        }
        
        return res;
    }
};
// @lc code=end

