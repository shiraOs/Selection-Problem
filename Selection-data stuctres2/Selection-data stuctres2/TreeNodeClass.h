#ifndef _TREENODECLASS_H
#define _TREENODECLASS_H

#include <string.h>
#include <iostream>
#include "Person.h"
using namespace std;

#pragma warning (disable:4996)

class BSTreeNode
{
private:
    int key;
    char data[MAX_SIZE];
    BSTreeNode *left, *right, *parent;

public:
    BSTreeNode(int key,const char* data, BSTreeNode* left, BSTreeNode* right, BSTreeNode* parent);    //c'tor
    ~BSTreeNode()=default;  //d'tor
    void Inorder();
    void Preorder();    
    void Postorder();

    int getkey() const;
    void setkey(int key);
    const char* getdata() const;
    void setdata(const char* data);

    BSTreeNode* getleft() const;
    void setleft(BSTreeNode* left);
    BSTreeNode* getright() const;
    void setright(BSTreeNode* right);
    BSTreeNode* getpartent() const;
    void setparent(BSTreeNode* parent);

    void FindkNumber(int& k, int& NumComp, Person& res);
};

#endif // !_TREENODECLASS_H