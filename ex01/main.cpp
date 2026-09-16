#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void printElement(T const & element)
{
    std::cout << element << std::endl;
}

template <typename T>
void addExclamation(T & element)
{
    element += " !";
}

int main(void)
{
    std::cout << "> Test 1 : tableau d'entiers int" << std::endl;
    int intArray[] = {0, 1, 2, 3, 4};
    size_t intLength = 5;
    ::iter(intArray, intLength, printElement<int>);

    std::cout << "\n> Test 2 : tableau de strings" << std::endl;
    std::string strArray[] = {"Heeeyyy", "vous", "tous"};
    size_t strLength = 3;
    ::iter(strArray, strLength, addExclamation<std::string>);
    ::iter(strArray, strLength, printElement<std::string>);

    std::cout << "\n> Test 3 : tableau CONSTANT d'entiers" << std::endl;
    const int constArray[] = {42, 42, 42};
    size_t constLength = 3;
    ::iter(constArray, constLength, printElement<int>);

    return 0;
}