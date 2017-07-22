#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

void print_map(vector<vector<int>> &map, int w, int h);
void print_bool_map(vector<vector<bool>> &bool_map, int row, int col);
int matrix_min_element(vector<vector<int>> &map);
int matrix_max_element(vector<vector<int>> &map);

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define BLUE    "\033[34m"      /* Blue */

int main() {

    // https://nuro.ai/techfair

    // (1, 4), (2, 1), (4, 5), and (5, 0)

    ifstream ifs("inputs_sample.txt");
    unsigned c, col, row, g;
    ifs >> c;
    cout << c << endl;
    while (c--) {
        ifs >> col >> row >> g;
        cout << col << " " << row << " " << g << endl;
        int num;
        vector<vector<int>> map(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                ifs >> num;
                map[i][j] = num;
            }
        }

        print_map(map, row, col);

        auto min_element = matrix_min_element(map);
        auto max_element = matrix_max_element(map);
        cout << "Min element: " << min_element << endl;
        cout << "Max element: " << max_element << endl << endl;

        vector<vector<bool>> bool_map(row, vector<bool>(col, true));

        std::map<int,int> row_to_min_count;
        std::map<int,int> row_to_max_count;
        for (int i = 0; i < row; i++) {
            row_to_min_count[i] = 0;
            row_to_max_count[i] = 0;
            for (int j = 0; j < col; j++) {
                if (map[i][j] == min_element) {
                    row_to_min_count[i]++;
                }
                if (map[i][j] == max_element) {
                    row_to_max_count[i]++;
                }
            }
//            cout << "Row " << i << " min count: " << row_to_min_count[i] << endl;
        }
//        cout << endl;

        std::map<int,int> col_to_min_count;
        std::map<int,int> col_to_max_count;
        for (int j = 0; j < col; j++) {
            col_to_min_count[j] = 0;
            col_to_max_count[j] = 0;
            for (int i = 0; i < row; i++) {
                if (map[i][j] == min_element) {
                    col_to_min_count[j]++;
                }
                if (map[i][j] == max_element) {
                    col_to_max_count[j]++;
                }
            }
//            cout << "Col " << j << " min count: " << col_to_min_count[j] << endl;
        }
//        cout << endl;

//        for (int i = 0; i < row; i++) {
//            if (row_to_max_count[i] == 0) {
//                for (int j = 0; j < col; j++) {
//                    bool_map[i][j] = false;
//                }
//            }
//        }

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

int matrix_min_element(vector<vector<int>> &map) {
    std::vector<int>::iterator min_it;
    int min = std::numeric_limits<int>::max();
    for (size_t i = 0; i < map.size(); i++) {
        min_it = std::min_element(map[i].begin(), map[i].end());
        min = *min_it < min ? *min_it : min;
    }
    return min;
}

int matrix_max_element(vector<vector<int>> &map) {
    std::vector<int>::iterator max_it;
    int max = 0;
    for (size_t i = 0; i < map.size(); i++) {
        max_it = std::max_element(map[i].begin(), map[i].end());
        max = *max_it > max ? *max_it : max;
    }
    return max;
}