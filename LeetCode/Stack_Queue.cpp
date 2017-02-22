
#include "Stack_Queue.h"


Stack_Queue::Stack_Queue()
{
}


Stack_Queue::~Stack_Queue()
{
}
//===================2017-02-03=======================
bool Stack_Queue::bracket_is_match(string text){
	stack<char> stk;
	for (int i = 0; i < text.length(); i++){
		switch (text[i])
		{
		case '(':
		case '[':
		case '{':
			stk.push(text[i]);
			break;
		case ')':
			if ('(' == stk.top()){
				stk.pop();
			}else{return false;}
			break;
		case ']':
			if ('[' == stk.top()){
				stk.pop();
			}else{return false;}
			break;
		case '}':
			if ('{' == stk.top()){	stk.pop();}
			else{return false;}
			break;
		default:
			break;
		}
	}
	return stk.empty();
}
int Stack_Queue::LongestValidParentheses(string text){
	int max_len = 0, last = -1;
	stack<int> left;
	for (int i = 0; i < text.length();++i){
		if (text[i] == '('){
			left.push(i);
		}else{
			if (left.empty()){
				last = i;
			}else{
				left.pop();//the top in stack left must be '('
				if (left.empty()){
					max_len = max(max_len,i-last);
				}else{
					max_len = max(max_len, i - left.top());
				}
			}
		}
	}
	return max_len;
}
//===================2017-02-09=======================
int Stack_Queue::largestRectangArea(vector<int> height){
	stack<int> s;
	s.push(0);
	int result = 0;
	for (int i = 0; i < height.size();){
		if (s.empty() || height[i]>height[s.top()]){
			cout << "height[" << i << "]="<<height[i]<< " has been pushed into s!" << endl;
			s.push(i++);
		}else{
			int tmp = s.top();
			s.pop();
			result = max(result, height[tmp] * (s.empty() ? i : i - s.top() - 1));
			
			cout <<"result="<<result<< ",栈顶元素height[" << tmp << "]=" << height[tmp] << " popup! current i=" << i << endl;
		}
	}
	return result;
}
/*  思路：如果时间复杂度要求是O(n2)的话，解法比较多也比较好理解。
比如可以遍历，对于当前 i 位置上的立柱，
计算出以这个i 立柱结尾的最大矩形，然后求出总的最大矩形。
    计算以i 立柱结尾的最大矩形又需要一次遍历，因此时间复杂度是 O(n2)。
或者可以用另 一种方法：最大矩形的高度毫无疑问必然和某一个立柱的高度相等，
或者说，最大矩形必然包含了某一个立柱的全部。
因此，可以遍历所有立柱，对当前立柱 i，以其高度左右扩展，看看以当前立柱 
i 的高度最多能包含进多大的矩形面积。最后选出最大的总面积即可。
这种思路的代码如下：
*/
int largestRectangleArea(vector<int> &height){
	int max = 0;
	for (int i = 0; i < height.size(); i++){
		int mid = i;
		int area = 0;
		for (; mid >= 0 && height[i]<=height[mid]; area += height[i], mid--);
		for (mid = i + 1; mid < height.size() && height[i] <= height[mid]; area += height[mid], mid++);
		if (area>max) max = area;
	}
	return max;
}
//==================2017-02-10=========================================
int Stack_Queue::evalPRN(vector<string> &tokens){
	int x, y;
	auto _token = tokens.back(); tokens.pop_back();
	if (_token.size() == 1 && string("+-*/").find(_token) != string::npos){
	    // 判断是操作符
		x = evalPRN(tokens);
		y = evalPRN(tokens);
		if (_token[0] == '+') x += y;
		else if (_token[0] == '-') x -= y;
		else if (_token[0] == '*') x *= y;
		else x /= y;
	}else{
		size_t i;
		x = stoi(_token, &i);
	}
	return x;
}
int Stack_Queue::evalPRN_Iter(vector<string> &tokens){
	stack<string> s;
	for (auto token : tokens){
		if (token.size() == 1 && string("+-*/").find(token) != string::npos){
			s.push(token);
		}else{
			int y = stoi(s.top());
			s.pop();
			int x = stoi(s.top());
			if (token[0] == '+') x += y;
			else if (token[0] == '-') x -= y;
			else if (token[0] == '*') x *= y;
			else x /= y;
			s.push(to_string(x));
		}
	}
	return stoi(s.top());
}



void  Stack_Queue::debug(){
	cout << endl << this->largestRectangArea(vector<int>({ 2, 1, 5, 6, 2, 3 })) << endl;

	cout << endl << "Stack_Queue.bracket_is_match(\"((({ { [] } })))()()[]{()}{\"):" 
		<< this->bracket_is_match("((({{[]}})))()()[]{()}{") << endl;
	cout << endl << "Stack_Queue.bracket_is_match(\"((()))()()(((()\"):"
		<< this->LongestValidParentheses("((()))()()(((()") << endl;
	int i = 0;
}