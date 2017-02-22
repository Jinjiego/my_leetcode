// LeetCode.cpp : 定义控制台应用程序的入口点。
//
#pragma once
#pragma execution_character_set("unicode")
#include "stdafx.h"
#include "Array.h"
#include"String.h"
#include"Stack_Queue.h"
#include"Tree.h"
int _tmain(int argc, _TCHAR* argv[])
{
	Array arry;
	vector<int> nums{ 1, 1,1, 2, 2, 4,4,4, 5, 5,6 };
	arry.removeDuplicates_nth(nums);

	Tree tree;
	tree.debug();
	Stack_Queue sq;
	sq.debug();

	String s;
	cout<<s.isPalindrome("A man,A plan,a canal:Panama");
	s.debug();
	int a;
	cin >> a;
	return 0;
}

