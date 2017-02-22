#include"String.h"
//===========2017-01-30==========================
bool String::isPalindrome(string s)
{  
	for (int i = 0, j = s.length() - 1; i < j;){
		if (in_a_Z(s[i])){
			if (in_a_Z(s[j])){
				if (!equal(s[i], s[j]))
					return false;
				i++; j--;
			}else{
				j--;
			}
		}else
		{
			++i;
		}
	}
	return true;
}
bool String::in_a_Z(char s){
	if (s >= 'a'&&s <= 'z' || s>='A'&&s<='Z'){
		return true;
	}
	return false;
}
bool String::equal(char c1, char c2){
	if (c1 - c2 == 0 || abs(c1 - c2) == 32){
		return true;
	
	}
	return false;
}
int String::strStr(const string S,const string  T,int pos){
	vector<int> next(T.length());
    kmp_next(T, next);

	for (int i = pos, j = 0;i<10;i++){
		 
	}
	return 0;

}
void String:: kmp_next(const string &T,vector<int> &next){
	int i = 1;
	


}
int atoi(string &str){
	 

	return 0;

}
string String::Add_Binary(string &a, string &b){
	string result;
	int carry = 0;
	for (int i = a.length() - 1, j = b.length() - 1; j >= 0 || i >= 0; i--, j--){
		int ai = i >=0 ? a[i] - '0' : 0;
		int bi = j >=0 ? b[j] - '0' : 0; 
		int tmp = (ai + bi + carry) % 2;
		carry = (ai + bi + carry) / 2;
		if (tmp){
			result = '1'+result;
		}else{ 
			result = '0' + result;
		}
	}
	if (carry){
		result = '1' + result;
	}
	return result;
}

bool isMatch(char * s,char* p){//¡î¡î¡î¡î¡î
	if (*p == '\0') return *s == '\0';
	if (*(p + 1) != '*'){ //the next character is not * in pattern string
		if (*p == *s || (*p == '.'&&s != '\0')){
			return isMatch(s + 1, p + 1);
		}
		else return false;
	
	}
	else{
		while (*p == *s || *p == '.'&& *s != '\0'){
			if (isMatch(s, p + 2)){
				return true;
			}
			s++;
		}
		return isMatch(s, p + 2);
	}
}

string longest_commen_prefix(vector<string> &strs){
	if (strs.empty()) return "";
	int i;
	for (i = 0;;i++){
		for (int vi = 1; vi < strs.size(); vi++){
			if (i >= strs[vi].size() || strs[vi][i] != strs[0][i]){
				return strs[0].substr(0, i);
			}
		}
	}
	return  strs[0].substr(0, i);
}

bool String::isNumber(string str){

	enum InputType{ INVALID, //0
	                SPACE,   //1
					SIGN,    //2
					DIGIT,   //3
					DOT,     //4
					EXPONENT,//5
					NUM_INPUT//6
	};
	const int TransitionTable[][NUM_INPUT] = {
	    -1,0,3,1,2,-1, //the first state cannot accepting 
		-1,8,-1,1,4,5,
	};
	 int status = 0;
	for (auto ch : str){
		InputType current_ch_type = INVALID;
		if (isspace(ch)){
			current_ch_type = SPACE;
		}else if (isdigit(ch)){
			current_ch_type = DIGIT;
		}else if (ch == '.'){
			current_ch_type = DOT;
		}else if (ch == 'e' || ch == 'E'){
			current_ch_type = EXPONENT;
		}else if (ch == '+' || ch == '-'){
			current_ch_type = SIGN;
		}
		status = TransitionTable[status][current_ch_type];
		if (status == -1) return false;
	}

	return status==1||status==4||status==7||status==8;

}
int LengthofLastWord(string str){
	int len = 0;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (str[i] != ' '){
			len++;
		}
		else if (len > 0){
			break;
		}
	}
	return len;

}
void String:: debug(){

	String S;
	isNumber("egdrt5h");

	cout<<endl<<"String:"<<S.Add_Binary(string("1100"), string("1100"));
	S.strStr("acabaabaabcacaabc", "aba abcac", 0);

}

