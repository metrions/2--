#include <iostream>
#include "./impl/Distribution.h"
#include <fstream>

using namespace std;

void test(){
    ifstream in("./files/file.txt");

    Distribution dist;
    // Подстановка к интерфейсу
    IDistribution& elem = dist;

    if (elem.getV() != 1.5 || elem.getU() != 0 || elem.getL() != 1) throw Exception("Неправильное чтение");

    // Геттеры и сеттеры
    elem.setL(12);
    elem.setU(102);
    elem.setV(11);
    if (elem.getL() != 12 || elem.getU() != 102 || elem.getV() != 11) {
        throw Exception("Неправильная реализация сеттеров и геттеров");
    }
    
    // Неправильные значения для сеттеров и геттеров
    try{
        elem.setL(0);
        cout << "Неправильный выброс для сеттера L";
    }
    catch(Exception exc){}

    try{
        elem.setV(-12);
        cout << "Неправильный выброс для сеттера V";
    }
    catch(Exception exc){}
    // Чтение из файла в файле (1, 2, 3)
    Distribution newDist(in);
    // Подстановка к интерфейсу
    IDistribution& newElem = newDist;

    // Запись в файл
    newElem.saveTofile("./files/newfile.txt");
    ifstream newFile("./files/newfile.txt");
    float value1;
    float value2;
    float value3;
    newFile >> value1;
    newFile >> value2;
    newFile >> value3;
    if (value1 != 1.5 || value2 != 1 || value3 != 1){
        throw new Exception("Wrong writing to file");
    }
    // Вывод значений
    newElem.getProperties();
}

/*
    Тестирующая функция
*/
int main(){
    test();
    // ifstream in("./files/file.txt");
    // Distribution newDist(in);
    // IDistribution& newElem = newDist;

}