#include <iostream>
#include <vector>

int main ( )
{
    typedef std::vector <int> Tvecint;
    int n;
    std::cin >> n >> std::skipws;
    Tvecint * tab = new Tvecint ( n );
    for ( int g = 0 ; g < n; g++ )
    {
        std::cin >> tab -> at ( g ) >> std::skipws;
    }

    std::cout << tab -> at ( 0 );

    for ( int i = 1 ; i < n ; ++i )
    {
        std::cout << " " << ( tab -> at ( i ) - tab -> at ( i - 1 ) );
    }

    delete tab;
    return 0;
}
