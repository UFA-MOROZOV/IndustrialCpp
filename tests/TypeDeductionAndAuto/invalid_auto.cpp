#include <initializer_list>
#include <vector>

template <typename T>
void f(T param) {}

template <typename T>
void g(std::initializer_list<T> param) {}

// auto createInitList() {
//   return {1, 2, 3}; // error: Cannot deduce return type from initializer list
// }

int main() {
  auto x = {11, 23, 9};  // std::initializer_list<int>

  /* error: Deduced conflicting types ('int' vs 'double') for initializer list
   * element type */
  // auto y = {1, 2, 3.0};

  /* error: Candidate template ignored: couldn't infer template argument 'T'*/
  // f({1, 2, 3});
  g({1, 2, 3});

  std::vector<int> v;
  auto resetV = [&v](const auto &newValue) { v = newValue; };

  /* Candidate template ignored: couldn't infer template argument
   * 'newValue:auto' */
  // resetV({1, 2, 3});
}
