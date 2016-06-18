void movedisks(int n , Tower orgin, Tower dst, Tower buffer){
	if(n<=0){
		return;
	}

	//move top n-1 disk from origin to buffer, use dst as buffer
	movedisks(n-1,origin,buffer,dst);
	// move the origin top disk to dst
	moveTop(origin,dst);

	// move the top n-1 disk from buffer to dst, use origin as buffer
	movedisks(n-1,buffer,dst,orgin)

}