#include <locale.h>
#include <stdio.h>
#define MONTH 12
#define SIZE 4
//int sum(int *ar, int *end);
int sum(const int *ar, int *end);

int strlen(char * s)
{	
	int i;
	for (i = 0; *s!='\0'; s++)
	{
		i++;
	}
	return i;
}

int sum(const int *ar, int *end) // добавляем конст и функция не сможет изменить сам массив и его значения
{	
	printf("Объем памяти под массив ar = %d;\n", sizeof(ar));
	int total = 0;
	//for (int i = 0; i < *end; i++)
	//{
	//	/*total += ar[i];*/
	//	total += *(ar + i);
	//}
	while (ar < end)
	{
		//total += *ar; // добавление значения к total
		//ar++; // перемещаем указатель на next элемент

		total += *(ar++); //увеличит адрес, и выведет значение второго адреса
		*++ar; // увеличит значение по первому адресу
	}
	return total;
}



int main()
{	
	setlocale(LC_ALL, "Rus");

	int urn[5] = { 100, 200, 300, 400, 500 };
	int *ptrl = NULL, *ptrl2 = NULL, *ptrl3 = NULL;

	sum(urn, urn + 5); 

	return 0;
	//1 - Присваивание значения указателю

	ptrl = urn; // присваивание указателю адресу
	ptrl2 = &urn[2]; // адрес 3го элемента

	printf(" Адрес первого элемента массива ptrl = %p,\n Значение первого элемента массива *ptrl = %d,\n Адрес самого указателя &ptrl = %p\n", ptrl, *ptrl, &ptrl);

	//Определение значения
	printf("*ptrl = %d\n", *ptrl);
	
	//Адрес указателя
	printf("&ptrl = %p\n", &ptrl);

	//4 - Сложение целочисленного значения с указателем
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("ptrl + %d = %p - %d\n", i, ptrl + i, *(ptrl + i));
	}

	//5 - Инкремент значения
	
	printf("Адрес указателя ptrl до ptrl++ = %p\n",
		&ptrl);
	printf("ptrl = %p, *ptrl = %d, &ptrl = %p \n", ptrl, *ptrl, &ptrl);
	ptrl++;//увеличим значения на 1   также можем уменьшить ptrl--;
	printf("увеличим значения на 1\n");
	printf("Адрес указателя ptrl после ptrl++:\n");
	printf("ptrl = %p, *ptrl = %d, &ptrl = %p\n\n", ptrl, *ptrl, &ptrl);

	//6 - Вычитание целочисленных значений
	printf("Вычитание = *ptrl = %d\n\n", *(ptrl - 1)); // *(ptrl + 1) вернет значение второго адреса, *ptrl + 1 увеличит значение элемента первого адреса на 1;

	//7 - Дикремент
	--ptrl; // --ptrl = ptrl--
	printf("Дикремент = *ptrl = %d\n\n", *(ptrl));

	ptrl2 = &urn[3]; // адрес третьего элемента
	//8 - Вычисление разности указателей
	printf("Вычисление разности указателей\n");
	printf("ptrl2 = %p(%d), ptrl = %p(%d), ptrl2 - ptrl = %d\n",
		ptrl2, *ptrl2, ptrl, *ptrl, ptrl2 - ptrl);


	//8.1 - Сравнение указателей
	printf("Сравнение указателей\n");
	printf("ptrl2 = %p(%d), ptrl = %p(%d), ptrl2 > ptrl = %d\n",
		ptrl2, *ptrl2, ptrl, *ptrl, ptrl2 > ptrl);



	return 0;




	int days[MONTH] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	printf("Объем памяти под массив days = %d;\n", sizeof(days));



	printf("Сумма элементов массива - %d\n", sum(days, days + MONTH));


	/*int a[4] = {31, 28, 31, 30};
	int * pa = NULL;

	pa = &a[0]; // &a[10] = a
	int x = *(pa + 1);

	pa = a;
	//*(pa + 1) = *(a + 1)
	printf("- %p - %p\n", &a[1], a+1);
	
	printf("\n\n");

	char name[50] = "Lesson References";
	int result = strlen(name); 
	
	printf("Длина строки = %d\n\n", result);*/



}
/*
	int days[MONTH] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	printf("days = %p; &days[0] = %p \n\n", days, &days[0]);
	if (days == &days[0])
		printf("YES\n");

	short dates[SIZE] = { 31, 28, 31, 30 };
	short *pti = NULL;

	short index;

	double bills[SIZE];
	double *ptf = NULL;

	pti = dates; // назначен 1й элемент массива
	ptf = bills;
	printf("\t\t short double \n");
	printf("\n");
	for (index = 0; index < SIZE; index++)
	{
		printf("указатели + %d:%10p %10p \n",
			index, pti + index, ptf + index);
	}
	printf("\n");
	for (index = 0; index < SIZE; index++)
	{
		printf("адрес %d элемента: %d\n",
			index, &days);
	}
	printf("\n");
	for (index = 0; index < SIZE; index++)
	{
		printf("значение %d элемента: %d\n",
			index, *(dates + index));
	}
	printf("\n");
	for (index = 0; index < SIZE; index++)
	{
		printf("значение %d элемента: %d\n",
			index, *(pti + index));
	}
*/
