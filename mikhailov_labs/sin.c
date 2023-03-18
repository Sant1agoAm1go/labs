#include <stdio.h>
#include <math.h>
double my_sin (double x, int n) {
	double s = x, p = x;
	double y = pow(x,2);
	int i = 1;
	while (i<n){
		p = -p*y/(2*i*(2*i+1));
  		s+=p;
		i++;
	}
	return s;
}
int main() {
double x;
	int n;
	printf("Введите число x и точность n: ");
	scanf("%lf",&x);
	scanf("%d",&n);
	double s = my_sin(x,n);
	printf("Мой синус: ");
	printf("%lf\n",s);
	printf("Мат. синус: ");
	printf("%lf\n",sin(x));
	printf("Равны ли они: ");
	printf("%d\n",fabs(s-sin(x)) < 0.001);
	return 0;
}
