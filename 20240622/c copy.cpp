// g++ c.cpp -o c
// cat input.txt | ./c ./c < input.txt
#include<bits/stdc++.h>
using namespace std;

enum Direction {
  Top = 0,
  Top_Right = 1,
  Right = 2,
  Bottom_Right = 3,
  Bottom = 4,
  Bottom_Left = 5,
  Left = 6,
  Top_Left = 7,
  Center = 8,
};

Direction judgeDirection(int sx, int sy, int tx, int ty) {
  Direction direction;
  if (sx < tx) {
    if (sy < ty) {
      direction = Top_Right;
      return direction;
    } else if (sy == ty) {
      direction = Right;
      return direction;
    } else {
      direction = Bottom_Right;
      return direction;
    }
  }
  if (sx == tx) {
    if (sy < ty) {
      direction = Top;
      return direction;
    } else if (sy == ty) {
      direction = Center;
      return direction;
    } else {
      direction = Bottom;
      return direction;
    }
  }
  if (sx > tx) {
    if (sy < ty) {
      direction = Top_Left;
      return direction;
    } else if (sy == ty) {
      direction = Left;
      return direction;
    } else {
      direction = Bottom_Left;
      return direction;
    }
  }
  return direction;
}

int main(void){
  Direction direction;
  long long sx, sy;
  cin >> sx >> sy;

  long long tx, ty;
  cin >> tx >> ty;

  direction = judgeDirection(sx, sy, tx, ty);

  long long fee = 0;

  while (true) {
    if (judgeDirection(sx, sy, tx, ty) == Center) break;

    if (judgeDirection(sx, sy, tx, ty) == Top_Left || judgeDirection(sx, sy, tx, ty) == Left || judgeDirection(sx, sy, tx, ty) == Bottom_Left) {
      if (((sx % 2) == 1 && (sy % 2) == 0) || ((sx % 2) == 0 && (sy % 2) == 1)) {
        sx--;
      } else if (judgeDirection(sx, sy, tx, ty) == Top_Left) {
        sy++;
        fee++;
      } else if (judgeDirection(sx, sy, tx, ty) == Bottom_Left) {
        sy--;
        fee++;
      }
    } else if (judgeDirection(sx, sy, tx, ty) == Top_Right || judgeDirection(sx, sy, tx, ty) == Right || judgeDirection(sx, sy, tx, ty) == Bottom_Right) {
      if (((sx % 2) == 0 && (sy % 2) == 0) || ((sx % 2) == 1 && (sy % 2) == 1)) {
        sx++;
      } else if (judgeDirection(sx, sy, tx, ty) == Top_Right) {
        sy++;
        fee++;
      } else if (judgeDirection(sx, sy, tx, ty) == Bottom_Right) {
        sy--;
        fee++;
      }
    } else {
      if (judgeDirection(sx, sy, tx, ty) == Top) {
        fee += (ty - sy);
        sy = ty;
      } else {
        fee += (sy - ty);
        sy = ty;
      }
    }
    // cout << sx << sy << endl;
    // cout << fee << endl;
    // sleep(1);
  }

  cout << fee << endl;

  return 0;
}
