#include<bits/stdc++.h>
using namespace std;

int max_space(vector<vector<char>> boss_space, int h, int w){
    vector<vector<int>> check_space(h, vector<int>(w, 0));
    
    int max_num = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(boss_space[i][j] == '.'){
                int tmp_max = 1;
                int min_count = w;
                bool ver_flag = false;
                for(int k = i; k < h; k++){
                    int count_space = 0;
                    for(int l = j; l < w; l++){
                        if(boss_space[k][l] == '.'){
                            count_space++;
                        }else{
                            if(l == j) ver_flag = true;
                            break;
                        }
                    }
                    if(ver_flag) break;
                    if(count_space < min_count){
                        min_count = count_space;
                    }
                    if(tmp_max < min_count * (k - i + 1)){
                        tmp_max = min_count * (k - i + 1);
                    }
                }
                if(max_num < tmp_max) max_num = tmp_max;
            }
        }
    }
    
    return max_num;
}

int main(void){
    int h, w;
    cin >> h >> w;
    
    vector<vector<char>> boss_space(h, vector<char>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> boss_space[i][j];
            // cout << boss_space[i][j] << flush;
        }
        // cout << endl;
    }
    
    // 領域を拡張して最大のマス数を算出する関数
    int max_number = max_space(boss_space, h, w);
    
    cout << max_number << endl;
    return 0;
}