#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int v):val(v){
		left=right=NULL;
	}
};

TreeNode* insertNode(TreeNode *root, int val){
	if(root==NULL){
		root=new TreeNode(val);
		return root;
	}

    TreeNode *cur=root;
	
	while(cur){
		if(val<=cur->val){
			if(cur->left){
				cur=cur->left;
			}else{
				cur->left=new TreeNode(val);
				break;
			}
		}else{
			if(cur->right){
				cur=cur->right;
			}else{
				cur->right=new TreeNode(val);
				break;
			}
		}
	}

	return root;
}

TreeNode* findleftmostnode(TreeNode *root){
	while(root->left){
		root=root->left;
	}

	return root;
}

void convert(TreeNode* node, TreeNode* &last_node){
	//use inorder traversal

	if(node==NULL){
		return;
	}

	//convert on the left sub tree
	if(node->left){
		convert(node->left,last_node);
	}
	//adjust the node's left
	node->left=last_node;
	if(last_node!=NULL){
		last_node->right=node;
	}
	// update the last node to be the node
	last_node=node;

	//convert on the right subtree
	if(node->right!=NULL){
		convert(node->right,last_node);
	}
	
}

TreeNode* BST2List(TreeNode *root){
	if(root==NULL){
		return NULL;
	}

	TreeNode *head=findleftmostnode(root);
	TreeNode *last_node=NULL;

	//convert
	convert(root,last_node);

	return head;
}


void printList(TreeNode *node){
	while(node){
		cout<<node->val<<" ";
		node=node->right;
	}
}

void printTree(TreeNode *root){
	//use inorder traversal
	if(root){
		printTree(root->left);
		cout<<root->val<<" ";
		printTree(root->right);
	}
}
int main(){
	TreeNode *root=NULL;
	
	srand(time(NULL));
	cout<<"Inserting data..."<<endl;

	for(int i=0; i<10; i++){
		// generate 10 random number
		int data=rand()%100;

		cout<<data<<" ";
		root=insertNode(root,data);
	}
	cout<<endl;

	cout<<"The bst is"<<endl;

	printTree(root);
	cout<<endl;

	root=BST2List(root);
	cout<<"the list is"<<endl;
	printList(root);
}