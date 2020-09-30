/*

1. formato --> "[type],[file],[total_size],[num_chunks]" --> "SYNC,IDLE,12,2" Ó "FOTA,NA,100,8"
2. COSAS POR ENVIAR:
 - IDLE: 	ENVIA - colores y tiempo --> "(r,g,b,t)" --> "(10,200,255,2000),(10,24,200,2000),..."
 - RYTH: 	ENVIA - colores          --> "(r,g,b)"
 - CIRCULAR:	ENVIA - colores          --> "(r,g,b)"
 - LINEAR:	ENVIA - colores          --> "(r,g,b)"

Ejemplos:  

"SYNC,IDLE,13,6"

"4(255,0,0),4(255,0,0),1000"
"8(0,0,255),200"
"3(255,0,0),3(255,0,0),2(255,0,0),1000"
"6(255,0,0),2(255,0,0),2000"

*/
/*
array[] = {  
           0 {R,G,B}, --> array[0].RED
           1 {R,G,B}, --> array[1].RED
           2 {R,G,B}, --> array[2].RED
           3 {R,G,B}, --> array[3].RED
        

        }
        
        1. Parseo
        2. Asigno
        3.llego al maximo
        4.hago Flush -->memset (aray,0,sizeof(array));
        5.Repite

        NOTA: excepciones
        11 elementos en el string <-> total_size
*/
#include <stdio.h>      
#include <stdlib.h> 
#include <string.h>
#include <stdint.h>
#include <list>

#define ARRAYSIZE 4


typedef struct
{
    uint8_t RED;
    uint8_t GREEN;
    uint8_t BLUE;
}RGB;

typedef struct
{
    char pixels;
    RGB  color;
}Group; // 4bytes

typedef struct
{
    std::list<Group> block; 
    uint32_t time;
}Frame;

struct first_msg
{
    char type [10] ;
    char file[10] ;
    int total_size;
    int num_chunks;
};

#define TOKEN() ptr = strtok (NULL,"(,)");

#define PARSE_COLOR(COLOR)  TOKEN()\
                            group.color.COLOR = atoi(ptr);\

char msg[4][40] = {"4(255,0,0),4(255,0,0),1000",
                   "8(0,0,255),200",
                   "3(255,0,0),3(255,0,0),2(255,0,0),1000",
                   "6(255,0,0),2(255,0,0),2000"};

void parsear_chunks(int MAX){
  int pixel_cnt=0;
  Frame frame;
  Group group;
  char * ptr;
  
  for(int i=0; i<MAX; i++){
      
    //printf ("Splitting string \"%s\" into tokens:\n",msg[i]);
    //PRIMER BLOQUE
    ptr = strtok (msg[i],"(,)");
    
    while(pixel_cnt < 8){
        group.pixels = atoi(ptr);
        pixel_cnt += group.pixels;

        PARSE_COLOR(RED); 
        PARSE_COLOR(GREEN);
        PARSE_COLOR(BLUE);
        TOKEN();

        frame.block.push_back(group); // insert group in block
        printf("%d(%d,%d,%d),",group.pixels,group.color.RED,group.color.GREEN,group.color.BLUE);
    }

    frame.time = atoi(ptr);
    printf("%d\r\n",frame.time);
    pixel_cnt=0;
}

}
void set_firstmsg_struct(char str1[],struct first_msg ref ){
 char * ptr;
  printf ("Splitting string \"%s\" into tokens:\n",str1);
  //TYPE
  ptr = strtok (str1,",");
  sprintf(ref.type,"%s",ptr);
  
  //FILE
  ptr = strtok (NULL, ",");
  sprintf(ref.file,"%s",ptr);

  //SIZE
  ptr = strtok (NULL, ",");
  ref.total_size = atoi(ptr);

  //CHUNKS
  ptr = strtok (NULL, ",");
  ref.num_chunks = atoi(ptr);

  printf("TYPE: %s\n",ref.type);
  printf("file: %s\n",ref.file);
  printf("total_size: %i\n",ref.total_size);
  printf("num_chunks: %i\n",ref.num_chunks);
}
int main(){

  struct first_msg ref;

  char str1 [] = "SYNC,IDLE,12,6";

  //set_firstmsg_struct (str1,ref);
  parsear_chunks(4);

/*
     int i;
  char buffer[256];
  printf ("Enter a number: ");
  fgets (buffer, 256, stdin);
  i = atoi (buffer);
  printf ("The value entered is %d. Its double is %d.\n",i,i*2);
  return 0;
}
*/

    return 0;
}