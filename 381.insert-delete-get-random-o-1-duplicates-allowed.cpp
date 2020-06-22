/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 */

// @lc code=start
class RandomizedCollection {
public:

    vector<int> nums;
    unordered_map<int, unordered_set<int>> positions;
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(positions.count(val)) {
            positions[val].insert(nums.size());
            nums.push_back(val);
            return false;
        }
        unordered_set<int> pos;
        positions[val] = pos;
        positions[val].insert(nums.size());
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(!positions.count(val)) return false;

        if(nums.back() == val) {
            positions[val].erase(nums.size() - 1);
            if(positions[val].empty()) positions.erase(val);
            nums.pop_back();
            return true;
        }

        unordered_set<int> &pos = positions[val];
        unordered_set<int> &lastpos = positions[nums.back()];
        int p = *pos.begin();
        lastpos.erase(nums.size() - 1);
        lastpos.insert(p);
        pos.erase(p);
        if(pos.empty()) positions.erase(val);
        nums[p] = nums.back();
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

