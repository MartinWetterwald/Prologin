#include <iostream>
#include <map>

typedef std::pair <short, short> Point;
typedef std::map <Point, char> Matrix;

int terrain ( Matrix * matrix, int y, int x, int altitude )
{
    Matrix::iterator it = matrix -> find ( std::make_pair ( y, x ) );
    if ( it == matrix -> end ( ) )
    {
        return 0;
    }

    if ( it -> second != altitude )
    {
        return 0;
    }

    matrix -> erase ( it );

    return 1 +
        terrain ( matrix, y, x - 1, altitude ) +
        terrain ( matrix, y, x + 1, altitude ) +
        terrain ( matrix, y - 1, x, altitude ) +
        terrain ( matrix, y + 1, x, altitude );
}

int main ( )
{
    int height, width;
    std::cin >> height >> std::skipws;
    std::cin >> width >> std::skipws;

    Matrix * matrix = new Matrix ( );

    for ( int i = 0 ; i < height ; ++i )
    {
        for ( int j = 0 ; j < width; ++j )
        {
            int altitude;
            std::cin >> altitude >> std::skipws;
            matrix -> insert ( std::make_pair ( std::make_pair ( i, j ), altitude ) );
        }
    }

    // Kepp the maximum of all chains and relaunch until we visited all points.
    int max = 0;
    while ( matrix -> size ( ) > 0 )
    {
        Matrix::iterator it = matrix -> begin ( );
        int value = terrain ( matrix, it -> first.first, it -> first.second, it -> second );
        if ( value > max )
        {
            max = value;
        }
    }

    std::cout << max;

    delete matrix;

    return EXIT_SUCCESS;
}
