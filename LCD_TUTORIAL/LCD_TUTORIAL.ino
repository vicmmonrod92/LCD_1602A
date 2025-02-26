//     * *               -------------------------------------------------------       
//    *   *              ***************** PROGRAMA LCD1602A  ******************        * * * *      
// - * - - * - - * -     ***** PROGRAMADO POR: VICTOR MANUEL MONROY RODRIGUEZ **       *       *     
//          *   *        *************** 11281218 840020588 6063 ***************       *       *     
//           * *         -------------------------------------------------------   * * *       * * *
//                       ------------------ ELECTRONICA VMMR  -------------------   

///DEFINE SECCION

#define EN 2   // Numero de pin donde se conecta enable de lcd.
#define RS 3   // Numero de pin donde se conecta RS en la lcd.

#define D4 7   // Numero de pin donde se conecta D4 en la lcd.
#define D5 8   // Numero de pin donde se conecta D5 en la lcd.
#define D6 9   // Numero de pin donde se conecta D6 en la lcd.
#define D7 10  // Numero de pin donde se conecta D7 en la lcd.

#define TRS 1  //valor del retardo para activar el pin RS.
#define TEN 2  //valor del retardo para activar el pin EN (enable).


//CONFIGURACION DE BITS y PRE inicio de programa.
void setup() {

  //  configuracion de entradas y salidas. 
  
  pinMode(2, OUTPUT);     //pin 2 como salida.
  pinMode(3, OUTPUT);     //pin 3 como salida.
  pinMode(5, INPUT);      //pin 5 como entrada.
  pinMode(7, OUTPUT);     //pin 7 como salida.
  pinMode(8, OUTPUT);     //pin 8 como salida.
  pinMode(9, OUTPUT);     //pin 9 como salida.
  pinMode(10, OUTPUT);    //pin 10 como salida.
  pinMode(11, OUTPUT);    //pin 11 como salida.

   
  digitalWrite(RS, LOW);  // RS=0      
  digitalWrite(EN, LOW);  // EN=0
  digitalWrite(D4, LOW);  // D4=0
  digitalWrite(D5, LOW);  // D5=0
  digitalWrite(D6, LOW);  // D6=0
  digitalWrite(D7, LOW);  // D7=0

  delay(50);   
  lcdini();              // Configuracion de la lcd.
  delay(50);
  
 
  CHARGEN(0,4,10,4,14,4,10,0,72);      // Generador de caracter.
  CHARGEN(0,1,2,3,4,5,6,7,80);         // Generador de caracter.
   
  
  
  


}

//PROGRAMA PRINCIPAL
void loop() {

    
  MENSAJE("HOLA MUNDO      ",1);      // Mensaje a mostrar en la lcd en la linea 1.(usar completamente las 16 posiciones de la lcd)
  MENSAJE("HELLO WORLD     ",2);      // Mensaje a mostrar en la lcd en la linea 1.(usar completamente las 16 posiciones de la lcd) 
  

  CARACTER(1,1,15);              // Escritura de un solo caracter en la lcd.
  CARACTER(2,2,15);              // Escritura de un solo caracter en la lcd.

  delay(750);

  BORRALCD();                    //borra la lcd.
  
  delay(500); 

}

//     * *               -------------------------------------------------------       
//    *   *              ***************** PROGRAMA LCD1602A  ******************        * * * *      
// - * - - * - - * -     ***** PROGRAMADO POR: VICTOR MANUEL MONROY RODRIGUEZ **       *       *     
//          *   *        *************** 11281218 840020588 6063 ***************       *       *     
//           * *         -------------------------------------------------------   * * *       * * *
//                       ------------------ ELECTRONICA VMMR  -------------------


