#include <iostream>
#include <list>

typedef std::pair <int, int> Step;
typedef std::list <Step> StepList;

int main ( )
{
    int n;
    std::cin >> n;

    StepList * recipe = new StepList [ n ];

    for ( int i = 0 ; i < n ; ++i )
    {
        int m;
        std::cin >> m;
        StepList steps ( m, { 0, 0 } );
        for ( auto & step : steps )
        {
            std::cin >> step.first;
            std::cin >> step.second;
        }
    }

    delete [ ] recipe;

    return 0;
}
