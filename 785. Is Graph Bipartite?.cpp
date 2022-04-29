

class Solution {
public:
    
    bool dfs(vector<vector<int>>& graph, vector<int>& colors, int src, int color) {
        
        if (colors[src])
            return colors[src] == color;
        
        colors[src] = color;
        
        for (auto n : graph[src]) {
            if (!dfs(graph, colors, n, -color)){
                return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int rows = graph.size();
        
        vector<int> colors(rows);
        
        for (int i=0; i<rows; i++) {
            if (!colors[i] && !dfs(graph, colors, i, 1)) {
                return false;
            }
        }
        
        return true;
    }
};



