#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100

float givenFunc(float, float);
float analyticSolution(float);

int main()
{
	float start, finish, step, indepVar, solutionN[N];
	float m1, m2, m3, m4; 
	int k;

	start=1; finish=2; step=(finish-start)/(N-1);
	solutionN[0]=1;

	for (k=0; k<N; k++)
	{
		indepVar=k*step;
		m1=step*givenFunc(indepVar, solutionN[k]);
		m2=step*givenFunc(indepVar+step/2, solutionN[k]+m1/2);
		m3=step*givenFunc(indepVar+step/2,solutionN[k]+m2/2);
		m4=step*givenFunc(indepVar+step, solutionN[k]+m3);
		solutionN[k+1]=solutionN[k]+(m1+2*m2+2*m3+m4)/6;
	};

	for (k=1; k!=N; k++)
	{
		indepVar=k*step;
		printf("numerical =%5.2f|\t| analytical =%5.2f\n", solutionN[k], analyticSolution(indepVar));
	}
	//return();
}

float givenFunc(float x, float y)
{
	return pow(x,2)-y/(2*x);
}

float analyticSolution(float x)
{
	return 2/7*pow(x,3) + 5/(7*sqrt(x));
			}
