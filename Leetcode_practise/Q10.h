#include "stl.h"

class Solution {
public:
	bool isMatch(string s, string p) {
		s.append("#");
		p.append("#");
		vector<vector<bool>> dp(p.size() + 1, vector<bool>(s.size() + 1, false));
		dp[0][0] = true;
		
		for (int i = 0; i < p.size(); i++)
			for (int j = 0; j < s.size(); j++)
			{
				if (p[i] == '*') {
					dp[i + 1][j] = dp[i][j];
					dp[i + 1][j + 1] = dp[i][j + 1];
					continue;
				}
				if (p[i + 1] != '*') {
					if (dp[i][j]) {
						dp[i + 1][j + 1] = s[j] == p[i] || p[i] == '.';
					}
				}
				else {
					if (dp[i][j] || dp[i + 1][j]) {
						dp[i + 1][j + 1] = s[j] == p[i] || p[i] == '.';
					}
					if (dp[i][j + 1]) {
						dp[i + 1][j + 1] = true;
					}
					if (dp[i][j]) {
						dp[i + 1][j] = true;
					}
				}
				
			}
		return dp[p.size()][s.size()];
	}
};