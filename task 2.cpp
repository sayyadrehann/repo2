#include <iostream>
#include <vector>
#include <string>
using namespace std;

void lrs(const string& s) {
    int n = s.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for (int i =1; i<=n;i++) {
        for (int j =1; j<=n;j++) {
            if (s[i-1] == s[j-1] && i != j)
                dp[i][j] =1+dp[i-1][j-1];
            else
                dp[i][j] =max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i = n, j = n;
    string res = "";
    while (i > 0&&j >0) {
        if (s[i-1] == s[j-1] && i != j) {
            res = s[i-1] + res;
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    cout << "Longest Repeating Subsequence: " << res << "\n";
}

int main() {
    string s = "AABCBDC";
    lrs(s);
    return 0;
}
