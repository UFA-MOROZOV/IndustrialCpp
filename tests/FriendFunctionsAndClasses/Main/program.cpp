#include <iostream>

#include "person.hpp"
#include "student.hpp"

std::ostream &operator<<(std::ostream &out, const Student &student) {
  return out << "Student{\"name\":\"" << student.name
             << "\", \"age\":" << student.age << "}";
}

int main() {
  Person person("Vasya", 20);
  Student student(person);

  std::cout << student << std::endl;
}