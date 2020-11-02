#ifndef DNA
#define DNA

void Generate_random_seq(int size);
void LCS(char* x, char* y,int size_x,int size_y);
void print_LCS(int row,int col,char** b,char* x,char* y);
void reverse_string(char* A);

typedef enum
{
    UP   = 'u',
    LEFT = 'l',
    DIAG = 'd',
}Direction;

#define ON 1
#define OFF 0
#define CREATE_2D_ARR(name) char **name = (char**)malloc((size_y)*sizeof(char*));\
                          for (int l = 0; l < size_y; l++)\
                          {   \
                                name[l] = (char*)malloc(size_x*sizeof(char*));\
                          }\


#define PRINT_C_2D_ARR(name,simbols)printf("  ");\
                        for(int x_p=0;x_p<size_x;x_p++)\
                        {\
                            printf("%c ",x[x_p]);\
                        }\
                        printf("\r\n");\
                         for (int row = 0; row < size_y; row++)\
                         {\
                             printf("%c ",y[row]);\
                             for (int col = 0; col < size_x; col++)\
                             {\
                                if(simbols && name[row][col]!=0)\
                                {\
                                    printf("%c,",name[row][col]);\
                                }  \
                                else\
                                {\
                                    printf("%d,",name[row][col]);\
                                }\
                             }\
                             printf("\r\n");\
                         }\
                         printf("***********\r\n");\


#define Destroy_C_2D_ARR(name) for (int l = 0; l < size_y; l++)\
                            {\
                                free(name[l]);\
                                name[l] = NULL;\
                            }\
                            free(name);\
                            name = NULL;\

#endif