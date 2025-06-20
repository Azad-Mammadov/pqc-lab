#include <iostream>
#include <string>

int main()
{

    std::cout << " Enter 2 strings: \n";
    std::string str1, str2;
    std::cin >> str1 >> str2;
    std::cout << "Here is the alphabetical order:  ";
    if (str1 < str2) {
        std::cout << str1 << " " << str2 << "\n";
    } else if (str1 > str2) {
        std::cout << str2 << " " << str1 << "\n";
    } else {
        std::cout << "Both strings are equal.\n";
    }    return 0;

}


