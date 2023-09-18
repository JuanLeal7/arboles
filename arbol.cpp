#include <iostream>
#include <conio.h>

using namespace std;
struct nodo{
    int valor;
    nodo *der;
	nodo *izq;  
};

nodo *crearnodo(int);
void insertar(nodo*&,int);
nodo *arbol= NULL;

int main(){
    int valor,n;
    cout<<"ingrese el tamaño del arbol\n";
    cin>>n;

for (int i=0 ; i < n ; i++)
{
    cout<<"ingrese el valor\n";
    cin>>valor;
    insertar(arbol,valor); 	
}
  

}

nodo *crearnodo(int x){
	nodo *Nnodo= new nodo();
	
	Nnodo->valor=x;
	Nnodo->der=NULL;
	Nnodo->izq=NULL;
	
	return Nnodo;
}

void insertar (nodo *&arbol,int x){
	if (arbol==NULL){
		nodo *Nnodo=crearnodo(x);
		arbol=Nnodo;
	}
	else{
		int raiz= arbol->valor;
		if(x<raiz){
			insertar(arbol->izq,x);
		}
		else{
			insertar(arbol->der,x);
		}
	}
}
