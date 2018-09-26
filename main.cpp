#include <windows.h>
#include <iostream>
#include <cmath>
//#include <conio.h>
//#include <stdio.h>
//#include <graphics.h>

using namespace std;

void dibujarEjeX(HDC mydc, int longitudEje, COLORREF colorLinea) {

    for (int i = 0; i <= longitudEje; i++) {
        SetPixel(mydc, (int)longitudEje/2, i, colorLinea);
    }
}

void dibujarEjeY(HDC mydc, int longitudEje, COLORREF colorLinea) {

    for (int i = 0; i <= longitudEje; i++) {
        SetPixel(mydc, i, (int)longitudEje/2, colorLinea);
    }
}

void dibujarEjes(HDC mydc, int longitudEje, COLORREF colorLinea) {
    dibujarEjeX(mydc, longitudEje, colorLinea);
    dibujarEjeY(mydc, longitudEje, colorLinea);
}

int getNewY(int number, int difference) {
    return number - difference;
}

float funcion(int tipoGrafica, float coeficientes[], int x) {

    switch (tipoGrafica) {
        case 0 :    return coeficientes[0] * x + coeficientes[1];
                    break;
        case 1 :    return coeficientes[0] * pow(x, 2) + coeficientes[1] * x + coeficientes[2];
                    break;
        case 2 :    return coeficientes[0] * pow(x, 3) + coeficientes[1] * pow(x, 2) + coeficientes[2] * x + coeficientes[3];
                    break;
        case 3 :    return coeficientes[0] * pow(x, 4) + coeficientes[1] * pow(x, 3) + coeficientes[2] * pow(x, 2) + coeficientes[3] * x + coeficientes[4];
                    break;
        case 4 :    return coeficientes[0] * sin(coeficientes[1] * x + coeficientes[2]) + coeficientes[3];
                    break;
        case 5 :    return coeficientes[0] * cos(coeficientes[1] * x + coeficientes[2]) + coeficientes[3];
                    break;
        case 6 :    return coeficientes[0] * tan(coeficientes[1] * x + coeficientes[2]) + coeficientes[3];
                    break;
        default :   return 1.0;
    }
    //return x;
    //return pow(x, 2);
    //return pow(x, 3);
    //return pow(x, 4);
    //return 30*cos(0.1*x);
}

