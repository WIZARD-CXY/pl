TreeNode* findInSucc(TreeNode *node){
	if(node==NULL){
		return NULL;
	}
	if(node->right){
		findleftmost(root->right);
	}else{
		// node->right == NULL
		// find upward until find the q is x's left child
        TreeNode *q=node;
		TreeNode *x=node->parent;
		while(x && x->left!=q){
			q=x;
			x=x->parent;
		}

		return x;
	}
}

TreeNode* findleftmost(TreeNode *node){
	while(node->left){
		node=node->left;
	}

	return node;
}