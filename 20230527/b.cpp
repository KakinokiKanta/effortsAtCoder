// g++ a.cpp -o a
// cat input.txt | ./a ./a < input.txt
#include<bits/stdc++.h>
using namespace std;
 
int main(void){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(m, vector<int>(n));
    vector<vector<int>> a_checker(n, vector<int>(n, 0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(0 < j){
                if(!a_checker[a[i][j]-1][a[i][j-1]-1]){
                    a_checker[a[i][j]-1][a[i][j-1]-1] = 1;
                }
            }
        }
    }

    int result = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((a_checker[i][j] == 0) && (a_checker[j][i] == 0) && (i!=j)){
                result++;
            }
        }
    }
    result /= 2;
    cout << result << endl;

    return 0;
}