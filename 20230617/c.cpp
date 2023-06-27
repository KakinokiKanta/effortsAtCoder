// g++ a.cpp -o a
// cat input.txt | ./a ./a < input.txt
#include<bits/stdc++.h>
using namespace std;
 
int main(void){
    int n;
    cin >> n;

    map<int, bool> is_number{};
    vector<int> result;
    int count = 0;

    for (int i=0; i<(3 * n); i++) {
        int num;
        cin >> num;

        if (is_number.count(num) == 0) {
            is_number.emplace(num, true);
        } else {
            if (is_number.at(num)) {
                result.push_back(num);
                is_number[num] = false;
            } else {
                count++;
            }
        }
        if(count == n) break;
    }

    for (int i=0; i<n; i++) {
        cout << result[i] << " " << flush;
    }
    cout << endl;

    return 0;
}