#include<stdlib.h>
#include<stdio.h>
#include<time.h>

struct personaggio{
    int Hp;
    int Strenght;
};
typedef struct personaggio P;

P SimulazioneLotta(P Attacco, P Difesa);


int main(){
    srand(time(NULL));

    P Eroe= {100, 1+rand()%40};
    P Nemico= {100, 1+rand()%40};

    printf("Inizio combattimento tra Eroe e il Nemico\n");

    do{
    Nemico=SimulazioneLotta(Eroe, Nemico);
    Eroe=SimulazioneLotta(Nemico, Eroe);

    if(Nemico.Hp<=0){
        printf("Vittoria Eroe\n");
    }else{
        if(Eroe.Hp<=0){
            printf("Vittoria Nemico");
        }else{
            printf("Vita Eroe= %d\n Vita Nemico=%d\n",Eroe.Hp, Nemico.Hp);
        }
    }
   
    } while(Eroe.Hp>0 && Nemico.Hp>0);
      
    return 0;
}

P SimulazioneLotta(P Attacco, P Difesa){
    Difesa.Hp= Difesa.Hp-Attacco.Strenght;
    return Difesa;
}

