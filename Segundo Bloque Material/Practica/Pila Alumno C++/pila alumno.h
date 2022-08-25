#include "Alumno.h"

class Pila
{
private:
    Alumno valores[50];
    int cantidad;

public:
    Pila();
    void inicpila();
    void apilar(Alumno dato);
    Alumno desapilar();
    bool pilavacia();
    void mostrar();
    Alumno tope();
    void leer ();

    void cargarMuchos();
    void pasar(Pila *otra);
};
