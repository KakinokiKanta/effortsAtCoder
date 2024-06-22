// g++ b.cpp -o b
// cat input.txt | ./b ./b < input.txt
#include<bits/stdc++.h>
using namespace std;
 
int main(void){
  int n;
  cin >> n;

  int a;
  queue<int> tmp_a;
  cin >> a;
  tmp_a.push(a);
  cin >> a;
  tmp_a.push(a);

  int count = 0;

  for (int i=2; i<2*n; i++) {
    cin >> a;
    tmp_a.push(a);
    if (tmp_a.front() == a)
    {
      count++;
    }
    tmp_a.pop();
  }

  cout << count << endl;

  return 0;
}
