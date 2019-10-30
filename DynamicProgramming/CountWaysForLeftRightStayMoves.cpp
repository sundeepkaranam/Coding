#include <bits/stdc++.h>
using namespace std;
/*
You start at index 0 in an array with length 'h'. At each step, you can move to the left, move to the right, or stay in the same place(Note! Stay in the same place also takes one step). How many possible ways are you still at index 0 after you have walked 'n' step?

Example： n = 3
1. right->left->stay
2. right->stay->left
3. stay->right->left
4. stay->stay->stay

*/
int countWays(int steps, int height, int startPos)
{

    if (steps == 0 || height == 0) {
        return 0;
    }
    else if (height == 1) {
        return 1;
    }

    vector<vector<int> > dp(height, vector<int>(steps + 1, 0));
    dp[0][1] = 1;
    dp[1][1] = 1;

    for (int j = 1; j <= steps; j++) {
        for (int i = 0; i < height; i++) {

            dp[i][j] += dp[i][j - 1];
            if (i - 1 >= 0)
                dp[i][j] += dp[i - 1][j - 1];
            if (i + 1 < height)
                dp[i][j] += dp[i + 1][j - 1];
        }
    }
    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[0].size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[startPos][steps];
}

int main()
{
    cout<<"\nNo Of Ways="<<countWays(3, 3, 0);
}
