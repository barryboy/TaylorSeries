#include <stdio.h>
#include <math.h>

long silnia(int n){
	if (n < 2) return 1L;
	return silnia(n-1)*n;
}

double sinus(double x, int n){
	long mianownik; 
	double licznik;
	double suma = 0.0;
        int i;	
	for (i = 0; i < n; i++)
	{
            suma += (pow(-1, i) / silnia(2 * i + 1)) * pow(x,2 * i + 1);
	}
	return suma;
}

int main()
{
	int n;
	double x;
	double mathsin;
	
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
	printf("dl. ciągu\tTaylor sin(%lf)\tmath.h sin%lf)\n", x, x);
	mathsin = sin(x);
	int i;
	for (i=1; i<n+1; i++){
		double wynik = sinus(x,i);
		printf("%d\t\t%lf\t\t%lf\n", i,wynik, mathsin);
	}
	
	return 0;
}
