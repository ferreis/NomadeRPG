#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <time.h>

using namespace std;


ifstream salas, menu;
fstream save;
string line;
bool fruit = false, comeco = true, *PontFruit;
int static escolha, f=0, chec[4], *v[4];
 //atributos do jogador
struct Personagem
{
   string snome;
   string sraca;
   string sclasse;
   int ifor;
   int idex;
   int isorte;
   int ivida;
   int iatualvida;
   int idef;
   int imagia;
};
Personagem orc;
//items
struct Equipamento
{
   string sarmadura;
   string sespada;
   string sextra;
   int ipotion;
};

void Nomaderpg(){
    menu.open("nomade.txt");
    while(menu.eof() == false)
    {
        getline(menu,line);
        cout << line<< endl;
    }
    menu.close();
}
 //função de inicialização do jogador
void IniJogador(Personagem &jogador){
    int raca;
    int classe;
    jogador.ifor=0;
    jogador.idex=0;
    jogador.isorte=0;
    jogador.ivida=3;
    jogador.idef=0;
    jogador.imagia=0;
    cout << "CRIE SEU PERSONAGEM\n\nNome: ";
    cin >> jogador.snome;
    system("cls");
    //Nomaderpg();
    cout << "Escolha a sua Raca: \n 1) Anao \n 2) Elfo \n 3) Halfling\n\nEscolha : ";
    cin >> raca;
    system("cls");
    //Nomaderpg();
        while(raca < 1 || raca > 3){
        cout << "Opcao inexistente, tente novamente:\n";
        cin >> raca;
        system("cls");
        cout << "Escolha a sua Raca: \n 1) Anao \n 2) Elfo \n 3) Halfling\n\nEscolha : ";
    }
    switch(raca){
    case 1:
         jogador.ifor+=1;
         jogador.ivida+=1;
         jogador.sraca = "Anao";
         break;
      case 2:
         jogador.imagia+=1;
         jogador.idex+=1;
         jogador.sraca = "Elfo";
         break;
      case 3:
         jogador.isorte+=2;
         jogador.idef+=1;
         jogador.ivida-= 1;
         jogador.sraca = "Halfling";
         break;
   }
   system("cls");
   //Nomaderpg();
   cout << "Escolha a Classe: \n 1) Guerreiro \n 2) Mago \n 3) Ladino \n\nEscolha : ";
   cin>>classe;
   switch (classe) {
      case 1:
         jogador.ifor+=4;
         jogador.idex+=1;
         jogador.ivida+=3;
         jogador.idef+=2;
         jogador.sclasse = "Guerreiro";
         break;
      case 2:
         jogador.ifor+=2;
         jogador.imagia+=5;
         jogador.idex+=1;
         jogador.ivida+=2;
         jogador.sclasse = "Mago";
         break;
      case 3:
         jogador.ifor+=3;
         jogador.idex+=2;
         jogador.ivida+=2;
         jogador.isorte+=3;
         jogador.sclasse = "Ladino";
         break;
      default:
         jogador.ifor+=3;
         jogador.idex+=2;
         jogador.ivida+=2;
         jogador.isorte+=2;
         jogador.idef+=2;
         jogador.sclasse = "Aldeao";
         break;
   }
   jogador.iatualvida = jogador.ivida;
   system("cls");
}
void tela_status(Personagem status){
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"|Nome: "<< status.snome<< "   |Classe: "<< status.sclasse<<"   |Raca: "<< status.sraca<<"| \n";
    cout<<"|Forca: "<< status.ifor<< "   |Destreza: "<< status.idex<<"   |Sorte: "<< status.isorte<<"| \n";
    cout<<"|Vida: "<< status.ivida<<"   |Defesa: "<< status.idef<<"   |Magia: "<< status.imagia<< "|\n";
    cout<<"----------------------------------------------------------------------------" << endl;
}

