// Leetcode_practise.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Q30.h"

int main()
{
	vector<vector<int>> l;
	vector<string> ss{ "bar","foo","the" };
	auto s = Solution();
	auto x = s.findSubstring("barfoofoobarthefoobarman",ss);
    return 0;
}

string t = "PAYPALISHIRING";