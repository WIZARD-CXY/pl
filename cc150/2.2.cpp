ListNode *kthtolast(ListNode *head, int k){
	if(k<=0){
		return NULL;	
	}
	ListNode *p1=head,*p2=head;

	for(int i=0; i<k-1; i++){
		if(p1==NULL){
			return NULL;
		}
		p1=p1->next;
	}
	if(p1==NULL){
		return NULL;
	}

	while(p1->next){
		p1=p1->next;
		p2=p2->next;
	}

	return p2;
}