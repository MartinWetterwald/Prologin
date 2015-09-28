#include <iostream>
#include <map>
#include <set>
#include <iterator>

typedef std::pair <int, int> Node;
typedef std::multimap <int, Node> NodeMap;
typedef std::set <Node> NodeSet;

int flow ( int n, int * * tab )
{
    NodeMap * nodeMap = new NodeMap ( );
    NodeSet * nodeSet = new NodeSet ( );
    int * * res = new int * [ n ];
    for ( int i = 0 ; i < n ; ++i )
    {
        int * res2 = new int [ i + 1 ];
        for ( int j = 0 ; j < i + 1 ; ++j )
        {
            res2 [ j ] = -1;
        }
        res [ i ] = res2;
    }

    res [ 0 ] [ 0 ] = tab [ 0 ] [ 0 ];
    int storey = 0;
    int id = 0;

    int nodeNumber = n * ( n + 1 ) / 2;
    int nb = 1;
    while ( nb < nodeNumber )
    {
        // If not last storey and we haven't inserted the child before
        if ( storey < n - 1 )
        {
            // We add the children in the neighbors.
            int childStorey = storey + 1;
            int leftChildId = id;
            int rightChildId = id + 1;
            // We check we haven't already inserted the child before
            if ( nodeSet -> find ( std::make_pair ( childStorey, leftChildId ) ) == nodeSet -> end ( ) )
            {
                nodeSet -> insert ( std::make_pair ( childStorey, leftChildId ) );
                nodeMap -> insert ( std::make_pair ( res [ storey ] [ id ] + tab [ childStorey ] [ leftChildId ], std::make_pair ( childStorey, leftChildId ) ) );
            }
            if ( nodeSet -> find ( std::make_pair ( childStorey, rightChildId ) ) == nodeSet -> end ( ) )
            {
                nodeSet -> insert ( std::make_pair ( childStorey, rightChildId ) );
                nodeMap -> insert ( std::make_pair ( res [ storey ] [ id ] + tab [ childStorey ] [ rightChildId ], std::make_pair ( childStorey, rightChildId ) ) );
            }
        }

        // Pops up neighbor with smallest cost
        NodeMap::const_iterator it = nodeMap -> begin ( );
        storey = it -> second.first;
        id = it -> second.second;
        if ( res [ storey ] [ id ] == -1 )
        {
            res [ storey ] [ id ] = it -> first;
        }
        ++nb;
        nodeMap -> erase ( it );
    }

    // We find out the max distance
    int max = 0;
    for ( int i = 0 ; i < n ; ++i )
    {
        for ( int j = 0 ; j < i + 1 ; ++j )
        {
            if ( res [ i ] [ j ] > max )
            {
                max = res [ i ] [ j ];
            }
        }
    }

    return max;
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
