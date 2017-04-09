// Leetcode_practise.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Q17.h"

int main()
{
	string t = "23";
	string p = "a*";
	vector<int> g{ -1, 2, 1, 4,};
	//string p = "c*a*b";
	//int size = 1410110141;
	auto s = Solution();
	auto x = s.letterCombinations(t);
    return 0;
}

string t = "PAYPALISHIRING";