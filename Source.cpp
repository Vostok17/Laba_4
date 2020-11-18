#include <iostream>
#include <cmath>
#include <limits>		// ліміти				
#define PI 3.141592		// pi 
																	// якщо користовач введе дані неправильного типу, cin перейде у "режим відмови",
using namespace std;												// а усі наступні запити на зчитування даних будуть проігноровані 
								
int main()															
{																	
	double eps, x = 0, y1, y2 = 0;
	int n = 0;														// numeric_limtis <streamsize>::max() задає максимальне значення, яке може містити об'єкт streamsize
	
	// перевірка вхідних даних від користувача
	do
	{
		cout << "Usage: enter eps > 0.\n";					 
		cout << "eps = ";									
		cin >> eps;													
		if (!cin or eps <= 0)	// неправильний тип або eps <= 0												
		{
			cout << "\nUnaccaptable value of 'eps'\n\n";
			cin.clear();	// переведення cin у "звичайний режим"
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// видалення значения попереднього вводу з вхідного буфера
		}								// numeric_limits<streamsize>::max() задає максимальну кількість символів, які потрібно ігнорувати											
	}									// а ігнорування відбуватиметься до появи '\n' (користувач натиснув Enter)
	while (!cin or eps <= 0);
	cout << endl;

	// Обчислення інтегралу
	do
	{
		y1 = y2;
		y2 = 0;
		n++;

		for (int i = 1; i <= n; i++)
		{
			x = PI / n * (i - 0.5);
			y2 += log(2 + sin(x));
		}
		y2 *= PI / n;
		printf("y2 - y1 = %13.10lf		n = %i\n", y2 - y1, n);
		
	} while (abs(y2 - y1) > eps);

	cout << "\n|y2 - y1| <= eps\n";

	// вивід результату
	printf("\nintegral = %.10lf\n\n", y2);

	system("Pause");
}
