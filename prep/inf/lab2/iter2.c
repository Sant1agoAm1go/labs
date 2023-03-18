#include <stdio.h>
#include <math.h>
double iter2(double a, double y, double n, double m) {
        for(int i = 0; i < m; i++) {
                y = y/(n*n)*((n*n-1)+1/2*(n+1)*a/(pow(y,n)-1/2*(n-1)*pow(y,n)/a));
        }
        return y;
}

void checkInput(int h) {
    if (h == 0){
        scanf("%*s");
    }

}
int main() {
        double a, y, n , m;
    int flag = 1;
        printf("Введите переменную а, нулевой член y0, корень n  и количество членов  m:\n");
        while (flag) {
            int x = scanf("%lf", &a);
            checkInput(x);
            int b = scanf("%lf", &y);
            checkInput(b);
            int c = scanf("%lf", &n);
            checkInput(c);
            int d = scanf("%lf", &m);
            checkInput(d);
            if (x+b+c+d == 4) {
                    flag = 0;
            }
            else {
                    printf("Ошибка ввода!\n");
                    printf("Введены неправильные данные.\n");
                printf("Повторите ввод:\n");
            }
        }
        double s = iter2(a,y,n,m);
        printf("Значение: ");
        printf("%.15lf\n",s);
        printf("Мат. корень: %.15lf\n", pow(a,1/n));
        return 0;
}
