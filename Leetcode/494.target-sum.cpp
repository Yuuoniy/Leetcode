/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 * 不要什么都想着 dp。。应该做点搜索的题目洗洗脑。。
 */
class Solution {
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        solve(nums,0,0,S);
        return count;
    }
    void solve(vector<int>& nums,int i,int sum,int S){
        if(i==nums.size()){
            if(sum==S) {
                count++;
            }
        }else{
            solve(nums,i+1,sum+nums[i],S);
            solve(nums,i+1,sum-nums[i],S);
        }
    }
};

