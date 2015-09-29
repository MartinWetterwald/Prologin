#include <iostream>
#include <map>
#include <set>
#include <iterator>

typedef std::pair <int, int> Node;
typedef std::multimap <int, Node> NodeMap;
typedef std::set <Node> NodeSet;

void addNeighbour ( NodeMap * neighboursMap, NodeSet * nodeSet, int storey, int column, int dst )
{
    // We check we haven't already inserted the child before
    if ( nodeSet -> find ( std::make_pair ( storey, column ) ) == nodeSet -> end ( ) )
    {
        nodeSet -> insert ( std::make_pair ( storey, column ) );
        neighboursMap -> insert ( std::make_pair ( dst, std::make_pair ( storey, column ) ) );
    }
}

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
            int leftChildColumn = column;
            int rightChildColumn = column + 1;
            addNeighbour ( neighboursMap, nodeSet, childStorey, leftChildColumn, dst [ storey ] [ column ] + graph [ childStorey ] [ leftChildColumn ] );
            addNeighbour ( neighboursMap, nodeSet, childStorey, rightChildColumn, dst [ storey ] [ column ] + graph [ childStorey ] [ rightChildColumn ] );
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

    // We find out the max distance (within the nodes of the last storey)
    int max = 0;
    for ( int i = 0 ; i < n ; ++i )
    {
        if ( dst [ n - 1 ] [ i ] > max )
        {
            max = dst [ n - 1 ] [ i ];
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
