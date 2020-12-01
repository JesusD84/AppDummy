#include<iostream>
using namespace std;

class Cuadrilatero {
    private:
        float ancho, alto;
        string color;

    public:
        Cuadrilatero(float ancho, float alto, string color) {
            this->ancho = ancho;
            this->alto = alto;
            this->color = color;
        }

        Cuadrilatero(float lado, string color) {
            this->ancho = this->alto = lado;
            this->color = color;
        }

        float getAncho() {
            return this->ancho;
        }

        float getAlto() {
            return this->alto;
        }

        string getColor() { 
            return this->color;
        }

        void setAncho(float ancho) {
            this->ancho = ancho;
        }

        void setAlto(float alto) {
            this->alto = alto;
        }

        void setColor(string color) {
            this->color = color;
        }

        float obtenerPerimetro() {
            float perimetro = 2 * (ancho + alto);
            return perimetro;
        }

        float obtenerArea() {
            float area = (ancho * alto);
            return area;
        }
};