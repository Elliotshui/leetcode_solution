/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 */

// @lc code=start
class Solution {
public:
    bool cmp(pair<double,int>& a,pair<double,int>& b)//sort by wage/quality
    {
        return a.first<b.first;
    }
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        double ans=0x3f3f3f3f;
        vector<pair<double,int> >rate;
        for(int i=0;i<quality.size();i++)
        {
            rate.push_back(make_pair(1.0*wage[i]/quality[i],i));
        }
        sort(rate.begin(),rate.end());//can not use self-defined cmp
        priority_queue<int>que;//maintain top K-1 largest element (exclude the pivot)
        int sum=0;
        for(int i=0;i<rate.size();i++)
        {
            if(que.size()<K-1)
            {
                que.push(quality[rate[i].second]);
                sum+=quality[rate[i].second];
            }
            else
            {
                ans=min(ans,1.0*rate[i].first*(sum+quality[rate[i].second]));
                if(!que.empty()&&que.top()>quality[rate[i].second])
                {
                    int tmp=que.top();
                    que.push(quality[rate[i].second]);
                    que.pop();
                    sum-=tmp;
                    sum+=quality[rate[i].second];
                }
 
            }
        }
        return ans;
    }
};
