/*

https://leetcode.com/problems/longest-palindromic-subsequence/

*/
class Solution {
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.size();
        if (n <= 1) {
            return n;
        }
        // vector<vector<int>> dp(n,vector<int> (n,0));
        int dp[n][n] = { 0 };

        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    //current length of palindrome  = (j+1-i)
                    // For length 1 palindromes we have to add 1 instead of 2
                    int subProblemResult = (i + 1 > j - 1) ? 0 : dp[i + 1][j - 1];
                    int adderLength = (i==j) ? 1 : 2;
                    dp[i][j] = adderLength + subProblemResult;
                }
                else {
                    int rightSubProblemResult = (i + 1 > j) ? 0 : dp[i + 1][j];
                    int leftSubProblemResult = (i > j - 1) ? 0 : dp[i][j - 1];
                    dp[i][j] = max(1, max(leftSubProblemResult, rightSubProblemResult));
                }
            }
        }
        return dp[0][n - 1];
    }
};