#include <iostream>

int flow ( int n, int * * tab )
{
    return 0;
}


int main ( )
{
    int n;
    std::cin >> n >> std::skipws;

    int * * tab = new int * [ n ];

    for ( int i = 0 ; i < n ; i++ )
    {
        int * o = new int [ i + 1 ];
        for ( int p = 0 ; p < i + 1 ; p++ )
        {
            std::cin >> o [ p ] >> std::skipws;
        }
        tab [ i ] = o;
    }
    std::cout << flow ( n, tab );
    return 0;
}
