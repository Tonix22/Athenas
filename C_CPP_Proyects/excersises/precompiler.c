#include <stdio.h>

#define STM32  (0)
#define AVR    (1)


//#define DEBUG  (1)
#define MICROCONTROLER (STM32)
#define RUN    (4)

#if DEBUG
    #define dbugprint(str) printf(str);
#else
    #define dbugprint(str)
#endif

#if MICROCONTROLER  == STM32
    #define SCREEN 10 
#elif MICROCONTROLER  == AVR
    #define SCREEN 5
#endif

#define STR1 "hola "

#define STR2 "mundo"

#define MSG STR1 STR2

#define var_arr(instance) var##instance

#define variable(nombre,accion) var_##nombre##_##accion

#define BASE_PATH "/spiffs"

#define DIR(NAME) BASE_PATH"/"#NAME".bin"

#define IDLE_FILE DIR(IDLE) // /spiffs/IDLE.bin
#define RITH_FILE DIR(RITH) // /spiffs/RITH.bin
#define CIRC_FILE DIR(CIRC) // /spiffs/CIRC.bin
#define LINE_FILE DIR(LINE) // /spiffs/LINE.bin


#define FOO void foo() \
                        { \
                            int a;\
                            a++;\
                        }\

         
int main(int argc, char const *argv[])
{
    int var1 =  2;
    int var2 =  4;
    int var_memory_controller;
    
    int variable(gpio,flags);
    int variable(serial,config);

    variable(memory,controller);
    var_gpio_flags=0; // ?????
    //printf("%d\r\n",var_arr(1));
    //dbugprint(MSG);

    int var = 1;
    

    switch (var)
    {
        case 1:
            var++;
        case 2:
            {
                int a = 3;
                var = a+var;
            }
            break;

        default:
            break;
    }


    return 0;
}
