/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.01%)
 * Total Accepted:    413.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 注意特殊情况，比如只有一个数据！
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //注意判断为空的情况
        if(strs.size()==0)
            return "";
        int n = strs.size();
        int idx = 0;
        char tmp;
        string prefix = "";
        while(idx<strs[0].size()){
           for(int i=0;i<n;i++){
            tmp = strs[0][idx];
            if(strs[i].size()<=idx||strs[i][idx]!=tmp)
                return prefix;
            }
            prefix+=tmp;
            ++idx;
        }
        return prefix;
        
    }
};

