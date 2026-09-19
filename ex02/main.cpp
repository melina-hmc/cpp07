#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

     std::cout << "\n> ADDITIONAL TESTS : \n" << std::endl;

    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "42";
    strArray[2] = "World";
    std::cout << "Complex type array: " << strArray[0] << " " << strArray[1] << " " << strArray[2] << std::endl;

    const Array<std::string> constArray(strArray);
    std::cout << "Const array read access: " << constArray[1] << std::endl;

    std::cout << "\n> DEEP COPY & ASSIGNMENT TESTS : \n" << std::endl;

    Array<std::string> copyArray(strArray);
    Array<std::string> assignedArray;
    assignedArray = strArray;
    
    copyArray[0] = "Bonjour";
    std::cout << "[Test copie] Modification de la copie :" << std::endl;
    std::cout << " strArray[0]  (original) = " << strArray[0] << std::endl;
    std::cout << " copyArray[0] (copie)    = " << copyArray[0] << std::endl;

    strArray[1] = "School";
    std::cout << "\n[Test assignation] Modification de l'original :" << std::endl;
    std::cout << " strArray[1]      (original) = " << strArray[1] << std::endl;
    std::cout << " assignedArray[1] (assigné)  = " << assignedArray[1] << std::endl;


    return 0;

/*
    std::cout << "\n> ADDITIONAL TESTS : \n" << std::endl;

    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "42";
    strArray[2] = "World";
    std::cout << "Complex type array: " << strArray[0] << " " << strArray[1] << " " << strArray[2] << std::endl;

    const Array<std::string> constArray(strArray);
    std::cout << "Const array read access: " << constArray[1] << std::endl;


    return 0;
*/
}

