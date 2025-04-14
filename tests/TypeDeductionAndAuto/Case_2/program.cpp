/*

template<typename T>​
void f(T&& param);​ // ParamType=T&&
f(expr)

Step 1: If expr is an lvalue, both T and ParamType are deduced to be lvalue
references​
Step 2: If expr is an rvalue, the “normal” (i.e., Case 1)
rules apply​

*/

template <typename T>
void f(T &&param) {}

int main() {
  int x = 1;
  const int cx = x;
  const int &rx = x;

  f(x);   // void f<int &>(int &param)
  f(cx);  // void f<const int &>(const int &param)
  f(rx);  // void f<const int &>(const int &param)
  f(0);   // void f<int>(int &&param)
}