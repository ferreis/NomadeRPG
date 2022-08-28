#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "jogo.h"
 using namespace std;
int main(){
  bool sair = false;
  int espera;
  Personagem jogador;
  IniJogador(jogador);
  do
  {
  IniJogo(jogador);
  Menu(jogador,sair);
  system("pause");
    
  } while (sair != true);
}
 
