class Solution
{
public:
    bool searchPattern(string pattern, string text)
    {
        vector<int> LPS = getLPSArray(pattern);
        int j = 0;
        int m = (int)text.length();
        int n = (int)pattern.length();

        for (int i = 0; i < m; i++)
        {
            if (pattern[j] == text[i])
            {
                ++j;
                if (j == n)
                {
                    return true;
                }
            }
            else
            {
                while (j > 0 && pattern[j] != text[i])

                    j = LPS[j - 1];
            }
        }
        return false;
    }
    vector<int> getLPSArray(string pattern)
    {
        // Calucalates Longest proper prefix which is also a suffix.
        int n = (int)pattern.length();
        vector<int> LPS(n, 0);

        for (int i = 1; i < n; ++i)
        {

            int j = LPS[i - 1];

            while (j > 0 && pattern[i] != pattern[j])

                j = LPS[j - 1];

            if (pattern[i] == pattern[j])
                ++j;

            LPS[i] = j;
        }

        return LPS;
    }

    bool rotateString(string A, string B)
    {
        if (A.length() != B.length())
            return false;
        if (A.length() == 0)
            return true;
        return searchPattern(B, A + A) || searchPattern(A, B + B);
    }
};
