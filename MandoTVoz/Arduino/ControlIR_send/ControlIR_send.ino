#include <IRremote.h> // Librería https://github.com/shirriff/Arduino-IRremote

// El pin definido por defecto en la librería para enviar códigos IR es el 3

/* Baudios del Bluetooth*/
#define HC05              38400
#define BQ_ZUM_BT         19200

// Power ON / OFF
unsigned int OnOff[68] = {4450, 4400, 600, 1650, 550, 1650, 550, 1650, 550, 550, 600, 500, 600, 550, 550, 550, 550, 550, 550, 1650, 550, 1650, 550, 1650, 600, 500, 600, 500, 600, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 550, 550, 550, 600, 500, 600, 550, 550, 550, 550, 550, 550, 1650, 550, 550, 550, 1650, 550, 1650, 600, 1650, 550, 1650, 550, 1650, 550, 1650, 550};
// Tecla 1
unsigned int T1[68] = {4450, 4400, 600, 1650, 550, 1650, 550, 1650, 600, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 1650, 600, 1650, 550, 550, 550, 550, 550, 550, 550, 500, 600, 550, 550, 550, 550, 550, 550, 1650, 600, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 1650, 600, 500, 600, 1650, 550, 1600, 600, 1650, 550, 1650, 600, 1600, 600};
// Tecla 2
unsigned int T2[68] = {4450, 4400, 600, 1650, 550, 1650, 550, 1650, 600, 500, 600, 550, 550, 550, 550, 550, 550, 500, 600, 1650, 550, 1650, 550, 1650, 600, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 550, 550, 1650, 600, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 550, 600, 1650, 550, 1650, 550, 1600, 600, 1650, 550, 1650, 600};
// Tecla 3
unsigned int T3[68] = {4400, 4450, 550, 1650, 550, 1650, 600, 1600, 600, 550, 550, 550, 550, 550, 550, 500, 600, 550, 550, 1650, 550, 1650, 600, 1650, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 600, 1600, 600, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 600, 500, 600, 550, 550, 1650, 550, 1650, 550, 1650, 550, 1650, 600, 1650, 550};
// Tecla 4
unsigned int T4[68] = {4450, 4400, 600, 1600, 600, 1650, 550, 1650, 550, 550, 550, 550, 550, 550, 600, 500, 600, 500, 600, 1650, 550, 1650, 550, 1650, 550, 550, 550, 550, 600, 500, 600, 500, 600, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 550, 550, 550, 600, 500, 600, 500, 600, 1650, 550, 1650, 550, 1650, 550, 550, 550, 1650, 600, 1650, 550, 1600, 600, 1650, 550};
// Tecla 5
unsigned int T5[68] = {4450, 4400, 600, 1650, 550, 1650, 550, 1650, 600, 500, 600, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 1650, 600, 1600, 600, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 550, 600, 500, 600, 1650, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 600, 1650, 550, 550, 550, 1650, 550, 1650, 550, 1650, 550, 1650, 600};
// Tecla 6
unsigned int T6[68] = {4450, 4400, 600, 1600, 600, 1650, 550, 1650, 550, 550, 550, 550, 550, 550, 550, 550, 600, 500, 600, 1650, 550, 1650, 550, 1650, 550, 550, 550, 550, 550, 550, 600, 500, 600, 550, 550, 550, 550, 1650, 550, 550, 550, 1650, 550, 550, 550, 550, 600, 500, 600, 550, 550, 1650, 550, 550, 550, 1650, 550, 550, 550, 1650, 600, 1600, 600, 1650, 550, 1600, 600};
// Tecla 7
unsigned int T7[68] = {4450, 4450, 550, 1650, 600, 1600, 600, 1650, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 600, 1650, 550, 1600, 600, 550, 550, 550, 550, 550, 550, 550, 550, 550, 600, 500, 600, 500, 600, 1650, 550, 1650, 550, 550, 550, 550, 550, 550, 550, 550, 600, 1650, 550, 1650, 550, 550, 550, 550, 550, 1650, 550, 1650, 600, 1650, 550, 1600, 600};
// Tecla 8
unsigned int T8[68] = {4400, 4450, 550, 1650, 550, 1650, 600, 1650, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 600, 1600, 600, 1650, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 600, 550, 550, 1650, 550, 1650, 550, 550, 550, 550, 550, 550, 550, 550, 600, 500, 600, 1650, 550, 550, 550, 550, 550, 1650, 550, 1650, 550, 1650, 600, 1650, 550};
// Tecla 9
unsigned int T9[68] = {4450, 4350, 650, 1650, 550, 1650, 550, 1650, 600, 500, 600, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 1650, 550, 1650, 600, 500, 600, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 1650, 600, 1600, 600, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 550, 600, 500, 600, 550, 550, 1600, 600, 1600, 600, 1650, 550, 1650, 600};
// Tecla 0
unsigned int T0[68] = {4450, 4400, 600, 1600, 600, 1650, 550, 1650, 550, 550, 550, 550, 550, 550, 600, 500, 600, 500, 600, 1650, 550, 1650, 550, 1650, 550, 550, 550, 550, 600, 500, 600, 500, 600, 550, 550, 1650, 550, 550, 550, 550, 550, 550, 550, 1650, 600, 500, 600, 550, 550, 550, 550, 550, 550, 1650, 550, 1650, 550, 1650, 600, 500, 600, 1600, 600, 1650, 550, 1650, 550};
// Programa Up
unsigned int PUp[68] = {4450, 4400, 600, 1650, 550, 1650, 550, 1650, 550, 550, 550, 550, 550, 550, 600, 500, 600, 550, 550, 1600, 600, 1650, 550, 1650, 550, 550, 550, 550, 600, 500, 600, 550, 550, 550, 550, 550, 550, 1650, 550, 550, 550, 550, 550, 1650, 600, 500, 600, 550, 550, 500, 600, 1650, 550, 550, 550, 1650, 550, 1650, 600, 500, 600, 1650, 550, 1650, 550, 1650, 550};
// Programa Down
unsigned int PDown[68] = {4400, 4450, 550, 1650, 550, 1650, 600, 1650, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 600, 1600, 600, 1600, 600, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 600, 500, 600, 500, 600, 550, 550, 1650, 550, 550, 550, 550, 550, 550, 550, 1650, 600, 1650, 550, 1600, 600, 1600, 600, 550, 550, 1650, 550, 1650, 600, 1650, 550};
// Volumen +
unsigned int VPlus[68] = {4450, 4400, 600, 1650, 550, 1650, 550, 1650, 600, 500, 600, 500, 600, 550, 550, 550, 550, 550, 550, 1600, 600, 1650, 550, 1650, 600, 500, 600, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 1650, 600, 1600, 600, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 600, 1650, 550, 1650, 550, 1600, 600, 1650, 550, 1650, 600};
// Volumen -
unsigned int VLess[68] = {4450, 4450, 550, 1650, 550, 1650, 600, 1650, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 550, 1650, 600, 1650, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 550, 1650, 600, 1650, 550, 550, 550, 1650, 550, 550, 550, 550, 550, 550, 550, 550, 600, 500, 600, 500, 600, 1650, 550, 550, 550, 1600, 600, 1650, 550, 1650, 600, 1650, 550};


