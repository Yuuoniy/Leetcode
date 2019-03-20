/*
* @Author: Yuuoniy
* @Date:   2017-10-28 16:17:16
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-28 16:41:30
*/
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 0; i < (int)prices.size() - 1; ++i) {
      if (prices[i] < prices[i + 1]) profit += (prices[i + 1] - prices[i]);
    }
    return profit;
  }
};

//没有添加(int)时报错：reference binding to null pointer of type 'value_type'
