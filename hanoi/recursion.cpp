#include <iostream>
#include <string>
using namespace std;

void move(int n, string s, string i, string d) {
  if (n>0) {
    move(n-1,s,d,i);
    cout << "Move " << n << " from " << s << " peg to " << d << " peg" << endl;
    move(n-1,i,s,d);
  }
}

int main() {
  int a;
  cout << "Enter the no of discs\n";
  cin >> a;
  move(a,"Source","Intermediate","Destination");
  return 0;
}