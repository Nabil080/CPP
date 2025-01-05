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
  } catch (int grade) {
    std::cerr << "Couldn't downgrade" << std::endl;
  }
  try {
    boss.upgrade();
  } catch (int grade) {
    std::cerr << "Couldn't upgrade" << std::endl;
  }
}

int main(int argc, char *argv[]) {

  base_test();
  exception_test();
  return 0;
}
