#ifndef DISTRIBUTION_H
#define DISTRIBUTION_H

#include <iostream>
#include "../IDistribution.h"
#include "../Exception.h"
#include <fstream>
#include <string>

using namespace std;
/*
    Класс для основного распределения
*/
class Distribution : public IDistribution {
private:
    float v;  // Форма
    float u;  // Сдвиг
    float l;  // Масштаб

    // Возвращает характеристики распределения
    double* properties() const;

protected:
    double math() const; 
    double disp() const;
    double y1() const;
    double y2() const;

public:
    // Конструктор с чтением из файла
    Distribution(ifstream &stream);
    Distribution();
    // Базовый конструктор
    Distribution(float v, float u, float l);

    // Моделирование случайной величины
    double modeling() const;
    double* modelingPool(int size);
    // Плотность
    double density(float x) const override;
    // Характеристики распределения
    void getProperties() const final;

    // Сеттеры и геттеры
    double getV() const override;
    double getU() const override ;
    double getL() const override ;
    void setV(float v) override ;
    void setU(float u) override ;
    void setL(float l) override ;

    // Запись в файл
    void saveTofile(std::string path) const override;

    // Деструктор
    ~Distribution();
};

#endif
