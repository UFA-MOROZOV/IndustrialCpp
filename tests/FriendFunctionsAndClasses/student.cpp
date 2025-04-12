#include "student.hpp"

#include "person.hpp"

Student::Student(const Person &person) {
  this->name = person.name;
  this->age = person.age;
}