#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
#include<limits.h>
#include<stack>
#include<queue>
#include<set>
#include<cstring>
using namespace std;

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool res=false;
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        int m=board.size();
        if(m==0){
            return false;
        }
        
        int n=board[0].size();
        if(n==0){
            return false;
        }
        
        //vis matrix
        vector<vector<bool> > vis(m,vector<bool>(n,0));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j]){
                    helper(board,word,0,vis,i,j);
                }
            }
        }
        
        return res;
    }
    //dfs 
    void helper(vector<vector<char> > &board, string &word, int index, vector<vector<bool> > &vis , int x, int y){
        if(x<0 || x>= board.size() || y<0 || y>= board[0].size()){
            return;
        }
        
        if(vis[x][y]){
            return;
        }
        
        if(board[x][y]!=word[index]){
            // current not equal so prune
            return;
        }
        //currently match
        if(index==word.size()){
            res=true;
            return;
        }
        
        vis[x][y]=1;
        
        // use dfs to search 4 direction
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        for(int i=0; i<4; i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            helper(board,word,index+1,vis,xx,yy);
        }
        vis[x][y]=0;
    }
};




int main(){
    Solution sln;
    vector<vector<char> > board(3,vector<char>(4));
    board[0]={'A','B','C','E'};
    board[1]={'S','F','C','S'};
    board[2]={'A','D','E','E'};

    vector<string> words;
    words.push_back("dog");
    words.push_back("dad");
    words.push_back("dgdg");
    words.push_back("can");
    words.push_back("again");


    
    sln.exist(board,"ABCCED");
}

