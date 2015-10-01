#include <iostream>
#include <set>

typedef std::pair <short, short> Point;
typedef std::set <Point> PointSet;

int terrain ( int * * matrix, int height, int width, int y, int x, int altitude, PointSet * toVisit )
{
    if ( x < 0 || x >= width || y < 0 || y >= height )
    {
        return 0;
    }

    if ( matrix [ y ] [ x ] == -1 )
    {
        return 0;
    }

    if ( matrix [ y ] [ x ] != altitude )
    {
        toVisit -> insert ( std::make_pair ( y, x ) );
        return 0;
    }

    PointSet::iterator it = toVisit -> find ( std::make_pair ( y, x ) );
    if ( it != toVisit -> end ( ) )
    {
        toVisit -> erase ( it );
    }

    matrix [ y ] [ x ] = -1;

    return 1 +
        terrain ( matrix, height, width, y, x - 1, altitude, toVisit ) +
        terrain ( matrix, height, width, y, x + 1, altitude, toVisit ) +
        terrain ( matrix, height, width, y - 1, x, altitude, toVisit ) +
        terrain ( matrix, height, width, y + 1, x, altitude, toVisit );
}

int main ( )
{
    int height, width;
    std::cin >> height >> std::skipws;
    std::cin >> width >> std::skipws;

    PointSet * toVisit = new PointSet ( );

    int * * matrix = new int * [ height ];
    for ( int i = 0 ; i < height ; ++i )
    {
        int * line = new int [ width ];
        for ( int j = 0 ; j < width; ++j )
        {
            std::cin >> line [ j ] >> std::skipws;
        }
        matrix [ i ] = line;
    }

    // Kepp the maximum of all chains and relaunch until we visited all points.
    int max = 0;
    while ( max == 0 || toVisit -> size ( ) > 0 )
    {
        PointSet::const_iterator it = toVisit -> begin ( );

        int value = terrain ( matrix, height, width, it -> first, it -> second, matrix [ it -> first ] [ it -> second ], toVisit );

        if ( value > max )
        {
            max = value;
        }
    }

    std::cout << max;

    delete toVisit;

    for ( int i = 0 ; i < height ; ++i )
    {
        delete [ ] matrix [ i ];
    }

    delete [ ] matrix;

    return EXIT_SUCCESS;
}
