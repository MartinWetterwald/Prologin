#include <iostream>
#include <list>

typedef std::pair <short, int> Step;
typedef std::list <Step> StepList;

int cooking ( StepList * recipe, short stepId )
{
    if ( recipe [ stepId ].size ( ) == 0 )
    {
        return 0;
    }

    int max = 0;
    for ( auto & step : recipe [ stepId ] )
    {
        int time = step.second + cooking ( recipe, step.first );
        if ( time > max )
        {
            max = time;
        }
    }

    return max;
}

int main ( )
{
    short n;
    std::cin >> n;

    StepList * recipe = new StepList [ n ];

    bool * root = new bool [ n ];

    for ( short i = 0 ; i < n ; ++i )
    {
        root [ i ] = true;
        int m;
        std::cin >> m;
        StepList steps ( m, { 0, 0 } );
        for ( auto & step : steps )
        {
            std::cin >> step.first;
            std::cin >> step.second;

            if ( root [ step.first ] )
            {
                root [ step.first ] = false;
            }
        }
        recipe [ i ] = steps;
    }

    // Find root
    short rootId = 0;
    for ( ; rootId < n && ! root [ rootId ] ; ++rootId );

    std::cout << cooking ( recipe, rootId );

    delete [ ] recipe;

    return 0;
}
