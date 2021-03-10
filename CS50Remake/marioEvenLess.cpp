// Creates a mario pyramid going downstairs
#include <iostream>

void stair(int);

int main() 
{
    int height;

    std::cout << "Height: ";
    std::cin >> height;

    stair(height);

}

void stair(int height) 
{
    if (height == 0) // End statement
    {
        return;
    }

    stair(height - 1); // Recursion
    
    for (int i = 0; i < height; i++) // Pyramid's bricks
    {
        std::cout << "#";
    }
    std::cout << std::endl;
}