void dibujarGrafica(int dominioSuperiorFuncion, int dominioInferiorFuncion,
                    float tamanioPaso, int tipoGrafica, float coeficientes[]) {

    system("cls");

    HWND myconsole = GetConsoleWindow();
    HDC mydc = GetDC(myconsole);

    const int LONGITUD_EJE = 400;
    //const float TAMANIO_PASO = 0.05;
    //const int LONGITUD_EJE_Y = 500;

    //int dominioSuperiorFuncion = 60;
    dominioSuperiorFuncion = dominioSuperiorFuncion > (int)(LONGITUD_EJE / 2) ? (int)(LONGITUD_EJE / 2) : dominioSuperiorFuncion;

    //int dominioInferiorFuncion = -20;
    dominioInferiorFuncion = abs(dominioInferiorFuncion) > (int)(LONGITUD_EJE / 2) ? (int)(-LONGITUD_EJE / 2) : dominioInferiorFuncion;
    //int rangoSuperiorFuncion = funcion(dominioSuperiorFuncion); // Reemplazar por funcion
    //int rangoInferiorFuncion = funcion(dominioInferiorFuncion); // Reemplazar por funcion


    //int dominioCuadrantePositivo = dominioSuperiorFuncion > 0 ? dominioSuperiorFuncion : 0;
    //int rangoCuadrantePositivo = funcion(dominioCuadrantePositivo);
    //cout << "dominioCuadrantePositivo: " << dominioCuadrantePositivo << endl;
    //cout << "rangoCuadrantePositivo: " << rangoCuadrantePositivo << endl;

    //int diferenciaDominioPixeles = dominioSuperiorFuncion - dominioInferiorFuncion;
    //cout << "diferenciaDominioPixeles: " << diferenciaDominioPixeles << endl;


    COLORREF colorLinea = RGB(0, 255, 0);

    dibujarEjes(mydc, LONGITUD_EJE, RGB(255, 255, 255));

    //Grafica los cuadrantes de x negativo
    float contadorEjeXNegativo = tamanioPaso;

    for (float i = -(int)(LONGITUD_EJE / 2); i <= 0; i+= tamanioPaso) {

        contadorEjeXNegativo += tamanioPaso;
        //cout << "(" << i << ", " << funcion(abs(i)) << ")" << endl;
        //funcion(int tipoGrafica, float coeficientes[], int x)
        if (funcion(tipoGrafica, coeficientes, abs(i)) < (int)(LONGITUD_EJE / 2) && i >= dominioInferiorFuncion && i <= dominioSuperiorFuncion) {
            //cout << "(" << i << ", " << funcion(i) << ")" << endl;

            if (funcion(tipoGrafica, coeficientes, i) >= 0) {
                SetPixel(mydc, contadorEjeXNegativo , getNewY((LONGITUD_EJE / 2), abs(funcion(tipoGrafica, coeficientes, i))), colorLinea);
                //cout << "(" << contadorEjeXNegativo  << ", " << getNewY((LONGITUD_EJE / 2), funcion(abs(i))) + (int)(LONGITUD_EJE / 2) << ")" << endl;
                //cout << "(" << contadorEjeXNegativo << ", " << getNewY((LONGITUD_EJE / 2), funcion(abs(i))) << ")" << endl;
            }
            else if (funcion(tipoGrafica, coeficientes, i) <=0) {
                if (abs(funcion(tipoGrafica, coeficientes, i)) + (int)(LONGITUD_EJE / 2) <= LONGITUD_EJE) {
                    SetPixel(mydc, contadorEjeXNegativo, abs(funcion(tipoGrafica, coeficientes, i)) + (int)(LONGITUD_EJE / 2), colorLinea);
                    //cout << "(" << contadorEjeXNegativo  << ", " << getNewY((LONGITUD_EJE / 2), abs(funcion(i))) + (int)(LONGITUD_EJE / 2) << ")" << endl;
                }
            }
        }

    }

    //Grafica los cuadrantes de x positivo
    float contadorEjeXPositivo = 200;

    for (float i = 0; i < (int)(LONGITUD_EJE / 2); i += tamanioPaso) {

        contadorEjeXPositivo += tamanioPaso;

        if (abs(funcion(tipoGrafica, coeficientes, i)) < (LONGITUD_EJE / 2) && i > dominioInferiorFuncion && i < dominioSuperiorFuncion) {
            //cout << "(" << i << ", " << funcion(i) << ")" << endl;

            if (funcion(tipoGrafica, coeficientes, i) >= 0) {
                SetPixel(mydc, contadorEjeXPositivo , getNewY((LONGITUD_EJE / 2), funcion(tipoGrafica, coeficientes, i)), colorLinea);
                //cout << "(" << contadorEjeXPositivo << ", " << getNewY((LONGITUD_EJE / 2), funcion(i)) << ")" << endl;
            }
            else if (funcion(tipoGrafica, coeficientes, i) <=0) {
                SetPixel(mydc, contadorEjeXPositivo, abs(funcion(tipoGrafica, coeficientes, i)) + (int)(LONGITUD_EJE / 2), colorLinea);
                //cout << "(" << (int)(LONGITUD_EJE / 2) - i  << ", " << abs(funcion(i)) + (int)(LONGITUD_EJE / 2) << ")" << endl;
            }
        }
    }
    /*
    for (double i = -10; i < 10; i += 0.05) {
        cout << "(" << pixel << ", " << (int)(pow(-i, 2) - 99) << ")" << endl;

        SetPixel(mydc, pixel, (int)(pow(i, 2) - 10), COLOR);
        pixel += 1;
    }
    */


    getchar();

    ReleaseDC(myconsole, mydc);
    cin.ignore();
}

