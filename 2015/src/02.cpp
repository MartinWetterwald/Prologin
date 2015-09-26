#include <iostream>
#include <vector>
#include <map>
void course_elephants0 ( int n, int l, std::vector < int > * v, std::vector < int > * p )
{
    std::map < int, int > result;
    for ( int m = 0 ; m < n ; m++ )
    {
        result.insert ( std::pair<int, int> ( ( l - p -> at ( m ) ) / v -> at ( m ), m ) );
    }

    std::cout << result.begin ( ) -> second;
}

int main ( )
{
    int l, n;
    std::cin >> n >> std::skipws >> l;
    std::vector < int > * v = new std::vector < int > ( n );
    for ( int m = 0 ; m < n ; m++ )
    {
        std::cin >> v -> at ( m ) >> std::skipws;
    }
    std::vector < int > * p = new std::vector < int > ( n );
    for ( int o = 0 ; o < n; o++ )
    {
        std::cin >> p -> at ( o ) >> std::skipws;
    }
    course_elephants0 ( n, l, v, p );

    delete p, n;
    return 0;
}
