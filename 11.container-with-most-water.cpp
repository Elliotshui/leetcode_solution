/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 * 递推, 令maxs(i, j)表示在(i,j)区间内的最大容积, 其中i < j
 * if(h[i] < h[j]) 
 *     maxs(i, j) = max(s(i, j), maxs(i + 1, j))
 * else
 *     maxs(i, j) = max(s(i, j), maxs(i, j - 1))
 * 递推求maxs(0, size - 1)即可
 * 双指针法
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, result = 0;
        while(i != j) {
            int s = (j - i) * min(height[i], height[j]);
            result = max(s, result);
            if(height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return result;
    }
};

