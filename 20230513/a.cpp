
// g++ Template.cpp -o Template
// cat input.txt | ./Template ./Template < input.txt
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    string win_result;
    cin >> win_result;

    int t_count = 0;
    int a_count = 0;
    bool win_flag = true; // Tが勝者のときtrue
    
    for(int i = 0; i < n; i++){
        if(win_result[i] == 'T'){
            t_count++;
        }else{
            a_count++;
        }

        if(t_count < a_count){
            win_flag = false;
        }else if(a_count < t_count){
            win_flag = true;
        }
    }

    if(win_flag){
        cout << 'T' << endl;
    }else{
        cout << 'A' << endl;
    }
    return 0;
}