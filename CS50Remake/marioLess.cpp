// Creates a pyramid like in mario with column's height set by the user
#include <iostream>

void stair(int);

int main() 
{
    int height;

    std::cout << "Height: ";
    std::cin >> height;

    stair(height);

}

// Where the magic happens
void stair(int height) 
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - i - 1; j++) // Pyramid's white spaces
        {
            std::cout << " ";
        }

        for (int k = 0; k < i + 1; k++) // Pyramid's bricks
        {
            std::cout << "#";
        } 
        
        std::cout << std::endl;
    }
}