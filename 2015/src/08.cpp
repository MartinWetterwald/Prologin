#include <iostream>

int liberties ( int height, int width, int x, int y, int * * matrix )
{
    return 0;
}


int main ( )
{
    int height, width, x, y;
    std::cin >> height >> std::skipws;
    std::cin >> width >> std::skipws;
    std::cin >> y >> std::skipws;
    std::cin >> x >> std::skipws;

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
    std::cout << liberties ( height, width, x, y, matrix );

    return 0;
}
