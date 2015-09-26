#include <iostream>
#include <vector>

std::vector <char> * getline ( )
{
    if (std::cin.flags ( ) & std::ios_base::skipws )
    {
        char c = std::cin.peek ( );
        if ( c == '\n' || c == ' ' )
        {
            std::cin.ignore ( );
        }
        std::cin.unsetf ( std::ios::skipws );
    }
    std::string line;
    std::getline ( std::cin, line );
    std::vector <char> * c = new std::vector <char> ( line.begin ( ), line.end ( ) );
    return c;
}

void censor ( int n, std::vector <char> * str, int m, std::vector <int> * positions )
{
    int word = 1;
    for ( int i = 0, j = 0 ; j < n ; ++j )
    {
        if ( i >= m )
        {
            std::cout << str -> at ( j );
            continue;
        }

        if ( word == positions -> at ( i ) )
        {
            if ( str -> at ( j ) != ' ' )
            {
                std::cout << "*";
                continue;
            }

            ++i;
        }
        if ( str -> at ( j ) == ' ' )
        {
            ++word;
        }
        std::cout << str -> at ( j );
    }
}


int main ( )
{
    int m, n;
    std::cin >> n >> std::skipws;
    std::vector <char> * str = getline ( );
    std::cin >> m >> std::skipws;
    std::vector <int> * positions = new std::vector <int> ( m );

    for ( int p = 0 ; p < m; ++p )
    {
        std::cin >> positions -> at ( p ) >> std::skipws;
    }
    censor ( n, str, m, positions );

    delete positions;
    delete str;
    return 0;
}
