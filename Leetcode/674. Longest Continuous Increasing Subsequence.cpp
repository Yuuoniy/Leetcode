class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    if (nums.size() == 0) //要注意边界条件!
      return 0;
    int n = nums.size();
    int d[n];
    int len = 1;
    d[0] = 1;
    for (int i = 1; i < n; i++) {
      d[i] = 1;

      if (nums[i - 1] < nums[i]) {
        if (d[i - 1] + 1 > d[i])
          d[i] = d[i - 1] + 1;
      }
      if (d[i] > len)
        len = d[i];
    }
    return len;
  }
};
