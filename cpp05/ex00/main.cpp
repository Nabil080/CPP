#include "Bureaucrat.hpp"
#include <iostream>

void base_test() {
  Bureaucrat noob("Noob");
  Bureaucrat boss("Boss", 1);

  std::cout << noob << std::endl;
  std::cout << boss << std::endl;

  noob.upgrade();
  noob.downgrade();
}

void exception_test() {
  Bureaucrat noob("Noob");
  Bureaucrat boss("Boss", 1);
  try {
    noob.downgrade();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    boss.upgrade();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    std::cout << "Initializing a bureaucrat with a wrong grade" << std::endl;
    Bureaucrat toolow("blabla", 400);
  } catch (std::exception &e) {
  std:
    std::cerr << e.what() << std::endl;
  }
}

int main(int argc, char *argv[]) {

  base_test();
  exception_test();
  return 0;
}
