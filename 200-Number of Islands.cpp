//这道题其实就是找连通分量
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int rows = grid.size();
		if (rows == 0) return 0;
		int cols = grid[0].size();
		if (cols == 0) return 0;

		int islands = 0;
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				if (grid[i][j] == '1'){
					islands++;
					grid[i][j] = '#';
					dfs(grid, i + 1, j, rows, cols);
					dfs(grid, i - 1, j, rows, cols);
					dfs(grid, i, j + 1, rows, cols);
					dfs(grid, i, j - 1, rows, cols);
				}
			}
		}
		return islands;
	}

	void dfs(vector<vector<char>>& grid, int r, int c, int rows, int cols){
		if (0 <= r && r < rows && 0 <= c && c < cols){
			if (grid[r][c] == '1'){
				grid[r][c] = '#';
				dfs(grid, r + 1, c, rows, cols);
				dfs(grid, r - 1, c, rows, cols);
				dfs(grid, r, c + 1, rows, cols);
				dfs(grid, r, c - 1, rows, cols);
			}
		}
	}
};