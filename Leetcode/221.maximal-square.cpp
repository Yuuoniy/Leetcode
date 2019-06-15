/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int maxWidth = 0;
        int n = matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
              if(i==0||j==0) dp[i][j] = matrix[i][j]-'0';
              else if(matrix[i][j]=='1')
              {
                  dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
              }
              maxWidth = max(maxWidth,dp[i][j]);
            }
            
        }
        return maxWidth*maxWidth;
        
    }
};

