class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    if (nums.size() == 0) //要注意边界条件!
      return 0;
    int n = nums.size();
    int d[n], count[n];
    int maxlen = 0, maxcount = 0;
    for (int i = 0; i < n; i++) {
      d[i] = count[i] = 1;
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          if (d[j] + 1 > d[i]) {
            d[i] = d[j] + 1; 
            count[i] = count[j]; //注意！
          } else if (d[j] + 1 == d[i])
            count[i]+=count[j];
        }
      }
      if (d[i] > maxlen) {
        maxlen = d[i];
        maxcount = count[i];
      } else if (d[i] == maxlen) {
        maxcount += count[i];
      }
    }
    return maxcount;
  }
};
