#include <iostream>

int main ( )
{
    uint16_t height, width, dheight, dwidth;
    std::cin >> height >> std::skipws >> width;

    dheight = height * 2;
    dwidth = width;

    char * * matrix = new char * [ dheight ];

    for ( uint16_t i = 0 ; i < dheight ; ++i )
    {
        matrix [ i ] = new char [ dwidth ];
        for ( uint16_t j = 0 ; j < dwidth ; ++j )
        {
            std::cin >> matrix [ i ] [ j ] >> std::skipws;
        }
    }

    for ( uint16_t i = 0 ; i < dheight ; ++i )
    {
        delete [ ] matrix [ i ];
    }

    delete [ ] matrix;

    return 0;
}

