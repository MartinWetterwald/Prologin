#include <iostream>
#include <map>
#include <set>
#include <iterator>

typedef std::pair <int, int> Node;
typedef std::multimap <int, Node> NodeMap;
typedef std::set <Node> NodeSet;

int flow ( int n, int * * graph )
{
    NodeMap * neighboursMap = new NodeMap ( );
    NodeSet * nodeSet = new NodeSet ( );
    int * * dst = new int * [ n ];
    for ( int i = 0 ; i < n ; ++i )
    {
        int * dst2 = new int [ i + 1 ];
        for ( int j = 0 ; j < i + 1 ; ++j )
        {
            dst2 [ j ] = -1;
        }
        dst [ i ] = dst2;
    }

    nodeSet -> insert ( std::make_pair ( 0, 0 ) );
    dst [ 0 ] [ 0 ] = graph [ 0 ] [ 0 ];
    int storey = 0;
    int column = 0;

    unsigned int nodeNumber = n * ( n + 1 ) / 2;
    unsigned int nb = 1;
    while ( nb < nodeNumber )
    {
        // If not last storey
        if ( storey < n - 1 )
        {
            // We add the children in the neighbors.
            int childStorey = storey + 1;
            int leftChildcolumn = column;
            int rightChildcolumn = column + 1;
            // We check we haven't already inserted the child before
            if ( nodeSet -> find ( std::make_pair ( childStorey, leftChildcolumn ) ) == nodeSet -> end ( ) )
            {
                nodeSet -> insert ( std::make_pair ( childStorey, leftChildcolumn ) );
                neighboursMap -> insert ( std::make_pair ( dst [ storey ] [ column ] + graph [ childStorey ] [ leftChildcolumn ], std::make_pair ( childStorey, leftChildcolumn ) ) );
            }
            if ( nodeSet -> find ( std::make_pair ( childStorey, rightChildcolumn ) ) == nodeSet -> end ( ) )
            {
                nodeSet -> insert ( std::make_pair ( childStorey, rightChildcolumn ) );
                neighboursMap -> insert ( std::make_pair ( dst [ storey ] [ column ] + graph [ childStorey ] [ rightChildcolumn ], std::make_pair ( childStorey, rightChildcolumn ) ) );
            }
        }

        // Pops up neighbor with smallest cost
        NodeMap::const_iterator it = neighboursMap -> begin ( );

        // Changes current node for next iteration
        storey = it -> second.first;
        column = it -> second.second;

        // Updates the distance matrix
        dst [ storey ] [ column ] = it -> first;

        neighboursMap -> erase ( it );
        ++nb;
    }

    // We find out the max distance
    int max = 0;
    for ( int i = 0 ; i < n ; ++i )
    {
        for ( int j = 0 ; j < i + 1 ; ++j )
        {
            if ( dst [ i ] [ j ] > max )
            {
                max = dst [ i ] [ j ];
            }
        }
    }

    return max;
}


int main ( )
{
    int n;
    std::cin >> n >> std::skipws;

    int * * graph = new int * [ n ];

    for ( int i = 0 ; i < n ; i++ )
    {
        int * o = new int [ i + 1 ];
        for ( int p = 0 ; p < i + 1 ; p++ )
        {
            std::cin >> o [ p ] >> std::skipws;
        }
        graph [ i ] = o;
    }
    std::cout << flow ( n, graph );
    return 0;
}
