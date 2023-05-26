
// g++ Template.cpp -o Template
// cat input.txt | ./Template ./Template < input.txt
#include<bits/stdc++.h>
using namespace std;

int cross_count(vector<vector<char>> grid, vector<vector<int>> &search_c, int y, int x, int h, int w){
    int count = 1;
    int start_y = y + 1;
    int start_x = x + 1;

    search_c[y][x] = 1;
    search_c[start_y][start_x] = 1;

    while(grid[start_y - 1][start_x + 1] != '#'){
        count++;
        start_y++;
        start_x++;
        search_c[start_y][start_x] = 1;
    }

    while((start_y < h) && (start_x < w) && (grid[start_y][start_x] == '#')){
        search_c[start_y][start_x] = 1;
        start_y++;
        start_x++;
    }

    return count;
}

// vector<int> cross_searcher(vector<vector<int>> search_c, int h, int w){
// }

int main(void){
    int h, w;
    cin >> h >> w;
    
    vector<vector<char>> c(h, vector<char>(w));

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> c[i][j];
        }
    }

    vector<vector<int>> search_c(h, vector<int>(w, 0));
    int min_grid = (h < w) ? h : w;
    vector<vector<int>> count_num(min_grid, vector<int>(2, 0));
    for(int i = 0; i < min_grid; i++){
        count_num[i][0] = i;
    }

    // crossの右上を探索
    for(int i = 0; i < h - 1; i++){
        for(int j = 0; j < w - 1; j++){
            if((c[i][j] == '#') && (search_c[i][j] == 0) && (c[i + 1][j + 1] == '#')){
                // crossのnをカウントする関数
                int id = cross_count(c, search_c, i, j, h, w);
                count_num[id - 1][1]++;
            }
        }
    }

    for(int i = 0; i < min_grid; i++){
        cout << count_num[i][1] << flush;
        if(i != min_grid - 1){
            cout << " " << flush;
        }else{
            cout << endl;
        }
    }

    return 0;
}