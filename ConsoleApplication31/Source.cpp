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

int sum(const int *ar, int *end) // ��������� ����� � ������� �� ������ �������� ��� ������ � ��� ��������
{	
	printf("����� ������ ��� ������ ar = %d;\n", sizeof(ar));
	int total = 0;
	//for (int i = 0; i < *end; i++)
	//{
	//	/*total += ar[i];*/
	//	total += *(ar + i);
	//}
	while (ar < end)
	{
		//total += *ar; // ���������� �������� � total
		//ar++; // ���������� ��������� �� next �������

		total += *(ar++); //�������� �����, � ������� �������� ������� ������
		*++ar; // �������� �������� �� ������� ������
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
	//1 - ������������ �������� ���������

	ptrl = urn; // ������������ ��������� ������
	ptrl2 = &urn[2]; // ����� 3�� ��������

	printf(" ����� ������� �������� ������� ptrl = %p,\n �������� ������� �������� ������� *ptrl = %d,\n ����� ������ ��������� &ptrl = %p\n", ptrl, *ptrl, &ptrl);

	//����������� ��������
	printf("*ptrl = %d\n", *ptrl);
	
	//����� ���������
	printf("&ptrl = %p\n", &ptrl);

	//4 - �������� �������������� �������� � ����������
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("ptrl + %d = %p - %d\n", i, ptrl + i, *(ptrl + i));
	}

	//5 - ��������� ��������
	
	printf("����� ��������� ptrl �� ptrl++ = %p\n",
		&ptrl);
	printf("ptrl = %p, *ptrl = %d, &ptrl = %p \n", ptrl, *ptrl, &ptrl);
	ptrl++;//�������� �������� �� 1   ����� ����� ��������� ptrl--;
	printf("�������� �������� �� 1\n");
	printf("����� ��������� ptrl ����� ptrl++:\n");
	printf("ptrl = %p, *ptrl = %d, &ptrl = %p\n\n", ptrl, *ptrl, &ptrl);

	//6 - ��������� ������������� ��������
	printf("��������� = *ptrl = %d\n\n", *(ptrl - 1)); // *(ptrl + 1) ������ �������� ������� ������, *ptrl + 1 �������� �������� �������� ������� ������ �� 1;

	//7 - ���������
	--ptrl; // --ptrl = ptrl--
	printf("��������� = *ptrl = %d\n\n", *(ptrl));

	ptrl2 = &urn[3]; // ����� �������� ��������
	//8 - ���������� �������� ����������
	printf("���������� �������� ����������\n");
	printf("ptrl2 = %p(%d), ptrl = %p(%d), ptrl2 - ptrl = %d\n",
		ptrl2, *ptrl2, ptrl, *ptrl, ptrl2 - ptrl);


	//8.1 - ��������� ����������
	printf("��������� ����������\n");
	printf("ptrl2 = %p(%d), ptrl = %p(%d), ptrl2 > ptrl = %d\n",
		ptrl2, *ptrl2, ptrl, *ptrl, ptrl2 > ptrl);



	return 0;




	int days[MONTH] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	printf("����� ������ ��� ������ days = %d;\n", sizeof(days));



	printf("����� ��������� ������� - %d\n", sum(days, days + MONTH));


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
	
	printf("����� ������ = %d\n\n", result);*/



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

	pti = dates; // �������� 1� ������� �������
	ptf = bills;
	printf("\t\t short double \n");
	printf("\n");
	for (index = 0; index < SIZE; index++)
	{
		printf("��������� + %d:%10p %10p \n",
			index, pti + index, ptf + index);
	}
	printf("\n");
	for (index = 0; index < SIZE; index++)
	{
		printf("����� %d ��������: %d\n",
			index, &days);
	}
	printf("\n");
	for (index = 0; index < SIZE; index++)
	{
		printf("�������� %d ��������: %d\n",
			index, *(dates + index));
	}
	printf("\n");
	for (index = 0; index < SIZE; index++)
	{
		printf("�������� %d ��������: %d\n",
			index, *(pti + index));
	}
*/
