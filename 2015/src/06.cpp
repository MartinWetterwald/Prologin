#include <iostream>
#include <vector>

class Snail
{
public:
    int position;
    int speed;
};

void race ( int n, int c, std::vector <Snail *> * player1, std::vector <Snail *> * player2 )
{
}

int main ( )
{
    int v2, p2, v, p, c, n;
    std::cin >> n >> std::skipws >> c;
    std::vector <Snail *> * player1 = new std::vector <Snail *> ( n );
    for ( int i = 0 ; i < n ; i++ )
    {
        std::cin >> p >> std::skipws >> v;
        Snail * q = new Snail ( );
        q -> position = p;
        q -> speed = v;
        player1 -> at ( i ) = q;
    }
    std::vector <Snail *> * player2 = new std::vector <Snail *> ( n );
    for ( int i2 = 0 ; i2 < n ; ++i2 )
    {
        std::cin >> p2 >> std::skipws >> v2;
        Snail * r = new Snail ( );
        r -> position = p2;
        r -> speed = v2;
        player2 -> at ( i2 ) = r;
    }
    race ( n, c, player1, player2 );

    for ( unsigned int i = 0 ; i < player1 -> size ( ) ; ++i )
    {
        delete player1 -> at ( i );
    }

    for ( unsigned int i = 0 ; i < player2 -> size ( ) ; ++i )
    {
        delete player2 -> at ( i );
    }

    delete player1;
    delete player2;

    return 0;
}
