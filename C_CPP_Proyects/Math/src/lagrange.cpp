#include <OpenXLSX.hpp>
#include <iostream>
#include <stdio.h>
#include <cmath> // math.h
#include "lagrange.h"
#include "koolplot.h"

using namespace std;
using namespace OpenXLSX;

float stimes[4] = {0*SAMPLE_TIME, 1*SAMPLE_TIME, 2*SAMPLE_TIME, 3*SAMPLE_TIME};
float Acel[4];

Acel_eq acel_vect {0,0,0,0};
Vel_eq  vel_vect  {0,0,0,0,0};
Pos_eq  pos_vect  {0,0,0,0,0,0};
float   last_acel = 0;

void Calculate_polynomial(void)
{

    float dividend;
    float diff;
    float mul;
    float temp;
    float rate;
    int i,j=0;
    for(i=0; i<DATA_BUFER; i++)
    {
        dividend  = 1;
        diff = 0;
        mul  = 1;
        for(j=0; j<DATA_BUFER; j++)
        {
            if(i!=j)
            {
                dividend  *= (stimes[i]-stimes[j]);
                diff -= stimes[j];
                mul  *= stimes[j];
            }
        }
        mul*=-1;
        rate = Acel[i] / dividend;

        acel_vect.A += rate;
        acel_vect.B += rate * diff;
        acel_vect.offset += rate * mul;
        
        if(i<(DATA_BUFER-1))
        {
            j--;
        }
        else
        {
            j-=2;
        }
        temp = (mul/stimes[j]) + (diff+stimes[j])*stimes[j];
        temp*= -1;
        acel_vect.C += (temp*rate);
    }
}
void integrate_accel(void)
{
    static float last_vel = 0; // this variable persist

    float* acel_p = &acel_vect.A;
    float* vel_p= &vel_vect.A;

    vel_vect.offset = last_vel;
    for(int pol = 4;pol != 0;pol--)
    {
        *vel_p = (*acel_p) / pol;
        last_vel += pow(stimes[3],pol)*(*vel_p);
        acel_p++;
        vel_p++;
    }
    printf("last_vel: %.3f\r\n",last_vel);
}
void integrate_vel(void)
{
    static float last_pos = 0; // this variable persist

    float* vel_p = &vel_vect.A;
    float* pos_p = &pos_vect.A;
    vel_vect.offset = last_pos;

    for(int pol = 5;pol != 0;pol--)
    {
        *pos_p = (*vel_p) / pol;
        last_pos += pow(stimes[3],pol)*(*pos_p);
        vel_p++;
        pos_p++;
    }
    printf("last_pos: %.3f\r\n",last_pos);
}

void Process_data(void)
{
    printf("input data: \r\n");
    for(int i=0;i<DATA_BUFER;i++)
    {
        printf("(%.3f,%.3f)\r\n",stimes[i],Acel[i]);
    }
    //Get polinimal factors
    Calculate_polynomial();
    //integrate acel
    integrate_accel();
    //integrate vel
    integrate_vel();

    printf("aceleracion: %.3fx^3 + %.3fx^2+ %.3fx+ %.3f\r\n",acel_vect.A,acel_vect.B,acel_vect.C,acel_vect.offset);
    printf("velocidad:   %.3fx^4 + %.3fx^3+ %.3fx^2+ %.3fx + %.3f\r\n",vel_vect.A,vel_vect.B ,vel_vect.C ,vel_vect.D,vel_vect.offset);
    printf("posicion:    %.3fx^5 + %.3fx^4+ %.3fx^3+ %.3fx^2 + %.3fx+%.3f\r\n",pos_vect.A , pos_vect.B , pos_vect.C , pos_vect.D , pos_vect.E , pos_vect.offset);
    
}

main()
{
    XLDocument doc2;
    doc2.open("./muestras.xlsx");
    
    auto wks2 = doc2.workbook().worksheet("5cmDERECHA");

    auto PrintCell = [](const XLCell& cell) {
        cout << "Cell type is ";

        switch (cell.valueType()) {
            case XLValueType::Empty:
                cout << "XLValueType::Empty";
                break;

            case XLValueType::Float:
                cout << "XLValueType::Float and the value is " << cell.value().get<double>() << endl;
                break;

            case XLValueType::Integer:
                cout << "XLValueType::Integer and the value is " << cell.value().get<int64_t>() << endl;
                break;

            default:
                cout << "Unknown";
        }
    };
    char cell_selected[5];
    int count = 1;
    float last_val = 0;
    float current_val = 0;
    do
    {
        memset(cell_selected,0,sizeof(cell_selected));
        sprintf(cell_selected,"B%d",count);
        count++;
        if(wks2.cell(cell_selected).valueType() == XLValueType::Float)
        {
            current_val = (float) wks2.cell(cell_selected).value().get<double>();
            if(last_val != current_val)
            {
                last_val = current_val;
                cout << "value is " << current_val << endl;
            }
        }
    }while(wks2.cell(cell_selected).valueType() != XLValueType::Empty);
    
    doc2.close();

    Plotdata x(-3.0, 3.0), y = sin(x) - 0.5*x;
    plot(x, y);
    /*
    Acel[0] = 0.390987;
    Acel[1] = 0.390987;
    Acel[2] = 0.390987;
    Acel[3] = 0.410147;
    last_acel = Acel[3];
    Process_data();
    
    Acel[0] = last_acel;
    Acel[1] = 10;
    Acel[2] = -4;
    Acel[3] = 0;
    
    last_acel = Acel[3];
    */
    
    return 0;
}