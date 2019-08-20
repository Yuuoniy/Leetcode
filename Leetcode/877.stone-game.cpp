/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 * 好眼熟的题目... 只能头或尾取数，感觉以前做过又不太记得了
 * 如果 alex 想要赢，就是取数大于对手或者使对手取的数不能赢？？
 * 特别巧妙地 return true 就可以了...
 * https://www.cnblogs.com/liaohuiqiang/p/9747678.html 
 * 对于空间优化部分有点不明白
 */
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int[][] dp = new int[piles.length][piles.length];
        for (int i = 0; i < piles.lenght; i++)
        {
            for (int j = i+1; j < piles.length; j++)
            {
                int parity = (j-i)%2;
                if(parity==1){
                    dp[i][j] = max(piles[i]+dp[i+1][j],piles[j]+dp[i][j-1]);

                }else{
                    dp[i][j] = max(-piles[i]+dp[i+1][j],-piles[j]+dp[i][j-1]);
                }
            }
            
        }
        return dp[0][piles.length-1]>0;
        
    }
};

