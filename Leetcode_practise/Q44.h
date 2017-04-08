#include "stl.h"

class Solution {
public:
	bool isMatch(string s, string p) {
		s.append("#");
		p.append("#");
		vector<vector<bool>> dp(p.size() + 1,vector<bool>(s.size() + 1,false));
		dp[0][0] = true;

		for (int i = 0; i < p.size(); i++)
			for (int j = 0; j < s.size(); j++)
			{
				if (p[i] == '*') {
					if (dp[i][j])  dp[i + 1][j] = true;
					if (dp[i + 1][j] || dp[i][j + 1])  dp[i + 1][j + 1] =  true;
				}
				else if(dp[i][j]) {
					dp[i + 1][j + 1] = s[j] == p[i] || p[i] == '?';
				}
			}
		return dp[p.size()][s.size()];
	}
};