void batalha(Personagem &P1, int &f, bool vantagem=false, bool chefe=false, bool veneno = false, bool luta = false){
        orc.idef = 1 + (rand()%3), orc.ifor = 1 + (rand()%3), orc.ivida = 4;
        if(chefe == true){
            cout << "VOCE CHEGOU A BATALHA FINAL CONTRA O CHEFE ORC, PREPARE-SE!!!\n\n";
        }
        else if(vantagem == false){
            cout << "VOCE ENCONTROU UM ORC!!! PREPARE-SE PARA LUTAR!!!\n\n";
        }
        else{
            cout << "VOCE EMBOSCOU O ORC!!! COMECOU A BATALHA!!!\n\n";
        }
        system("pause");
        system ("cls");
        int turno=0;
        while(P1.iatualvida > 0 && orc.ivida > 0){
            int ataqueP = P1.ifor + rand()%6;
            int ataqueO = orc.ifor + rand()%6;
            int defesaP = P1.idef + rand()%6;
            int defesaO = orc.idef + rand()%6;
            if(turno==0 && vantagem==true){
                ataqueP += 4;
                defesaP += 4;
            }
            if(chefe == true){
                ataqueO +=4;
                defesaO +=4;
            }
            if(veneno == true){
                ataqueO -=2;
                defesaO -=2;
            }
            if(P1.sclasse == "Mago"){
                ataqueP += rand()%P1.imagia;
            }
            if(ataqueP > defesaO){
                orc.ivida--;
                cout << "Seu ataque funcionou, vida do Orc: " << orc.ivida << "\n\n";
                system("pause");
                system ("cls");
            }
            else{
                cout << "Seu ataque falhou, vida do Orc: " << orc.ivida << "\n\n";
                system("pause");
                system ("cls");
            }
            if((ataqueO > defesaP) && orc.ivida > 0){
                P1.iatualvida--;
                cout << "Ataque do orc funcionou, sua vida: " << P1.iatualvida << "\n\n";
                system("pause");
                system ("cls");
            }
            else if((ataqueO <= defesaP) && orc.ivida >0){
                cout << "Ataque do orc falhou, sua vida: " << P1.iatualvida << "\n\n";
                system("pause");
                system ("cls");
            }
            turno++;
        }
        if(P1.iatualvida == 0){
            cout << "Voce morreu!!\n\n";
            system("pause");
            system ("cls");
            f=40;
        }
        if(orc.ivida == 0){
            cout << "Voce ganhou a batalha!!\n\n";
            cout << "Voce consegue uma poao do 'Golias',voce se sente mais forte e resistente\n";
            P1.ivida=P1.ivida+1;
            P1.ifor=P1.ifor+1;
            system("pause");
            system ("cls");
        }
}

void emboscada(Personagem &jogador, int &f, bool chefe = false){
    int teste = jogador.idex;
    if(jogador.sraca == "Halfling" || jogador.sraca== "Anao"){
        if(jogador.sclasse == "Ladino"){
            jogador.idex = jogador.idex+3;
        }else{
            jogador.idex=jogador.idex+1;
        }
    }
    if(chefe == false){
        if(jogador.idex<=rand()%11){
            batalha(jogador, f, true);
        }else{
            batalha(jogador, f);
        }
    }
    else{
        if(jogador.idex<=rand()%11){
            batalha(jogador, f, true, true);
        }else{
            batalha(jogador, f, false, true);
        }
    }
    if(jogador.sraca =="Halfling" || jogador.sraca=="Anao"){
        if(jogador.sclasse == "Ladino"){
            jogador.idex=jogador.idex-3;
        }else{
            jogador.idex=jogador.idex-1;
        }
    }
}

int escrever(int LinhaI, int LinhaF,int escolha=0){
    salas.open("jogo.txt");
    for(int m=0; m<LinhaF; m++)
    {
        getline(salas,line);
        if(m >= LinhaI){
            cout << line<< endl;
        }
    }
    salas.close();
    if(escolha!= 1){
        cout << "Escolha (Menu:5) : ";
        cin >> escolha;
        system("cls");
        return escolha;
    }

}

int descansar(Personagem P1, int f){
    int sorte = rand()%(3+P1.isorte);
    if(sorte==0){
        return 50;
    }
    else{
        cout << "Descansa tranquilamente, e recupera sua vida perdida...\n\n";
        system("pause");
        system("cls");

        return f;
    }
}

void Pantano(Personagem &P1, int &f){
    escolha = escrever(0, 8);
    if(escolha == 1){
        f=50;
    }
    else if(escolha == 2){
        escolha = escrever(8, 19);
        if(escolha == 1){
            f=1;
        }
        else if(escolha == 2){
            f=2;
        }
    }
}

void Rio(Personagem &P1, int &f){
    if(chec[0]==0){
        escolha = escrever(19, 28);
        if(escolha == 1){
            if(P1.sraca != "Halfling")
            {
                cout << "Fruta venenosa: -1 de vida\n\n";
                system("pause");
                system("cls");
                P1.iatualvida--;
            }
            else{
                cout << "Voce se sente mais forte: +1 de forca\n\n";
                system("pause");
                system("cls");
                P1.ifor++;
            }
        }
        else if(escolha == 2){
            cout << "Fruta adiquirida!\n\n";
            system("pause");
            system("cls");
            PontFruit= &fruit;
            *PontFruit = true;
        }
        chec[0]=1;
    }
    escolha = escrever(28, 37);
    if(escolha == 1){
        escolha = escrever(37,44);
        if(escolha == 1){
            if(P1.sraca == "Anao"){
                cout << "Você por ser anao nao consegue nadar muito bem, e a forte correnteza lhe arrasta para as profundezas!!\n\n";
                system("pause");
                system("cls");
                f=40;
            }
            else{
                f=2;
            }
        }
    }
    else if(escolha == 2){
        f=3;
    }
}

