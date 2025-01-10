#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> grid;
bool canPlace(int row, int col, int n)
{
    // check column
    for (int i = row - 1; i >= 0; i--)
    {
        if (grid[i][col] == "Q")
            return false;
    }
    // left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--)
    {
        if (grid[i][j] == "Q")
            return false;
    }
    // right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++)
    {
        if (grid[i][j] == "Q")
            return false;
    }
    // if we arrived here means safe
    return true;
}
void f(int row, int n)
{
    if (row == n)
    {
        // we placed each queen successfully
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    // travel in each column
    for (int col = 0; col < n; col++)
    {
        if (canPlace(row, col, n))
        {
            grid[row][col] = "Q";
            f(row + 1, n);
            grid[row][col] = "."; // backtrack
        }
    }
}
vector<vector<string>> nqueens(int n)
{
    grid.resize(n, vector<string>(n, "."));
    f(0, n);
}
int main()
{
    int x;
    cin >> x;
    nqueens(x);
    return 0;
}