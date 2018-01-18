#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#define size 5
#define size2 8
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int length = size, length2 = size2, task;
	
	do
	{
		cout << "Введите номер задания - ";
		cin >> task;
		
		switch (task)
		{
			case 1:
			{
				/*1.	Дан квадратный массив из n элементов.Найти произведение элементов первой строки*/
				int m[4][4], mul = 1, mul2;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						m[i][j] = -50 + rand() % 100;
						cout << "Index I = " << i << ", Index J = " << j << " == "<< m[i][j] << endl;
					}
				}
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (i == 0)
						{	
							mul2 = mul;
							mul *= m[i][j]; 
							cout << m[i][j] << " * " << mul2 << " == " << mul << endl;
						}
					}
				} cout << "Сумма произведений первой строки = " << mul << endl;

			} break;

			case 2:
			{
				/*2.	Дана целочисленная квадратная матрица.Написать программу упорядочения ее строк по возрастанию сумм их элементов*/
				int m[4][4], m2[4], sum0 = 0, sum1 = 0, sum2 = 0, sum3 =0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						m[i][j] = -50 + rand() % 100;
						cout << "Index I = " << i << ", Index J = " << j << " == " << m[i][j] << endl;
					}
				}
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (i == 0)
						{
							sum0 += m[i][j];
							m2[i] = sum0;
						}	
						if (i == 1)
						{
							sum1 += m[i][j];
							m2[i] = sum1;
						}
							
						if (i == 2)
						{
							sum2 += m[i][j];
							m2[i] = sum2;
						}	
						if (i == 3)
						{
							sum3 += m[i][j];
							m2[i] = sum3;
						}
							
					}
				}
			
				for (int i = 0; i < 4; i++)
				{
					for (int j = 4 - 1; j >= 0; j--)
					{
						if (m2[j - 1] > m2[j])
						{
							int temp = m2[j - 1];
							m2[j - 1] = m2[j];
							m2[j] = temp;
						}
					}
				}
				cout << "\nСортировка -- " << endl;
				for (int i = 0; i < 4; i++)
				{
					cout << m2[i] << endl;
				}
			} break;

			case 3:
			{
				/*3.	Дана целочисленная матрица размера 5×10.Найти минимальное значение среди сумм элементов всех ее строк*/
				int m[5][10], sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, m2[5], min;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						m[i][j] = -50 + rand() % 100;
						cout << "Index I = " << i << ", Index J = " << j << " == " << m[i][j] << endl;
					}
				}
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						if (i == 0)
						{
							sum0 += m[i][j];
							m2[i] = sum0;
						}
						if (i == 1)
						{
							sum1 += m[i][j];
							m2[i] = sum1;
						}

						if (i == 2)
						{
							sum2 += m[i][j];
							m2[i] = sum2;
						}
						if (i == 3)
						{
							sum3 += m[i][j];
							m2[i] = sum3;
						}
						if (i == 4)
						{
							sum4 += m[i][j];
							m2[i] = sum4;
						}
					}
				} 
				cout << "Суммы = " << endl;
				for (int i = 0; i < 5; i++)
				{	
					cout << m2[i] << endl;
					if (i == 0)
						min = m2[i];
					else if (m2[i] < min)
						min = m2[i];
				}
				cout << "Минимальное значение сумм строк = " << min << endl;

			} break;

			case 4:
			{
				/*4.	В произвольной матрице - отсортировать по убыванию элементы последовательности, расположенные после второго отрицательного числа.*/
				int m[4][4], count = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						m[i][j] = -50 + rand() % 100;
						cout << "Index I = " << i << ", Index J = " << j << " == " << m[i][j] << endl;
					}
				}
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (m[i][j] < 0)
						{
							count++;
							if(count == 2)
								for (int a = i; a < 4; a++)
								{
									for (int b = 4 - 1; b >= i; b--)
									{
										if (m[i][a - 1] < m[i][a])
										{
											int temp = m[i][a - 1];
											m[i][a - 1] = m[i][a];
											m[i][a] = temp;
										}
									}
								}
						}
					}
				}
				cout << "\n\n" << endl;
				count = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (m[i][j] < 0)
						{
							count++;
							if (count == 2)
							{
								for (int a = i; a < 4; a++)
								{
									for (int b = i; b < 4; b++)
									{
										cout << "Index I = " << i << ", Index J = " << j << " == " << m[i][j] << endl;
									}
								}
								
							}
						}
					}

				}
			} break;

			case 5:
			{
				/*5.	Дан массив A(n, m).Удалить строки массива, не имеющие ни одного повторяющегося элемента*/
				int m[4][4], count = 0;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						m[i][j] = -50 + rand() % 100;
						cout << m[i][j] << "\t";
						if (j == 4 - 1)
							cout << "\n";
					}
				}
				system("pause");
				for (int i = 0; i < 4; i++)
				{
					for (int j = 1; j < 4; j++)
					{
						if (m[i][j] == m[i][j - 1])
						{
							count++;
							cout << m[i][j] << " && " << m[i][j - 1] << endl;
						}
						else if (count == 0)
						{
							for (int a = i; a < 4; a++)
							{
								for (int b = 0; b < 4; b++)
								{
									m[a][b] = 0;
									cout << "Index I = " << a << "Index J = " << b << ", ==== " << m[a][b] << endl;
								}
							}
						}
					}
				}
			} break;

			case 6:
			{
				/*Элементы матрицы A сделать с помощью генератора случайных чисел.
					Сделать новую матрицу B, в которой удалить с матрицы А ряд, 
					в котором минимальный элемент среди элементов главной диагонали*/
				int m[5][5], n[5][5], min, index;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						m[i][j] = 10 + rand() % 100;
						cout << m[i][j] << "\t";
					} cout << endl;
				}
				for (int i = 0; i < 5; i++)
				{
					if (i == 0)
					{
						min = m[i][i];
						index = i;
					}
					else if (m[i][i] < min)
					{
						min = m[i][i];
						index = i;
					}
				}
				cout << "===============" << endl;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{	
						if (index == i)
							m[i][j] = 0;
						n[i][j] = m[i][j];
					}
				}
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{	
						if (i != index)
						{
							cout << n[i][j] << "\t";
							if (j == 4)
								cout << endl;
						}	
					} 
				}

				
			} break;

			case 7:
			{
				int const n = 11;
				int A[n][n];
				int i = 1, j, k, p = n / 2;
				for (k = 1; k <= p; k++)/*Цикл по номеру витка*/
				{
					for (j = k - 1; j<n - k + 1; j++) 
						A[k - 1][j] = i++;/*Определение значений верхнего гор столбца*/
					for (j = k; j<n - k + 1; j++)
						A[j][n - k] = i++;/* --//-- По правому вертикальному столбцу*/
					for (j = n - k - 1; j >= k - 1; --j) 
						A[n - k][j] = i++;/* --//-- по нижнему горизонтальному столбцу*/
					for (j = n - k - 1; j >= k; j--) 
						A[j][k - 1] = i++;/* --//-- по левому вертикальному столбцу*/
				}
				if (n % 2 == 1) A[p][p] = n*n;
				for (i = 0; i<n; i++)
					for (j = 0; j<n; j++)
					{
						printf(" %4d ", A[i][j]);
						if (j == n - 1) printf("\n");
					}
			} break;

			case 22:
			{
				int m[5][5], p = 5 / 2;
				for (int i = 1; i <= p; i++)
				{

				}
			} break;

			case 8:
			{
				/*Написать программу, которая в матрице чисел A(N, M) находит все элементы, равные числу, введенному с клавиатуры.Подсчитать число таких элементов*/
				int m[size][size2], a, count = 0;
				cout << "Введите число а - ";
				cin >> a;
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length2; j++)
					{
						m[i][j] = 0 + rand() % 100;
						if (m[i][j] == a)
							count++;
						cout << m[i][j] << "\t";
					} cout << endl;
				} 
				cout << "Кол-во элементов равное числу " << a << " === " << count << endl;
			} break;

			case 9:
			{
				/*9.	Дана целочисленная матрица размера 5х5. Заменить в данной матрице все отрицательные элементы первой строки числом 0. */
				int m[5][5];
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						m[i][j] = -50 + rand() % 100;
						cout << m[i][j] << "\t";
						if (j == 5 - 1)
							cout << "\n";
					}
				}
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						if (i == 0)
							if (m[i][j] < 0)
								m[i][j] = 0;
					}
				}
				cout << "\n";
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						cout << m[i][j] << "\t";
						if (j == 5 - 1)
							cout << "\n";
					}
				}

			} break;

			case 10:
			{
				/*Дана целочисленная прямоугольная матрица размера M·N.
					Отсортировать каждый столбец с четным номером по неубыванию, а каждый  столбец с нечетным номером - по невозрастанию.*/
				int m[size][size2];
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length2; j++)
					{
						m[i][j] = -50 + rand() % 100;
						cout << m[i][j] << "\t";
					} cout << endl;
				} 
				/*for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length2; j++)
					{
						for (int k = 0; k < length2 - 1; k++)
						{
							if (m[i][k] > m[i][k + 1])
							{
								int temp = m[i][k];
								m[i][k] = m[i][k + 1];
								m[i][k + 1] = temp;
							}
						}
					}
				}*/
				for (int j = 0; j < length2; j++)
				{
					if (j % 2 == 0)
					{
						for (int i = 0; i < length; i++)
						{
							for (int b = 0; b < length - 1; b++)
							{
								if (m[j][b] > m[j][b + 1])
								{
									int temp = m[j][b];
									m[j][b] = m[j][b + 1];
									m[j][b + 1] = temp;
								}
							}
						}
					}
					else
					{
						for (int i = 0; i < length; i++)
						{
							for (int b = 0; b < length - 1; b++)
							{
								if (m[j][b] < m[j][b + 1])
								{
									int temp = m[j][b];
									m[j][b] = m[j][b + 1];
									m[j][b + 1] = temp;
								}
							}
						}
					}		
				}
				cout << "==========" << endl;
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length2; j++)
					{
						cout << m[i][j] << "\t";
					} cout << endl;
				}
				

			} break;

			case 11:
			{	
				/*Дана целочисленная прямоугольная матрица размера M·N.Сформировать одномерный массив, 
					состоящий из элементов, лежащих в интервале[1, 20].Найти среднеарифметическое  полученного одномерного массива*/
				int m[size][size], m2[size], sum = 0;
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length; j++)
					{
						m[i][j] =  + rand() % 19;
						cout << m[i][j] << "\t";
					}
					cout << endl;
				} for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length; j++)
					{
						if (m[i][j] >= 1 && m[i][j] <= 20)
							m2[j] = m[i][j];
						cout << m2[j] << "\t";
					} cout << endl;
				}
			
				//int m[5][5];
				//for (int i = 0; i < 5; i++)
				//{
				//	for (int j = 0; j < 5; j++)
				//	{
				//		m[i][j] = -50 + rand() % 100;
				//		cout << m[i][j] << "\t";
				//		if (j == 4)
				//			cout << "\n";
				//	}
				//}
				//cout << "\n=========" << endl;
				//int x, y;

				////применяем пузырьковый метод сортировки 


				//for (int i = 0; i < 5; i++)
				//{
				//	/*for (int j = 0; j < 5; j++)
				//	{*/
				//		for (int p = 4; p >= 0; p--)
				//		{
				//			if (m[i][p] < m[i][p - 1])
				//			{
				//				int temp = m[i][p];
				//				m[i][p] = m[i][p - 1];
				//				m[i][p - 1] = temp;
				//			}
				//		}

				//	/*}*/
				//}

				//cout << "\n *-* =========" << endl;

				//for (int i = 0; i < 5; i++)
				//{
				//	for (int j = 0; j < 5; j++)
				//	{
				//		cout << m[i][j] << "\t";
				//	}
				//	cout << endl;
				//}
				//cout << "\n *-* =========" << endl;

				//for (y = 0; y < 5; y++)
				//{
				//	for (int i = 0; i < (5 - 1); i++)
				//	{
				//		if (m[i][0] > m[i + 1][0])
				//		{
				//			for (int j = 0; j < 5; j++)
				//			{
				//				x = m[i][j];
				//				m[i][j] = m[i + 1][j];
				//				m[i + 1][j] = x;
				//			}
				//		}
				//	}
				//}
				//for (int i = 0; i < 5; i++)
				//{
				//	for (int j = 0; j < 5; j++)
				//	{
				//		cout << m[i][j] << "\t";
				//		if (j == 4)
				//			cout << "\n";
				//	}
				//}

			} break;

			case 12:
			{
				/*12.	Дана матрица целых чисел размера NxM.Вывести номер строки, содержащей минимальное число одинаковых элементов*/
				int m[5][10], min = 0, count = 0, count2, index = 0;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						m[i][j] = 0 + rand() % 10;
						cout << m[i][j] << "\t";
					} cout << endl;
				}
				for (int i = 0; i < 5; i++)
				{	
					count = 0;
					for (int j = 1; j < 10; j++)
					{
						if (m[i][j] == m[i][j - 1])
						{
							count++;
							count2 = count;
						}
					}
					cout << "В строке " << i << " кол-во одинаковых элементов - " << count << endl;

				}
			} break;
			case 21:
			{
				const int N = 5;
				int m[N][N];

				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
					{
						m[i][j] = -50 + rand() % 100;
						cout << m[i][j] << "\t";
						if (j == N - 1)
							cout << "\n";
					}
						

				int s[N], n[N][N];

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++)
						for (int k = j + 1; k < N; k++)
							if (m[i][j] == m[i][k])
								n[i][j]++;
					int maxCount = 0;
					for (int j = 0; j < N; j++)
						if (n[i][j] > maxCount)
							maxCount = n[i][j];
					s[i] = maxCount + 1;
					cout << s[i] << " ";
				}

				cout << "nn";

				for (int i = 0; i < N; i++) {
					int maxCount = s[i];
					int index = i;
					for (int j = i + 1; j < N; j++)
						if (s[j] > maxCount) {
							maxCount = s[j];
							index = j;
						}

					int temp = s[i];
					s[i] = maxCount;
					s[index] = temp;

					for (int k = 0; k < N; k++) {
						temp = m[i][k];
						m[i][k] = m[index][k];
						m[index][k] = temp;
					}
				}

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++)
						cout << m[i][j] << " ";
					cout << endl;
				}
			} break;

			case 16:
			{
				/*16.	Разработать программу, реализующую обработку числового двухмерного произвольного массива тремя методами сортировки(пузырьком, вставкой, выбором).*/
				int m[size][size2], min;
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length2; j++)
					{
						m[i][j] = -50 + rand() % 100;
						cout << m[i][j] << "\t";
					} cout << endl;
				} 
				cout << "\nСОРТИРОВКА ПУЗЫРЬКОМ" << endl;
				for (int i = 0; i < length; i++)
				{
					if (i % 2 == 0)
					{
						for (int j = 0; j < length2; j++)
						{
							for (int b = 0; b < length2 - 1; b++)
							{
								if (m[i][b] > m[i][b + 1])
								{
									int temp = m[i][b];
									m[i][b] = m[i][b + 1];
									m[i][b + 1] = temp;
								}
							}
						}
					}
					else
					{
						for (int j = 0; j < length2; j++)
						{
							for (int b = 0; b < length2 - 1; b++)
							{
								if (m[i][b] < m[i][b + 1])
								{
									int temp = m[i][b];
									m[i][b] = m[i][b + 1];
									m[i][b + 1] = temp;
								}
							}
						}
					}
					
				}
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length2; j++)
					{
						cout << m[i][j] << "\t";
					} cout << endl;
				}
				cout << "\nНовый массив " << endl;

				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length2; j++)
					{
						m[i][j] = -50 + rand() % 100;
						cout << m[i][j] << "\t";
					} cout << endl;
				}
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length2; j++)
					{
						min = j;
						for (int k = 0; k < length2; k++)
						{
							if (m[i][k] > m[i][min])
								min = k;
						}
						int temp = m[i][j];
						m[i][j] = m[i][min];
						m[i][min] = temp;
					}
				}
				cout << "\nСОРТИРОВКА" << endl;
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length2; j++)
					{
						cout << m[i][j] << "\t";
					} cout << endl;
				}
				/*int m[size], min, temp;
				for (int i = 0; i < size; i++)
				{
					m[i] = -100 + rand() % 200;
					cout << m[i] << endl;
				}
				cout << "=============" << endl;
				for (int i = 0; i < size; i++)
				{
					min = i;
					for (int j = i + 1; j < size; j++)
					{
						if (m[j] > m[min])
							min = j;
					}
					temp = m[i];
					m[i] = m[min];
					m[min] = temp;
				}*/

			} break;

			case 33:
			{	
				int m[size][size2];
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length2; j++)
					{	
						m[i][j] = -50 + rand() % 100;
						cout << m[i][j] << "\t";
					} cout << endl;
				}
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length2; j++)
					{
						for (int k = 0; k < length2 - 1; k++)
						{
							if (m[i][k] > m[i][k + 1])
							{
								int temp = m[i][k];
								m[i][k] = m[i][k + 1];
								m[i][k + 1] = temp;
							}
						}
					}
				}
				cout << "======" << endl;
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length2; j++)
					{
						cout << m[i][j] << "\t";
					} cout << endl;
				}
				/*for (int i = 0; i < col; i++)
				{
					for (int j = 0; j < row; j++)
					{
						for (int k = 0; k < col; k++)
						{
							if (mas[i, j] < mas[i, k])
							{
								int tmp = mas[i][j];
								mas[i][j] = mas[i][k];
								mas[i][k] = tmp;
							}
						}
					}
				}*/
			} break;

		}
	} while (task < 17);


}