void Cabana(Personagem &P1, int &f){
    escolha = escrever(45, 55);
    if(escolha == 1){
        f=3;
    }
    else if(escolha == 2 && chec[2] == 0){
        escolha = escrever(249,256);
        if (escolha == 1){
            batalha(P1, f);
            chec[2]=1;
        }
        else if(escolha == 2){
            emboscada(P1, f);
            chec[2]=1;
        }
        else if(escolha == 3){
            if(P1.sclasse == "Ladino"){
                cout << "Voce consegue fugir\n\n";
                system("pause");
                system("cls");
                f=3;
            }
            else{
                cout << "Voce tenta escapar, mas nao consegue!!\n\n";
                batalha(P1, f);
                system("pause");
                system("cls");
            }
            chec[2]=1;
        }
        if(f == 2){
            escrever(280,282,1);
            system("pause");
            system("cls");
            P1.ifor++;
        }
        chec[1]=1;
    }
    else if(escolha == 2 && chec[1] == 1){
        cout << "Nao ha mais nada em volta da casa!!\n\n";
        system("pause");
        system("cls");
    }
    else if(escolha == 3 && chec[2] == 0){
        P1.iatualvida = P1.ivida;
        f=descansar(P1, f);
        chec[2]= 1;
    }
    else if(escolha == 3 && chec[2] == 1){
        cout << "Voce nao pode mais descansar!\n\n";
        system("pause");
        system ("cls");
    }
}

void Cidade(Personagem &P1, int &f){
    escolha = escrever(66,74);
    if(escolha == 1){
        P1.iatualvida = P1.ivida;
        escolha = escrever(74,85);
        if(escolha == 1){
            f=8;
        }
        else if(escolha == 2){
            escrever(144,161,1);
            system("pause");
            system("cls");
            f=40;
        }
    }
    else if(escolha == 2){
        escolha = escrever(85,96);
        if(escolha == 1){
            escolha = escrever(127,144);
            if(escolha == 1){
                f=8;
            }
            else if(escolha == 2 && chec[3]==0){
                cout << "Voce pega os itens na mochila e consegue mais forca, seguindo em frente para a Pedra do ritual Orc.\n\n";
                system("pause");
                system("cls");
                P1.ifor++;
                chec[3] = 1;
                f=8;
            }
            else if(escolha == 2 && chec[3]==1){
                cout << "Você ja pegou tudo da mochila!!\n\n";
                system("pause");
                system("cls");
            }
        }
        else if(escolha == 2){
            escolha = escrever(97,110);
            if(escolha == 1){
                f=8;
            }
            else if(escolha == 2){
                escrever(144,161,1);
                system("pause");
                system("cls");
                f=40;
            }
        }
        else if(escolha == 3){
            escolha = escrever(118,126);
            if(escolha == 1){
                f=8;
            }
            else if(escolha == 2){
                escrever(144,161,1);
                system("pause");
                system("cls");
                f=40;
            }
        }
    }
}

void PedraOrc(Personagem &P1, int &f){
    escolha = escrever(161,178);
    if(escolha == 1){
        escrever(178,195);
        if(escolha == 1){
            escrever(202,222,1);
            system("pause");
            system("cls");
            f=40;
        }
    }
    else if(escolha == 2){
        escrever(223,228,1);
        system("pause");
        system("cls");
        batalha(P1, f, false, true);
        if(f!=40){
            escrever(230,236,1);
            f=40;
            system("pause");
            system("cls");
        }
        else{
            escrever(228,230,1);
            system("pause");
            system("cls");
        }
    }
    else if(escolha == 3){
        if(fruit == true){
            escolha = escrever(236,246);
        }
        else{
            escrever(286,292,1);
            escolha = 1;
        }
        if(escolha == 1){
            emboscada(P1, f, true);
            if(f!=40){
                escrever(230,236,1);
                f=40;
                system("pause");
                system("cls");
            }
            else{
                escrever(228,230,1);
                system("pause");
                system("cls");
            }
        }
        else if(escolha == 2){
            escrever(282,286,1);
            system("pause");
            system("cls");
            batalha(P1, f, false, true, true);
            if(f!=40){
                escrever(230,236,1);
                f=40;
                system("pause");
                system("cls");
            }
            else{
                escrever(228,230,1);
                system("pause");
                system("cls");
            }
        }
    }
}


