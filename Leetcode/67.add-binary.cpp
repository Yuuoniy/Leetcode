/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (38.02%)
 * Total Accepted:    278.8K
 * Total Submissions: 733K
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size()-1,j = b.size()-1;
        int carry = 0;
        while(i>=0||j>=0){
            int p = i>=0?a[i--]-'0':0;
            int q = j>=0?b[j--]-'0':0;
            int sum = p+q+carry;
            res = to_string(sum%2)+res;
            carry = sum/2;
        }
        return carry == 1?"1"+res:res;
        
    }
};
// 使用 0 补全较短的字符串
// 大数相加的思路
// 注意 char 和 int
// 利用 % 和 /
