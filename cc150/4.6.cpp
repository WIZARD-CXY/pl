TreeNode* findInSucc(TreeNode *node){
	if(node->right){
		findleftmost(root->right);
	}else{
		// node->right == NULL
		// find upward
        TreeNode *q=node;
		TreeNode *x=node->parent;
		while(x &&x->left!=node){
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