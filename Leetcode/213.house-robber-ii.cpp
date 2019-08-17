/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        int res = 0;
        vector<int> dp(nums.size()*2+2,0);
       
        for (int i = 1; i <= nums.size()*2; i++)
        {
          dp[i] = nums[(i-1)%nums.size()]+max(dp[i-2],dp[i-3]);
          res = max(res,dp[i]);
        }
        return res;
        
    }
};

