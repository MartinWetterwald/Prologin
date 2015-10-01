#include <iostream>

int terrain ( int * * matrix, int height, int width )
{
    return 0;
}

int main ( )
{
    int height, width;
    std::cin >> height >> std::skipws;
    std::cin >> width >> std::skipws;

    int * * matrix = new int * [ height ];
    for ( int * * i = matrix ; i < matrix + height ; ++i )
    {
        int * line = new int [ width ];
        for ( int * j = line ; j < line + width; ++j )
        {
            std::cin >> * j >> std::skipws;
        }
        * i = line;
    }

    std::cout << terrain ( matrix, height, width );

    for ( int i = 0 ; i < height ; ++i )
    {
        delete [ ] matrix [ i ];
    }

    delete [ ] matrix;

    return EXIT_SUCCESS;
}
