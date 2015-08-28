#include <iostream>
using namespace std;

struct TrieNode{
	bool isWord;
	TrieNode* child[26];
	int cnt;

    TrieNode():isWord(false),cnt(0){
    	for(int i=0; i<26; i++){
    		child[i]=NULL;
    	}
    }
};

void insert(TrieNode *root, string s){
	TrieNode *p=root;
	root->cnt++;
	for(auto c : s){
		int idx=c-'a';

		if(p->child[idx]==NULL){
			// new node
			p->child[idx] = new TrieNode();
		}
		p->child[idx]->cnt++;
		p=p->child[idx];
	}
	p->isWord=true;
}

int query(TrieNode *root, string s){
	TrieNode *p=root;

	for(auto c : s){
		int idx=c-'a';

		if(p->child[idx]==NULL){
			return 0;
		}else{
			p=p->child[idx];
		}
	}

	return p->cnt;
}

int main(){
	int n;

	cin>>n;
	TrieNode *root= new TrieNode();
	for(int i=0; i<n; i++){
		string s;
		cin>>s;
		insert(root,s);
	}

	int m;
	cin>>m;

	for(int i=0; i<m; i++){
		string ss;
		cin>>ss;
		cout<<query(root,ss)<<endl;
	}
	
}