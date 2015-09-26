#include <iostream>
#include <vector>
int reponse_universelle(int n){
  return 42;
}


int main(){
  int n;
  std::cin >> n >> std::skipws;
  std::cout << reponse_universelle(n) << "\n";
  return 0;
}
