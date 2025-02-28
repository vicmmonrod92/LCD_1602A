//     * *               -------------------------------------------------------       
//    *   *              ***************** PROGRAMA LCD1602A  ******************        * * * *      
// - * - - * - - * -     ***** PROGRAMADO POR: VICTOR MANUEL MONROY RODRIGUEZ **       *       *     
//          *   *        *************** 11281218 840020588 6063 ***************       *       *     
//           * *         -------------------------------------------------------   * * *       * * *
//                       ------------------ ELECTRONICA VMMR  -------------------   
//  26/02/2025


// Funcion para borrar lcd.
void BORRALCD(){  
                  CONV(1,2);
                  CONV(2,2);
                  CONV(16,2);              
                  }

///Generador de caracteres
void CHARGEN(int a,int b,int c,int d,int e,int f,int g,int h,int px)
{

     CONV(px,2);
     CONV(a,1);
     CONV(b,1);
     CONV(c,1);
     CONV(d,1);
     CONV(e,1);
     CONV(f,1);
     CONV(g,1);
     CONV(h,1);

}

//// Funcion de escritura de mensajes en LCD
void MENSAJE(char x[16],int u){

          int h;
          CONV(8,2); // display OFF

if(u==1){ CONV(128,2); }
if(u==2){ CONV(192,2); }
        
          for(h=0;h<16;h++){CONV(int(x[h]),1);}
                  
  
          CONV(12,2); // display ON
  
   
}
//// Funcion de escritura de un solo caracter en la lcd
void CARACTER(char x,int u,int px){

          int h=int(x);
          CONV(8,2); // display OFF

if(u==1){ CONV(128+px,2); }
if(u==2){ CONV(192+px,2); }
        
          CONV(h,1);
                  
  
          CONV(12,2); // display ON
  
   
}

//// Conversion de decimal a hexadecimal y escritura en lcd.
void CONV(int c,int u){
  
   bool z=false;
   int x=0,y=0;
   
   while(z==false){
    
    if(c==0){z=true;}    
    if(c>0){
           if(c<16){y=c;z=true;}
           else{c=c-16;x++;}
           }
    } 

      DATOS(x,u);
      DATOS(y,u);     
  
  }

/// Conversion de Valores Hexadecimales a binarios y escritura en lcd. 
void DATOS(int W,int q){

switch(W)
{
   case 0:
   if(q==1){lcd_write(false,false,false,false);}
   if(q==2){lcd_func(false,false,false,false);}
   break;
   case 1:
   if(q==1){lcd_write(false,false,false,true);}
   if(q==2){lcd_func(false,false,false,true);}
   break;
   case 2:
   if(q==1){lcd_write(false,false,true,false);}
   if(q==2){lcd_func(false,false,true,false);}
   break;
   case 3:
   if(q==1){lcd_write(false,false,true,true);}
   if(q==2){lcd_func(false,false,true,true);}
   break;
   case 4:
   if(q==1){lcd_write(false,true,false,false);}
   if(q==2){lcd_func(false,true,false,false);}
   break;
   case 5:
   if(q==1){lcd_write(false,true,false,true);}
   if(q==2){lcd_func(false,true,false,true);}
   break;
   case 6:
   if(q==1){lcd_write(false,true,true,false);}
   if(q==2){lcd_func(false,true,true,false);}
   break;
   case 7:
   if(q==1){lcd_write(false,true,true,true);}
   if(q==2){lcd_func(false,true,true,true);}
   break;
   case 8:
   if(q==1){lcd_write(true,false,false,false);}
   if(q==2){lcd_func(true,false,false,false);}
   break; 
   case 9:
   if(q==1){lcd_write(true,false,false,true);}
   if(q==2){lcd_func(true,false,false,true);}
   break;
   case 10:
   if(q==1){lcd_write(true,false,true,false);}
   if(q==2){lcd_func(true,false,true,false);}
   break;
   case 11:
   if(q==1){lcd_write(true,false,true,true);}
   if(q==2){lcd_func(true,false,true,true);}
   break;
   case 12:
   if(q==1){lcd_write(true,true,false,false);}
   if(q==2){lcd_func(true,true,false,false);}
   break;
   case 13:
   if(q==1){lcd_write(true,true,false,true);}
   if(q==2){lcd_func(true,true,false,true);}
   break;
   case 14:
   if(q==1){lcd_write(true,true,true,false);}
   if(q==2){lcd_func(true,true,true,false);}
   break;
   case 15:
   if(q==1){lcd_write(true,true,true,true);}
   if(q==2){lcd_func(true,true,true,true);}
   break; 
   default:
   break;

}


}

// Funcion escritura de valores en LCD 
void lcd_write(bool h,bool g,bool f,bool e) {
  
  
  digitalWrite(RS, HIGH);  
  delay(TRS);                      
  digitalWrite(EN, HIGH);   
  delay(TEN);
   
  state(D7,h);
  state(D6,g);
  state(D5,f);
  state(D4,e);

  delay(TEN);                      
  digitalWrite(EN,LOW);
  delay(TRS);
  digitalWrite(RS,LOW);
  delay(TEN);
  
}

// LCD funciones
void lcd_func(bool h,bool g,bool f,bool e) {
  
  digitalWrite(RS, LOW);
  delay(TRS);
  digitalWrite(EN, HIGH);   
  delay(TEN);
  
  state(D7,h);
  state(D6,g);
  state(D5,f);
  state(D4,e);
  
  delay(TEN);
  digitalWrite(EN, LOW);
  delay(TEN); 
}
/// Funcion para configuracion de la LCD.
void lcdini(){
  
  
  lcd_func(false,false,true,true);
  lcd_func(true,false,false,false);  //0x38

  // 4bit mode
  lcd_func(false,false,true,false); 

  //home
  lcd_func(false,false,false,false);
  lcd_func(false,false,true,false);
   
   //function set 
  lcd_func(false,false,true,false);
  lcd_func(true,false,false,false);   
      
   //display On-Off control
   lcd_func(false,false,false,false);
   lcd_func(true,true,false,false); 

   //clear display
  lcd_func(false,false,false,false);
  lcd_func(false,false,false,true);   
  
}

/// Funcion de escritura digital para pines de arduino.
void state(int d,bool g){

if(g==true){digitalWrite(d,HIGH);}
else{digitalWrite(d,LOW);}

}

//     * *               -------------------------------------------------------       
//    *   *              ***************** PROGRAMA LCD1602A  ******************        * * * *      
// - * - - * - - * -     ***** PROGRAMADO POR: VICTOR MANUEL MONROY RODRIGUEZ **       *       *     
//          *   *        *************** 11281218 840020588 6063 ***************       *       *     
//           * *         -------------------------------------------------------   * * *       * * *
//                       ------------------ ELECTRONICA VMMR  -------------------   