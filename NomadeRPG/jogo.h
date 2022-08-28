#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

 //atributos do jogador
struct Personagem
{
   string snome;
   string sraca;
   string sclasse;
   int ifor=0;
   int idex=0;
   int isorte=0;
   int ivida=0;
   int idef=0;
   int imagia=0;
};
//items
struct Equipamento
{
   string sarmadura;
   string sespada;
   string sextra;
   int ipotion;
};
 //função de inicialização do jogador
void IniJogador(Personagem &jogador){

   int raca;
   int classe;
   cout << "CRIE SEU PERSONAGEM\n\nNome:";
   cin >> jogador.snome;
   system("cls");
   cout << "Escolha a sua Raca: \n 1) Anao \n 2) Elfo \n 3) Halfling\n\nEscolha : \n";
   cin >> raca;
   system("cls");
   while(raca < 1 || raca > 3){
      cout << "Opcao inexistente, tente novamente:\n";
      cin >> raca;
      system("cls");
      cout << "Escolha a sua Raca: \n 1) Anao \n 2) Elfo \n 3) Halfling\n\nEscolha : \n";
   }
   switch(raca){
      case 1:
         jogador.ifor+=1;
         jogador.ivida+=1;
         jogador.sraca = "Anão";
         break;
      case 2:
         jogador.imagia+=1;
         jogador.idex+=1;
         jogador.sraca = "Elfo";
         break;
      case 3:
         jogador.isorte+=2;
         jogador.idex+=1;
         jogador.ivida-=1;
         jogador.sraca = "Halfling";
         break;
   }
   system("cls");
   cout << "Escolha a Classe: \n 1) Guerreiro \n 2) Mago \n 3) Ladino: \n";
   cin>>classe;
   switch (classe) {
      case 1:
         jogador.ifor+=5;
         jogador.idex+=1;
         jogador.ivida+=3;
         jogador.idef+=2;
         jogador.sclasse = "Guerreiro";
         break;
      case 2:
         jogador.imagia+=7;
         jogador.idex+=1;
         jogador.ivida+=2;
         jogador.sclasse = "Mago";
         break;
      case 3:
         jogador.ifor+=1;
         jogador.idex+=4;
         jogador.ivida+=2;
         jogador.isorte+=3;
         jogador.sclasse = "Ladino";
         break;
      default:
         jogador.ifor+=2;
         jogador.idex+=2;
         jogador.ivida+=2;
         jogador.isorte+=2;
         jogador.idef+=2;
         jogador.sclasse = "Aldeao";
         break;
   }
}
void tela_status(Personagem status){
    cout<<"╭══════════════════════════════════════════════════════════════════════════╮"<<endl;
    cout<<"|Nome:"<< status.snome<< " |Classe:"<< status.sclasse<<" |Raça:"<< status.sraca<<"| \n";
    cout<<"|Força:"<< status.ifor<< "    |Destreza:"<< status.idex<<" |Sorte:"<< status.isorte<<"| \n";
    cout<<"|Magia:"<< status.imagia<< "    |Vida:"<< status.ivida<<" |Defesa:"<< status.idef<<"| \n";
    cout<<"╰══════════════════════════════════════════════════════════════════════════╯";
}
void IniJogo(Personagem P1){
   ifstream salas;
   string line;
   salas.open("jogo.txt");
   for (int i = 0; i < 30; i++)
   {
      getline(salas, line);
      if (i<7)
      {
         cout << line<<endl;
      }
   }
   
   salas.close();
}
void Menu(Personagem P1, bool &sair){
    int espera;
    string desenhomenu[31][11];
    for (int x = 0; x < 31;x++){
        for (int y = 0; y < 11; y++){
            if(x==10){
                desenhomenu[x][1]="            Menu            ";
                desenhomenu[x][3]="         1- Inicio          ";
                desenhomenu[x][5]="         2- Status          ";
                desenhomenu[x][7]="         3- Salvar          ";
                desenhomenu[x][9]="         4-  Sair           ";
            }else if (x==0||y==0||x==30||y==10){
                desenhomenu[x][y]="#";
            }
            else if(y%2==0){
                desenhomenu[x][y]="-";
            }else if(y%2 == 0){
                desenhomenu[x][y] = " ";
            }
        }
    }
       for (int y = 0; y < 11;y++){
        for (int x = 0; x < 31; x++)
        {
              cout << desenhomenu[x][y];
        }
        cout<<endl;
    }
    cin>>espera;
    system("cls");
    switch(espera){
    case 1:
        break;
    case 2:
        tela_status(P1);
        cout << "Para voltar digite 1: ";
        system("cls");
        Menu(P1,sair);
        break;
      case 4:
         sair = true;
      break;
    }
}
