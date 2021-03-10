// Creates an pyramid like in mario with two columns. The height and spaces between are specified by the user
#include <iostream>

void stair(int, int); // Function prototype

int main() 
{
    int height, space;

    std::cout << "Height: ";
    std::cin >> height;

    std::cout << "Spaces: ";
    std::cin >> space;

    stair(height, space);
}

// Where the magic happens
void stair(int height, int space)
{
    for (int i = 0; i < height; i++) // First pyramid's white spaces
    {
        for (int j = 0; j < height - i - 1; j++)
        {
            std::cout << " ";
        }

        for (int k = 0; k < i + 1; k++) // First pyramid's bricks
        {
            std::cout << "#";
        } 
        
        for (int s = 0; s < space; s++) // Spaces in between
        {
            std::cout << " ";
        }

        for (int k = 0; k < i + 1; k++) // Second pyramid's bricks
        {
            std::cout << "#";
        }

        std::cout << std::endl;
    }
}