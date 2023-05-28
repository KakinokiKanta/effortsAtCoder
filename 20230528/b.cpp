// g++ a.cpp -o a
// cat input.txt | ./a ./a < input.txt
#include<bits/stdc++.h>
using namespace std;
 
int main(void){
    int t;
    cin >> t;
    vector<long long> n(t);
    for(int i=0; i<t; i++){
        cin >> n[i];
    }

    for(int i=0; i<t; i++){
        long long result = -1;
        // if(n[i] < 7) break;

        int i_max;
        for(i_max=0; pow(2, i_max)<n[i]; i_max++){
        }

        for(long long j=n[i]; j>0; j--){
            int count_1 = 0;
            long long x = j;
            long long sum = 0;
            for(int k=i_max; k>=0; k--){
                if(pow(2, k) <= x){
                    count_1++;
                    x -= pow(2, k);
                    sum += pow(2, k);
                }
                if(x == 0) break;
                if(count_1 == 3) break;
            }
            if(count_1 == 3){
                result = sum;
                break;
            }
        }
        cout << result << endl;
    }
    
    return 0;
}