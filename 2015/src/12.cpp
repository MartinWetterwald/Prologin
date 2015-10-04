#include <iostream>
#include <unordered_set>

typedef std::unordered_set <uint16_t> USet;

int main ( )
{
    uint16_t n;
    std::cin >> n >> std::skipws;

    USet * graph = new USet [ n ];

    for ( uint16_t i = 0 ; i < n ; ++i )
    {
        uint16_t j;
        std::cin >> j >> std::skipws;
        graph [ i ].insert ( j );
        graph [ j ].insert ( i );
    }

    delete [ ] graph;

    return 0;
}
