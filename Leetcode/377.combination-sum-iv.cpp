/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */
// 改 int 为 unsigned int， long long 也是不行的！
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
         vector<unsigned int> dp(target+1,0);
         dp[0] = 1;
        for (unsigned int i = 1; i <=target; i++)
        {
            for (auto a:nums)
            {
                if(i>=a) dp[i]+=dp[i-a];
            }
            
        }
        return dp[target];
        
    }
};
