#include <iostream>
#include <iterator>

void crenellations ( int n, int h )
{
    int width = 4 * ( n - 1 ) + 3;

    // Top of Castle
    // First line
    for ( int c = 1 ; c < width ; ++c )
    {
        if ( c % 2 != 0 || c % 4 == 0 )
        {
            std::cout << " ";
        }
        else
        {
            std::cout << "_";
        }
    }
    std::cout << std::endl;

    // Second line
    for ( int c = 1 ; c <= width ; ++c )
    {
        if ( c % 2 != 0 )
        {
            std::cout << "|";
            continue;
        }
        if ( c % 4 == 0 )
        {
            std::cout << "_";
            continue;
        }
        std::cout << " ";
    }
    std::cout << std::endl;

    // Core of the Castle (2 < line < h+1)
    for ( int line = 3 ; line < h + 1 ; ++line )
    {
        std::cout << "|";
        std::fill_n ( std::ostream_iterator <char> ( std::cout ), width - 2, ' ' );
        std::cout << "|";
        std::cout << std::endl;
    }

    // Last line
    std::cout << "|";
    std::fill_n ( std::ostream_iterator <char> ( std::cout ), width - 2, '_' );
    std::cout << "|";
}

int main ( )
{
    int h, n;
    std::cin >> n >> std::skipws >> h;
    crenellations ( n, h );
    return 0;
}
