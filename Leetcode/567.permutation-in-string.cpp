/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 * 要关注排列的形式，而是关注排列中元素的数量关系，太巧妙了。！
 * 滑动窗口！
 * 判断 s1长度的滑动窗口在s2上的是否含有s1的全部字符
 * 可以直接记录区别！
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        map<char,int> count;
        for (int i = 0; i < s1.size(); i++)
        {
            count[s1[i]]++;
            count[s2[i]]--;
        }
        for (int i = s1.size(); i < s2.size(); i++)
        {
           count[s2[i]]--;
           count[s2[i-s1.size()]]++;
           if(check(count)) return true;

        }
        return false;
        
        
    }

    bool check(map<char,int> count){
        for (map<char,int>::iterator i = count.begin(); i < count.end(); i++)
        {
            if(i->second!=0) return false;
        }
        return true;
        
    }
};

