#include "LedControlMS.h"
LedControl matriz=LedControl(12,11,10,1);
void RepresentarMatriz(byte *,int);
byte Corazon_datos[] = {
B00000000,
B01100110,
B11111111,
B11111111,
B01111110,
B00111100,
B00011000,
B00000000};
// cara emoji
byte Cara_datos[] =
{B00111100,
B01000010,
B10100101,
B10000001,
B10100101,
B10011001,
B01000010,
B00111100};
// cara emoji
byte Cara_datos2[] =
{B00111100,
B01000010,
B10100101,
B10000001,
B10100101,
B01100110,
B01000010,
B00111100};
//Saludo HI
byte Mensaje_datos[] =
{B00000000,
B00000100,
B00000000,
B01010100,
B01110100,
B01010100,
B00000000,
B00000000};


void setup() {
matriz.shutdown(0,false);
matriz.setIntensity(0,8);// La valores están entre 1 y 15
matriz.clearDisplay(0);


}

void loop() {
RepresentarMatriz(Corazon_datos,2000); // llama método para mostrar Corazón
delay(500);
RepresentarMatriz(Cara_datos,2000); // llama método para mostrar emoji
delay(500);
RepresentarMatriz(Mensaje_datos,2000); // llama método para mostrar HI
delay(500);
matriz.clearDisplay(0);
}

void RepresentarMatriz(byte *Datos,int espera)
{
for (int i = 0; i < 8; i++)
{
matriz.setColumn(0,i,Datos[7-i]);
}
delay(200);
}
