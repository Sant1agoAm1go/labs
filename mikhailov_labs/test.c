#include <stdio.h>
#include <math.h>
double my_func (double a, double y, double n, double m, int *k) 
double yn = pow(a,1/n);
while (fabs(y-yn)m){ 
y = y/(n*n)*((n*n-1)+1/2*(n+1)*a/(pow(y,n)-1/2*(n-1)*pow(y,n)/a));
printf("%lf\n",y);
*k = *k + 1;
}
printf("Количество членов: ");
printf("%d\n",*k);
return y;
}
int main(){ 
double a, y, n, m;
int i = 0;
printf("Введите переменную а, нулевой член y0, корень n и точность m:\n");
scanf("%lf %lf %lf %lf",a,y,n, m);
while (y > a){ 
printf("Ошибка\n");
scanf("%lf %lf %lf %lf",a,y,n, m);
}
double s = my_func(a,y,n,m,i);
printf("Мой корень: ");
printf("%.15lf\n",s);
printf("Мат. корень: %.15lf\n", pow(a,1/n));

return 0;
}
