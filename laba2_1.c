#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100 // Разбиение заданного участка определяется константой

float givenFunc(float, float); //Инициализация производной функции (т.н. "правая часть").
float analyticSolution(float); //Инициализация функции аналитического решения.

int main()
{
	float start, finish, step, indepVar, solutionN[N]; // Инициализация переменных начала, конца участка вычисления, шага разбиения, координаты 'x', массива решений "диффура" в точке.
	float m1, m2, m3, m4; // Инициализация вспомогательных переменных  
	int k;//Инициализация переменной-итератора.           

	start=1; finish=2; step=(finish-start)/(N); // Присваивание переменным соответствующих значений
	solutionN[0]=1;// Решение "диффура" в начальной точке по условию задачи

	for (k=0; k<N; k++)// Цикл реализует решение "диффуров" методом Рунге-Кутта(ы) четвертого порядка 
	{
		indepVar=start+k*step; // Вычисление "икса" с учетом шага разбиения
		m1=givenFunc(indepVar, solutionN[k]);
		m2=givenFunc(indepVar+step/2, solutionN[k]+step*m1/2);
		m3=givenFunc(indepVar+step/2,solutionN[k]+step*m2/2);
		m4=givenFunc(indepVar+step, solutionN[k]+step*m3);
		solutionN[k+1]=solutionN[k]+step*(m1+2*m2+2*m3+m4)/6;
		
		printf("Numerical = %.7f | %d.step | Analytical = %.7f\n", solutionN[k],k+1, analyticSolution(indepVar)); // Сравнение результатов вычисления решений "диффура" численно и аналитически с указанием шага. Количество знаков после запятой увеличено для наблюдения погрешности, т.к. метод Рунге-Кутта считается довольно точным, погрешности начинают появлятся после 4-го, 5-го знака после запятой
	};

/*	for (k=0; k<N; k++)
	{
		indepVar=start+k*step;
		printf("Numerical = %.2f | %d.step | Analytical = %.2f\n", solutionN[k],k+1, analyticSolution(indepVar));
	} */ // Решение из методички, хотя ничто не мешает вынести вывод результатов на экран в цикл с вычислениями
	//return();
}

float givenFunc(float x, float y) //Функция возварщает заданную "правую часть". Предусмотрены параметры для вычислений
{
	return pow(x,2)-y/(2*x);
}

float analyticSolution(float x) // Функция возвращает аналитическое, точное решение. Параметром является координата 'x' на заданном отрезке.
{
	return (2*pow(x,3))/7 + 5/(7*sqrt(x));
			}
