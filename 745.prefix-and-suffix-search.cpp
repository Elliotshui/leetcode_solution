/*
 * @lc app=leetcode id=745 lang=cpp
 *
 * [745] Prefix and Suffix Search
 */

// @lc code=start
class WordFilter {

    class TrieNode {
    public:
        TrieNode *child[27];
        int weight;
        TrieNode() {
            for (int i = 0; i < 27; ++i) {
                child[i] = nullptr;
            }
            weight = -1;
        }
    };
    class Trie {
    private:
        TrieNode *root;
    public:
        Trie() {
            root = new TrieNode();
        }
        void insert(std::string w, int weight) {
            TrieNode *curr = root;
            for(int i = 0; i < w.length(); ++i) {
                if(curr->child[w[i] - 'a'] == nullptr) {
                    curr->child[w[i] - 'a'] = new TrieNode();
                }
                curr = curr->child[w[i] - 'a'];
                curr->weight = weight;
            }
        }
        int search(std::string w) {
            TrieNode *curr = root;
            for(int i = 0; i < w.length(); ++i) {
                if(curr->child[w[i] - 'a'] == nullptr) {
                    return -1;
                }
                curr = curr->child[w[i] - 'a'];
            }
            return curr->weight;
        }
        
    };

private:
    Trie T;
    
public:
    WordFilter(std::vector<std::string>& words) {
        for(int i = 0; i < words.size(); ++i) {
            for(int j = 0; j <= words[i].length(); ++j) {
                T.insert(words[i].substr(j) + "{" + words[i], i);
            }
        }
    }
    int f(std::string prefix, std::string suffix) {
        return T.search(suffix + "{" + prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
// @lc code=end

