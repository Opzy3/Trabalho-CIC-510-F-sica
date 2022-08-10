#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// função para ler sem pressionar enter
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
//início do algoritmo e declaração de variáveis
int main(void) {
  
  char continuar;
  float Hi, Vi, V2, Mi, M2, M3, M4, G, G2, F;  
  G = 10;
  srand(time(NULL)); 


//Introdução 
  system("clear");
  printf("!!!!!!!!!!!!!!!!JOGO DA MONTANHA RUSSA!!!!!!!!!!!!!!!\n\n");
  sleep(2);
  printf("Pressione alguma tecla para continuar. ");
  getch();
  setbuf(stdin,NULL);
  system("clear");
//inserir valores das variáveis M, H, V 

  printf("\n\nPara que o carrinho percorra a distância de A até B, um carrinho bate na sua traseira e você entra em movimento!\n\n");

  //a altura H digitada será considerada como metro
  printf("Digite a altura da montanha russa: \n");  
  scanf("%f", &Hi);
  //a massa inicial (mi) será considerada como kg 
  printf("Digite a massa inicial do carrinho que bateu na sua traseira : \n");
  scanf("%f", &Mi);
  //Velocidade inicial (vi) sera considerada em m/s
  printf("Digite a velocidade, do carrinho que bateu na sua traseira: \n");
  scanf("%f", &Vi);
  sleep(1);
  system("clear");
  // Calculos dos valores inseridos 
  M2=Mi+Mi*0.25;
  V2 = 2*Mi*Vi/(Mi+M2);
  M3= 2*M2*(V2*V2 + 2*G*Hi)/(5*G*Hi);      
  G2= 3*G/5;
  M4=3*M3/2;
  F= -1*M4*G/24;
  // declaração da variavel de escolha
  int Escolha;
//Primeira pergunta sobre o caminho de A até B
printf("Agora, seu carrinho está descendo até o ponto B, Contudo, para que ele chegue com velocidade suficiente no ponto C, Qual deverá ser a nova massa do carrinho? \n");
// declaração de variáveis para fazer as multiplas escolhas
float variavel1 = M3 - 2.8 ;
float variavel2 = M3 + 1;
float variavelnova1 = M3 + 1.2;
printf("1) %.2f\n", variavel1);  
printf("2) %.2f\n", variavel2);
printf("3) %.2f\n", M3);
printf ("4) %.2f\n", variavelnova1);
scanf("%d", &Escolha);
// caso a variavel nao seja a resposta certa, ele pergunta novamente, inserindo uma frase dizendo que é a resposta errada
while(Escolha != 3){
    system("clear");
    printf("Agora, seu carrinho está descendo até o ponto B, Contudo, para que ele chegue com velocidade suficiente no ponto C, Qual deverá ser a nova massa do carrinho? \n");

printf("1) %.2f\n", variavel1);  
printf("2) %.2f\n", variavel2);
printf("3) %.2f\n", M3);
printf ("4) %.2f\n", variavelnova1);
printf("Escolha errada, selecione novamente:\n");
scanf("%d", &Escolha);

  }
  //caso vc acerte, ele limpa a tela e passa para proxima pergunta
  printf("VOCÊ ACERTOU! Vamos Continuar...\n\n ");
  sleep(2);
  system("clear");
//Segunda pergunta da gravidade de C até E
printf("Chegando ao ponto C, o carrinho iniciará uma descida brusca até o ponto D, onde ele precisará subir novamente ao ponto E, qual o valor da gravidade para que esse movimento ocorra? \n");
//declaração de variáveis para multipla escolha
float variavel3 = G2*2.3;
float variavel4 = G2 - 3;
float variavelnova2 = G2-1.7;
  
printf("1) %.2f\n", G2);  
printf("2) %.2f\n", variavel3);
printf("3) %.2f\n", variavel4);
printf ("4) %.2f\n", variavelnova2);
scanf("%d", &Escolha);
// caso não seja a resposta certa, ele pergunta denovo
while(Escolha != 1){
    system("clear");
    printf("Chegando ao ponto C, o carrinho iniciará uma descida brusca até o ponto D, onde ele precisará subir novamente ao ponto E, qual o valor da gravidade para que esse movimento ocorra? \n");

printf("1) %.2f\n", G2);  
printf("2) %.2f\n", variavel3);
printf("3) %.2f\n", variavel4);
printf ("4) %.2f\n", variavelnova2);
printf("Escolha errada, selecione novamente:\n");
scanf("%d", &Escolha);

  }
//caso seja a resposta certa ele sai da estrutura de repetição, imprime que você acertou e logo em seguida mostra a proxima pergunta 
printf("VOCÊ ACERTOU! Vamos continuar...\n\n ");
sleep(2);
system("clear");
//Terceira pergunta 
system("clear");
printf("Depois de chegar no ponto E o carrinho parte até o ponto F e sua massa muda para que ele suba ao ponto G  %.2f metros acime do ponto F.\n \nQual o valor dessa nova massa?\n",Hi/2);
float variavel5 = M4 - 4;
float variavel6 = M4 + 2;
float variavelnova3 = M4 - 1.7; 
printf("1) %.2f\n", M4);  
printf("2) %.2f\n", variavel5);
printf("3) %.2f\n", variavel6);
printf("4) %.2f\n", variavelnova3);
scanf("%d", &Escolha);

while(Escolha != 1){
    system("clear");
    printf("Depois de chegar no ponto E o carrinho parte até o ponto F e sua massa muda para que ele suba ao ponto G  %.2f metros acime do ponto F.\n \nQual o valor dessa nova massa?\n",Hi/2);

printf("1) %.2f\n", M4);  
printf("2) %.2f\n", variavel5);
printf("3) %.2f\n", variavel6);
printf ("4) %.2f\n", variavelnova3);
printf("Escolha errada, selecione novamente:\n");
scanf("%d", &Escolha);

  }
printf("VOCÊ ACERTOU!!!!!!!\n\n ");
sleep(2);
system("clear");
//quarta pergunta
printf("Após chegar no ponto E, O carrinho desce até um ponto F onde o ponto H que está a %.2f metros a baixo do ponto G. Ao chegar em H, Carrinho começa a desacelerar até um ponto I que está a %.2f a frente em linha reta.\n \nQual o valor dessa força?\n",Hi/8, 3*Hi);

float variavel7 = F - 2;
float variavel8 = F + 3;
float variavelnova4 = F + 2;
printf("1) %.2f\n", variavel7);  
printf("2) %.2f\n", F);
printf("3) %.2f\n", variavel8);
printf("4) %.2F\n", variavelnova4);
scanf("%d", &Escolha);
while(Escolha != 2){
    system("clear");
    printf("Após movimentar até o ponto G, O carrinho desce a um ponto H que está a %.2f metro a baixo de G. Ao chegar em H,o carrinho começa a desacelerar até um ponto I que está a %.2f na sua frente.\n \nQual o valor desta força?\n",Hi/8, 3*Hi);

printf("1) %.2f\n", variavel7);  
printf("2) %.2f\n", F);
printf("3) %.2f\n", variavel8);
printf("4) %.2F\n", variavelnova4);
printf("Resposta errada, digite novamente:\n");
scanf("%d", &Escolha);

  }
// imprime que você ganhou na tela
printf("VOCÊ ACERTOU!!!!!!!\n\n ");
sleep(2);
system("clear");
printf("************JOGO DA MONTANHA RUSSA**************\n\n\n");
printf("************************************************");
printf("PARABÉNS, VOCÊ TERMINOU O JOGO COM SUCESSO!!!!!");
printf("************************************************");

}