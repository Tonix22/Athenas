#ifndef HELPER_H
#define HELPER_H

#define PRINT_MATRIX(M)  for(int i=0;i<ROWS;i++)\
                            {\
                                for(int j=0;j<COLS;j++)\
                                {\
                                    printf("%d,",M[i][j]);\
                                }\
                                printf("\r\n");\
                            }

#define COPY_MATRIX(S,D)    for(int i=0; i < ROWS ; i++)\
                            {\
                                memcpy(S[i] ,D[i], sizeof(int32_t)*COLS);\
                            }


#define min(X, Y) (((X) < (Y)) ? (X) : (Y))

#define CREATE_2D_ARR(ARR)  int32_t** ARR = (int32_t **) malloc(sizeof(int32_t*)*ROWS);\
                            for(int i=0;i < n ;i++)\
                            {\
                                ARR[i] = (int32_t *) malloc(sizeof(int32_t)*COLS);\
                            }

#define DESTROY_2D_ARR(ARR) for(int i=0;i < n ;i++)\
                            {\
                                free(ARR[i]);\
                            }\
                            free(ARR);


#define D_eq_W()     for(int i=0; i < n ; i++)\
                    {\
                        memcpy(D[i], W+i*(COLS), sizeof(int32_t)*COLS);\
                    }\


void Floy_Marshal_I(int32_t* W, int ROWS, int COLS);

#endif