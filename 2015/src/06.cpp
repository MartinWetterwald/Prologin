#include <iostream>
#include <vector>
class escargot {
public:
  int position;
  int vitesse;
};

void course_baveuse0(int n, int c, std::vector<escargot *> * joueur1, std::vector<escargot *> * joueur2){
  /* Inserez votre code ici */
}


int main(){
  int v2, p2, v, p, c, n;
  std::cin >> n >> std::skipws >> c;
  std::vector<escargot * > *joueur1 = new std::vector<escargot *>( n );
  for (int i = 0 ; i < n; i++)
  {
    std::cin >> p >> std::skipws >> v;
    escargot * q = new escargot();
    q->position=p;
    q->vitesse=v;
    joueur1->at(i) = q;
  }
  std::vector<escargot * > *joueur2 = new std::vector<escargot *>( n );
  for (int i2 = 0 ; i2 < n; i2++)
  {
    std::cin >> p2 >> std::skipws >> v2;
    escargot * r = new escargot();
    r->position=p2;
    r->vitesse=v2;
    joueur2->at(i2) = r;
  }
  course_baveuse0(n, c, joueur1, joueur2);
  return 0;
}
