// Const cast from const pointer to usual one. UB but compiles

int main() {
  const int *const *x;
  int** p = const_cast<int**>(x);
}
