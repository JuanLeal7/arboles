#include <iostream>
#include <conio.h>

using namespace std;
struct nodo{
    int valor;
    nodo *der;
	nodo *izq;  
	nodo *papa;
};

nodo *crearnodo(int,nodo *);
void insertar(nodo*&,int,nodo *);
void mostrar(nodo*,int);
bool buscar(nodo*,int);
void eliminar(nodo *,int);
void eliminarnum(nodo *);
void reemplazar(nodo *,nodo *);
void borrar(nodo *);
void pre(nodo *);
void in(nodo *);
void post(nodo *);

nodo*min(nodo *);
nodo *arbol= NULL;

int main(){
    int valor,n;
    int y=0;
    cout<<"ingrese la cantidad del del arbol\n";
    cin>>n;

for (int i=0 ; i < n ; i++)
{
    cout<<"ingrese el valor\n";
    cin>>valor;
    insertar(arbol,valor,NULL); 	
}
  
int opc;
do{	

cout<<"OPCIONES\n";
cout<<"1.Mostrar arbol\n";
cout<<"2.Buscar un valor en el arbol\n";
cout<<"3.Borrar valor de la lista\n";
cout<<"4.Mostrar en Pre_orden\n";
cout<<"5.Mostrar en In_orden\n";
cout<<"6.Mostrar en Post_orden\n";
cout<<"7.EXIT\n";
cin>>opc;


	switch(opc){
		case 1: mostrar(arbol,y);
				cout<<"\n";
				system("pause");
				break;
		
		case 2:
				cout<<"digite el valor que desea buscar\n";
				cin>>valor;
				if(buscar(arbol,valor)==true){
				cout <<"el valor se encuentra en el arbol\n";
				}else{
				cout <<"el valor no se encuentra en el arbol\n";
				}
				system("pause");	
				break;
		
		case 3:	cout <<"digite el valor que desea eliminar\n";
				cin>>valor;
				eliminar(arbol,valor);
				system("pause");
				break;
		
		case 4:	pre(arbol);
				system("pause");
				break;
		
		case 5:	in(arbol);
				system("pause");
				break;
				
		case 6:	post(arbol);
				system("pause");
				break;	
	}
	system("cls");	

   }while(opc !=7);

}

nodo *crearnodo(int x, nodo* papa){
	nodo *Nnodo= new nodo();
	
	Nnodo->valor=x;
	Nnodo->der=NULL;
	Nnodo->izq=NULL;
	Nnodo->papa=papa;
	
	return Nnodo;
}

void insertar (nodo *&arbol,int x, nodo* papa){
	if (arbol==NULL){
		nodo *Nnodo=crearnodo(x,papa);
		arbol=Nnodo;
	}
	else{
		int raiz= arbol->valor;
		if(x<raiz){
			insertar(arbol->izq,x,arbol);
		}
		else{
			insertar(arbol->der,x,arbol);
		}
	}
}

void mostrar (nodo *arbol,int y){
	if (arbol==NULL){
	return;
}
	else{
	 	mostrar(arbol->der,y+1);
	 	for(int i=0;i<y;i++);
	 	cout<<" ";
		}
		cout<<arbol->valor<<endl;
		mostrar(arbol->izq,y+1);
}

bool buscar(nodo*arbol,int b){
	if (arbol==NULL){
	return false;
	}
	else if(arbol->valor==b){
	 return true;
	}else if(b < arbol->valor){
		return buscar(arbol->izq,b);
	}else{
		return buscar(arbol->der,b);
	}
	
}

void eliminar(nodo *arbol,int x){
	if (arbol == NULL){
		return ;
	}
	else if(x < arbol->valor){
		eliminar(arbol->izq,x);
	}
	else if(x >arbol->valor){
		eliminar(arbol->der,x);
	}else{
		eliminarnum(arbol);
	}
}
nodo *min(nodo *arbol){
	if(arbol==NULL){
		return NULL;
	}
	if(arbol->izq){
		return min(arbol->izq);
	}
	else{
		return arbol;
	}
}

void reemplazar(nodo *arbol, nodo *Nnodo){
	if(arbol->papa){
		if(arbol->valor == arbol->papa->izq->valor){
			arbol->papa->izq=Nnodo;
		}
		else if(arbol->valor == arbol->papa->der->valor){
			arbol->papa->der=Nnodo;
		}
	}
	if(Nnodo){
		Nnodo->papa=arbol->papa;
		
	}
}

void borrar(nodo *nodo){
	nodo->izq = NULL;
	nodo->der =NULL;
	delete nodo;
	
}

void eliminarnum(nodo *eliminar){
	if(eliminar->izq && eliminar->der){
	 nodo *menor=min(eliminar->der);
	 eliminar->valor = menor->valor;
	 eliminarnum(menor);
	}
	else if(eliminar->izq){
		reemplazar(eliminar,eliminar->izq);
		borrar(eliminar);
	}
	else if(eliminar->der){
		reemplazar(eliminar,eliminar->der);
		borrar(eliminar);
	}
	else{
		reemplazar(eliminar,NULL);
		borrar(eliminar);
	}
}

void pre(nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		cout<<arbol->valor<<"->";
		pre(arbol->izq);
		pre(arbol->der);
	}
}

void in(nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		in(arbol->izq);
		cout<<arbol->valor<<"->";
		in(arbol->der);
	}
}

void post(nodo *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		in(arbol->izq);
		in(arbol->der);
		cout<<arbol->valor<<"->";
	}
}



