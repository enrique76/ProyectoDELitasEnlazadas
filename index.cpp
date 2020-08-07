#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>

using namespace std;

struct Nodo{
    float dato;
    Nodo *siguiente;
};

void insertarLista(Nodo *&,float);
void mostrarLista(Nodo *);
void Menu(Nodo *);
void Salir();
void Buscar(Nodo *,float);
void Eliminar(Nodo *&,float);
void EliminarLista(Nodo *&,float &);
void Borrando();
void Suma(Nodo *);
void Resta(Nodo *);
void Producto(Nodo *);
void Divicion(Nodo *);
void Media(Nodo *);
void MaxMin(Nodo *,float&,float&);

int opc;
int cont = 0;

int main(){

    Nodo *lista = NULL;
    float dato;
    bool V = true;
    
    while(V==true){
        system("cls");
        Menu(lista);

        switch(opc){
//--------------------Agregar Elementos---------------
            case 1: 
                system("cls");
                cout<<"\n\tDigite un numero: "; cin>>dato;
                insertarLista(lista,dato);
                cout<<"\n\nPresione cualquier tecla para continuar";
                getch();
                system("cls");
            break;
//--------------Mostrar elementos-----------------
            case 2: 
                if(lista == NULL){
                    cout<<"\naun no hay elementos para mostrar";
                    Sleep(2000);
                    system("cls");
                }
                else{
                    system("cls");
                    cout<<"\n\n\tMostrando datos\n\n";
                    mostrarLista(lista);
                    cout<<"\n\nPresione cualquier tecla para continuar";
                    getch();
                    system("cls");
                }
            break;
//------------------Borrar elementos----------------
            case 3:
                if(lista == NULL){
                    cout<<"\nLa lista esta basia, no puedes borrar nada";
                    Sleep(2000);
                    system("cls");
                }
                else{
                    do{
                        system("cls");
                        cout<<"\n\n\tMenu de borrar\n";
                        cout<<"\n\t1. Borrar todos los elementos";
                        cout<<"\n\t2. Borrar n cantidad de elementos";
                        cout<<"\n\nOpccion: "; cin>>opc;
                    }while(opc < 1 || opc > 2);

                    if(opc == 1){
                        while(lista != NULL){
                            EliminarLista(lista,dato);
                        }
                        Borrando();
                        cout<<"\n\nTodos los datos han sido eliminados corectamente";
                        getch();
                        system("cls");
                    }
                    else{
                        system("cls");
                        float elemento;
                        cout<<"\n\tBorrar n cantidad de elementos";
                        cout<<"\n\n\tCuantos elementos quieres borar: "; cin>>opc;

                        while(opc>0){
                            cout<<"\n\nQue elemento deceas borrar: "; cin>>elemento;
                            Eliminar(lista,elemento);
                            getch();
                            opc--;
                        }

                    }
                }
            break;
//--------------------Buscar elemento-----------------
            case 4:
                if(lista == NULL){
                    cout<<"\nLa lista esta basia, no puedes buscar nada";
                    Sleep(2000);
                    system("cls");
                }
                else{
                    cout<<"\nQue dato decea buscar: "; cin>>dato;
                    Buscar(lista,dato);
                    getch();
                    system("cls");
                }
            break;
            //--------------Calculos-----------
            case 5: 
                
                if(cont < 1){
                    cout<<"\nLa lista tiene muy pocos datos, no puedes calcular nada";
                    Sleep(2000);
                    system("cls");
                }
                else{
                    system("cls");
                    cout<<"\nLos datos son: \n\n";
                    mostrarLista(lista);
                    cout<<"\n\n\t1. Suma";
                    cout<<"\n\n\t2. Resta";
                    cout<<"\n\n\t3. Producto";
                    cout<<"\n\n\t4. Divicion";
                    cout<<"\n\n\t5. Media";

                    do{
                        cout<<"\n\nopccion: "; cin>>opc;
                    }while(opc<1 || opc > 5);
    //-------------Menu de calculos----

                    switch(opc){
                        case 1:
                            Suma(lista);
                        break;
                        case 2:
                            Resta(lista);
                        break;
                        case 3:
                            Producto(lista);
                        break;
                        case 4:
                            Divicion(lista);
                        break;
                        case 5:
                            Media(lista);
                        break;
                    }
                    getch();
                }
            break;
            case 6:
                Salir();
                V = false;
            break;
        }
        system("cls");
    }

    getch();
    return 0;
}

