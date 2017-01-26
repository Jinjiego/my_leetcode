#include"stdafx.h"
class Array{
	vector<float> ArrayData;
	Array(){
		
		ArrayData.push_back(1);
		ArrayData.push_back(2);
	
	}
	~Array(){
	}
	//==============================================================
	int search_rotated(const vector<float>&nums,float target);
	int longest_Consecutive_Sequence(const vector<int>&nums);
	vector<int> two_sum(const vector<int> &nums, int target);
	//==============================================================

	vector<vector<int>>four_sum(const vector<int> &nums, int target);
	vector<vector<int>> four_sum_map(const vector<int> &nums, int target);
	template<typename BidiIt>
	bool next_permutation(BidiIt first, BidiIt last);
	int trap(const vector<int> &A);
	//==============================================================
	void rotate(vector<vector<int>>& matrix);
	vector<int>  plus_one(vector<int> &digits, int digit);
	int singleNumber(vector<int> &nums);

};