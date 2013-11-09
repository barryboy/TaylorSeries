#include <stdio.h>
#include <math.h>

long silnia(int n){
	if (n < 2) return 1L;
	return silnia(n-1)*n;
}

long double cosinus(double x, int n){
	double suma = 0.0L;
        int i;	
	for (i = 0; i < n; i++)
	{
            suma += (pow(-1, i) / silnia(2 * i)) * pow(x,2 * i);
	}
	return suma;
}

int main()
{
	int n;
	double x;
	double mathcos;
	
	printf("Podaj wartość X0:\n");
	scanf("%lf",&x);
	if (x > 2 * M_PI or x < (-2) * M_PI)
	{
		printf("Przesuwamy wartość X0 do przedziału <-2PI, 2PI>\n");
		printf("X = %lf -->  ", x);
		while(x>2*M_PI or x<(-2)*M_PI)
                {
	    		if (x>0) x -= 2*M_PI;
                        else x += 2*M_PI;
                }
		printf("X = %lf\n", x);
	}
	printf("Podaj dlugość szeregu:\n");
	scanf("%d",&n);
	printf("dl. ciągu\tTaylor cos(%lf)\tmath.h cos(%lf)\n", x, x);
	mathcos = cos(x);
	int i;
	for (i=1; i<n+1; i++){
		double wynik = cosinus(x,i);
		printf("%d\t\t%lf\t\t%lf\n", i, wynik, mathcos);
	}
	
	return 0;
}
