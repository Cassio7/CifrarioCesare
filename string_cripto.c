#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*funzione per il cifrario di Cesare, gli passo tutta la stringa con * con il riferimento al puntatore*/
void cesare(char *stringa){
  int k=0,c=0, t=0;//k=salto da eseguire. c=contatore. t=var temporanea.
  do{
  printf("Inserisci il salto da eseguire, superiore a 1 ma inferiore a 25\n");
  scanf("%d",&k);
}while(k<1||k>25);//inserimento di k compreso tra 1-26
  printf("----------------------------------------------------------\n\n" );
  printf("La tua frase: %s\n",stringa);
  printf("La tua frase cifrata/cyphertext tramite cifr. di Cesare e' : \n" );
  for (c=0;c<strlen(stringa);c++){//ciclo per la stampa della frase cifrata
    t=0;
    if(isspace(stringa[c])){//controllo se il carattere è uno spazio
      printf(" ");
    }
    else{
/*controllo se il carattere è fuori dal range dell'alfabeto minuscolo quindi può essere: ! : / ...*/
      if (stringa[c]<97||stringa[c]>122) {
        printf("%c",stringa[c]);
      }
      else{
/*la if controllara se il carattere ascii + k sfora 122, se è così metto t=26 di modo che
 rientro nel range dei caratteri minuscoli, sottraendo t quando vado a stampare.
 E' necessario per il cifrario di Cesare perchè dopo "z" si riparte da "a" (123-26=97)*/
      if(stringa[c]+k>122){
        t=26;
      }
      printf("%c",stringa[c]+k-t);
    }
  }
}
printf("\n");
}

/*funzione per il cifrario a sostituzione, gli passo tutta la stringa con * con il riferimento al puntatore*/
void sos(char *stringa){
  /*alfabeto normale di 26 caratteri*/
  char alfabeto[26]={'a','b', 'c', 'd' ,'e' ,'f' ,'g' ,'h' ,'i' ,'j' ,'k','l' ,'m' ,'n', 'o', 'p' ,'q', 'r', 's' ,'t' ,'u', 'v' ,'w' ,'x' ,'y','z'} ;
  int c=0,i=0,a=0;//c=contatore. i=contatore. a=flag.
  char alfabeto_mescolato[26],temp;//temp=var temporanea ci inserisco un carattere per poi passarlo ad alfabeto mesc
  for (c=0;c<26;c++){
    do{
    a=0;
    printf("Inserisci una lettera minuscola alla volta dell'alfabeto per creare alfabeto mescolato, non sono ammesse ripetizioni\n");
    scanf("\n%c", &temp);
    if (temp<97||temp>122) {//controllo se non è un carattere dell'alfabeto minuscolo
      printf("Carattere non valido\n");
      a++;
    }
  }while(a!=0);//esce solo quando il carattere è valido
    a=0;
/*controllo se temp è presente in alfabeto, se si inserisco temp nella posizione c dentro alfabeto_mescolato.
Poi metto uno "0" al posto della lettera corrispondente su alfabeto, così nel ciclo successivo la stessa
lettera non viene inserita.*/
    for (i=0;i<strlen(alfabeto);i++) {
      if(temp==alfabeto[i]){
        alfabeto_mescolato[c]=temp;
        alfabeto[i]='0';
        i=100;//metto i a 100 così esce dal ciclo quando trova la lettera
        a++;//aumento a di 1 così per un controllo seguente
      }
    }
/*se a==0 significa che la lettera non è stata inserita in alfabeto_mescolato */
    if (a==0) {
      printf("La lettera %c e' stata gia' inserita\n",temp);
/*diminuisco c di 1 così nel ciclo successivo non si perde una posizione dato che le lettere
vanno inserite in alfabeto_mescolato[c]. Se non facessi c-- si perderebbe una posizione*/
      c--;
    }
/*stampo le lettere dell'alfabeto_mescolato così l'utente vede cosa ha inserito e in quale posizione
(durante la stampa di queste lettere vengono stampati a video caratteri strani/random in posizioni
non ancora definite, credo che la memoria si sporchi in alcuni casi, non danno nessun problema dato
che vengono sostituite dai caratteri inseriti dall'utente, ma son brutti da vedere durante la stampa)*/
    printf("Lettere gia' inserite:");
    for (i=0;i<strlen(alfabeto_mescolato);i++) {
        printf(" %c",alfabeto_mescolato[i]);
    }
    printf("\n\n--------------------------------------------------------------------\n" );
  }
printf("La tua frase: %s\n",stringa);
printf("La tua frase cifrata/cyphertext tramite sostituzione e' : \n" );
for (i=0;i<strlen(stringa);i++) {//ciclo della stampa della frase cifrata
  if(isspace(stringa[i])){//controllo se è uno spazio
    printf(" ");
  }
  else{
/*controllo se il carattere è fuori dal range dell'alfabeto minuscolo quindi può essere: ! : / ...*/
    if (stringa[i]<97||stringa[i]>122) {
      printf("%c",stringa[i]);
    }
    else{
/*inserisco dentro a il numero ascii corrispondente alla lettera -97, perchè 97 è "a".
Così riesco a trovare la posizione di quella lettera nell'alfabeto es: c=99-97 = 2 (si parte da 0)
Quindi la lettera corrispondente si trova nella stessa posizione nell'alfabeto_mescolato*/
      a=stringa[i]-97;
      printf("%c",alfabeto_mescolato[a]);
      a=0;//azzero a per il ciclo successivo
  }
}
}
}

void main()
{
    char stringa[256];//dichiarazione stringa per inserimento della frase
    int scelta=0,a=0;//scelta=controllo per il menù a scelta. a=var di controllo
    do{
    a=0;
    printf("Benvenuto nel cifrario, inserisci la tua parola, non sono ammesse maiuscole e numeri:\n");
    fgets(stringa, sizeof(stringa), stdin);
    for(int c1=0;c1<strlen(stringa);c1++){
      if(isdigit(stringa[c1])){//vedere se il carattere è un numero
        a++;
      }
      if (isalpha(stringa[c1])&&isupper(stringa[c1])){//vedere se il carattere è maiuscolo
        a++;
      }
  }
}while(a!=0);//fa passare solamente caratteri minuscoli e caratteri speciali(, . : ...)
    do{
      printf("\n\n1 - Il Cifrario di Cesare\n");
      printf("2 - Il Cifrario a sostituzione\n");
      printf("Inserisci 1 o 2\n" );
      scanf("%d",&scelta );
    }while(scelta<1||scelta>2);//scelta deve essere 1 o 2
/*switch serve per "switchare" i vari case in base a cosa ci sta dentro scelta e deve
corrispondere al numero vicino case.*/
    switch(scelta){
        case 1://apertura case 1
        /*faccio partire la funzione cesare, cioè cifr. di Cesare e gli passo la stringa*/
               cesare(stringa);
               break;//indica la fine del case
        case 2://apertura case 2
        /*faccio partire la funzione sos, cioè cifr. a sostituzione e gli passo la stringa*/
               sos(stringa);
               break;//indica la fine del case
             }
}
