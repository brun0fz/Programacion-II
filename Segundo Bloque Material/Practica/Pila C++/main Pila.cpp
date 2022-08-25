#include <iostream>
#include "pila.h"

using namespace std;


int main()
{
    Pila p;
    Pila q;
    p.cargarMuchos();
    p.mostrar();
    q.pasar(&p);
    q.mostrar();

    p.mostrar();

    cout << "Hello world!" << endl;
    return 0;
}
