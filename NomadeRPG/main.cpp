#include <iostream>
#include "jogo.h"

using namespace std;

int main()
{
  Personagem P1;
  bool sair = true;
  do
  {
    Menu(P1);
    cout << "\n \n \n \n \n \n ";
  } while (sair == false);
}
