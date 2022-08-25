

class Pila
{
private:
    int valores[50];
    int cantidad;

public:
    Pila();

    void inicpila();
    void apilar(int dato);
    int desapilar();
    bool pilavacia();
    void mostrar();
    int tope();
    void leer ();

    void cargarMuchos();
    void pasar(Pila *otra);
};



