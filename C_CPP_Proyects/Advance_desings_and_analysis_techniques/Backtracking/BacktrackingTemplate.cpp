#include <iostream>
#include <vector>
#define MAXCANDIDATES 2


bool finished = false;

bool is_a_solution(int a[],int k,int n)
{
    return (k==n);
}
void construct_candidates(int a[],int k,int n, int c[],int* ncandidates)
{
    c[0] = true;
    c[1] = false;
    *ncandidates = 2;
}

void process_solution(int a[],int k)
{
    int i;
    printf("{");
    for(i=1;i<=k;i++)
    {
        if(a[i]==true)
        {
            printf("%d ",i);
        }
    }
    printf("}\n");
}


void backtrack(int a[], int k,int input)
{
    int c[MAXCANDIDATES];
    int ncandidates;
    int i;
    if(is_a_solution(a,k,input))
    {
        process_solution(a,k);
    }
    else
    {
        k++;
        construct_candidates(a,k,input,c,&ncandidates);
        for(i=0;i<ncandidates;i++)
        {
            a[k]=c[i];
            printf("k: %d,i: %d a:[%d,%d,%d,%d]\r\n",k,i,a[0],a[1],a[2],a[3]);
            backtrack(a,k,input);
            if(finished) return;
        }
    }
}

void generate_subsets(int n)
{
    int a[4] = {0};
    backtrack(a,0,n);
}

int main(int argc, char const *argv[])
{
    generate_subsets(3);
    return 0;
}
