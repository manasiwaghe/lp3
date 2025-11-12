#include <iostream>
using namespace std;

int fibonacci(int n) {
  if (n <= 1)
    return n;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

void recursive(int n) {
  for (int i = 0; i < n; ++i)
    cout << fibonacci(i) << " ";
}

void iterative(int n) {
  int a1 = 0;
  int a2 = 1;

  cout << a1 << " " << a2 << " ";

  for (int i = 2; i < n; i++) {
    int a3 = a2 + a1;
    a1 = a2;
    a2 = a3;
    cout << a2 << " ";
  }

  cout << endl;
}

void dp(int n) {
    if (n <= 0)
        return;
    int fib[n];
    fib[0] = 0;
    if (n > 1)
        fib[1] = 1;

    for (int i = 2; i < n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    for (int i = 0; i < n; i++)
        cout << fib[i] << " ";
    cout << endl;
}

int main() {
  cout<<"recursive: ";
  recursive(10);
  cout << endl;
  cout<<"iterative: ";
  iterative(10);
  cout<<endl;
  cout<<"dynamic programming: ";
  dp(10);
  return 0;
}
