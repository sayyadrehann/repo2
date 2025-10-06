#include <bits/stdc++.h>
using namespace std;


struct Cell {
    int val;
    char dir;
};


pair<string, vector<vector<Cell>>> LCS(string a, string b) {
    int m = a.size(), n = b.size();
    vector<vector<Cell>> c(m + 1, vector<Cell>(n + 1, {0, 'h'}));


   
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                c[i][j].val = c[i - 1][j - 1].val + 1;
                c[i][j].dir = 'd';
            } else if (c[i - 1][j].val >= c[i][j - 1].val) {
                c[i][j].val = c[i - 1][j].val;
                c[i][j].dir = 'u';  
            } else {
                c[i][j].val = c[i][j - 1].val;
                c[i][j].dir = 's';  
            }
        }
    }


   
    function<string(int, int)> Print_lcs = [&](int i, int j) -> string {
        if (i == 0 || j == 0) return "";
        if (c[i][j].dir == 'd')
            return Print_lcs(i - 1, j - 1) + a[i - 1];
        else if (c[i][j].dir == 'u')
            return Print_lcs(i - 1, j);
        else
            return Print_lcs(i, j - 1);
    };


    string lcs_str = Print_lcs(m, n);
    return {lcs_str, c};
}


int main() {
    string a = "GDVEGTA";
    string b = "GVCEKST";


    auto result = LCS(a, b);
    string lcs_str = result.first;


    cout << "LCS: " << lcs_str << endl;
    return 0;
}