/* Buffer datos */
#define bufferSize 1
char myBuffer[bufferSize];
int i = 0;
int nChar = 0;

String cmd;

IRsend irsend;

void enviarCodIR (char* data) {
  switch(data[0]) {
    case 'W':
      irsend.sendRaw(OnOff,68,38);
      delay(100);   
      break;
    case '1':
      irsend.sendRaw(T1,68,38);
      delay(100);   
      break;
    case '2':
      irsend.sendRaw(T2,68,38);
      delay(100);   
      break;
    case '3':
      irsend.sendRaw(T3,68,38);
      delay(100);   
      break;
    case '4':
      irsend.sendRaw(T4,68,38);
      delay(100);   
      break;
    case '5':
      irsend.sendRaw(T5,68,38);
      delay(100);   
      break;
    case '6':
      irsend.sendRaw(T6,68,38);
      delay(100);   
      break;
    case '7':
      irsend.sendRaw(T7,68,38);
      delay(100);   
      break;
    case '8':
      irsend.sendRaw(T8,68,38);
      delay(100);   
      break;
    case '9':
      irsend.sendRaw(T9,68,38);
      delay(100);   
      break;
    case '0':
      irsend.sendRaw(T0,68,38);
      delay(100);   
      break;
    case 'P':
      irsend.sendRaw(PUp,68,38);
      delay(100);   
      break;
    case 'D':
      irsend.sendRaw(PDown,68,38);
      delay(100);   
      break;
    case 'M':
      irsend.sendRaw(VPlus,68,38);
      delay(100);   
      break;
    case '-':
      irsend.sendRaw(VLess,68,38);
      delay(100);   
      break;
  }
  Serial.flush();   

}
void setup()
{
  Serial.begin(BQ_ZUM_BT);
  Serial.flush();   
}

void loop() {
  
  if (Serial.available() > 0){
     i = 0;
     memset(myBuffer, 0, sizeof(myBuffer));
     delay(bufferSize);
     
     nChar = Serial.available();
     if (nChar > bufferSize) {
       nChar = bufferSize;
     }
     
     while (nChar--) {
       myBuffer[i++] = Serial.read();
       delay(3);
     }
     
     enviarCodIR(myBuffer);
     
  }
}  
