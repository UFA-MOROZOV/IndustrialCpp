#pragma once

#include <string>

#include "person.hpp"

class Student {
 private:
  std::string name;
  int age;

  friend std::ostream &operator<<(std::ostream &out, const Student &student);

 public:
  Student(const Person &person);
};