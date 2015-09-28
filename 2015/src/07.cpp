#include <iostream>
#include <vector>
int ecoulement0(int n, std::vector<std::vector<int> *> * tab){
  /* complétez le code ici. */
  return 0;
}


int main(){
  int n;
  std::cin >> n >> std::skipws;
  std::vector<std::vector<int> * > *tab = new std::vector<std::vector<int> *>( n );
  for (int i = 0 ; i < n; i++)
  {
    std::vector<int > *o = new std::vector<int>( i + 1 );
    for (int p = 0 ; p < i + 1; p++)
    {
      std::cin >> o->at(p) >> std::skipws;
    }
    tab->at(i) = o;
  }
  std::cout << ecoulement0(n, tab) << "\n";
  return 0;
}
