/// AUTOR CHRISTIAN CONTRERAS
#include "lib/include.h"

char *lectura_cadena(char delim, int *ptr){
    char letra;
    static char array[50];
    int counter = 0;
    letra = readChar();  
    while (letra != delim){
        array[counter] = letra;
        letra = readChar();
        counter ++;
    }
    *ptr = strlen(array);
    return &array[0];
}


char *inversion_nombre(char *nombre, int length){
    static char nombre_inv[50];
    int counter = 0;
    int idx = 0; 
    for (int i = length; i > 0; i--){
        nombre_inv[counter] = *(nombre + (i -1));
        nombre_inv[counter + 1] = idx + '0';
        idx ++; 
        counter = counter + 2;
    }
    nombre_inv[counter - 1] = '\n'; 
    return &nombre_inv[0];
}

int main(void)
{
    uint16_t valor = 0;
    char c='5'; 
 
    Configurar_PLL(_20MHZ);  //Confiuracion de velocidad de reloj
    //Configurar_UART0();//Yo FCLK 20MHZ Baudrate 9600

    //Experimento 1
    //  Configurar_UART1(); //Jorge,Alberto,Navarro,Saul,Fabela -fclk 25MHZ Baud-rate 57600
    //  Configurar_UART7(); //Angel,Fernanda,Sonia,Aleidis,Monse -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART4(); //Argelia,Roxana,Yesica,Vanesa,Christian,Abiu -fclk 10MHZ Baud-rate 4800
    //  Configurar_UART2(); //Brizet,Monse,Luis,Majo,Alonso -fclk 40MHZ Baud-rate 115200
    //  Configurar_UART3(); //Jesus,Yesica,Carlos,Dulce,Rodolfo,Leonardo -fclk 80MHZ Baud-rate 19200
    //  Configurar_UART2(); //Andrea,Avila,Pamela,Paulina -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART5(); //Hector,Cecilia,Carolina,Jozzafat -fclk 40MHZ Baud-rate 28800
    Configurar_GPIO();
    Configurar_UART0();

    int longit; 
    longit = 0; 
    
    while(1)
    {
         c = readChar();
         switch(c)
         {
             case 'r':
                 //GPIODATA port F 662
                 printChar('a');
                 GPIOF->DATA = (1<<1);
                 break;
             case 'b':
                 //GPIODATA port F 662
                 printChar('b');
                 GPIOF->DATA = (1<<2);
                 break;
             case 'g':
                 //GPIODATA port F 662
                 printChar('c');
                 GPIOF->DATA = (1<<3);
                 break;
             case 'y':
                 //GPIODATA port F 662
                 printChar('d');
                 GPIOF->DATA = (1<<3) | (1<<2);
                 break;
             default:
                 printChar((char)valor);
                 GPIOF->DATA = (0<<1) | (0<<2) | (0<<3);
                 break;
    char *nombre_inicial = lectura_cadena(',', &longit);
    char *nombre_inv = inversion_nombre(nombre_inicial, longit);
    printString(nombre_inv);
         }
    }
}
