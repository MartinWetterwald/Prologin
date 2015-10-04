#include <iostream>
#include <queue>

static const char WALL = '#';
static const char WAY = '.';
static const char BEGIN = 'd';
static const char END = 'a';

struct __attribute__ ( ( __packed__ ) ) Node
{
    int32_t mdst;
    char mtype;
    Node ( ) : mdst ( -1 ), mtype ( '?' ) { };
};

struct Point
{
    uint16_t mx, my;
    Point ( ) = default;
    Point ( uint16_t x, uint16_t y ) : mx ( x ), my ( y ) { };
};

static int linkToThePast ( Node * * matrix, uint16_t height, uint16_t width, const Point & root )
{
    uint16_t dheight = height * 2;
    uint16_t dwidth = width;

    std::queue <Point> fifo;
    matrix [ root.my ] [ root.mx ].mdst = 0;
    fifo.push ( root );

    while ( fifo.size ( ) > 0 )
    {
        Point current = fifo.front ( );
        fifo.pop ( );

        // Construction of neighbors
        std::vector <Point> neighbors;
        {
            // Can we go to the left
            if ( current.mx - 1 >= 0 && matrix [ current.my ] [ current.mx - 1 ].mtype != WALL )
            {
                neighbors.push_back ( Point ( current.mx - 1, current.my ) );
            }
            // Can we go to the right
            if ( current.mx + 1 < dwidth && matrix [ current.my ] [ current.mx + 1 ].mtype != WALL )
            {
                neighbors.push_back ( Point ( current.mx + 1, current.my ) );
            }
            // Can we go to the top
            if ( current.my - 1 >= 0 && current.my != height && matrix [ current.my - 1 ] [ current.mx ].mtype != WALL )
            {
                neighbors.push_back ( Point ( current.mx, current.my - 1 ) );
            }
            // Can we go to the bottom
            if ( current.my + 1 < dheight && current.my != height - 1 && matrix [ current.my + 1 ] [ current.mx ].mtype != WALL )
            {
                neighbors.push_back ( Point ( current.mx, current.my + 1 ) );
            }
            // Can we go to the past
            if ( current.my < height && matrix [ current.my + height ] [ current.mx ].mtype != WALL )
            {
                neighbors.push_back ( Point ( current.mx, current.my + height ) );
            }
            // Can we go to the present
            if ( current.my >= height && matrix [ current.my - height ] [ current.mx ].mtype != WALL )
            {
                neighbors.push_back ( Point ( current.mx, current.my - height ) );
            }
        }

        for ( auto & neighbor : neighbors )
        {
            if ( matrix [ neighbor.my ] [ neighbor.mx ].mdst < 0 )
            {
                if ( matrix [ neighbor.my ] [ neighbor.mx ].mtype == END )
                {
                    return matrix [ current.my ] [ current.mx ].mdst + 1;
                }

                matrix [ neighbor.my ] [ neighbor.mx ].mdst = matrix [ current.my ] [ current.mx ].mdst + 1;
                fifo.push ( neighbor );
            }
        }
    }

    return 0;
}

int main ( )
{
    uint16_t height, width, dheight, dwidth;
    std::cin >> height >> std::skipws >> width;

    dheight = height * 2;
    dwidth = width;

    Node * * matrix = new Node * [ dheight ];

    Point root;

    for ( uint16_t i = 0 ; i < dheight ; ++i )
    {
        matrix [ i ] = new Node [ dwidth ];
        for ( uint16_t j = 0 ; j < dwidth ; ++j )
        {
            std::cin >> matrix [ i ] [ j ].mtype >> std::skipws;
            if ( matrix [ i ] [ j ].mtype == BEGIN )
            {
                root.mx = j;
                root.my = i;
            }
        }
    }

    std::cout << linkToThePast ( matrix, height, width, root );

    for ( uint16_t i = 0 ; i < dheight ; ++i )
    {
        delete [ ] matrix [ i ];
    }

    delete [ ] matrix;

    return 0;
}

