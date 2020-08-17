#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum
{
    NIL    =  0,
    PUSH   =  1,
    POP    = -1,
    ACCEPT = -2,
    ERROR  = -3,
}states_t;


#define ALPHABET 3 /* Größe des Eingabealphabets */

#define MAX_LEN 80
/*
 Ein einfacher Kellerautomat ("pushdown automaton")

 Symbol   | (       | )      | \0
 ---------+---------+--------+-----------
 State 0  | PUSH 1  | ERROR  | ACCEPT
 State 1  | PUSH 1  | POP    | ERROR
*/

int states[2][ALPHABET*2] =
{
   {
      '(' , PUSH  ,
      ')' , ERROR ,
      '\0', ACCEPT
   },
   {
      '(' , PUSH ,
      ')' , POP  ,
      '\0', ERROR
   }
};


int main( int argc, char** argv )
{
   int stack[100] = { 0 };
   int* stack_pointer = stack;
   
   char  input_tape  [MAX_LEN+1] = {0};
   char* cabezal = input_tape;
   
   states_t action   = NIL;
   int i             = 0;
   int sp_value      = 0;
   
   /* Eingabe-Zeichenkette */
   printf("Bitte Ausdruck eingeben: ");
   fgets(input_tape, sizeof(input_tape), stdin);
   input_tape[strlen(input_tape)-1]='\0'; /* Zeilenvorschub (NL) von fgets() durch binäre Null ersetzen */


   /* Startzustand auf Stack ("push") */
   *(stack_pointer++) = 0;

   /* Ausführungsschleife */
   do
   {
      /* Aktion auf Basis des Eingabesymbols ermitteln */
      action = ERROR;
      sp_value = *(stack_pointer-1);
      
      for( i = 0; i < ALPHABET; ++i )
      {
         if( states[sp_value][i*2] == *cabezal )
         {
            action = (states_t) states[sp_value][i*2+1];
            break;
         }
      }

      /* Ausführen der Aktionen */
      if( action == ERROR )
      {
         printf("Unerwartetes Zeichen an Position %lu\n", cabezal-input_tape);
         break;
      }
      else if( action == ACCEPT )
         printf("Ausdruck akzeptiert!\n");
      else if( action == POP )
         --stack_pointer;
      else if( action == PUSH)
         *(stack_pointer++) = action;

      /* Eingabe erweitern... */
      ++cabezal;
   }
   while( action != ACCEPT );

   return 0;
}
