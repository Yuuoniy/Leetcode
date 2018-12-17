/*
* @Author: Yuuoniy
* @Date:   2017-11-02 22:11:46
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-11-02 22:44:08
*/
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> res(findNums.size(), -1);
    bool flag = false;
    for (int i = 0; i < findNums.size(); ++i) {
      for (int j = 0; j < nums.size(); ++j) {
        if (nums[j] == findNums[i]) {
          while (nums[j] <= findNums[i] && j < nums.size()) {
            j++;
          }
          res[i] = j == nums.size() ? -1 : nums[j];
          break;
        }
      }
    }
    return res;
  }
};
