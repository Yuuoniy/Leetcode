/*
* @Author: Yuuoniy
* @Date:   2017-10-26 09:04:28
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-26 09:16:22
*/
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int minprice = INT_MAX, maxProfit = 0;
    for (int i = 0; i < prices.size(); ++i) {
      if (prices[i] < minprice) minprice = prices[i];
      if (prices[i] - minprice > maxProfit) maxProfit = prices[i] - minprice;
    }
    return maxProfit;
  }
};

//利用两个变量记录
