/*

template<typename T>​
void f(T param);​ // ParamType=T
f(expr)

Step 1: If expr’s type is a reference, ignore the reference part​
Step 2: If expr is const, ignore that, too​

*/

template <typename T>
void f(T param) {}

template <typename T>
void g(const T param) {}

int main() {
  int x = 1;
  const int cx = x;
  const int &rx = x;

  f(x);   // void f<int>(int param)
  f(cx);  // void f<int>(int param)
  f(rx);  // void f<int>(int param)
  g(x);   // void g<int>(const int param)
  g(cx);  // void g<int>(const int param)
  g(rx);  // void g<int>(const int param)

  int *px = &x;
  const int *pcx = &x;
  int *const cpx = &x;
  const int *const cpcx = &x;

  f(px);    // void f<int *>(int *param)
  f(pcx);   // void f<const int *>(const int *param)
  f(cpx);   // void f<int *>(int *param)
  f(cpcx);  // void f<const int *>(const int *param)
}