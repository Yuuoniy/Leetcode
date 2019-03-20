/*
* @Author: Yuuoniy
* @Date:   2017-10-27 10:55:42
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-27 11:05:09
*/
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0, right = numbers.size() - 1;
    while (numbers[left] + numbers[right] != target) {
      if (numbers[left] + numbers[right] < target) {
        ++left;
      } else
        --right;
    }
    return vector<int>({left + 1, right + 1});
  }
};
//前后指针 充分利用已经排好序的特性
// Time Limit Exceeded :
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    int leftSum = 0;
    for (int i = 0; i < numbers.size(); ++i) {
      leftSum = target - numbers[i];
      for (int j = i + 1; j < numbers.size(); ++j) {
        if (numbers[j] == leftSum) {
          res.push_back(i + 1);
          res.push_back(j + 1);
          return res;
        }
      }
    }
  }
};
