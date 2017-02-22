#include "stdafx.h"
#include "Tree.h"


Tree::Tree()
{
	root = nullptr;
   
}
Tree::~Tree()
{
	this->destory();
	cout << "tree has been destoried!" << endl;
}
void Tree::destory(){
	this->del_tree(this->root);

}
void Tree::del_tree(TreeNode * root){
	if (root){
		del_tree(root->left);
		del_tree(root->right);
		delete root;
	}
}

TreeNode* Tree:: BuildTree(string &Pre, string &In,string d){
	// build tree with previous tranverse and Inorder 
	//cout <<d<< "=======================================" << endl;
	//cout <<d<< "Pre=" << Pre << ",In=" << In << endl;
	if (Pre.size() == 0 || In.size() == 0){
		return nullptr;
	}else{
		TreeNode *cur=new TreeNode(Pre[0]);
		cout <<d<< "create node " << Pre[0] << endl;
		int rooti = In.find(Pre[0]);
		d += "    ";
		cur->left=BuildTree(Pre.substr(1,rooti ), In.substr(0, rooti),d);
		cur->right=BuildTree(Pre.substr(rooti + 1, Pre.size()), In.substr(rooti + 1, In.size()),d);
		return cur;
	}
}
void Tree::disp(int offset){
	queue<TreeNode *> q;
	q.push(this->root);
	unordered_map<DataType, int> InOrd;
	int count = 0; 
	this->InOrder(this->root,count,InOrd);//获得中序遍历序列
	while (!q.empty()){
		vector<TreeNode*> cache;
		//把处在同一行的节点拉出来
		while (!q.empty()){ cache.push_back(q.front()); q.pop(); }
		string line = "";
		for (int i = 0; i < InOrd.size() + offset; line += "  ", ++i);
		for (auto p:cache)
		if (p){
			//找当前节点中序遍历位置
			int index = offset + 2 * InOrd[p->val] + 1;
			line[index] = p->val;
			//孩子节点入队
			if (p->left)  q.push(p->left);
			if (p->right) q.push(p->right);
		}	
		cout << line << endl;
	}
	cout  << "=======================================" << endl;
}
void Tree::InOrder(TreeNode* root, int &count,unordered_map<DataType,int> &In){
	if (root){
		InOrder(root->left,count, In);
		In [ root->val]=count;count++;
		InOrder(root->right,count,In);
	}
}
vector<vector<DataType>> Tree::levelOrderButtom(TreeNode*root){

	queue<TreeNode *> q;
	vector<vector<DataType>> result;
	q.push(root);
	while (!q.empty()){
		vector<TreeNode*> cache;
		vector<DataType> vec;
		while (!q.empty()){ cache.push_back(q.front()); q.pop(); }
		for (auto p:cache)
		if (p){
		   vec.push_back(p->val);
		   if (p->left) q.push(p->left);
		   if (p->right) q.push(p->right); 
		}
		result.push_back(vec);
	}

	reverse(result.begin(),result.end());
	return result;



}
void Tree::show(){
	cout << "========================================" << endl;
	this->show(this->root, this->root, string("   "));
	cout << "========================================" << endl;
}
void Tree::show(TreeNode *parent,TreeNode* root,string &prefix){
	prefix += "|";
	if (root){
		cout << prefix<<"--" << root->val << endl;
		if (root==parent||root == parent->right){
			prefix.pop_back(); prefix += " ";
		}
		show(root,root->left, prefix+"  ");
		show(root,root->right, prefix+"  ");
	}else{
		if (parent->left || parent->right) //有一个孩子节点不空就打印，以区分左右孩子
		   cout << prefix << "--" << "{}"<< endl;
	}

}
vector<DataType> postorderTraversal(TreeNode * root){
	vector<DataType> result;
	TreeNode  dummy('-');
	return result;
}

int Tree::depth(TreeNode* root){
	if (!root) return 0;
	return max(depth(root->left), depth(root->right) )+ 1;

}
int Tree::width(TreeNode* root){
	if (!root) return 0;
	return width(root->left) + width(root->right) + 1;

	 
}
void Tree::debug(){
	int a = 0;
	this->root = this->BuildTree(string("ABDHIEJKCFLMGNO"), string("HDIBJEKALFMCNGO"), " ");
	this->show();
	this->disp(5);
	 
	vector<vector<DataType>> result=this->levelOrderButtom(this->root);

	this->root=this->BuildTree(string("ABDEHJKLMNCFGI"),string("DBJHLKMNEAFCGI")," ");
	this->show();
	this->disp(5);
	cout << this->depth(this->root)<<endl;
	cout << this->width(this->root)<<endl;
	


}