void salvar(Personagem P1, int f, int chec[], int fruit){
    save.open("save.csv");
    save << "sep=, \n";
    save << P1.snome << "\n";
    save << P1.sclasse << "\n";
    save << P1.sraca << "\n";
    save << P1.ifor << "\n";
    save << P1.idex << "\n";
    save << P1.isorte << "\n";
    save << P1.ivida << "\n";
    save << P1.idef << "\n";
    save << P1.imagia<< "\n";
    save << f << "\n";
    save << fruit << "\n";
    for(int i=0; i<4; i++)
    {
        save << chec[i] << "\n";
    }
    save.close();
    cout << "Salvamento realizado com sucesso!!\n";
    Sleep(2000);
    system("cls");
}

void carregar(Personagem &P1, int &f, int *v[], bool &fruit){
    save.open("save.csv");
    string load;
    int fruta;
    getline(save, load);
    getline(save, P1.snome);
    getline(save, P1.sclasse);
    getline(save, P1.sraca);
    getline(save, load);
    P1.ifor = atoi(load.c_str());
    getline(save, load);
    P1.idex = atoi(load.c_str());
    getline(save, load);
    P1.isorte = atoi(load.c_str());
    getline(save, load);
    P1.ivida = atoi(load.c_str());
    getline(save, load);
    P1.idef = atoi(load.c_str());
    getline(save, load);
    P1.imagia = atoi(load.c_str());
    getline(save, load);
    f = atoi(load.c_str());
    getline(save, load);
    fruta = atoi(load.c_str());
    if(fruta == 0){
        fruit = false;
    }
    else if(fruta == 1){
        fruit = true;
    }
    for(int i=0; i<4; i++){
        getline(save, load);
        *v[i] = atoi(load.c_str());
    }
    save.close();
    cout << "Carregamento realizado com sucesso!!\n";
    Sleep(2000);
    system("cls");
}

void Fase(Personagem &P1,int &f){
    if(escolha == 5){}
    else if (f == 0){
        Pantano(P1, f);
        Fase(P1, f);
    }
    else if(f == 1){
        Rio(P1, f);
        Fase(P1, f);
    }
    else if(f == 2){
        Cabana(P1, f);
        Fase(P1, f);
    }
    else if(f == 3){
        Cidade(P1, f);
        Fase(P1, f);
    }
    else if(f == 4){

    }
    else if(f == 8){
        PedraOrc(P1, f);
        Fase(P1, f);
    }
    else if(f == 40){
        menu.open("fim.txt");
        while(menu.eof() == false)
        {
            getline(menu,line);
            cout << line<< endl;
        }
        menu.close();
    }
    else if(f == 50){
        escrever(59,63,1);
        system("pause");
        system("cls");
        f=40;
        Fase(P1,f);
    }
}

void Menu(Personagem &P1, int &f){
    srand(time(NULL));
    int espera;
    int voltar;
    Nomaderpg();
    menu.open("menu.txt");
    while(menu.eof() == false)
    {
        getline(menu,line);
        cout << line<< endl;
    }
    menu.close();
    cin>>espera;
    system("cls");
    switch(espera){
    case 1:
        if(comeco == true || f==40)
        {
            f=0;
            IniJogador(P1);
            for(int i; i<4; i++)
            {
                chec[i]=0;
            }
            comeco = false;
        }
        escolha = 0;
        Fase(P1, f);
        Menu(P1, f);
        break;
    case 2:
        tela_status(P1);
        cout << "Para voltar digite 1: ";
        cin >> voltar;
        system("cls");
        Menu(P1, f);
        break;
    case 3:
        if(comeco == false){
            cout << "Deseja salvar realmente? (1-sim / 2-nao) ";
            cin >> escolha;
            system("cls");
            if(escolha == 1){
                salvar(P1, f, chec, fruit);
            }
        }
        else{
            cout << "NADA PARA SALVAR!";
            Sleep(2000);
            system("cls");
        }
        Menu(P1, f);
        break;
    case 4:
        cout << "Deseja carregar um salvamento? (1-sim / 2-nao) ";
        cin >> escolha;
        system("cls");
        if(escolha == 1){
            for(int i=0; i<4; i++){
                v[i] = &chec[i];
            }
            carregar(P1, f, v, fruit);
        }
        comeco = false;
        Menu(P1, f);
        break;
    case 5:
        break;

    }
}
#endif // JOGO_H_INCLUDED
