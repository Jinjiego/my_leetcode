
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
			
			cout <<"result="<<result<< ",ջ��Ԫ��height[" << tmp << "]=" << height[tmp] << " popup! current i=" << i << endl;
		}
	}
	return result;
}
/*  ˼·�����ʱ�临�Ӷ�Ҫ����O(n2)�Ļ����ⷨ�Ƚ϶�Ҳ�ȽϺ���⡣
������Ա��������ڵ�ǰ i λ���ϵ�������
����������i ������β�������Σ�Ȼ������ܵ������Ρ�
    ������i ������β������������Ҫһ�α��������ʱ�临�Ӷ��� O(n2)��
���߿������� һ�ַ����������εĸ߶Ⱥ������ʱ�Ȼ��ĳһ�������ĸ߶���ȣ�
����˵�������α�Ȼ������ĳһ��������ȫ����
��ˣ����Ա��������������Ե�ǰ���� i������߶�������չ�������Ե�ǰ���� 
i �ĸ߶�����ܰ��������ľ�����������ѡ��������������ɡ�
����˼·�Ĵ������£�
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
	    // �ж��ǲ�����
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