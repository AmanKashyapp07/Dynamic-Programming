#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findPaths(vector<vector<int>> &maze, int x, int y, int n, string path, vector<string> &result) {
    // Base condition: if the destination is reached, store the path
    if (x == n - 1 && y == n - 1) {
        result.push_back(path);
        return;
    }

    // Save the original value and mark the current cell as visited
    int temp = maze[x][y];
    maze[x][y] = -1;

    // Explore in all possible directions
    // Move Down
    if (x + 1 < n && maze[x + 1][y] == 1) {
        findPaths(maze, x + 1, y, n, path + "D", result);
    }

    // Move Left
    if (y - 1 >= 0 && maze[x][y - 1] == 1) {
        findPaths(maze, x, y - 1, n, path + "L", result);
    }

    // Move Right
    if (y + 1 < n && maze[x][y + 1] == 1) {
        findPaths(maze, x, y + 1, n, path + "R", result);
    }

    // Move Up
    if (x - 1 >= 0 && maze[x - 1][y] == 1) {
        findPaths(maze, x - 1, y, n, path + "U", result);
    }

    // Backtrack: restore the original value of the cell
    maze[x][y] = temp;
}

vector<string> ratInMaze(vector<vector<int>> &maze, int n) {
    vector<string> result;
    if (maze[0][0] == 1) { // Start only if the initial cell is not blocked
        findPaths(maze, 0, 0, n, "", result);
    }
    sort(result.begin(), result.end()); // Sort the result in lexicographical order
    return result;
}

int main() {
    int n;
    cout << "Enter the size of the matrix (N): ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter the matrix values (0 for blocked, 1 for open):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    vector<string> paths = ratInMaze(maze, n);
    if (paths.empty()) {
        cout << "No paths available.\n";
    } else {
        cout << "Possible paths:\n";
        for (const string &path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}
