// Factorial calculator with user input number
#include <iostream>

//function prototype or declaration
int fact(int);

int main()
{
    int x;

    std::cout << "Enter a number to see it`s factorial: ";
    std::cin >> x;

    int result = fact(x);

    std::cout << "Factorial of " << x << " = " << result << std::endl; 
    return 0;
}

//function actual definition
int fact(int num)
{
    if (num == 1)
    {
        return 1;
    }
    else
    {
        return num * fact(num - 1); // Recursion
    }
}