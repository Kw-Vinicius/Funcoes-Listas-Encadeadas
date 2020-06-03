#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//-----------------------------------------------------------------------------------------------------------------

struct Elementos{
 int num;
 struct Elementos *prox;
}; 
typedef struct Elementos Elementos;

int vazia(Elementos *LISTA);
void inicia(Elementos *LISTA);
int menu(void);
void opcao(Elementos *LISTA, int op);
Elementos *criaNo();
void insereFim(Elementos *LISTA);
void insereInicio(Elementos *LISTA);
void exibe(Elementos *LISTA);
void libera_memoria(Elementos *LISTA);
void inserir_indicada(Elementos *LISTA);
int testar_elemento(Elementos *LISTA);
void excluir_elemento(Elementos *LISTA);
void buscar_elemento(Elementos *LISTA);
void excluir_repetidos(Elementos *LISTA);

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------



int main(void)
{

 Elementos *LISTA = (Elementos *) malloc(sizeof(Elementos));
 if(!LISTA){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }
 inicia(LISTA);
 int opt;
 
 do{
  opt=menu();
  opcao(LISTA,opt);
 }while(opt);

 free(LISTA);
 return 0;
}

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------


void inicia(Elementos *LISTA)
{
 LISTA->prox = NULL;
}


// -----------------------------------------------------------------------------------------------------------




int menu(void)
{
 int opt;
 system("pause");
system("cls");

 printf("Escolha a opcao\n");
 printf("0. Sair\n");
 printf("1. Exibir lista\n");
 printf("2. Adicionar Elementos no inicio\n");
 printf("3. Adicionar Elementos no final\n");
 printf("4. Zerar lista\n");
 printf("5. Inserir Elementos na posicao indicada\n");
 printf("6. Testar se existe o elemento na lista encadeada\n");
 printf("7. Excluir elemento(valor//posicao)\n");
 printf("8. Buscar elemento na lista(valor//posicao)\n");
 printf("9. Excluir elementos repeditos\n");
 printf("Opcao: "); 
 scanf("%d", &opt);
 
 return opt;
}

//-----------------------------------------------------------------------------------------------------------------

void opcao(Elementos *LISTA, int op)
{
 switch(op){
  case 0:
   libera_memoria(LISTA);
   break;
   
  case 1:
   exibe(LISTA);
   break;
  
  case 2:
   insereInicio(LISTA);
   break;
  
  case 3:
   insereFim(LISTA);
   break;  
   
  case 4:
   inicia(LISTA);
   break;

  case 5:
   inserir_indicada(LISTA);
   break;
  
  case 6:
    if(testar_elemento(LISTA))
    {
      printf("Elemento existe na lista\n");
    }else printf("Elemento nao existe na lista\n");
    break;

  case 7:
    excluir_elemento(LISTA);
    break;

  case 8:
    buscar_elemento(LISTA);
    break;

  case 9:
    excluir_repetidos(LISTA);
    break;

  default:
   printf("Comando invalido\n\n");
 }
}


// --------------------------------------------------------------------------------------------------------------------

int vazia(Elementos *LISTA)
{
 if(LISTA->prox == NULL)
  return 1;
 else
  return 0;
}

//----------------------------------------------------------------------------------------------------------------------

void insereFim(Elementos *LISTA)
{
 Elementos *novo=(Elementos *) malloc(sizeof(Elementos));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }
 printf("Novo elemento: "); 
 scanf("%d", &novo->num);
 novo->prox = NULL;
 
 if(vazia(LISTA))
  LISTA->prox=novo;
 else{
  Elementos *tmp = LISTA->prox;
  
  while(tmp->prox != NULL)
   tmp = tmp->prox;
  
  tmp->prox = novo;
 }
}

//------------------------------------------------------------------------------------------------------------------

void insereInicio(Elementos *LISTA)
{
 Elementos *novo=(Elementos *) malloc(sizeof(Elementos));
 if(!novo){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }
 printf("Novo elemento: "); 
 scanf("%d", &novo->num);
 
 Elementos *Auxiliar_temporario = LISTA->prox;
 
 LISTA->prox = novo;
 novo->prox = Auxiliar_temporario;
}


//------------------------------------------------------------------------------------------------------------------

void exibe(Elementos *LISTA)
{
 if(vazia(LISTA)){
  printf("Lista vazia!\n\n");
  return ;
 }
 
 Elementos *tmp;
 tmp = LISTA->prox;
 
 while( tmp != NULL){
  printf("%5d", tmp->num);
  tmp = tmp->prox;
 }
 printf("\n\n");
}


//-----------------------------------------------------------------------------------------------------------------

void libera_memoria(Elementos *LISTA)
{
 if(!vazia(LISTA)){
  Elementos *proxElementos,
     *atual;
  
  atual = LISTA->prox;
  while(atual != NULL){
   proxElementos = atual->prox;
   free(atual);
   atual = proxElementos;
  }
 }
}


//-----------------------------------------------------------------------------------------------------------------



