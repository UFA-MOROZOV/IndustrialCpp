/*

template<typename T>​
void f(T& param);​ // ParamType=T&
f(expr)

Step 1: if expr’s type is a reference, ignore the reference part​
Step 2: pattern-match expr’s type against ParamType to determine T​

*/

template <typename T>
void f(T &param) {}

template <typename T>
void g(const T &param) {}

int main() {
  int x = 1;
  const int cx = x;
  const int &rx = x;

  f(x);   // void f<int>(int &param)
  f(cx);  // void f<const int>(const int &param)
  f(rx);  // void f<const int>(const int &param)

  g(x);   // void g<int>(const int &param)
  g(cx);  // void g<int>(const int &param)
  g(rx);  // void g<int>(const int &param)
}