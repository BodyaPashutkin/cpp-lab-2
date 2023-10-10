#include <iostream>
#include <iomanip>

//делаем степень
long double stepen(long double baza, int stepen){
    long double resultat = 1;
    int i = 0;
    while (i<stepen){//for (int i = 0; i < stepen; i++){
        i++;
        resultat *= baza;
    }
    return resultat;
}
//делаем двойной факториал
long double double_factorial(long double znachenie){
    long double resultat = 1;
    //int k = znachenie;
    while (znachenie>0){//for (int k = value; k > 0; k-=2) {
        resultat *= znachenie;
        znachenie-=2;
    }
    return resultat;
}
//получение t
long double T(long double x){
    long double chislitel = 0;
    long double znamenatel = 0;
    int k = 0;
    while (k<=10){//for (int k = 0; k<=10; k++){
        long double podchislitel = stepen(x, (2*k+1));
        long double podznamenatel = double_factorial((2*k+1));
        chislitel += (podchislitel/podznamenatel);
        long double podchislitel_2 = stepen(x, 2*k);
        long double podznamenatel_2 = double_factorial(2*k);
        znamenatel += (podchislitel_2/podznamenatel_2);
        k++;
    }
    return chislitel/znamenatel;
}

//главная функция
int main(){
    long double y;
    std::cout << "Введите y: " << std::endl;//printf("Введите y: ");
    std:: cin >> y;//scanf("%Lf", &y);
    long double chislitel = (7 * T(0.25) + 2 * T(1 + y));
    long double znamenatel = (6 - T(stepen(y,2)-1));
    std:: cout << std:: setprecision(11) << chislitel/znamenatel << std::fixed; //printf("Результат: %.10Lf\n", result);
    return 0;
}