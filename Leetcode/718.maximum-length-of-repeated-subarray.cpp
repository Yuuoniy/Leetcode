/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 * 这不就是最长公共子串？
 * 用一维数组优化一下...
 * 注意顺序！！
 * 成一维之后我们要注意修改某一状态的值之后不能影响到别的状态的转移，
 * 现在的转移方式比如转移到了某一时刻，前面都是当前阶段的状态，
 * 后面都是上一阶段的状态，那么很有可能，
 * 后面当前阶段的状态就会从前面当前阶段的状态转移过来，所以要反过来
 */
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        // vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1,0));
        int size = max(A.size(),B.size());
        if(A.size()==0||B.size()==0) return 0;
        vector<int> dp(size+1,0);
     

        int res = 0;
        for (int i = 1; i <= A.size(); i++)
        {
            for (size_t j = B.size(); j>=1; j--)
            {
               if(A[i-1]==B[j-1]){
                   dp[j] = dp[j-1]+1;
                   res = max(res,dp[j]);
               }else{
                   dp[j]= 0;
               }
            }
            
        }
        return res;
    }
};

