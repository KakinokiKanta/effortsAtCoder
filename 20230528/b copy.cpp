// g++ a.cpp -o a
// cat input.txt | ./a ./a < input.txt
#include<bits/stdc++.h>
using namespace std;

void x_max(int n_max, vector<bool> &f3){
    int i_max;
    for(i_max=0; pow(2, i_max)<n_max; i_max++){
    }

    int f3_ind = n_max;
    for(int i=0; i<f3_ind; i++){
        int count_1 = 0;
        int x = i;
        for(int j=i_max; j>=0; j--){
            if(pow(2, j) <= x){
                count_1++;
                x -= pow(2, j);
                if(x == 0) break;
            }
        }
        if(count_1 == 3){
            f3[i] = true;
        }
    }
}
 
int main(void){
    int t;
    cin >> t;
    vector<long long> n(t);
    for(int i=0; i<t; i++){
        cin >> n[i];
    }
    // long long n_max = *max_element(n.begin(), n.end());
    // cout << "++++++++" << endl;
    // vector<bool> f3(n_max, false);
    // x_max(n_max, f3);

    for(int i=0; i<t; i++){
        long long result = -1;

        for(long long j=n[i]; j>0; j--){
            if(f3[j]){
                result = j;
                break;
            }
        }
        cout << result << endl;
    }
    
    return 0;
}