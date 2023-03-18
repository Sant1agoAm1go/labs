#include <stdio.h>
#include <math.h>
double my_exp (double  x, int n){
        double s = 1, p = 1;
        double y = pow(x,2);
        for(int i = 1; i < n+1; i++) {
                p = -p*y/i;
                s+=p;
        }
        return s;
}
int main() {
        double x;
        int n;
        printf("Введите степень x и точность n: ");
        scanf("%lf",&x);
        scanf("%d",&n);
        double s = my_exp(x,n);
        printf("Моя экспонента: ");
        printf("%lf\n",s);
        printf("Мат. экспонента: ");
        printf("%lf\n",exp(-x*x));
        printf("Равны ли они: ");
        printf("%d\n",fabs(s-exp(-x*x)) < 0.02);
        return 0;
}
