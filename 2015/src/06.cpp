#include <iostream>
#include <vector>
#include <iterator>
#include <cassert>

struct Snail
{
    int mx;
    int my;
    int mspeed;
    bool mlocked;

    Snail ( int mx, int my, int speed );
};

typedef std::vector <Snail *> SnailVector;
typedef SnailVector::iterator SnailIterator;

Snail::Snail ( int x, int y, int speed ) : mx ( x ), my ( y ), mspeed ( speed ), mlocked ( false ) { };

int race ( SnailVector * player1, SnailVector * player2 )
{
    for ( SnailIterator it1 = player1 -> begin ( ) ; it1 != player1 -> end ( ) ; ++it1 )
    {
        for ( SnailIterator it2 = player2 -> begin ( ) ; it2 != player2 -> end ( ) ; ++it2 )
        {
            if ( ( * it2 ) -> mlocked )
            {
                continue;
            }
            double p1Temps =  ( * it2 ) -> mx  / ( double ) ( * it1 ) -> mspeed;
            double p2Temps = ( * it1 )  -> my / ( double ) ( * it2 ) -> mspeed;
            if ( p1Temps > p2Temps )
            {
                ( * it1 ) -> mlocked = true;
                break;
            }
            else if ( p1Temps == p2Temps )
            {
                assert ( false );
            }
            else
            {
                ( * it2 ) -> mlocked = true;
            }
        }
    }

    int maxSpeed = 0;
    int winner = -1;
    int currentSnail = 1;
    for ( SnailIterator it = player1 -> begin ( ) ; it != player1 -> end ( ) ; ++it )
    {
        if ( ! ( * it ) -> mlocked )
        {
            if ( maxSpeed < ( * it ) -> mspeed )
            {
                maxSpeed = ( * it ) -> mspeed;
                winner = currentSnail;
            }
        }
        ++currentSnail;
    }

    for ( SnailIterator it = player2 -> begin ( ) ; it != player2 -> end ( ) ; ++it )
    {
        if ( ! ( * it ) -> mlocked )
        {
            if ( maxSpeed < ( * it ) -> mspeed )
            {
                maxSpeed = ( * it ) -> mspeed;
                winner = currentSnail;
            }
        }
        ++currentSnail;
    }

    return winner;
}

int main ( )
{
    int v2, p2, v, p, c, n;
    std::cin >> n >> std::skipws >> c;
    SnailVector * player1 = new std::vector <Snail *> ( n );
    for ( int i = 0 ; i < n ; i++ )
    {
        std::cin >> p >> std::skipws >> v;
        Snail * q = new Snail ( 0, p, v );
        player1 -> at ( i ) = q;
    }
    SnailVector * player2 = new SnailVector ( n );
    for ( int i2 = 0 ; i2 < n ; ++i2 )
    {
        std::cin >> p2 >> std::skipws >> v2;
        Snail * r = new Snail ( p2, 0, v2 );
        player2 -> at ( i2 ) = r;
    }
    std::cout << race ( player1, player2 );

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
