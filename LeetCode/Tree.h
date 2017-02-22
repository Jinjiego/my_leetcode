#pragma once
#pragma execution_character_set("unicode")
#define DataType char 
struct TreeNode{
	DataType val;
	TreeNode * left;
	TreeNode* right;
	TreeNode(DataType x) :val(x), left(nullptr), right(nullptr){
	}
};
 

class Tree
{
public:
	TreeNode * root;
	Tree();
	~Tree();
	TreeNode*  BuildTree(string& Pre, string&In,string d);
	void debug();
	void destory();
	void del_tree(TreeNode * root);
	int depth(TreeNode* root);
	int width(TreeNode* root);
	void show();
	void show(TreeNode *parent,TreeNode* root, string &prefix);
	void disp(int offset);
	void InOrder(TreeNode* root, int &count, unordered_map<char, int> &In);
	vector<vector<DataType>> levelOrderButtom(TreeNode*root);



};

