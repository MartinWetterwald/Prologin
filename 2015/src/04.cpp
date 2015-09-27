#include <iostream>
#include <cstring>

char * getline ( )
{
    if ( std::cin.flags ( ) & std::ios_base::skipws )
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
    char * c = new char [ line.length ( ) + 1 ];
    strcpy ( c, line.c_str ( ) );
    return c;
}

void censor ( int n, char * str, int m, int * positions )
{
    int word = 1;
    for ( int i = 0, j = 0 ; j < n && str [ j ] != '\0' ; ++j )
    {
        if ( i >= m )
        {
            std::cout << str [ j ];
            continue;
        }

        if ( word == positions [ i ] )
        {
            if ( str [ j ] != ' ' )
            {
                std::cout << "*";
                continue;
            }

            ++i;
        }
        if ( str [ j ] == ' ' )
        {
            ++word;
        }
        std::cout << str [ j ];
    }
}


int main ( )
{
    int m, n;
    std::cin >> n >> std::skipws;
    char * str = getline ( );
    std::cin >> m >> std::skipws;
    int * positions = new int [ m ];

    for ( int p = 0 ; p < m; ++p )
    {
        std::cin >> positions [ p ] >> std::skipws;
    }
    censor ( n, str, m, positions );

    delete [ ] positions;
    delete [ ] str;
    return 0;
}
