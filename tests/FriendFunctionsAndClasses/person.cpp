#include "person.hpp"

#include "student.hpp"

Person::Person(const std::string &name, const int age) : name(name), age(age) {}

Person::Person(const Student &student) {
  // std::cout << student.name
  //           << std::endl; // Error: 'name' is a private member of 'Student'
}