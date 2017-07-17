#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void print_map(vector<vector<int>> &map, int w, int h);

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define BLUE    "\033[34m"      /* Blue */

int main() {

    // (1, 4), (2, 1), (4, 5), and (5, 0)

    ifstream ifs("input.txt");
    unsigned c, w, h, g;
    ifs >> c;

    while (c--) {
        ifs >> w >> h >> g;

        int num;
        int row_sum[w];
        int col_sum[h];
        vector<vector<int>> map(w, vector<int>(h, 0));
        for (int i = 0; i < w; i++) {
            col_sum[i] = 0;
            for (int j = 0; j < h; j++) {
                ifs >> num;
                map[i][j] = num;
            }
        }

        for (int i = 0; i < h; i++) {
            row_sum[i] = 0;
            for (int j = 0; j < w; j++)
                row_sum[i] = row_sum[i] + map[i][j];
        }

        for (int j = 0; j < w; j++) {
            col_sum[j] = 0;
            for (int i = 0; i < h; i++)
                col_sum[j] = col_sum[j] + map[i][j];
        }

        for (int i = 0; i < h; i++) {
            cout << "row " << i << ": " << row_sum[i] << "\t";
            cout << "col " << i << ": " << col_sum[i] << endl;
        }

        cout << endl;

        print_map(map, w, h);
    }


    ifs.close();
    return 0;
}

void print_map(vector<vector<int>> &map, int w, int h) {
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (i == 1 || i == 2 || i == 5 || i == 6) cout << BLUE;
            if (j == 1 || j == 2 || j == 5 || j == 6) cout << BLUE;
            if (i == 1 && j == 4) cout << RED;
            if (i == 2 && j == 1) cout << RED;
            if (i == 5 && j == 2) cout << RED;
            if (i == 6 && j == 5) cout << RED;
            cout << map[i][j] << " ";
            cout << RESET;
        }
        cout << endl;
    }
}