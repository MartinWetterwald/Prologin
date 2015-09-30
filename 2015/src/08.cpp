#include <iostream>
#include <set>
#include <utility>

enum Color { BLACK = 0, WHITE = 1, EMPTY = 2 };
typedef std::pair <int, int> Intersection;
typedef std::set <Intersection> IntersectionSet;

int otherColor ( int color )
{
    if ( color == BLACK )
    {
        return WHITE;
    }

    if ( color == WHITE )
    {
        return BLACK;
    }

    return -1;
}

int liberties ( int * * matrix, IntersectionSet * visited, int height, int width, int y, int x, int color )
{
    if ( visited -> find ( std::make_pair ( y, x ) ) != visited -> end ( ) )
    {
        return 0;
    }
    visited -> insert ( std::make_pair ( y, x ) );

    if ( x < 0 || x >= width || y < 0 || y >= height )
    {
        return 0;
    }

    if ( matrix [ y ] [ x ] == otherColor ( color ) )
    {
        return 0;
    }

    if ( matrix [ y ] [ x ] == EMPTY )
    {
        return 1;
    }

    return
        liberties ( matrix, visited, height, width, y, x - 1, color ) +
        liberties ( matrix, visited, height, width, y, x + 1, color ) +
        liberties ( matrix, visited, height, width, y - 1, x, color ) +
        liberties ( matrix, visited, height, width, y + 1, x, color );
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

    if ( x < 0 || x >= width || y < 0 || y >= height )
    {
        return EXIT_FAILURE;
    }

    int color = matrix [ y ] [ x ];
    if ( color != BLACK && color != WHITE )
    {
        return EXIT_FAILURE;
    }

    IntersectionSet * visited = new IntersectionSet ( );

    std::cout << liberties ( matrix, visited, height, width, y, x, color );

    delete visited;

    for ( int i = 0 ; i < height ; ++i )
    {
        delete [ ] matrix [ i ];
    }

    delete [ ] matrix;

    return EXIT_SUCCESS;
}
