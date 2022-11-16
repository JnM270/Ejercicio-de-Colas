//Ejercicio de Colas. Altura de pacientes en cm. Juan Bauza

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct nd {
int valor;
struct nd*sig;
};
struct cola {
struct nd*primerN, *ultimoN;
};

struct nd *crearnd (int valor){
struct nd*nuevoN = (struct nd*) malloc(sizeof(struct nd));
nuevoN->valor = valor;
nuevoN->sig  = NULL;
return nuevoN;
};

struct cola *crearcl(){
struct cola*c = (struct cola*) malloc(sizeof (struct cola));
c ->primerN = c->ultimoN=NULL;
return  c;
};

void enQueue(int valor, struct cola**c){
struct nd* nuevoN =  crearnd(valor);

if((*c )->primerN == NULL){
(*c )->primerN = (*c )->ultimoN = nuevoN;
return;};



(*c )->ultimoN->sig = nuevoN;
(*c) ->ultimoN= nuevoN;}

int deQueue(struct cola **c){
if( (*c )->primerN==NULL)return INT_MIN;


     
struct nd*Nborrado = (*c)->primerN;
int valor = Nborrado->valor;


      
(*c) ->primerN = Nborrado->sig;
if((*c)->primerN==NULL){
(*c)->ultimoN = NULL;}
free(Nborrado);
return valor;}

void mostrarN (struct cola ** c){
if((*c )->primerN==NULL) return;


    
printf("Primer valor: %d \nValor final: %d \n", (*c )->primerN->valor, (*c )->ultimoN->valor);
struct nd* actualN  = (*c )->primerN;

while(actualN){
printf("%d,  ", actualN->valor);
actualN = actualN->sig;
}
printf("\n\n");
printf("Se presenta Cola de nodos que contiene alturas de pacientes en cm  \n\n");}

int main (){
int cm;
struct cola *c = crearcl();
    
enQueue(150*cm, &c);
enQueue(172*cm, &c);
enQueue(166*cm, &c);
enQueue(193*cm, &c);
enQueue(180*cm, &c);
enQueue(177*cm, &c);
enQueue(164*cm, &c);
enQueue(179*cm, &c);
enQueue(151*cm, &c);
enQueue(167*cm, &c);
enQueue(158*cm, &c);
mostrarN( &c);

for( int i = 0; i < 12 ; i++){
printf("Nodo borrado: %d \n", deQueue(&c));
mostrarN(&c);
};
return 0;
};
