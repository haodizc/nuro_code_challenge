#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

void print_map(vector<vector<int>> &map, int w, int h);
void print_bool_map(vector<vector<bool>> &bool_map, int row, int col);
Coordinate convert_coordinate(int x, int y, int h);

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define BLUE    "\033[34m"      /* Blue */

struct Coordinate {
    int x;
    int y;
};

int main() {
    // https://nuro.ai/techfair

    // (1, 2), (2, 1), (4, 5), and (5, 0)
    // (1, 4), (2, 5), (4, 1), and (5, 6)

    ifstream ifs("inputs_sample.txt");
    unsigned c, col, row, g;
    ifs >> c;
    cout << c << endl << endl;
    while (c--) {
        ifs >> col >> row >> g;
        cout << "W: " << col << "\t" << "H: " << row << "\t" << "G: " << g << endl;
        int num;
        vector<vector<int>> map(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ifs >> num;
                map[i][j] = num;
            }
        }

        print_map(map, row, col);


        vector<vector<bool>> bool_map(row, vector<bool>(col, true));


        print_bool_map(bool_map, row, col);
    }


    ifs.close();
    return 0;
}

void print_map(vector<vector<int>> &map, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << map[i][j] << " ";
            cout << RESET;
        }
        cout << endl;
    }
    cout << endl;
}

void print_bool_map(vector<vector<bool>> &bool_map, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            bool_map[i][j] ? cout << RED : cout << BLUE;
            cout << bool_map[i][j] << RESET << " ";
        }
        cout << endl;
    }
    cout << endl;
}

Coordinate convert_coordinate(int x, int y, int h) {
    // 7x7
    // (1, 2), (2, 1), (4, 5), and (5, 0)
    // (1, 4), (2, 5), (4, 1), and (5, 6)

    Coordinate c = {x, h - 1 - y};
    return c;
}