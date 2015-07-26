Node* copy_nodestructure(Node* root){
	ma<Node*, Node*> mm;
    return copy_recursive(root,mm)
}

Node *copy_recursive(Node *root, map<Node*, Node*> &mm){
	if(root==NULL){
		return NULL;
	}

	if((it=mm.find(root))!=mm.end()){
		//already exist, just return
		return it.second;
	}

	// just new 
	Node *node = new Node;

	mm[root]=node;
	node->p1=copy_recursive(root->p1,mm);
	node->p2=copy_recursive(root->p2,mm);

	return root;
}