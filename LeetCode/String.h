#include"stdafx.h"
class String{

public:
	bool isPalindrome(string s);
	bool in_a_Z(char s);
	bool equal(char c1, char c2);
	void kmp_next(const string &T, vector<int> &next);
	int strStr(const string S, const string  T, int pos);
	string Add_Binary(string &a, string &b);
	bool isNumber(string s);

	void debug();
};