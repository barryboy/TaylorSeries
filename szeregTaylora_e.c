#include <stdio.h>
#include <math.h>

long silnia(int n){
	if (n < 2) return 1L;
	return silnia(n-1)*n;
}

long double e_to_X(double x, int n)
{
	long double suma = 0.0L;
        int i;	
	for (i = 0; i < n; i++)
	{
		suma += pow(x,i) / silnia(i);
	}
	return suma;
}

int main()
{
	int n;
	double x;
	double mathe;
	
	printf("Podaj wartość X0:\n");
	scanf("%lf",&x);
	printf("Podaj dlugość szeregu:\n");
	scanf("%d",&n);
	printf("dl. ciągu\tTaylor e^(%lf)\tmath.h e^%lf\n", x, x);
	mathe = pow(M_E,x);
	int i;
	for (i=1; i<n+1; i++){
		long double wynik = e_to_X(x,i);
		printf("%d\t\t%llf\t\t%lf\n", i, wynik, mathe);
	}
	
	return 0;
}
