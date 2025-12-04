#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

class Maze {
private:
    char grid[20][20];
    bool solvable;

    bool solveMaze() {
        int startRow = 0, startCol = 0;

        // Find S
        for (int r = 0; r < 20; r++) {
            for (int c = 0; c < 20; c++) {
                if (grid[r][c] == 'S') {
                    startRow = r;
                    startCol = c;
                }
            }
        }

        bool visited[20][20] = {false};
        queue<pair<int, int>> q;

        q.push({startRow, startCol});
        visited[startRow][startCol] = true;

        int directions[4][2] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int row = current.first;
            int col = current.second;

            if (grid[row][col] == 'E') {
                return true;
            }

            for (auto& d : directions) {
                int newRow = row + d[0];
                int newCol = col + d[1];

                if (newRow >= 0 && newRow < 20 &&
                    newCol >= 0 && newCol < 20 &&
                    !visited[newRow][newCol] &&
                    grid[newRow][newCol] != '#') {

                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }
            }
        }

        return false;
    }

public:
    Maze(ifstream& file) {
        string line;

        for (int r = 0; r < 20; r++) {
            getline(file, line);
            for (int c = 0; c < 20; c++) {
                grid[r][c] = line[c];
            }
        }

        // Skip blank line between mazes
        if (!file.eof()) {
            getline(file, line);
        }

        solvable = solveMaze();
    }

    void printResult() {
        cout << "Maze: " << (solvable ? "YES" : "NO") << endl;
    }
};


