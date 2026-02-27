#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <string>

using namespace std;

/**
 * Класс Rectangle представляет прямоугольник
 */
class Rectangle {
private:
    double width;   // Ширина прямоугольника
    double height;  // Высота прямоугольника

public:
    /**
     * Конструктор прямоугольника
     * @param w - ширина
     * @param h - высота
     * @throws invalid_argument если ширина или высота <= 0
     */
    Rectangle(double w, double h) {
        if (w <= 0 || h <= 0) {
            throw invalid_argument("Ширина и высота должны быть положительными числами");
        }
        width = w;
        height = h;
    }

    /**
     * Вычисляет периметр прямоугольника
     * Формула: P = 2 * (a + b)
     * @return периметр
     */
    double perimeter() const {
        return 2 * (width + height);
    }

    /**
     * Вычисляет площадь прямоугольника
     * Формула: S = a * b
     * @return площадь
     */
    double area() const {
        return width * height;
    }

    /**
     * Вычисляет длину диагонали прямоугольника
     * Формула: d = √(a² + b²) - по теореме Пифагора
     * @return длина диагонали
     */
    double diagonal() const {
        return sqrt(width * width + height * height);
    }

    /**
     * Возвращает ширину прямоугольника
     */
    double getWidth() const {
        return width;
    }

    /**
     * Возвращает высоту прямоугольника
     */
    double getHeight() const {
        return height;
    }

    /**
     * Выводит информацию о прямоугольнике
     */
    void print() const {
        cout << "╔════════════════════════════════════════╗" << endl;
        cout << "║         ПРЯМОУГОЛЬНИК                  ║" << endl;
        cout << "╠════════════════════════════════════════╣" << endl;
        cout << "║ Ширина:           " << setw(20) << fixed << setprecision(2) << width << " ║" << endl;
        cout << "║ Высота:           " << setw(20) << fixed << setprecision(2) << height << " ║" << endl;
        cout << "╠════════════════════════════════════════╣" << endl;
        cout << "║ Периметр:         " << setw(20) << fixed << setprecision(2) << perimeter() << " ║" << endl;
        cout << "║ Площадь:          " << setw(20) << fixed << setprecision(2) << area() << " ║" << endl;
        cout << "║ Длина диагонали:  " << setw(20) << fixed << setprecision(2) << diagonal() << " ║" << endl;
        cout << "╚════════════════════════════════════════╝" << endl;
    }
};

int main() {
    cout << "=== Программа вычисления параметров прямоугольника ===" << endl << endl;

    // Тестовые данные
    double testCases[][2] = {
        {5.0, 3.0},
        {10.0, 8.0},
        {7.5, 4.2},
        {12.3, 6.7}
    };

    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTests; i++) {
        cout << "Тест " << (i + 1) << ":" << endl;
        try {
            Rectangle rect(testCases[i][0], testCases[i][1]);
            rect.print();
        } catch (const invalid_argument& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
        cout << endl;
    }

    // Пример с некорректными данными
    cout << "Тест с некорректными данными:" << endl;
    try {
        Rectangle invalidRect(-5, 3);
    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
