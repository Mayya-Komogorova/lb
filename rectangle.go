package main

import (
	"fmt"
	"math"
)

// Rectangle представляет прямоугольник с шириной и высотой
type Rectangle struct {
	Width  float64
	Height float64
}

// NewRectangle создает новый прямоугольник
func NewRectangle(width, height float64) (*Rectangle, error) {
	if width <= 0 || height <= 0 {
		return nil, fmt.Errorf("ширина и высота должны быть положительными числами")
	}
	return &Rectangle{Width: width, Height: height}, nil
}

// Perimeter вычисляет периметр прямоугольника
// Формула: P = 2 * (a + b)
func (r *Rectangle) Perimeter() float64 {
	return 2 * (r.Width + r.Height)
}

// Area вычисляет площадь прямоугольника
// Формула: S = a * b
func (r *Rectangle) Area() float64 {
	return r.Width * r.Height
}

// Diagonal вычисляет длину диагонали прямоугольника
// Формула: d = √(a² + b²) - по теореме Пифагора
func (r *Rectangle) Diagonal() float64 {
	return math.Sqrt(r.Width*r.Width + r.Height*r.Height)
}

// Print выводит информацию о прямоугольнике
func (r *Rectangle) Print() {
	fmt.Println("╔════════════════════════════════════════╗")
	fmt.Println("║         ПРЯМОУГОЛЬНИК                  ║")
	fmt.Println("╠════════════════════════════════════════╣")
	fmt.Printf("║ Ширина:           %-20.2f ║\n", r.Width)
	fmt.Printf("║ Высота:           %-20.2f ║\n", r.Height)
	fmt.Println("╠════════════════════════════════════════╣")
	fmt.Printf("║ Периметр:         %-20.2f ║\n", r.Perimeter())
	fmt.Printf("║ Площадь:          %-20.2f ║\n", r.Area())
	fmt.Printf("║ Длина диагонали:  %-20.2f ║\n", r.Diagonal())
	fmt.Println("╚════════════════════════════════════════╝")
}

func main() {
	fmt.Println("=== Программа вычисления параметров прямоугольника ===\n")

	// Тестовые данные
	testCases := []struct {
		width  float64
		height float64
	}{
		{5.0, 3.0},
		{10.0, 8.0},
		{7.5, 4.2},
		{12.3, 6.7},
	}

	for i, tc := range testCases {
		fmt.Printf("Тест %d:\n", i+1)
		rect, err := NewRectangle(tc.width, tc.height)
		if err != nil {
			fmt.Printf("Ошибка: %v\n\n", err)
			continue
		}
		rect.Print()
		fmt.Println()
	}

	// Пример с некорректными данными
	fmt.Println("Тест с некорректными данными:")
	_, err := NewRectangle(-5, 3)
	if err != nil {
		fmt.Printf("Ошибка: %v\n", err)
	}
}
