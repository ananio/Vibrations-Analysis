/////////////////////////////////////////////////////////////////////////
////                                                                 ////
//// RR2_USB_Cdc_Monitor.c                                           ////
////                                                                 ////
/////////////////////////////////////////////////////////////////////////
#include <18F4550.h>
#device ADC=8
#fuses HSPLL,NOWDT,NOPROTECT,NOLVP,NODEBUG,USBDIV,PLL5,CPUDIV1,VREGEN
#use delay(clock=48000000)

#include "usb_cdc.h"

#use fast_io(b)
#use fast_io(d)
#use fast_io(e)

//Parte desde la memoria 0x1000
#build(reset=0x1000,interrupt=0x1008)
#org 0x0000,0x0FFF {}

//variables
unsigned int8  an1=0;
unsigned int8  an2=0;
unsigned int8  an3=0;
unsigned int8  an4=0;

unsigned int8  i=0;
unsigned int8  j=0;
unsigned int16 k=0;
unsigned int8  image[416]={0};               



void main()
{ 
   set_tris_d(0x00); 
   set_tris_e(0x00); //salidas mux
   set_tris_b(0x00); //salidas demux
   
   output_D(0x00);

   setup_adc (adc_clock_div_32); 
   setup_adc_ports(AN0_TO_AN3|VSS_VDD);
   
   usb_init_cs();
   do 
   { 
      usb_task();
      if (usb_enumerated()) 
      {       
         if (usb_cdc_kbhit()) 
         { 
            i = toupper(usb_cdc_getc()); 
            if(i=='S')
            {
               i = 'n';
               output_toggle(PIN_D2);
               
               for(k=0;k<416;k++){
               
                  set_adc_channel (0);
                  delay_us(20);
                  image[k]=read_adc();
                  
               }
               
               k=0;
               
               while(k<416){ 
               
                  i = toupper(usb_cdc_getc()); 
                  
                  if(i=='S'){
                     usb_cdc_putc(image[k]);
                     k = k + 1;
                     i = 'n';
                  }
               
               }

               
            }//if(i==S)
         }//if (usb_cdc_kbhit()) 
      }//if (usb_enumerated()) 
   } while (TRUE); 
}
