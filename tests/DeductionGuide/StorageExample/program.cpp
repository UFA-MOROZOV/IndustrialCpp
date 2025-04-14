#include <iterator>
#include <string>
#include <vector>

template <typename T> struct Storage {
  T t;

  Storage(T t) : t(t) {}

  template <typename It> Storage(It begin, It end) : t(begin, end) {}
};

// Constructor match -> Template instance
Storage(const char *) -> Storage<std::string>;

// Deduction guides can be templated
template <typename It>
Storage(It, It)
    -> Storage<std::vector<typename std::iterator_traits<It>::value_type>>;

Storage a{10};
// decltype(a) == Storage<int>
// no guide required, deduced from Storage(T t)

Storage b{"Hello World!"};
// decltype(b) == Storage<std::string>
// follows the const char* guide

std::vector<int> data{1, 2, 3, 4, 5, 6};
Storage c{data.begin(), data.end()};
// decltype(c) == Storage<std::vector<int>>
// follows the double iterator guide

int main() {}
