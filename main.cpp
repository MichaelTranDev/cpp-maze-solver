#include "maze.cpp"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("maze.dat");

    if (!file) {
        cout << "Error: maze.dat not found!" << endl;
        return 1;
    }

    while (!file.eof()) {
        Maze maze(file);
        maze.printResult();
    }

    file.close();
    return 0;
}


