/* Copyright (c) 2017, Eric Pernia.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * =============================================================================
 *
 * Copyright (c) 2017, Eric Pernia.
 * Todos los derechos reservados.
 * 
 * La redistribución y el uso en las formas de código fuente y binario, con o 
 * sin modificaciones, están permitidos siempre que se cumplan las siguientes 
 * condiciones:
 * 
 * 1. Las redistribuciones del código fuente deben conservar el aviso de
 *    copyright anterior, esta lista de condiciones y el siguiente descargo de
 *    responsabilidad.
 * 
 * 2. Las redistribuciones en formato binario deben reproducir el aviso de
 *    copyright anterior, esta lista de condiciones y el siguiente descargo de
 *    responsabilidad en la documentación y/u otros materiales suministrados 
 *    con la distribución.
 * 
 * 3. Ni el nombre de los titulares de derechos de autor ni los nombres de sus
 *    colaboradores pueden usarse para apoyar o promocionar productos 
 *    derivados de este software sin permiso específico previo y por escrito.
 * 
 * ESTE SOFTWARE SE SUMINISTRA POR LOS PROPIETARIOS DEL COPYRIGHT Y
 * COLABORADORES ''COMO ESTÁ'' Y CUALQUIER GARANTÍAS EXPRESA O IMPLÍCITA,
 * INCLUYENDO, PERO NO LIMITADO A, LAS GARANTÍAS IMPLÍCITAS DE COMERCIALIZACIÓN
 * Y APTITUD PARA UN PROPÓSITO PARTICULAR SON RECHAZADAS. EN NINGÚN CASO LOS
 * PROPIETARIOS DEL COPYRIGHT Y COLABORADORES SERÁN RESPONSABLES POR NINGÚN
 * DAÑO DIRECTO, INDIRECTO, INCIDENTAL, ESPECIAL, EJEMPLAR O COSECUENCIAL
 * (INCLUYENDO, PERO NO LIMITADO A, LA ADQUISICIÓN O SUSTITUCIÓN DE BIENES O
 * SERVICIOS; LA PÉRDIDA DE USO, DE DATOS O DE BENEFICIOS; O INTERRUPCIÓN DE LA
 * ACTIVIDAD EMPRESARIAL) O POR CUALQUIER TEORÍA DE RESPONSABILIDAD, YA SEA POR
 * CONTRATO, RESPONSABILIDAD ESTRICTA O AGRAVIO (INCLUYENDO NEGLIGENCIA O
 * CUALQUIER OTRA CAUSA) QUE SURJA DE CUALQUIER MANERA DEL USO DE ESTE SOFTWARE,
 * INCLUSO SI SE HA ADVERTIDO DE LA POSIBILIDAD DE TALES DAÑOS.
 *
 * =============================================================================
 * Fecha de creacion: 2017-03-15
 * =============================================================================
 */

/*==================[inlcusiones]============================================*/

#include "programa.h"   // <= su propio archivo de cabecera
#include "sapi.h"       // <= Biblioteca sAPI

/*==================[definiciones y macros]==================================*/

/*==================[definiciones de datos internos]=========================*/
uint8_t led=LEDB;
char ReceivedByte;
delay_t ledtoggle;
/*==================[definiciones de datos externos]=========================*/

/*==================[declaraciones de funciones internas]====================*/

/*==================[declaraciones de funciones externas]====================*/

/*==================[funcion principal]======================================*/

// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE RESET.
int main( void ){

   // ---------- CONFIGURACIONES ------------------------------
   // Inicializar y configurar la plataforma
   boardConfig();  
   uartConfig(UART_USB, 115200);   
   delayConfig(&ledtoggle, 500);
   // ---------- REPETIR POR SIEMPRE --------------------------
   while(1)
   {      
     //gpioToggle( led );
       //      delay(500);
    if(delayRead(&ledtoggle)){
      
         gpioToggle( led );
         
     }  
     if(uartReadByte(UART_USB, &ReceivedByte)){
        gpioWrite(led, OFF);
        if(ReceivedByte=='a'){
            led=LEDB;        
        }
        if(ReceivedByte=='1'){
            led=LED1;       
        }
        if(ReceivedByte=='2'){
            led=LED2;       
        }
        if(ReceivedByte=='3'){
            led=LED3;        
        }
    }
     if(gpioRead(TEC1)==0)delayConfig(&ledtoggle, 50);    
     if(gpioRead(TEC2)==0)delayConfig(&ledtoggle, 100); 
     if(gpioRead(TEC3)==0)delayConfig(&ledtoggle, 200); 
     if(gpioRead(TEC4)==0)delayConfig(&ledtoggle, 500); 
   } 

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta 
   // directamenteno sobre un microcontroladore y no es llamado/ por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return FALSE;
}

/*==================[definiciones de funciones internas]=====================*/

/*==================[definiciones de funciones externas]=====================*/

/*==================[fin del archivo]========================================*/
