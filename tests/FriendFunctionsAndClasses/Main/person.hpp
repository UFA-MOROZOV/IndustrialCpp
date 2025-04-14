#pragma once

#include <string>

class Student;

class Person {
 private:
  std::string name;
  int age;

 public:
  Person(const std::string &name, const int age);

  Person(const Student &student);

 protected:
  friend class Student;
};