void insertarLista(Nodo *&lista,float n ){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1 != NULL) &&(aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if(lista == aux1){
        lista = nuevo_nodo;
    }
    else{
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;

    cont+=1;

    cout<<"\n\tEl elemento "<<n<<" se inserto corectamente";
}

void mostrarLista(Nodo *lista){
    Nodo *actual = new Nodo();
    actual = lista;

    while(actual != NULL){
        cout<<actual->dato;
        if(actual->siguiente != NULL){
            cout<<" -> ";
        }
        else{
            cout<<".";
        }
        actual = actual->siguiente;
    }
}

void Menu(Nodo *lista){
    float max = -9999999,min = 9999999;
    cout<<"\n\n\tMenu\n\n";
    cout<<"\t1. Agregar dato a la lista";
    cout<<"\n\t2. Mostrar listas";
    cout<<"\n\t3. Borrar elemento de la lista";
    cout<<"\n\t4. Buscar un elemento";
    cout<<"\n\t5. Calculos";
    cout<<"\n\t6. Salir";
    cout<<"\n\nDatos exixtentes: "<<cont;

    MaxMin(lista,max,min);

    do{
        cout<<"\n\nOpccion: "; cin>>opc;
        if(opc < 1 || opc > 6){
            cout<<"\nDato invalido";
        }
    }while(opc < 1 || opc > 6);

}

void Salir(){
    cout<<"\nSaliendo";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
}

void Buscar(Nodo *lista,float n){
    bool band = false;
    Nodo *actual = new Nodo();
    actual = lista;

    while((actual!=NULL)&&(actual->dato <= n)){
        if(actual->dato == n){
            band = true;
        }
        actual = actual->siguiente;
    }

    if(band == true){
        cout<<"\nEl elemento "<<n<<" SI ha sido encontrado en lista";
    }
    else{
        cout<<"\nEl elemento "<<n<<" NO ha sido encontrado en lista";
    }

}

void Eliminar(Nodo *&lista,float n){
    Nodo *aux_borrar;
    Nodo *anterior = NULL;

    aux_borrar = lista;

    while((aux_borrar != NULL)&&(aux_borrar->dato != n)){
        anterior = aux_borrar;
        aux_borrar = aux_borrar->siguiente;
    }
    // Elemento no ha sido encontrado
    if(aux_borrar == NULL){
        cout<<"\n\nEl elemto "<<n<<" NO ha sido encontrado";
    }
    else if(anterior == NULL){
        lista = lista->siguiente;
        delete aux_borrar;

        cout<<"\n\nEl elemto "<<n<<" se ha borrado corectamente";
        cont-=1;
    }
    else{
        anterior->siguiente = aux_borrar->siguiente;
        delete aux_borrar;

        cout<<"\n\nEl elemto "<<n<<" se ha borrado corectamente";
        cont-=1;
    }

}


void EliminarLista(Nodo *&lista,float &n){

    Nodo *aux = lista;
    n = aux->dato;
    lista = aux->siguiente;

    cont = 0;

    delete aux;

}

void Borrando(){
    cout<<"\nBorrando";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
}

void Suma(Nodo *lista){
    float suma = 0;

    while(lista!=NULL){
        suma+= lista->dato;
        lista = lista->siguiente;
    }

    cout<<"\nLa suma de los datos es: "<<suma;
}

void Resta(Nodo *lista){
    float resta = lista->dato;

    while(lista!=NULL){
        lista = lista->siguiente;
        resta-= lista->dato;
        lista = lista->siguiente;
    }

    cout<<"\nLa resta de los datos es: "<<resta;
}

void Producto(Nodo *lista){
    float producto = 1;

    while(lista!=NULL){
        producto*= lista->dato;
        lista = lista->siguiente;
    }

    cout<<"\nLa producto de los datos es: "<<producto;
}

void Divicion(Nodo *lista){

    float divicion = lista->dato;

    while(lista!=NULL){
        if(lista->dato != 0 || divicion != 0){
            lista = lista->siguiente;
            divicion/= lista->dato;
            lista = lista->siguiente;
        }
        else{
            lista = lista->siguiente;
        }
    }

    cout<<"\nLa divicion de los datos es: "<<divicion;
}

void Media(Nodo *lista){
    float suma = 0;
    float media;

    while(lista!=NULL){
        suma+= lista->dato;
        lista = lista->siguiente;
    }

    media = suma/cont;

    cout<<"\nLa media de los datos es: "<<media;
}

void MaxMin(Nodo *lista,float&max,float&min){

    if(cont >= 2 ){
        while(lista != NULL){
                if(lista->dato > max){
                    max = lista->dato;
                }
                if(lista->dato < min){
                    min  = lista->dato;
                }
                lista = lista->siguiente;
            }

        cout<<"\tDato Maximo: "<<max<<"   \tDato Minimo: "<<min<<endl;
    }
    else{
        cout<<"\tDato Maximo: 0\tDato Minimo: 0"<<endl;
    }
}
