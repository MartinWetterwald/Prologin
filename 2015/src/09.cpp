#include <iostream>
#include <set>

typedef std::pair <short, short> Point;
typedef std::set <Point> PointSet;

int terrain ( char * * matrix, short height, short width, short y, short x, char altitude, PointSet * toVisit )
{
    // Out of bounds
    if ( x < 0 || x >= width || y < 0 || y >= height )
    {
        return 0;
    }

    // Already visited
    if ( matrix [ y ] [ x ] == -1 )
    {
        return 0;
    }

    // It's not a point we want to count now so we skip it,
    // but are interested in it for later recursions (to visit for later).
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

    // We mark the point as visited, increment the total and recurse with neighborhood.
    matrix [ y ] [ x ] = -1;

    return 1 +
        terrain ( matrix, height, width, y, x - 1, altitude, toVisit ) +
        terrain ( matrix, height, width, y, x + 1, altitude, toVisit ) +
        terrain ( matrix, height, width, y - 1, x, altitude, toVisit ) +
        terrain ( matrix, height, width, y + 1, x, altitude, toVisit );
}

int main ( )
{
    short height, width;
    std::cin >> height >> std::skipws;
    std::cin >> width >> std::skipws;

    PointSet * toVisit = new PointSet ( );

    char * * matrix = new char * [ height ];
    for ( short i = 0 ; i < height ; ++i )
    {
        char * line = new char [ width ];
        for ( short j = 0 ; j < width; ++j )
        {
            std::cin >> line [ j ] >> std::skipws;
        }
        matrix [ i ] = line;
    }

    // Keep the maximum of all chains and relaunch until we visited all points.
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

    for ( short i = 0 ; i < height ; ++i )
    {
        delete [ ] matrix [ i ];
    }

    delete [ ] matrix;

    return EXIT_SUCCESS;
}
