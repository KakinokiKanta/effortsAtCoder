// g++ a.cpp -o a
// cat input.txt | ./a ./a < input.txt
#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
 
int main(void){
    int n, k;
    cin >> n >> k;
 
    vector<int> a(n, 0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    long long fac_n = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            fac_n++;
        }
    }
 
    vector<vector<int>> f1(fac_n, vector<int>(n));
    long long iter_f1 = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            vector<int> na = a;
            reverse(na.begin() + i, na.begin() + j + 1);
            f1[iter_f1] = na;
            iter_f1++;
        }
    }
 
    for(int i = 0; i < fac_n - 1; i++){
        for(int j = 0; j < fac_n - 1 - i; j++){
            bool change_flag = false;
            for(int k = 0; k < n; k++){
                if(f1[j][k] > f1[j + 1][k]) change_flag = true;
                if(f1[j][k] < f1[j + 1][k]) break;
            }
            if(change_flag){
                vector<int> tmp_f = f1[j];
                f1[j] = f1[j + 1];
                f1[j + 1] = tmp_f;
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        cout << f1[k - 1][i] << " " << flush;
    }
    cout << endl;
    return 0;
}