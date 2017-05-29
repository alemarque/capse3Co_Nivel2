/*============================================================================
 * Licencia: 
 * Autor: 
 * Fecha: 
 *===========================================================================*/

/*==================[inlcusiones]============================================*/

#include "programa.h"   // <= su propio archivo de cabecera
#include "sapi.h"       // <= Biblioteca sAPI

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/
char ReceivedByte;
/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[declaraciones de funciones externas]====================*/

/*==================[funcion principal]======================================*/

// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
int main( void ){

   // ---------- CONFIGURACIONES ------------------------------
   // Inicializar y configurar la plataforma
   boardConfig();  
   uartConfig(UART_USB, 115200); 
   
   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE )
   {      
      
uartWriteString(UART_USB,"TEC1=");
      if(gpioRead(TEC1)==1)uartWriteByte(UART_USB, '0');
      else uartWriteByte(UART_USB, '1');
      uartWriteByte(UART_USB, ' ');
      
      uartWriteString(UART_USB,"TEC2=");
      if(gpioRead(TEC2)==1)uartWriteByte(UART_USB, '0');
      else uartWriteByte(UART_USB, '1');
      uartWriteByte(UART_USB, ' ');
      
      uartWriteString(UART_USB,"TEC3=");
      if(gpioRead(TEC3)==1)uartWriteByte(UART_USB, '0');
      else uartWriteByte(UART_USB, '1');
      uartWriteByte(UART_USB, ' ');
      
      uartWriteString(UART_USB,"TEC4=");
      if(gpioRead(TEC4)==1)uartWriteByte(UART_USB, '0');
      else uartWriteByte(UART_USB, '1');
      uartWriteByte(UART_USB, ' ');
      
      uartWriteString(UART_USB,"LEDR=");
      if(gpioRead(LEDR)==ON)uartWriteByte(UART_USB, '1');
      else uartWriteByte(UART_USB, '0');
      uartWriteByte(UART_USB, ' ');
      
      uartWriteString(UART_USB,"LEDG=");
      if(gpioRead(LEDG)==ON)uartWriteByte(UART_USB, '1');
      else uartWriteByte(UART_USB, '0');
      uartWriteByte(UART_USB, ' ');
      
      uartWriteString(UART_USB,"LEDB=");
      if(gpioRead(LEDB)==ON)uartWriteByte(UART_USB, '1');
      else uartWriteByte(UART_USB, '0');
      uartWriteByte(UART_USB, ' ');
      
      uartWriteString(UART_USB,"LED1=");
      if(gpioRead(LED1)==ON)uartWriteByte(UART_USB, '1');
      else uartWriteByte(UART_USB, '0');
      uartWriteByte(UART_USB, ' ');
      
      uartWriteString(UART_USB,"LED2=");
      if(gpioRead(LED2)==ON)uartWriteByte(UART_USB, '1');
      else uartWriteByte(UART_USB, '0');
      uartWriteByte(UART_USB, ' ');
      
      uartWriteString(UART_USB,"LED3=");
      if(gpioRead(LED3)==ON)uartWriteByte(UART_USB, '1');
      else uartWriteByte(UART_USB, '0');
      uartWriteByte(UART_USB, ' ');
      uartWriteString(UART_USB,"\r\n");
     


      if(uartReadByte(UART_USB, &ReceivedByte)){
         if(ReceivedByte=='r'){
            gpioToggle( LEDR );       
         }
         if(ReceivedByte=='v'){
            gpioToggle( LEDG );       
         }
         if(ReceivedByte=='a'){
            gpioToggle( LEDB );        
         }
         if(ReceivedByte=='1'){
            gpioToggle( LED1 );        
         }
         if(ReceivedByte=='2'){
            gpioToggle( LED2 );       
         }
         if(ReceivedByte=='3'){
            gpioToggle( LED3 );        
         }
      }
      delay(500);
      
      // Si se presiona TEC1, enciende el LEDR
      //gpioWrite( LEDR, !(gpioRead(TEC1)) );
      
      // Si se presiona TEC2, enciende el LED1
      //gpioWrite( LED1, !(gpioRead(TEC2)) );
      
      // Si se presiona TEC3, enciende el LED2
      //gpioWrite( LED2, !(gpioRead(TEC3)) );
      
      // Si se presiona TEC4, enciende el LED3
      //gpioWrite( LED3, !(gpioRead(TEC4)) );

      // Intercambia el valor del LEDB
      //gpioToggle( LEDB );
      
      // Retardo bloqueante durante 100ms
      //delay( 100 );
   } 

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta 
   // directamenteno sobre un microcontroladore y no es llamado/ por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}

/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
