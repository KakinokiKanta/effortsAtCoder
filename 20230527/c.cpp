// g++ a.cpp -o a
// cat input.txt | ./a ./a < input.txt
#include<bits/stdc++.h>
using namespace std;
 
int main(void){
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pair<int, int>> item;
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        item.insert({x, y});
    }

    int t_x = 0;
    int t_y = 0;

    for(int i=0; i<n; i++){
        h--;

        if(s[i] == 'R'){
            t_x++;
        }else if(s[i] == 'L'){
            t_x--;
        }else if(s[i] == 'U'){
            t_y++;
        }else{
            t_y--;
        }
        if(h < 0){
            cout << "No" << endl;
            return 0;
        }

        if((h < k) && item.count({t_x, t_y})){
            item.erase({t_x, t_y});
            h = k;
        }
    }

    cout << "Yes" << endl;
    return 0;
}