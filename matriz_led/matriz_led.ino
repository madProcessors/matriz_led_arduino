#include "LedControlMS.h"

LedControl matriz=LedControl(12,11,10,1);

void RepresentarMatriz(byte *,int);
void animar(byte [][8], int, int);

byte linea_horizontal[][8] = {
   {
    B11111111,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00000000,
    B11111111,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00000000,
    B00000000,
    B11111111,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B11111111,
    B00000000,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B11111111,
    B00000000,
    B00000000,
    B00000000
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B11111111,
    B00000000,
    B00000000
  },
  {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B11111111,
    B00000000
  },
    {
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B11111111
  }
};


byte linea_vertical[][8] = {
   {
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000,
    B10000000
  },
  {
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000,
    B01000000
  },
  {
    B00100000,
    B00100000,
    B00100000,
    B00100000,
    B00100000,
    B00100000,
    B00100000,
    B00100000
  },
  {
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000,
    B00010000
  },
  {
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B00001000,
    B00001000
  },
  {
    B00000100,
    B00000100,
    B00000100,
    B00000100,
    B00000100,
    B00000100,
    B00000100,
    B00000100
  },
  {
    B00000010,
    B00000010,
    B00000010,
    B00000010,
    B00000010,
    B00000010,
    B00000010,
    B00000010
  },
    {
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000001,
    B00000001
  }
};


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




void setup() {
  matriz.shutdown(0, false);
  matriz.setIntensity(0, 15);// La valores están entre 1 y 15
  matriz.clearDisplay(0);
  Serial.begin(9600);
}




void loop() {
  animar(linea_horizontal, 8, 50); // LINEA HORIZONTAL
  delay(500);

  animar(linea_vertical, 8, 50); // LINEA VERTICAL
  delay(500);

  matriz.clearDisplay(0);
}




void RepresentarMatriz(byte *Datos, int espera)
{
  for (int i = 0; i < 8; i++) // 8 columnas en cada fila
  {
    matriz.setColumn(0, i, Datos[7-i]);
  }
  delay(espera);
}




// <FRAMES, NUMERO DE FRAMES, INTERVALO ENTRE FILAS>
void animar(byte Datos[][8], int n_frames, int interv){
  Serial.print("frames: ");
  Serial.println((unsigned char)n_frames);

  for (int i = 0; i < n_frames; i++)
  {
    Serial.println((unsigned char)Datos[i]);
    RepresentarMatriz(Datos[i], interv);
  }
}
