#include"Array.h"
//=================2017-01-22===========================================
int Array::search_rotated(const vector<float>&ArrayData, float target){
	int first = 0, last =ArrayData.max_size(),mid;
	while (first!=last){
		mid = (int)(first + last) / 2;
		if (target == ArrayData[mid]) return mid;
		if (ArrayData[first] <=ArrayData[mid]){
		    
			if (ArrayData[first] <= target && target < ArrayData[mid])
				last = mid;
			else
				first = mid + 1;		
		}else{
			if (ArrayData[mid] <= target && target < ArrayData[last - 1])
				first = mid + 1;
			else
				last = mid;
		}
	}
	return -1;
}
int Array::longest_Consecutive_Sequence(const vector<int>&nums){
	  unordered_map<int, bool> used;
	  for (auto i : nums)  used[i] = false;
	  int  Longest = 0;
	  for (auto i : nums){
		  if (used[i]) continue;
		  int length = 1;
		  used[i] = true;
		  for (int j = i + 1; used.find(j) != used.end(); j++){
			  used[j] = true;
			  length++;
		  }
		  for (int j = i - 1; used.find(j) != used.end(); j--){
			  used[j] = true;
			  length++;

		  }
		  Longest= Longest>length ? Longest : length;

	  }
	  return  Longest;

}
vector<int> Array::two_sum(const vector<int> &nums, int target){
	unordered_map<int, int> mapping;
	vector<int> result;

	for (int i = 0; i < nums.size(); i++) mapping[nums[i]] = i;
	for (int i = 0; i < nums.size(); i++){
		const int gap = nums[i] - target;
		if (mapping.find(gap) != mapping.end() && mapping[gap]>i){
			result.push_back(i + 1);
			result.push_back(mapping[gap]+1);
		
		 }

	
	
	}




}
vector<vector<int>> three_sum(const vector<int> &nums,int target){
	vector<vector<int>> result;

	sort(nums.begin(), nums.end());
	auto last = nums.begin();
	for (auto i = nums.begin(); i != last-2; i++) {
		auto j = i + 1;
		if (i > nums.begin() && *i == *(i - 1)) continue;
		auto k = last - 1;
		while (j<k){
			if (*i + *j + *k < target){
				j++;
				while (*j == *(j + 1) && j<k) j++;

			}
			else if (*i + *j + *k>target){
				k--;
				while (*k == *(k - 1) && k>j) k--;
			
			}
			else{
				result.push_back({ *i, *j, *k });
				j++; k--;
				while (*j == *(j + 1) && *k == *(k - 1) && j < k) j++;			
			}
		}
	
	}
	return result;



}
//=================2017-01-23==============================================
vector<vector<int>> Array::four_sum(const vector<int> &nums, int target){
	vector<vector<int>> result;
	if (nums.size() < 4) return result;
	sort(nums.begin(), nums.end());
	auto last = nums.end();
	for (auto i = nums.begin(); i < prev(last, 3); i++){
		for (auto j = next(i); j < prev(last,2); j++){
	       
			auto k = next(j);
			auto l = prev(last);    
			while (k < l){
				if (*i + *j + *k + *l < target){
					k++;
					while (*k == *(k + 1) && k<l) k++;
				}
				else if (*i + *j + *k + *l > target){
					l--;
					while (*l == *(l - 1) && k < l) --l;
				}
				else{
					result.push_back({ *i, *j, *k, *l });
					++k; --l;
				}
			}
		}
	}
}
vector<vector<int>> Array::four_sum_map(const vector<int> &nums, int target){
	vector<vector<int>> result;

	unordered_map<int,vector<pair<int, int>> > cache;
	for (size_t a = 0; a < nums.size(); a++)
	for (size_t b = a+1; b < nums.size(); b++){
		cache[nums[a] + nums[b]].push_back(pair<int, int>(a, b));
	}
	for (size_t c = 0; c < nums.size();c++)
	for (size_t d = c + 1; d < nums.size(); d++){
		const int key = target - nums[c] - nums[d];
		if (cache.find(key) == cache.end())continue;
		const auto& vec = cache[key];
		for (size_t k = 0; k < nums.size(); k++){
			if (c <= vec[k].second) continue;
			result.push_back({ nums[vec[k].first], nums[vec[k].second], nums[c], nums[d] });

		}
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;

}
template<typename BidiIt>
bool Array::next_permutation(BidiIt first, BidiIt last){
	const auto rfirst = reverse_iterator<BidiIt>(last);
	const auto rlast = reverse_iterator<BidiIt>(first);
	auto pivot = next(rfirst);

	while (pivot != rlast && *pivot >= *prev(pivot)) ++pivot;

	if (pivot == rlast){
		reverse(rfirst, rlast);
		return false;
	
	}
	auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
	swap(*change,*pivot);
	reverse(rfirst, pivot);
	return true;


}
int Array::trap(const vector<int> &A){
	const int n = A.size();
	int *max_left = new int[n]();
	int *max_right = new int[n]();
	for (int i = 1; i < n; ++i){
		max_left[i] = max(max_left[i-1],A[i-1]);
		max_right[i] = max(max_right[n-i], A[n-i]);
	}
	int sum = 0;
	for (int i = 0; i < n; ++i){
		int height = min(max_left[i],max_right[i]);
		if (height>A[i]){
			sum += height - A[i];
		}
	}
	delete[] max_left;
	delete[] max_right;
	return sum;

}
//=================2017-01-24=============================================
//Rotate Image
void Array::rotate(vector<vector<int>>& matrix){
	const int n = matrix.size();
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n - i; j++){
		swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
	}
	for (int i = 0; i < n / 2;i++)
	for (int j = 0; j < n; j++){
		swap(matrix[i][j],matrix[n-1-i][j]);
	}
}
//plus one 
vector<int>  Array::plus_one(vector<int> &digits, int digit){
	int c = digit;
	for (auto it = digits.rbegin(); it != digits.rend(); ++it){
		*it += c;
		c = *it / 10;// 有没有进位
		*it = *it % 10;
	}
	return digits;
}
int Array::singleNumber(vector<int> &nums){
	int x=0;
	for (auto i : nums){
		x ^= i;
	}
	return x;

}
int singleNumberII(vector<int> &nums){
	const int W = sizeof(int)* 8;
	int count[W];
	fill_n(count, W, 0);
	for (auto num : nums)
	for (int i = 0; i < W; i++){
		count[i] += (num >> i) & 1;
		count[i] %= 3;
	}
	int result = 0;
	for (int i = 0; i < W; i++){
		result += (count[i] << i);
	   
	}
	return result; 


}
 