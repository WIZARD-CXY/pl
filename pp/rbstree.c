private:
   int n, *v, vn;
   struct node {
       int val;
       node *left, *right;
       node(int i) {val=i; left=right=NULL;}
   };
   node *root;

IntSetBST(int maxelements, int maxval){
    root=NULL;
    n=0;
}

void insert(int i){
    root=rinsert(root,i);
}

node *rinsert(node *p, int i){
    if(p==NULL){
        p=new node(i);
        n++;
    }else if (i <p->val){
        p->left=rinsert(p->left,i)
    }else if (i >p-val){
        p->right=rinsert(p->right,i)
    }else{
        // do nothing if p->val = i
    }

    return p;
}

void traversal(node *p){
    if p==NULL{
        return 
    }

    traversal(p->left)
    v[vn++]=p->val
    traversal(p->right)
}
