#include <string>
#include <iostream>

int main(void)
{
    std::string     str = "HI THIS IS BRAIN";
    std::string     *stringPTR = &str;
    std::string&    stringREF = str;

    std::cout << "str adress : " << &str << std::endl;
    std::cout << "pointer adress : " << &stringPTR << std::endl;
    std::cout << "reference adress : " << &stringREF << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "str value : " << str << std::endl;
    std::cout << "pointer value : " << stringPTR << std::endl;
    std::cout << "reference value : " << stringREF << std::endl;
    return (0);
}
