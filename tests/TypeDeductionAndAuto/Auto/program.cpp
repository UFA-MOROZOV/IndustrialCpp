int main() {
  auto x = 1;            // int
  const auto cx = x;     // const int
  const auto &rx = x;    // const int&
  const auto &&rvr = 0;  // const int&&

  auto *px = &x;                // int*
  auto *const cpx = &x;         // int* const
  const auto *const cpcx = &x;  // const int* const

  auto &&lux = x;  // int&
  auto &&rux = 0;  // int&&
}