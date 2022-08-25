#include <iostream>
#include "Auto.h"
#include "strings.h"

using namespace std;

int main()
{

    Auto autito1;

    Auto autito2(12345,"rojo","ford");

    cout<<"Autito 1\n"<<endl;

    autito1.mostrar();

    cout<<"\nAutito 2\n"<<endl;

    autito2.mostrar();

    cout<<"\nAutito 1\n"<<endl;

    autito1.setPatente(789654);
    autito1.setColor("violeta");
    autito1.setMarca("Audi");

    autito1.mostrar();

    return 0;
}
