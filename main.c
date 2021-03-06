#include <main.h>

int32 TE1, TE2;

//Velocidad sonido: a 20° --------- 343.31 m/s
//                  a 24° --------- 345.65 m/s
void main()
{ 
   //D distancia entre los 2 micrófonos (cm)
   float d1, d2, punto, D=0.2;

    port_b_pullups (TRUE);                  //Habilita pull-up internos del puerto B        
 //  enable_interrupts(INT_RB);              // Habilita la interrupcion del puerto B ( RB4 - RB7).
 //  enable_interrupts(GLOBAL);              // Habilita las interrupciones globales.
 //  ext_int_edge(H_TO_L);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8); //a 20MHz cuenta de a 1.6uS
   while(TRUE)
   {
     if(input_state(pin_B4)==0)
       { 
        TE1=get_timer1();
        set_timer1(0);
       }
     
     if (input_state(pin_B5)==0)
       {
        TE2=get_timer1();
        set_timer1(0);    
        }
        
    If (!TE2) 
     {
       d1= (float) 343.31 * TE2 * 0.0000016;
       punto=(float) (D-d1)/2;
     }
    If (!TE1) 
     {
      d2= (float) 343.31 * TE1 * 0.0000016;
      punto=(float) (D-d2)/2;
     }
  }
}


