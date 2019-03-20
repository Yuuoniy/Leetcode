/*
* @Author: Yuuoniy
* @Date:   2017-10-28 10:34:27
* @Last Modified by:   Yuuoniy
* @Last Modified time: 2017-10-28 11:04:46
*/
// Time Limit Exceeded :
class Solution {
 public:
  int countPrimes(int n) {
    int res = 0;
    for (int i = 1; i < n; i++) {
      res += ifPrimed(i);
    }
    return res;
  }
  bool ifPrimed(int a) {
    if (a == 1) return false;  //特殊情况
    for (int i = 2; i <= sqrt(a); ++i) {
      if (a % i == 0) return false;
    }
    return true;
  }
};

// Sieve of Eratosthenes:
//
class Solution {
 public:
  int countPrimes(int n) {
    vector<bool> prime(n, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 0; i < sqrt(n); ++i) {
      if (prime[i])
        for (int j = i * i; j < n; j += i) {
          prime[j] = false;
        }
    }
    return count(prime.begin(), prime.end(), true);
  }
};
