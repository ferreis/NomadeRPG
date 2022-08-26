#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "inteface.h"
#include "jogo.h"
 using namespace std;
 void escrever(string text, int time){
  for(int i =0; i<text.size();i++){
    sleep(time);
    cout<<text[i];
  }
 }
 
int main()
{
  bool sair = false;
  Personagem jogador;
  Nomaderpg();
  IniJogador(jogador);
  do{
   // Menu();
    historia();

  cout << "\n \n \n \n \n \n ";
  } while (sair == false);
}
 
