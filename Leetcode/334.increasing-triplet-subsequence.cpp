/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *  优化空间很大，我的复杂度太高了
 * 可以使用变量来记录第一小和第二小的数
 */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size = nums.size();
        if(size==0) return false;
        vector<int>  dp(size+1,1);
        int res = 1;
        for (int i = 1; i < size; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[j]+1,dp[i]);
                    res = max(res,dp[i]);
                    if(res>=3) return true;
                }
            }
        }
        return false;
        
    }
};

