#include <OpenXLSX.hpp>
#include <iostream>
#include <stdio.h>
#include <cmath> // math.h
#include <vector>
#include "lagrange.h"
#include "matplotlibcpp.h"

using namespace std;
using namespace OpenXLSX;
namespace plt = matplotlibcpp;

float stimes[DATA_BUFER] = {0*SAMPLE_TIME, 1*SAMPLE_TIME, 2*SAMPLE_TIME};
float Acel[DATA_BUFER];

Acel_eq acel_vect {0,0,0,0};
Vel_eq  vel_vect  {0,0,0,0,0};
Pos_eq  pos_vect  {0,0,0,0,0,0};
float   last_acel = 0;
vector<double> velocity_plot;
vector<double> position_plot;
vector<double> time_axis;
float time_marks = 0;
int simpsons_factors[]= {1,3,3,1};


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
        // acel_vect.offset += rate * mul;
        
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
    acel_vect.offset = Acel[0];
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
    //printf("input data: \r\n");
    //for(int i=0;i<DATA_BUFER;i++)
    //{
    //    printf("(%.3f,%.3f)\r\n",stimes[i],Acel[i]);
    //}
    //Get polinimal factors
    Calculate_polynomial();
    //integrate acel
    //integrate_accel();
    //integrate vel
    //integrate_vel();

    printf("aceleracion: %.3fx^3 + %.3fx^2+ %.3fx+ %.3f\r\n",acel_vect.A,acel_vect.B,acel_vect.C,acel_vect.offset);
    //printf("velocidad:   %.3fx^4 + %.3fx^3+ %.3fx^2+ %.3fx + %.3f\r\n",vel_vect.A,vel_vect.B ,vel_vect.C ,vel_vect.D,vel_vect.offset);
    //printf("posicion:    %.3fx^5 + %.3fx^4+ %.3fx^3+ %.3fx^2 + %.3fx+%.3f\r\n",pos_vect.A , pos_vect.B , pos_vect.C , pos_vect.D , pos_vect.E , pos_vect.offset);
    
    float vel_point;
    //float pos_point;
    for(float i=0; i < DATA_BUFER;i+=.5)
    {
        vel_point  = acel_vect.A*pow(i,3) + acel_vect.B*pow(i,2) + acel_vect.C + acel_vect.offset;
        //vel_point = vel_vect.A*pow(i,4) + vel_vect.B*pow(i,3) + vel_vect.C*pow(i,2) + vel_vect.D*i+vel_vect.offset;
        velocity_plot.push_back(vel_point);
        time_axis.push_back(time_marks);
        time_marks+=.5;
    }


}

main()
{ 
    XLDocument doc2;
    doc2.open("./muestras.xlsx");
    vector<double> acelerations;

    acelerations.reserve(200);
    velocity_plot.reserve(400);
    position_plot.reserve(400);
    time_axis.reserve(400);

    auto wks2 = doc2.workbook().worksheet("5cmDERECHA");

    char cell_selected[5];
    int count = 1;
    float last_val = 0;
    float current_val = 0;
    float diff = 0;


    char interpolation_index = 0;
    float simpsons_sum = 0;
    float velocity_area = 0;
    float last_area = 0;
    char simp_index = 0;
    int increment_time = 0;
    do
    {
        memset(cell_selected,0,sizeof(cell_selected));
        sprintf(cell_selected,"B%d",count);
        count++;
        if(wks2.cell(cell_selected).valueType() == XLValueType::Float)
        {
            current_val = (float) wks2.cell(cell_selected).value().get<double>();
            diff = abs(current_val-last_val);

            if(last_val != current_val && (diff>.03))
            {
                last_val = current_val;
                simpsons_sum += simpsons_factors[simp_index++]*current_val;
                acelerations.push_back(current_val);
                cout<<current_val<<", ";
            }
            if(simp_index == DATA_BUFER)
            {
                cout<<"sum"<<simpsons_sum<<endl;
                simpsons_sum = (simpsons_sum)*3/8;
                simpsons_sum = (simpsons_sum)*(DATA_BUFER-1)/DATA_BUFER;
                velocity_area = simpsons_sum-.4;
                velocity_plot.push_back(velocity_area);
                increment_time+=DATA_BUFER;
                time_axis.push_back(increment_time);
                simp_index = 0;
                simpsons_sum = 0;
                cout<<endl;

            }
        }
    }while(wks2.cell(cell_selected).valueType() != XLValueType::Empty);
    
    doc2.close();
    
    plt::named_plot("aceleration",acelerations);
    plt::named_plot("velocity",time_axis,velocity_plot);
    plt::legend();
    plt::show();
    
    return 0;
}