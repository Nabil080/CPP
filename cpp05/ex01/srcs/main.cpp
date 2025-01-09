#include "Form.hpp"
#include <iostream>

void base_test() {

  try {
    Form base;
    std::cout << base << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Form too_low("Too low", 500, 500);
    std::cout << too_low << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}

void exception_test() {}

int main(void) {

  base_test();
  exception_test();
  return 0;
}
