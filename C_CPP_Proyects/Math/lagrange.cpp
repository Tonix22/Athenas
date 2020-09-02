#include<stdio.h>


float time[4],Acel[4];

float A,B,C,offset;

float div;
float diff;
float mul;
float temp;
float rate;
main()
{
    
    int n,i,j,d=1;
    n = 4;

    time[0] = 1;
    time[1] = 2;
    time[2] = 3;
    time[3] = 4;

    Acel[0] = 2;
    Acel[1] = 5;
    Acel[2] = 6;
    Acel[3] = 8;
    printf("input data: [%f,%f,%f,%f]\r\n",Acel[0], Acel[1], Acel[2], Acel[3]);

    for(i=0; i<n; i++)
    {
        div  = 1;
        diff = 0;
        mul  = 1;
        for(j=0; j<n; j++)
        {
            if(i!=j)
            {
                div  *= (time[i]-time[j]);
                diff -= time[j];
                mul  *= time[j];
            }
        }
        mul*=-1;
        rate = Acel[i] / div;
        A += rate;
        B += rate * diff;
        offset += rate * mul;
        
        if(i<(n-1))
        {
            j--;
        }
        else
        {
            j-=2;
        }
        temp = (mul/time[j]) + (diff+time[j])*time[j];
        temp*= -1;
        C += (temp*rate);
    }
    
    printf("polinomial: %fx^3 , %fx^2, %fx, %f\r\n",A,B,C,offset);


    return 0;
}