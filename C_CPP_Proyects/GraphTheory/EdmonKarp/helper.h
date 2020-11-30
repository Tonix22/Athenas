#ifndef HELPER_H
#define HELPER_H

#define PRINT_MATRIX(M)  for(int i=0;i<ROWS;i++)\
                            {\
                                for(int j=0;j<COLS;j++)\
                                {\
                                    printf("%d,",M[i][j].color);\
                                }\
                                printf("\r\n");\
                            }

#define CREATE_2D_ARR(ARR)  Grid_Edge** ARR = (Grid_Edge **) malloc(sizeof(Grid_Edge*)*ROWS);\
                            for(int i=0;i < ROWS ;i++)\
                            {\
                                ARR[i] = (Grid_Edge*) malloc(sizeof(Grid_Edge)*COLS);\
                            }

#define DESTROY_2D_ARR(ARR) for(int i=0;i < ROWS ;i++)\
                            {\
                                free(ARR[i]);\
                            }\
                            free(ARR);



#endif