#include <iostream>

//делаем степень
long double pow(long double base, int pow){
    long double result = 1;
    for (int i = 0; i < pow; i++){
        result *= base;
    }
    return result;
}
//делаем двойной факториал
long double double_factorial(long double value){
    long double result = 1;
    for (int k = value; k > 0; k-=2) {
        result *= k;
    }
    return result;
}
//получение t
long double getT(long double x){
    long double numerator = 0;
    long double denominator = 0;
    for (int k = 0; k<=10; k++){
        long double subnumerator = pow(x, (2*k+1));
        long double denominator = double_factorial((2*k+1));
        numerator += (subnumerator/denominator);
    }
    for (int k = 0; k<=10; k++){
        long double subnumerator = pow(x, 2*k);
        long double subdenominator = double_factorial(2*k);
        denominator += (subnumerator/subdenominator);
    }
    long double result = (numerator/denominator);
    return result;
}
//Связующая функция
long double getResult(long double y){
    long double numerator = (7 * getT(0.25) + 2 * getT(1 + y));
    long double denominator = (6 - getT(pow(y,2)-1));
    return numerator/denominator;
}
//главная функция
int main(){
    long double y;
    printf("Введите y: ");
    scanf("%Lf", &y);
    long double result = getResult(y);
    printf("Результат: %.10Lf\n", result);
    return 0;
}