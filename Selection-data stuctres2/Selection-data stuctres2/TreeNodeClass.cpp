#include "TreeNodeClass.h"

BSTreeNode::BSTreeNode(int key,const char* data, BSTreeNode* left, BSTreeNode* right, BSTreeNode* parent)
{
	this->setkey(key);
	this->setdata(data);
	this->right = right;
	this->left = left; 
	this->parent = parent;
}

void BSTreeNode::Inorder()
{
	if (this->left != nullptr)
		this->left->Inorder();
	cout << " " << this->key << " ";
	if (this->right != nullptr)
		this->right->Inorder();

	cout << endl;
}

void BSTreeNode::Preorder()
{
	cout << " " << this->data << " ";
	if (this->left != nullptr)
		this->left->Inorder();	
	if (this->right != nullptr)
		this->right->Inorder();

	cout << endl;
}

void BSTreeNode::Postorder()
{
	
	if (this->left != nullptr)
		this->left->Inorder();
	if (this->right != nullptr)
		this->right->Inorder();
	cout << " " << this->data << " ";

	cout << endl;
}

int BSTreeNode::getkey() const
{
	return this->key;
}

void BSTreeNode::setkey(int key)
{
	this->key = key;
}

const char* BSTreeNode::getdata() const
{
	return this->data;
}

void BSTreeNode::setdata(const char* data)
{
	strcpy(this->data, data);
}

BSTreeNode* BSTreeNode::getleft() const
{
	return this->left;
}

void BSTreeNode::setleft(BSTreeNode* left)
{
	this->left = left;
}

BSTreeNode* BSTreeNode::getright() const
{
	return this->right;
}

void BSTreeNode::setright(BSTreeNode* right)
{
	this->right = right;
}

BSTreeNode* BSTreeNode::getpartent() const
{
	return this->parent;
}

void BSTreeNode::setparent(BSTreeNode* parent)
{
	this->parent = parent;
}

void BSTreeNode::FindkNumber(int& k, int& NumComp, Person &res)
{//go over the tree in inorder way, reduce k each time it gets to root.
 //When k reach 0 it's the root with key we are looking for. Return from all recursive calls.
	if (k <= -1)
		return;

	if (this->left != nullptr)
		this->left->FindkNumber(k, NumComp,res);
	k--; 
	NumComp++;
	if (k == 0)
	{
		res.setId(this->getkey());
		res.setName(this->getdata());
		k = -1;
	}
	if (this->right != nullptr)
		this->right->FindkNumber(k, NumComp,res);
}