int main()
{
    char res;
    float coeficientes[5];
    int tipoFuncionDiagramar = -1;
    float tamanioPaso;
    int dominioSuperiorFuncion;
    int dominioInferiorFuncion;

    do {

        system("cls");

        cout << "Seleccione el tipo de ecuacion que desea graficar: " << endl;
        cout << endl;
        cout << "1.- Primer grado" << endl;
        cout << "2.- Segundo grado" << endl;
        cout << "3.- Tercer grado" << endl;
        cout << "4.- Cuarto grado" << endl;
        cout << "5.- Trigonometrica" << endl;
        cout << endl;
        cout << "Presione la S para salir." << endl;

        cin >> res;

        system("cls");

        float a, b, c, d, e;

        switch (toupper(res)) {
            case '1':
                      a = 1;
                      b = 0;

                      cout << "Primer grado: ax + b" << endl;
                      cout << endl;
                      cout << "Ingrese los valores de a y b: ";

                      cin >> a >> b;

                      coeficientes[0] = a;
                      coeficientes[1] = b;

                      tipoFuncionDiagramar = 0;

                      cout << "Ingrese el tamano de paso que desea utilizar: ";
                      cin >> tamanioPaso;

                      cout << "Ingrese el limite inferior del dominio de la funcion: ";
                      cin >> dominioInferiorFuncion;

                      cout << "Ingrese el limite superior del dominio de la funcion: ";
                      cin >> dominioSuperiorFuncion;

                      dibujarGrafica(dominioSuperiorFuncion, dominioInferiorFuncion,
                                     tamanioPaso, tipoFuncionDiagramar, coeficientes);

                      break;
            case '2':
                      a = 1;
                      b = 1;
                      c = 0;

                      cout << "Segundo grado: ax^2 + bx + c" << endl;
                      cout << endl;
                      cout << "Ingrese los valores de a, b y c: ";

                      cin >> a >> b >> c;

                      coeficientes[0] = a;
                      coeficientes[1] = b;
                      coeficientes[2] = c;

                      tipoFuncionDiagramar = 1;

                      cout << "Ingrese el tamano de paso que desea utilizar: ";
                      cin >> tamanioPaso;

                      cout << "Ingrese el limite inferior del dominio de la funcion: ";
                      cin >> dominioInferiorFuncion;

                      cout << "Ingrese el limite superior del dominio de la funcion: ";
                      cin >> dominioSuperiorFuncion;

                      dibujarGrafica(dominioSuperiorFuncion, dominioInferiorFuncion,
                                     tamanioPaso, tipoFuncionDiagramar, coeficientes);

                      break;
            case '3': a = 1;
                      b = 1;
                      c = 1;
                      d = 0;

                      cout << "Tercer grado: ax^3 + bx^2 + cx + d" << endl;
                      cout << endl;
                      cout << "Ingrese los valores de a, b, c y d: ";

                      cin >> a >> b >> c >> d;

                      coeficientes[0] = a;
                      coeficientes[1] = b;
                      coeficientes[2] = c;
                      coeficientes[3] = d;

                      tipoFuncionDiagramar = 2;

                      cout << "Ingrese el tamano de paso que desea utilizar: ";
                      cin >> tamanioPaso;

                      cout << "Ingrese el limite inferior del dominio de la funcion: ";
                      cin >> dominioInferiorFuncion;

                      cout << "Ingrese el limite superior del dominio de la funcion: ";
                      cin >> dominioSuperiorFuncion;

                      dibujarGrafica(dominioSuperiorFuncion, dominioInferiorFuncion,
                                     tamanioPaso, tipoFuncionDiagramar, coeficientes);

                      break;
            case '4': a = 1;
                      b = 1;
                      c = 1;
                      d = 1;
                      e = 0;

                      cout << "Cuarto grado: ax^4 + bx^3 + cx^2 + dx + e" << endl;
                      cout << endl;
                      cout << "Ingrese los valores de a, b, c, d y e: ";

                      cin >> a >> b >> c >> d >> e;

                      coeficientes[0] = a;
                      coeficientes[1] = b;
                      coeficientes[2] = c;
                      coeficientes[3] = d;
                      coeficientes[4] = e;

                      tipoFuncionDiagramar = 3;

                      cout << "Ingrese el tamano de paso que desea utilizar: ";
                      cin >> tamanioPaso;

                      cout << "Ingrese el limite inferior del dominio de la funcion: ";
                      cin >> dominioInferiorFuncion;

                      cout << "Ingrese el limite superior del dominio de la funcion: ";
                      cin >> dominioSuperiorFuncion;

                      dibujarGrafica(dominioSuperiorFuncion, dominioInferiorFuncion,
                                     tamanioPaso, tipoFuncionDiagramar, coeficientes);

                      break;
            case '5': do {
                        system("cls");
                        cout << "Seleccione funcion trigonometrica a utilizar:" << endl;
                        cout << endl;
                        cout << "1.- sen(expresion)" << endl;
                        cout << "2.- cos(expresion)" << endl;
                        cout << "3.- tan(expresion)" << endl;
                        cout << endl;
                        cout << "Presione R para regresar." << endl;

                        cin >> res;

                        switch(res) {
                            case '1':   a = 1;
                                        b = 0;
                                        c = 1;
                                        d = 0;

                                        cout << "Funcion seno: a * sen(bx + c) + d" << endl;
                                        cout << endl;
                                        cout << "Ingrese los valores de a, b, c, d: ";

                                        cin >> a >> b >> c >> d;

                                        coeficientes[0] = a;
                                        coeficientes[1] = b;
                                        coeficientes[2] = c;
                                        coeficientes[3] = d;

                                        tipoFuncionDiagramar = 4;

                                        cout << "Ingrese el tamano de paso que desea utilizar: ";
                                        cin >> tamanioPaso;

                                        cout << "Ingrese el limite inferior del dominio de la funcion: ";
                                        cin >> dominioInferiorFuncion;

                                        cout << "Ingrese el limite superior del dominio de la funcion: ";
                                        cin >> dominioSuperiorFuncion;

                                        dibujarGrafica(dominioSuperiorFuncion, dominioInferiorFuncion,
                                                       tamanioPaso, tipoFuncionDiagramar, coeficientes);

                                        break;
                            case '2':   a = 1;
                                        b = 0;
                                        c = 1;
                                        d = 0;

                                        cout << "Funcion coseno: a * cos(bx + c) + d" << endl;
                                        cout << endl;
                                        cout << "Ingrese los valores de a, b, c, d: ";

                                        cin >> a >> b >> c >> d;

                                        coeficientes[0] = a;
                                        coeficientes[1] = b;
                                        coeficientes[2] = c;
                                        coeficientes[3] = d;

                                        tipoFuncionDiagramar = 5;

                                        cout << "Ingrese el tamano de paso que desea utilizar: ";
                                        cin >> tamanioPaso;

                                        cout << "Ingrese el limite inferior del dominio de la funcion: ";
                                        cin >> dominioInferiorFuncion;

                                        cout << "Ingrese el limite superior del dominio de la funcion: ";
                                        cin >> dominioSuperiorFuncion;

                                        dibujarGrafica(dominioSuperiorFuncion, dominioInferiorFuncion,
                                                       tamanioPaso, tipoFuncionDiagramar, coeficientes);

                                        break;
                            case '3':   a = 1;
                                        b = 0;
                                        c = 1;
                                        d = 0;

                                        cout << "Funcion tangento: a * tan(bx + c) + d" << endl;
                                        cout << endl;
                                        cout << "Ingrese los valores de a, b, c, d: ";

                                        cin >> a >> b >> c >> d;

                                        coeficientes[0] = a;
                                        coeficientes[1] = b;
                                        coeficientes[2] = c;
                                        coeficientes[3] = d;

                                        tipoFuncionDiagramar = 6;

                                        cout << "Ingrese el tamano de paso que desea utilizar: ";
                                        cin >> tamanioPaso;

                                        cout << "Ingrese el limite inferior del dominio de la funcion: ";
                                        cin >> dominioInferiorFuncion;

                                        cout << "Ingrese el limite superior del dominio de la funcion: ";
                                        cin >> dominioSuperiorFuncion;

                                        dibujarGrafica(dominioSuperiorFuncion, dominioInferiorFuncion,
                                                       tamanioPaso, tipoFuncionDiagramar, coeficientes);

                                        break;
                            case 'S':   break;
                            default :   cout << "Error: Se ha ingresado un valor no valido.";
                                        break;
                        }

                      } while (toupper(res) != 'R');

                      break;
            default :   cout << "Error: se ha ingresado un valor no valido." << endl;
                        break;
        }

    } while (toupper(res) != 'S');

    return 0;
}
