/*
 * @Author: yuuoniy 
 * @Date: 2019-08-18 16:33:56 
 * @Last Modified by: yuuoniy
 * @Last Modified time: 2019-08-18 16:42:10
 */
/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 * 参考题解：https://www.cnblogs.com/grandyang/p/4028713.html
 * 空间可以优化！
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], n = nums.size();
        vector<int> f(n,0),g(n,0);
        f[0] = nums[0];
        g[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            f[i] = max(max(f[i-1]*nums[i],g[i-1]*nums[i]),nums[i]);
            g[i] = min(min(f[i-1]*nums[i],g[i-1]*nums[i]),nums[i]);
            res = max(res,f[i]);
        }
        return res;
    }
};

