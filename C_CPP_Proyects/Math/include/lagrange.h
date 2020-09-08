#ifndef HEADER_FILE
#define HEADER_FILE



#define DATA_BUFER 4
#define SAMPLE_TIME 1

typedef struct
{
    float A,B,C,offset;
 
}Acel_eq;

typedef struct
{
    float A,B,C,D,offset;
 
}Vel_eq;

typedef struct 
{
    float A,B,C,D,E,offset;
}Pos_eq;

#endif