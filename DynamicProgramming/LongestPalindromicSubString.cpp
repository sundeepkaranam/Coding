/*
https://leetcode.com/problems/longest-palindromic-substring/
*/

class Solution {
public:
    string longestPalindrome(string s) {  
    int n = s.size();  
    if(n <= 1){
        return s;
    }
    // vector<vector<bool>> dp(n,vector<bool> (n,false)); 
    bool dp[n][n] = {false};
    int maxLength = 1; 
    int start = 0;    
    for (int len = 1; len <= n; ++len) 
    { 
        for (int i = 0; i < n-len+1 ; ++i) 
        { 
            int j = i + len - 1; 
            if (s[i] == s[j] && ((i+1) > (j-1) || dp[i+1][j-1])) 
            { 
                dp[i][j] = true; 
                if (len > maxLength) 
                { 
                    start = i; 
                    maxLength = len; 
                } 
            } 
        } 
    }
      return s.substr(start,maxLength);  
    }  
};