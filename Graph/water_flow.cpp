#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int row = heights.size();
    int col = heights[0].size();

    queue<pair<int, int>> qP;
    queue<pair<int, int>> qA;


    vector<vector<int>> ans;

    vector<bool> vis1[row];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            vis1[i].push_back(0);
        }
    }

    int di[4] = {1, 0, -1, 0}, dj[4] = {0, 1, 0, -1};

    for (int i = 0; i < row; i++)
    {
        qP.push({i, 0});
        vis1[i][0] = true;
    }
    for (int i = 0; i < col; i++)
    {
        qP.push({0, i});
        vis1[0][i] = true;
    }

    while (!qP.empty())
    {
        int ri = qP.front().first;
        int rj = qP.front().second;
        qP.pop();

        for (int i = 0; i < 4; i++)
        {
            if ((ri + di[i]) < 0 || (ri + di[i]) >= row || (rj + dj[i]) < 0 || (rj + dj[i]) >= col)
                continue;
            if ((heights[ri + di[i]][rj + dj[i]] >= heights[ri][rj]) && !(vis1[ri + di[i]][rj + dj[i]]))
            {
                vis1[ri + di[i]][rj + dj[i]] = true;
                qP.push({ri + di[i], rj + dj[i]});
            }
        }
    }

    vector<bool> vis2[row];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            vis2[i].push_back(0);
        }
    }


    for (int i = 0; i < row; i++)
    {
            qA.push({i, col - 1});
            vis2[i][col - 1] = true;
    }
    for (int i = 0; i < col; i++)
    {
            qA.push({row - 1, i});
            vis2[row - 1][i] = true;
    }

    

    while (!qA.empty())
    {
        int ri = qA.front().first;
        int rj = qA.front().second;
        qA.pop();

        for (int i = 0; i < 4; i++)
        {
            if ((ri + di[i]) < 0 || (ri + di[i]) >= row || (rj + dj[i]) < 0 || (rj + dj[i]) >= col)
                continue;
            if ((heights[ri + di[i]][rj + dj[i]] >= heights[ri][rj]) && !(vis2[ri + di[i]][rj + dj[i]]))
            {
                vis2[ri + di[i]][rj + dj[i]] = true;
                qA.push({ri + di[i], rj + dj[i]});
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(vis1[i][j] && vis2[i][j])
             ans.push_back({i,j});
        }
        
    }
    
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    vector<vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
    vector<vector<int>> ans = pacificAtlantic(heights);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}