#define _CRT_SECURE_NO_WARNINGS

	#include <iostream>
	#include <fstream>
    #include <stdio.h>
	#include <cctype>

	using namespace std;
	void menu();
	void slov_v_stroke(int& n, int& c);
	void sort(char** a, int size);
	void line(int a[], int n);
	int main()
	{
		    setlocale(LC_ALL, "Russian");
		    int namber = 1;
		    while (namber != 0)
			    {
			        menu();
			        cout << "Задание № ";
			        cin >> namber;
			        switch (namber) {
			
			        case 1: {
					            int n = 0, c = 0, k = 0;
					            int size = 0;
					            slov_v_stroke(n, c);
					            char* arr[20]; //Массив
					            char* s = new char[100];
					            ifstream  fin("text.txt");
					            if (!fin) {
						                cout << "ошибка открытия файла" << endl;
						                return 1;
				}
					            while (!fin.eof())// Выдаёт истину, если файл пуст, а если файл не пуст, то выдаётся ложь
					           {
						                fin.getline(s, 100, '\n');// Выводим данные из потока
					                k++;
						                char  seps[] = " ,.;!?"; // Строка разделителей
						                char* token; // указатель на новой слово
						                token = strtok(s, seps);// находим первое слово
					
					
						                while (token != NULL) {
						                    if (k == c) { arr[size++] = token; /*tolower(arr[size][0]);*/ }
							                    token = strtok(NULL, seps); ;// выделяем следующее слово
					}
							            }
				
					            sort(arr, size); // Сортируем 
				
					
						            break;
					        }
		}
			    }
		}

	void menu()
	{
		    cout << "1 " << endl;
		    cout << "0 - EXIT" << endl;
		}

	void slov_v_stroke(int& n, int& c)
	{
		    char* s = new char[100];
		    ifstream  fin("text.txt");
		    if (!fin) {
		        cout << "ошибка открытия файла" << endl;
			        exit;
	}
    while (!fin.eof())
		    {
		        fin.getline(s, 100, '\n');
		        c++;
	        char  seps[] = " ,.;!?"; // Строка разделителей
		        char* token; // указатель на новой слово
		        token = strtok(s, seps);// находим первое слово
			        n = 0; //n - количество слов
		
				        while (token != NULL) {
			            token = strtok(NULL, seps); n++;// выделяем следующее слово
		}
			    }
		}
	void sort(char** a, int size)
{
		    char  seps[] = " ";
		    int* b = new int[size];
		    for (int i = 0; i < size; i++)
			    {
			        if (isupper(a[i][0]))//прописной символ ?
				        {
				            a[i][0] = tolower(a[i][0]);//Преобразование в строчный
				        }
			        int t = a[i][0];
			        b[i] = t;
	
				    }
	    line(b, size);
		    for (int i = 0; i < size; i++)
			    {
			        for (int j = 0; j < size; j++)
				            if ((char)b[i] == a[j][0]) 
							{
								cout << a[j] << endl; a[j] = seps; break; 
							}
			    }
		}
	void line(int a[], int n)
	{
		    int i, j, min, mink = 0, t;
		    for (i = 0; i < n - 1; i++)
			    {
			        min = a[i];
			        for (j = i + 1; j < n; j++)
				        {
				            if (a[j] > min)
					            {
					                min = a[j];
					                mink = j;
					            }
				        }
			        if (a[i] < min)
				        {
				            t = a[i];
				            a[i] = a[mink];
				            a[mink] = t;
				        }
			    }
		}
