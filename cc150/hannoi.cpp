void movedisks(int n , Tower orgin, Tower dst, Tower buffer){
	if(n<=0){
		return;
	}

	//move top n-1 pan from origin to buffer, use dst as buffer
	movedisks(n-1,origin,buffer,dst);
	// move the origin top pan to dst
	moveTop(origin,dst);

	// move the top n-1 pan from buffer to dst, use origin as buffer
	movedisks(n-1,buffer,dst,orgin)

}