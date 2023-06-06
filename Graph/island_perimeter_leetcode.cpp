#include <bits/stdc++.h>
using namespace std;

void dfs(int tr, int tc, int i, int j, vector<vector<int>> &grid, int &perimeter)
{
    if (i < 0 || j < 0){
        perimeter += 1;
        return;}
    if (i >= tr || j >= tc){
        perimeter += 1;
        return;}
    if (!grid[i][j]){
        perimeter += 1;
        return;}
    
    if(grid[i][j] == 2){
        return;
    }
    grid[i][j] = 2;
    dfs(tr, tc, i - 1, j, grid, perimeter);
    dfs(tr, tc, i + 1, j, grid, perimeter);
    dfs(tr, tc, i, j - 1, grid, perimeter);
    dfs(tr, tc, i, j + 1, grid, perimeter);
}

int islandPerimeter(vector<vector<int>> &grid)
{
    int tr = grid.size(), tc = grid[0].size();
    int perimeter = 0, i, j, f = 0;
    for (i = 0; i < tr; i++)
    {
        for (j = 0; j < tc; j++)
        {
            if (grid[i][j])
            {
                f = 1;
                break;
            }
        }
        if (f)
            break;
    }
    dfs(tr, tc, i, j, grid, perimeter);
    return perimeter;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> grid = {{1, 1}, {1, 1}};
    cout << islandPerimeter(grid) << endl;
    return 0;
}