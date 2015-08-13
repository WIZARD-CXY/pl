class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    struct cell{
        int i;
        int j;
        int h;
    };
    
    struct cmp{
        bool operator()(const cell &a ,const cell &b){
            return a.h > b.h;
        }
    };
    
    int trapRainWater(vector<vector<int> > &heights) {
        // write your code here
        m=heights.size();
        n=heights[0].size();
        
        vis=vector<vector<bool> > (m,vector<bool>(n,0));
        
        int res=0;
        // Put the cells on the border into min heap.
        for (int i = 0; i < m; ++i) {
            minheap.push(cell{i, 0, heights[i][0]});
            minheap.push(cell{i, n - 1, heights[i][n - 1]});
        }
        for (int j = 0; j < n; ++j) {
            minheap.push(cell{0, j, heights[0][j]});
            minheap.push(cell{m - 1, j, heights[m - 1][j]});
        }

        // BFS with priority queue (min heap)
        while (!minheap.empty()) {
            cell c = minheap.top();
            minheap.pop();
            vis[c.i][c.j] = true;

            res += fill(heights, c.i + 1, c.j, c.h); // Up
            res += fill(heights, c.i - 1, c.j, c.h); // Down
            res += fill(heights, c.i, c.j + 1, c.h); // Right
            res += fill(heights, c.i, c.j - 1, c.h); // Left
        }

        return res;
    }
    int fill(vector<vector<int>>& heights, int i, int j, int height) {
        // Out of border.
        if ( i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        // Fill unvisited cell.
        if (!vis[i][j]) {
            vis[i][j] = true; // Marked as visited.
            //use the max of the neighbour
            minheap.push(cell{i, j, max(height, heights[i][j])});
            return max(0, height - heights[i][j]); // Fill in the gap.
        }

        return 0;
    }
private:
    int m;
    int n;
    priority_queue<cell,vector<cell>,cmp> minheap;
    vector<vector<bool> > vis;
};
