/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */
class Solution {
public:

    bool searchword(vector<vector<char>>& board, vector<vector<bool>>& used, string word, int i, int j, int d) {
        if(d == word.length())
            return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;
        if(used[i][j] || board[i][j] != word[d])
            return false;
        
        used[i][j] = true;
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        bool found = false;
        for(int dir = 0; dir < 4; ++dir) {
            found = found || searchword(board, used, word, i + dx[dir], j + dy[dir], d + 1);
        }
        if(found) return true;
        used[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int c = board.size();
        if(c == 0)
            return false;
        int r = board[0].size();
        if(r == 0)
            return false;

        vector<vector<bool>> used;
        for(int i = 0; i < c; ++i) {
            vector<bool> tmp;
            for(int j = 0; j < r; ++j) {
                tmp.push_back(false);
            }
            used.push_back(tmp);
        }
        for(int i = 0; i < c; ++i) {
            for(int j = 0; j < r; ++j) {
                if(searchword(board, used, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};

