/*************************************************/  
#include <stdio.h>  
#include <stdlib.h>  
/*************************************************/  
/* ESTRUTURA DOS NÓS */  
typedef struct no_arvore{  
    int info,altura;  
    struct no_arvore *esq, *dir;  
}*no_arv;  

/*************************************************/  
/* ALOCA MEMÓRIA */  
no_arv aloca_no_arv(){  
  no_arv aux=(struct no_arvore*)malloc(sizeof(struct no_arvore));  
  if (aux==NULL)  
     printf("\n\n\t\tNAO FOI POSSIVEL ALOCAR MEMORIA.");   
  return aux;  
}  
/*************************************************/  
/* RETORNA ALTURA */  
int altura(no_arv raiz ){  
    if( raiz == NULL )  
        return 0;  
    else  
        return raiz->altura;  
}  
/*************************************************/  
/* CALCULAR ALTURA */  
int calcular_altura(no_arv esq, no_arv dir ){  
    int ae, ad;  
    ae=altura(esq);  
    ad=altura(dir);  
       if(ae>ad)  
           return ae+1;  
       else  
           return ad+1;  
}  
/****************************************************/  
/* ALTURA MAIOR */  
int altura_maior(int a, int b){  
  if (a>=b)  
    return a;  
  else return b;  
}  
/****************************************************/  
/* ROTAÇÂO A DIREITA */  
no_arv rot_dir(no_arv no){  
    no_arv aux;  
    aux = no->esq;  
    no->esq = aux->dir;  
    aux->dir = no;  
    no->altura = altura_maior(altura(no->esq),altura(no->dir))+1;  
    aux->altura = altura_maior(altura(aux->esq),altura(no))+1;  
    return aux;   
}  
/****************************************************/  
/* ROTAÇÂO A ESQUERDA */  
no_arv rot_esq(no_arv no){  
    no_arv aux;  
    aux = no->dir;  
    no->dir = aux->esq;  
    aux->esq = no;  
    no->altura = altura_maior(altura(no->esq),altura(no->dir))+1;  
    aux->altura = altura_maior(altura(aux->dir),altura(no))+1;  
    return aux;   
}  
/****************************************************/  
/* ROTAÇÂO DUPLA ESQUERDA-DIREITA */  
no_arv rot_esq_dir(no_arv no){  
    no->esq = rot_esq( no->esq );  
    return rot_dir(no);  
}  
/****************************************************/  
/* ROTAÇÂO DUPLA DIREITA-ESQUERDA */  
no_arv rot_dir_esq(no_arv no){  
    no->dir=rot_dir(no->dir);  
    return rot_esq(no);  
}  
/****************************************************/
/* VERIFICA AVL */  
void verifica_avl(no_arv *no){  
  if ((*no)!=NULL){  
       if ( (altura((*no)->dir) - altura((*no)->esq))==-2){  
            if ( (altura((*no)->esq->dir) - altura((*no)->esq->esq) )==-1)  
               *no=rot_dir(*no);  
            else  
               *no=rot_esq_dir(*no);  
       }else  
           if ( (altura((*no)->dir) - altura((*no)->esq))==2){  
                if((altura((*no)->dir->dir)-altura((*no)->dir->esq))==1)  
                    *no=rot_esq(*no);  
                else  
                    *no=rot_dir_esq(*no);  
           }      
    (*no)->altura=calcular_altura((*no)->esq,(*no)->dir);           
    if((*no)->esq!=NULL)     
        verifica_avl(&((*no)->esq));  
    if((*no)->dir!=NULL)  
        verifica_avl(&((*no)->dir));    
  }  
  
}  
/* INSERE NO */  
void insere(no_arv *no, int x){  
    if (*no == NULL){  
        *no = aloca_no_arv();  
        (*no)->info=x;  
        (*no)->esq = NULL;  
        (*no)->dir = NULL;  
    }else {  
        if (x < (*no)->info)  
            insere(&((*no)->esq), x);  
        else  
            insere(&((*no)->dir), x);  
    }  
    /* atualiza altura dos que estão acima*/  
    (*no)->altura=calcular_altura((*no)->esq,(*no)->dir);  
    verifica_avl(no);  
}  
/****************************************************/  
/* CARREGA ARVORE DO ARQUIVO "arvore.txt" */  
void carrega_arvore(no_arv *no){  
    FILE *arquivo;    
    char str_no[5],x;  
    arquivo=fopen ("arvore.txt","r");    
    if (!arquivo)  
       printf("Não foi possivel abrir  o arquivo arvore.txt");  
    else  
       x=getc(arquivo);         
       fseek(arquivo,-1,SEEK_CUR);   
       while (x!=EOF){    
          fgets(str_no,5,arquivo);  
          insere(no,atoi(str_no));                       
          x=getc(arquivo);  
          fseek(arquivo,-1,SEEK_CUR);   
       }      
}  
/****************************************************/  
/* BUSCA ELEMENTO NA ARVORE */  
no_arv busca(no_arv no,int x){  
     static int cont=0;  
     if(no==NULL){  
       cont=0;  
       return(NULL);  
     }  
     if(x==no->info){  
       printf(" Encontrado no nivel: %d",cont);  
       cont=0;  
       return(no);  
     }  
     if(x<no->info){  
      cont++;  
      return(busca(no->esq,x));  
     }  
     if(x>no->info){  
      cont++;  
      return(busca(no->dir,x));  
     }  
}  
/****************************************************/  
/* RETORNA MAIOR */  
no_arv retorna_maior(no_arv *no){  
    no_arv aux;  
    aux = *no;  
    if (aux->dir==NULL){  
        *no=(*no)->esq;  
        return (aux);  
    }else  
        return (retorna_maior(&((*no)->dir)));  
}  
/****************************************************/  
  
  
/****************************************************/  
/* EXCLUI NO */  
int exclui(no_arv *no, int x){  
    static int alt;  
    no_arv aux;  
    int resultado;  
    if (*no == NULL)  
        return 0;                 
    if ((*no)->info==x){ //encontrou  
        aux=*no;  
        /* se não tiver filho na esquerda */  
        if ((*no)->esq==NULL)  
            *no=(*no)->dir; /*então o filho da direita substitui */   
        else   
            /* se não tem filho a direita */  
            if ((*no)->dir==NULL)   
               *no=(*no)->esq; /* então o filho da esquerda substitui */  
            else{ /* senão possui dois filhos */  
               aux=retorna_maior(&((*no)->esq)); /* busca o substituto */  
               (*no)->info=aux->info;   
            }  
        free (aux); /* ou é folha */  
        return 1;  
    }else{  
        if (x<(*no)->info)  
            return (exclui(&((*no)->esq),x));   
        else  
            return (exclui(&((*no)->dir),x));  
    }  
}  
/****************************************************/  
/* DESTRUIR ARVORE */  
no_arv destruir_arvore(no_arv *no){  
     if(*no==NULL)  
       printf("\n\tEsta vazia\n");  
       return NULL; /* para garantir o retorno NULL mesmo que a raiz já seja NULL */  
     if((*no)->esq!=NULL)  
        (*no)->esq=destruir_arvore(&((*no)->esq));  
     if((*no)->dir!=NULL)  
        (*no)->dir=destruir_arvore(&((*no)->dir));  
     free(no);  
     return NULL;  
     printf("\nVoltando um nivel...");       
}  
/*************************************************/  
/* IN_ORDEM */  
void in_ordem(no_arv no){  
  if (no!=NULL){  
     if(no->esq!=NULL)  
        in_ordem(no->esq);  
     printf("[%d]",no->info);
     if(no->esq) printf("left %d\n", no->esq->info); 
     if(no->dir) printf("right %d\n", no->dir->info); 
     if(no->dir!=NULL)  
        in_ordem(no->dir);  
  }else  
      printf("\n\tA arvore esta vazia!\n");   
}  
/*************************************************/  
/* PRE_ORDEM */  
void pre_ordem(no_arv no){  
  if (no!=NULL){  
     printf("[%d]",no->info);   
     if(no->esq!=NULL)  
        pre_ordem(no->esq);  
     if(no->dir!=NULL)  
        pre_ordem(no->dir);  
  }else  
      printf("\n\tA arvore esta vazia!\n");    
}  
/*************************************************/  
/* POS_ORDEM */  
void pos_ordem(no_arv no){  
  if (no!=NULL){  
     if(no->esq!=NULL)  
        pos_ordem(no->esq);  
     if(no->dir!=NULL)  
        pos_ordem(no->dir);  
     printf("[%d]",no->info);    
  }else  
      printf("\n\tA arvore esta vazia!\n");    
  
}  
/*************************************************/  
/* MOSTRAR (PRE_ORDEM) */  
void mostrar(no_arv no){  
     static int cont=0;  
     if(no==NULL)  
       printf("\nEsta vazia\n");  
     else  
       printf("[%d] , Altura: %d ",no->info,no->altura);  
     if(no->esq!=NULL){  
        printf("\n\tEsquerda:");       
        mostrar(no->esq);  
     }  
     if(no->dir!=NULL){  
        printf("\n\tDireita:");  
        mostrar(no->dir);  
     }  
     printf("\nVoltando um nivel...");  
}  
/*************************************************/  
/* MOSTRAR ARVORE*/  
void mostrar_arvore(no_arv no){  
  if (no!=NULL){  
    printf("\n***********************************");  
    printf("\n******* Caminho da arvore *********");  
    printf("\n***********************************\n\tRaiz:");  
    mostrar(no);  
    printf("\n***********************************\n");  
  }else  
      printf("\n\tA arvore esta vazia!\n");    
}  
/*************************************************/  
/* MENU */  
void menu(){  
  printf("\n\t##########################################");  
  printf("\n\t##  Estruturas de Dados II ##");     
  printf("\n\t## Arvore Binaria  - AVL                ##");     
  printf("\n\t##                        ##");     
  printf("\n\t##########################################");  
  printf("\n\t##  OPCOES ");  
  printf("\n\t## 1 - Inserir 1 elemento.");  
  printf("\n\t## 2 - Inserir 10 elementos.");  
  printf("\n\t## 3 - Mostrar arvore. (PRE-ORDEM)");  
  printf("\n\t## 4 - Buscar elemento.");  
  printf("\n\t## 5 - Excluir elemento.");  
  printf("\n\t## 2 - Percurso IN-ORDEM.");  
  printf("\n\t## 7 - Percurso PRE-ORDEM.");  
  printf("\n\t## 8 - Percurso POS-ORDEM.");  
  printf("\n\t## 9 - Destruir arvore.");    
  printf("\n\t## 0 - Sair.");  
  printf("\n\t##########################################\n");    
}  
/****************************************************/  
/* MAIN */  
int main(){  
    no_arv raiz=NULL;  
    int op,i,x;  
    //carrega_arvore(&raiz);  
    do{  
         menu();  
         printf("\n\tOpcao: ");  
         scanf("%d",&op);  
         switch(op){  
               case 1:  
                    printf("\n\tNovo elemento(inteiro):");  
                    scanf(" %d",&x);  
                    insere(&raiz, x);  
               break;  
               case 2:  
                    in_ordem(raiz);            
               break;  
               case 3:  
                    printf("\n\tElemento a ser removido: ");  
                    scanf(" %d",&x);  
                    if (exclui(&raiz,x))  
                       printf("\n\tElemento foi excluido.");  
                    else  
                       printf("\n\tEste elemento nao esta na arvore!");                                          
                    verifica_avl(&raiz);  
               break;   
               case 5:  
                    mostrar_arvore(raiz);  
               break;  
               case 6:  
                    for(i=0;i<10;i++){  
                      printf("\n\tNovo elemento(inteiro):");  
                      scanf(" %d",&x);   
                      insere(&raiz, x);  
                    }  
               break;  
               case 4:  
                    printf("\n\tElemento procurado: ");  
                    scanf(" %d",&x);   
                    if (busca(raiz,x)==NULL)  
                       printf("\n\tEste elemento nao esta na arvore!\n");  
               break;  
               case 7:  
                    pre_ordem(raiz);  
               break;  
               case 8:  
                    pos_ordem(raiz);  
               break;                                               
               case 9:  
                    printf("\n\n\tDestruindo arvore...\n\t");    
                    raiz=destruir_arvore(&raiz);  
               break;                 
               case 0:break;                
               default: printf("\n\tOpcao invalida."); break;  
        }  
        printf("\n\n\t");          
    }while (op!=0);   
  
  return 0;  
}