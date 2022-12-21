node* next(node*n){	
		//inorder_successor
iF(N->RIGHT){
	N = n->right;
	WHILE(N->left != null){
	N = n->left;
}
	Return n;
}
while(n->parent != Null){
	if(n->parent->left == node){
	Return n->parent;
	}
	N = n->parent;
}
Return null;
	}
	
node * prev(node *n){
		if(n->left){
			N = n->left;
			while(n->right != null){
				N = n->right;
			}
			Return n;
		}
		while(n->parent != NULL){
			if(n->parent->right == node)
				Return n->parent;
		}
		Return null;
}

Node* smaller_greaterequal(int v){
   // returns node with smallest value >= v
    smaller_greaterequal(root,v);   
}

Node* smaller_greaterqual(node *n, int v){
		if(!n)return n;
		if(n->val == v) return n;
		if(n->val < v) return smakker_greaterequal(n->right,v);
		
		if(n->val  > v){
			node* k = smaller_greater(n->left,v)
			if(k) return k;
			return n;
		}
}

node* larger_smallerequal(int v){
    //returns largest element in bbst <= v
    node* greater_equal(root,v);
}

node* largest_smalleqaul(node *n, v){
		if(!n)return null;
        if(n->val == v) return v;
	    if(n->val > v){
				Return laregest_smallequal(n->left);
			
		}
		if(n->val < v){
			Int k = largest_smallequal(n->lefT);
			if(k)return k;
			Return n;
		}	

}
	

