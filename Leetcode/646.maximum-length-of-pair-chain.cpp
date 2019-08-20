/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 * 贪心算法，很巧妙
 * 最近做题感觉好差... 可能就是太偷懒了吧
 */
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 0, end = INT_MIN;
        sort(pairs.begin(),pairs.end(),[](vector<int>& a,vector<int>& b){
            return a[1]<b[1];
        });
        for (auto pair:pairs)
        {
           if(pair[0]>end){
               ++res;
               end = pair[1];
           }
        }
        return res;
    }
};

