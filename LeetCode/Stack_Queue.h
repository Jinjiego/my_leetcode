#pragma once
#include"stdafx.h"
class Stack_Queue
{
public:
	Stack_Queue();
	~Stack_Queue();
	bool bracket_is_match(string text);
	void  debug();
	int LongestValidParentheses(string text);
	int largestRectangArea(vector<int> height);
	int evalPRN(vector<string> &token);
	int evalPRN_Iter(vector<string> &tokens);
};

