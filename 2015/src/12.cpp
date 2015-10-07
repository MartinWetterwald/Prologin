#include <iostream>
#include <unordered_set>

typedef std::unordered_set <uint16_t> USet;
typedef std::pair <USet, USet> USetPair;

#define BLOCK_SIZE 32

void findRoot ( USetPair * graph, uint32_t * visited, uint16_t node, uint16_t & ret )
{
    if ( ! ( visited [ node / BLOCK_SIZE ] & ( 1 << ( node % BLOCK_SIZE ) ) ) )
    {
        ret = node;
        visited [ node / BLOCK_SIZE ] |= ( 1 << ( node % BLOCK_SIZE ) );
        for ( const auto & neighbor : graph [ node ].first )
        {
            findRoot ( graph, visited, neighbor, ret );
        }
    }
}

void archeMinus ( USetPair * graph, uint32_t * visited, uint16_t node, uint16_t & size1, uint16_t & size2 )
{
    if ( ! ( visited [ node / BLOCK_SIZE ] & ( 1 << ( node % BLOCK_SIZE ) ) ) )
    {
        ++size1;
        visited [ node / BLOCK_SIZE ] |= ( 1 << ( node % BLOCK_SIZE ) );
        for ( const auto & neighbor : graph [ node ].second )
        {
            archeMinus ( graph, visited, neighbor, size2, size1 );
        }
    }
}

int main ( )
{
    uint16_t n;
    std::cin >> n >> std::skipws;

    uint16_t visitedSize = 1 + n / BLOCK_SIZE;
    uint32_t * visited = new uint32_t [ visitedSize ];
    std::fill ( visited, visited + visitedSize, 0 );

    USetPair * graph = new USetPair [ n ];

    for ( uint16_t i = 0 ; i < n ; ++i )
    {
        uint16_t j;
        std::cin >> j >> std::skipws;
        graph [ i ].first.insert ( j );
        graph [ j ].second.insert ( i );
    }

    uint16_t root = 0, size1 = 0, size2 = 0;
    findRoot ( graph, visited, 0, root );

    std::fill ( visited, visited + visitedSize, 0 );
    archeMinus ( graph, visited, root, size1, size2 );

    if ( size1 > size2 )
    {
        std::cout << size1;
    }
    else
    {
        std::cout << size2;
    }

    delete [ ] graph;

    delete [ ] visited;

    return 0;
}
