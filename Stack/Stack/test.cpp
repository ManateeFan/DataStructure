#include <iostream>

#include "Stack.hpp"

using namespace std;

int main() {
  Stack<int, 20> s;
  s.push(1);
  s.push(2);
  s.push(3);
  cout << "s is empty: " << s.empty() << endl;
  cout << "s.top: " << s.top() << endl;
  s.pop();
  cout << "s.pop() - > s.top: " << s.top() << endl;
  return 0;
}