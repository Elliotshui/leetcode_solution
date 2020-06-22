/*
 * @lc app=leetcode id=811 lang=cpp
 *
 * [811] Subdomain Visit Count
 */

// @lc code=start
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
       unordered_map<string, int> cnt;
       for(string &s: cpdomains) {
           int count = 0, i = 0;
           while(s[i] != ' ') {
               count *= 10;
               count += s[i] - '0';
               i++;
           }
           
           while(i < s.length()) {
               if(s[i] == ' ' || s[i] == '.') {
                   string subdomain = s.substr(i + 1, s.length() - i - 1);
                   if(!cnt.count(subdomain)) {
                       cnt[subdomain] = 0;
                   }
                   cnt[subdomain] += count;
               }
               i++;
           }
       }
       vector<string> res;
       for(auto it = cnt.begin(); it != cnt.end(); ++it){
           stringstream s; 
           s << it->second;
           s << ' ';
           s << it->first;
           res.push_back(s.str());
       } 
       return res;
    }
};
// @lc code=end

