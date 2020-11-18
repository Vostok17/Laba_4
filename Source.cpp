#include <iostream>
#include <cmath>
#include <limits>		// ����				
#define PI 3.141592		// pi 
																	// ���� ���������� ����� ��� ������������� ����, cin ������� � "����� ������",
using namespace std;												// � �� ������� ������ �� ���������� ����� ������ ����������� 
								
int main()															
{																	
	double eps, x = 0, y1, y2 = 0;
	int n = 0;														// numeric_limtis <streamsize>::max() ���� ����������� ��������, ��� ���� ������ ��'��� streamsize
	
	// �������� ������� ����� �� �����������
	do
	{
		cout << "Usage: enter eps > 0.\n";					 
		cout << "eps = ";									
		cin >> eps;													
		if (!cin or eps <= 0)	// ������������ ��� ��� eps <= 0												
		{
			cout << "\nUnaccaptable value of 'eps'\n\n";
			cin.clear();	// ����������� cin � "��������� �����"
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// ��������� �������� ������������ ����� � �������� ������
		}															// numeric_limits<streamsize>::max() ���� ����������� ������� �������, �� ������� ����������													
	}																// � ����������� �������������� �� ����� '\n' (���������� �������� Enter)
	while (!cin or eps <= 0);
	cout << endl;

	// ���������� ���������
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

	// ���� ����������
	printf("\nintegral = %.10lf\n\n", y2);

	system("Pause");
}
