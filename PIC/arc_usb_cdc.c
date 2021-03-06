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
//unsigned int8  an1=0;
//unsigned int8  an2=0;
//unsigned int8  an3=0;
//unsigned int8  an4=0;

unsigned int8  i=0;
//unsigned int8  j=0;
unsigned int16 k=0;
unsigned int8  image[600]={0}; 



void main()
{
   byte frequency;

   setup_ccp1 (CCP_PWM);
   setup_timer_2(T2_DIV_BY_16, 2, 1);
   set_pwm1_duty(1); 
//   setup_timer_2(T2_DIV_BY_16, PR2, 16);
   

   
 //  setup_ccp2 (CCP_PWM);

 //    set_pwm1_duty(PR2/2);
 //  set_pwm2_duty(duty_PWM2);

   set_tris_d(0x00); 
   set_tris_e(0x00); //salidas 
   set_tris_b(0x00); //salidas
   
   output_D(0x00);
   
//   set_pwm1_duty(100);

   setup_adc (adc_clock_div_32); 
   setup_adc_ports(AN0_TO_AN3);
   
   usb_init_cs();
   
   while(TRUE) 
   { 
      output_toggle(PIN_D3);
      
      usb_task();
      if (usb_enumerated()) 
      {       
         if (usb_cdc_kbhit()) 
         { 
  
            i = toupper(usb_cdc_getc()); 
            
            if(i=='S')
            {
         
               output_toggle(PIN_D2);
               
               for(k=0;k<600;k++){
                  set_adc_channel (0);
                  delay_us(200);
                  image[k]=read_adc();
                  output_toggle(PIN_D5);
               }

               
               k=0;
               i = 'n';
               
               for(k=0;k<600;k++){ 
                  i = toupper(usb_cdc_getc()); 
                  
                  if(i=='S'){
                     usb_cdc_putc(image[k]);
                     i = 'n';
                     output_toggle(PIN_D2);
                     delay_us(40);
                  }
               }
               
               }
               
            if(i=='L')
            {
         
               output_toggle(PIN_D2);
               
               for(k=0;k<600;k++){

                  set_adc_channel (1);
                  delay_us(200);
                  image[k]=read_adc();
                  output_toggle(PIN_D5);
               }

               
               k=0;
               i = 'n';
               
               for(k=0;k<600;k++){ 
               
                  i = toupper(usb_cdc_getc()); 
                  
                  if(i=='L'){
                     usb_cdc_putc(image[k]);
                     i = 'n';
                     output_toggle(PIN_D2);
                     delay_us(40);
                  }
                  
               }
            }
            
            if(i=='Q')
            {
         
               output_toggle(PIN_D2);
               
               for(k=0;k<600;k++){
               
                  set_adc_channel (2);
                  delay_us(200);
                  image[k]=read_adc();
                  output_toggle(PIN_D5);
               }

               
               k=0;
               i = 'n';
               
               for(k=0;k<600;k++){ 
               
                  i = toupper(usb_cdc_getc()); 
                  
                  if(i=='Q'){
                     usb_cdc_putc(image[k]);
                     i = 'n';
                     output_toggle(PIN_D2);
                     delay_us(40);
                  }
                  
               }
            }
            
                        if(i=='P')
            {
         
               i = toupper(usb_cdc_getc()); 
               
               frequency = (int)i;
               
               setup_timer_2(T2_DIV_BY_16, frequency, 1);
               set_pwm1_duty(frequency/2); 
               
               i = 'n';

            }

            i = 'n';   
            
         }//if (usb_cdc_kbhit()) 
      }//if (usb_enumerated()) 
      
   }
   
   }