void inserir_indicada(Elementos *LISTA)
{

  int op,cont=0;
  Elementos *tmp,
        *aux,
        *aux2;
  printf("Digite a posicao para inserir um novo elemento na lista: \n");
  scanf("%d",&op);

 tmp = LISTA->prox;
 
 while( tmp != NULL)
   {

     cont++;
     tmp = tmp->prox;

   }
if(op==1)
{
  insereInicio(LISTA);
}else if(op==cont){
  insereFim(LISTA);

}else{
op=op-2;

if(cont<op)
{
  printf("A posicao escolhida nao pode ser adicionada na lista, pois a lista possui atualmente %d elementos",cont);
}else{
      Elementos *novo=(Elementos *) malloc(sizeof(Elementos));
      if(!novo)
       {
          printf("Sem memoria disponivel!\n");
          exit(1);
       }
         printf("Novo elemento: "); 
         scanf("%d", &novo->num);

      cont=0;
      tmp= LISTA->prox;

      while(cont!=(op))
      {
        cont++;
        tmp=tmp->prox;
      }

      if(cont==op)
      {
        aux=tmp->prox;
        tmp->prox = novo;
        novo->prox = aux;
      }
}
}
}


//-----------------------------------------------------------------------------------------------------------------


int testar_elemento(Elementos *LISTA)
{
if(vazia(LISTA)){
  printf("Lista vazia!\n\n");
  return 0;
 }

 int escolhido;
 Elementos *aux;
 aux = LISTA->prox;
 
printf("Digite um valor para fazer a busca na lista:\n");
scanf("%d",&escolhido);

 while( aux != NULL)
 {
    if(aux->num==escolhido)
    {
      return 1;
    }else aux = aux->prox;
 }
  return 0;
}


//-----------------------------------------------------------------------------------------------------------------

void excluir_elemento(Elementos *LISTA)
{

  int op;
  int valor_posicao;
  int cont=0;
  Elementos *aux1;
  Elementos *aux2;

  printf("Deseja excluir um elemento por valor[1] ou por posicao[2]?\n");
  scanf("%d",&op);

    if(op!=2&&op!=1)
    {
      do{
        system("cls");
        printf("\nEscolha [1] para excluir elemento por valor\nEscolha [2] para excluir elemento por posicao\n");
        scanf("%d",&op);
      }while(op!=2&&op!=1);
    }

// ------------------------------------------ Por Valor ---------------------------------------------------- // 
  if(op==1)
  {
    printf("Digite algum valor para excluir elementos da lista:\n");
    scanf("%d",&valor_posicao);
    aux1 = LISTA;
    aux2 = LISTA->prox;
    
    while( aux2 != NULL)
     {
        if(aux2->num==valor_posicao)
        {
          aux1->prox=aux2->prox;
          free(aux2);
          return;
        }else{
          aux1 = aux1->prox;
          aux2 = aux2->prox;
        } 
     }
  }


// ------------------------------------------ Por Posição ---------------------------------------------------- // 


  if(op==2)
  {

    printf("Digite alguma posicao para excluir um elemento da lista:\n");
    scanf("%d",&valor_posicao);

    aux1 = LISTA;
    aux2 = LISTA->prox;

    while( aux2 != NULL)
     {
        cont++;
        if(cont==valor_posicao)
        {
          aux1->prox=aux2->prox;
          free(aux2);
          return;
        }else{
          aux1=aux1->prox;
          aux2=aux2->prox;
        }
     }
  }

}


// ------------------------------------------------------------------------------------------------------------------------------

void buscar_elemento(Elementos *LISTA)
{

  int tipo_buscar;
  int busca_valor_posicao;
  Elementos *aux1;
  int cont=0;
  int x=-1;

  printf("Deseja buscar um elemento da lista por valor[1] ou por posicao[2]?\n");
  scanf("%d",&tipo_buscar);

    if(tipo_buscar!=1&&tipo_buscar!=2)
    {
      do{
          printf("Digite [1] para buscar por valor\nDigite [2] para buscar por posicao\n");
          scanf("%d",&tipo_buscar);
      }while(tipo_buscar!=1&&tipo_buscar!=2);
    }

  if(tipo_buscar==1)
  {
      aux1 = LISTA->prox;
      printf("Digite o valor que deseja buscar na lista:\n");
      scanf("%d",&busca_valor_posicao);

      while( aux1 != NULL)
        {
          cont++;
        if(aux1->num==busca_valor_posicao)
        {
          printf("O valor %d esta armazenado na posicao %d\n",busca_valor_posicao,cont);
          return;

        }else aux1 = aux1->prox;
      }
  }

  if(tipo_buscar==2)
  {
    aux1=LISTA->prox;
    printf("Digite a posicao que deseja buscar na lista:\n");
    scanf("%d",&busca_valor_posicao);
    while( aux1 != NULL)
        {
            cont++;
            if(cont==busca_valor_posicao)
            {       
                printf("Na posicao %d foi armazenado o valor %d\n",busca_valor_posicao,aux1->num);
                return;
            }else 
                aux1 = aux1->prox;
        }
  }
}



// ------------------------------------------------------------------------------------------------------------------------------


void excluir_repetidos(Elementos *LISTA)
{
Elementos *aux1,     //Ponteiro atual
          *aux2,    //Ponteiro anterior
          *aux3;   //Ponteiro seguinte

for(aux1=LISTA; aux1 != NULL; aux1 = aux1->prox)
  {
    aux2 = NULL;
      for(aux3 = aux1->prox; aux3 != NULL; )
        {
            if(aux3->num == aux1->num)
            {
              if(aux2 == NULL)
                aux1->prox = aux3->prox;
               else 
                 aux2->prox = aux3->prox;

               Elementos *remove = aux3;
               aux3 = aux3->prox;
               free(remove);
            }else{
                aux2 = aux3;
                aux3 = aux3->prox;
            }
        }
  }

}

// ------------------------------------------------------------------------------------------------------------------------------