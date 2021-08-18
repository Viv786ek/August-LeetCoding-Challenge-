//https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3902/
//DP
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), dp = 0, dp1 = 1, dp2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0') // Single digit
                dp += dp1;
            if (i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')) // Two digits
                dp += dp2;
            dp2 = dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
    }
};
