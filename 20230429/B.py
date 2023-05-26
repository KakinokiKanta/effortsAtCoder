# g++ Template.cpp -o Template
# cat input.txt | ./Template ./Template < input.txt
#include<bits/stdc++.h>


void shift_ver(vector<vector<char>> &grid, int h, int w){

    vector<char> tmp_space = grid[0];
    for(int i = 0; i < h - 1; i++){
        for(int j = 0; j < w; j++){
            grid[i][j] = grid[i + 1][j];
        }
    }
    grid[h - 1] = tmp_space;
}

void shift_sq(vector<vector<char>> &grid, int h, int w){

    for(int i = 0; i < h; i++){
        char tmp_space = grid[i][0];
        for(int j = 0; j < w - 1; j++){
            grid[i][j] = grid[i][j + 1];
        }
        grid[i][w - 1] = tmp_space;
    }
}

int main(void)
    hw = list(map(int, input().split()))

    for i in hw[0] - 1:
        for j in hw[1] - 1:
            a[i][j] = input()

    for i in hw[0] - 1:
        for j in hw[1] - 1:
            b[i][j] = input()

    exist_flag = false
    grid_flag = false
    for i in h - 1:
        if(i != 0) shift_ver(a, h, w) // 縦にシフトする関数
        for(int j = 0; j < w + 1; j++)
            if(j != 0) shift_sq(a, h, w); // 横にシフトする関数
            for(int k = 0; k < h; k++)
                for(int l = 0; l < w; l++)
                    if(a[k][l] != b[k][l])
                        grid_flag = true;
                        break;
                if(grid_flag) break;
            if(!grid_flag) exist_flag = true;
            if(exist_flag) break;
            grid_flag = false;
        if(exist_flag) break;
    
    if(exist_flag)
        cout << "Yes"<< endl;
    else
        cout << "No"<< endl;
    
    return 0;
