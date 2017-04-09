#include "stl.h"
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> hash;
		hash.push_back("");
		hash.push_back("");
		hash.push_back("abc");
		hash.push_back("def");
		hash.push_back("ghi");
		hash.push_back("jkl");
		hash.push_back("mno");
		hash.push_back("pqrs");
		hash.push_back("tuv");
		hash.push_back("wxyz");

		vector<string> res;

		if (digits.empty())	return res;

		for (int i = 0; i < hash[digits[0] - '0'].size(); i++) {
			res.emplace_back(1, hash[digits[0] - '0'][i]);
		}

		for (int i = 1; i < digits.size(); i++) {
			vector<string> tmp;
			for (int j = 0; j < res.size(); j++)
				for (int k = 0; k < hash[digits[i] - '0'].size(); k++) {
					tmp.emplace_back(res[j] + hash[digits[i] - '0'][k]);
				}
			res.swap(tmp);
		}

		return res;
	}
};