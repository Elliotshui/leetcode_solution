/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start

class Solution {
public:

int dist(string& s1, string& s2) {
    int cnt = 0;
    for(int i = 0; i < s1.size(); ++i) {
        if(s1[i] != s2[i])
            cnt += 1;
    }
    return cnt;
}

vector<vector<int>> buildMap(string& beginWord, vector<string>& wordList) {
    
    vector<vector<int>> map;
    
    for(int i = 0; i < wordList.size(); ++i) {
        vector<int> tmp;
        for(int j = 0; j < wordList.size(); ++j) {
            if(dist(wordList[i], wordList[j]) == 1)
                tmp.push_back(j);
        }
        map.push_back(tmp);
    }
    
    //beginword
    vector<int> tmp;
    for(int i = 0; i < wordList.size(); ++i) {
        if(dist(beginWord, wordList[i]) == 1) {
            tmp.push_back(i);
        }
    }
    map.push_back(tmp);
    return map;
}


vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<int>> map = buildMap(beginWord, wordList);
    int sz = wordList.size();
    
    vector<int> pathlen;
    for(int i = 0; i < sz; ++i) pathlen.push_back(sz + 2);
    
    queue<vector<int>> q;
    for(int i = 0; i < map[sz].size(); ++i) {
        q.push({map[sz][i]});
        pathlen[map[sz][i]] = 1;
    }
    vector<vector<int>> res;
    
    while(!q.empty()) {
        
        vector<int> tmp = q.front();
        int last = tmp.back();
        
        if(wordList[last] == endWord) {
            if(pathlen[last] < tmp.size())  break;
            else {
                res.push_back(tmp);
                pathlen[last] = tmp.size();
            }
        }
        else {
            pathlen[last] = tmp.size();
            for(int i = 0; i < map[last].size(); ++i) {
                
                if(tmp.size() < pathlen[map[last][i]]) {
                    vector<int> tmp1 = tmp;
                    tmp1.push_back(map[last][i]);
                    q.push(tmp1);
                }
            }
        }
        q.pop();
    }
    
    vector<vector<string>> res_str;
    for (int i = 0; i < res.size(); ++i) {
        vector<string> tmp;
        tmp.push_back(beginWord);
        for(int j = 0; j < res[i].size(); ++j) {
            tmp.push_back(wordList[res[i][j]]);
        }
        res_str.push_back(tmp);
    }
    return res_str;
};



};
// @lc code=end

