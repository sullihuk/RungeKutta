#include <math.h>
#include <stdio.h>
#define n 100

float f(float, float);
float ya(float);

int main (void)
{
	float a, b, h, x, y[n];
	float m1,m2,m3,m4; // дополнительные переменные
	int k;
	a=0; b=1; h=(b-a)/(n-1);
	y[0]=1;
	 // начальное условие
	for (k=0; k<n-1; k++) // метод Рунге - Кутты
	{
		x=k*h;
		m1=h*f(x,y[k]);
		m2=h*f(x+h/2,y[k]+m1/2);
		m3=h*f(x+h/2,y[k]+m2/2);
		m4=h*f(x+h,y[k]+m3);
		y[k+1]=y[k]+(m1+2*m2+2*m3+m4)/6;
	}

	// сравнение с аналитическим решением
	for (k=0; k<n; k++)
	{
		x=k*h;
		printf("numerical = %5.2f \t\t analytical = %5.2f\n",y[k],ya(x));
	}
}
float f(float x, float y) // правая часть
{
return 2*(x*x+y);
}
float ya(float x)
 // аналитическое решение
{
return 1.5*exp(2*x)-x*x-x-0.5;
}
