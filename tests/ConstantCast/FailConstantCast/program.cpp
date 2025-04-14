// Const cast can't cast non-similar types. Compilation error

int main() {
  int **x;
  const int *y = const_cast<int*>(x);
}
