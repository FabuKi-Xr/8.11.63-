#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


int findmean(int x,int y) {
	int mean;
	mean = x / y;
	return mean;
}
int main()
{
	struct student {
		char name[20];
		char surname[30];
		int total;//still not divided
		double score;
	}student[50], risk[50], safe[50], unsafe[50];

	int n = 0, mean = 0, sum = 0 ;

	printf("===welcome to this program===\n");
	printf("Enter number of your student : ");
	scanf_s("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter student[%d] name : ",i);
		scanf("%s", student[i].name);

		printf("Enter student[%d] surname : ",i);
		scanf("%s", student[i].surname);

		printf("Enter student[%d]'s total: ",i);
		scanf_s("%d", &student[i].total);

		sum += student[i].total;

		student[i].score = (double)student[i].total / 140 * 35;

	}
	mean = findmean(sum, n);
	int j=0,k=0,l=0;
	for (int i = 0;i < n;i++) 
	{
		if (student[i].total >= mean )
		{
				safe[j] = student[i];
				j = j + 1;
		}

		if (student[i].total < mean && student[i].total > 40)
		{
				risk[k] = student[i];
				k = k + 1;
		}

		if (student[i].total <= 40)
		{
				unsafe[j] = student[i];
				l = l + 1;
		}

	}
	printf("\n===SAFE===\n");
	for (int i = 0;i < j;i++) 
	{
		printf("%s\t%s\t%d\t%.2lf\n", safe[i].name,safe[i].surname,safe[i].total,safe[i].score);
	}
	printf("\n===RISK===\n");
	for (int i = 0;i < k;i++)
	{
		printf("%s\t%s\t%d\t%.2lf\n", risk[i].name, risk[i].surname, risk[i].total, risk[i].score);
	}
	printf("\n===UNSAFE===\n");
	for (int i = 0;i < l;i++)
	{
		printf("%s\t%s\t%d\t%.2lf\n", unsafe[i].name, unsafe[i].surname, unsafe[i].total, unsafe[i].score);
	}
	return 0;
}