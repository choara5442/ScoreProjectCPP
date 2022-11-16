#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

struct student {
	int no;
	int sub1;
	int sub2;
	int sub3;
	int sum;
	double ave;
	int rank;
};

void inputdata(struct student s[], int tot);
void printdata(struct student s[], int tot);
void processranking(struct student s[], int tot, int process);
void sortingno(struct student s[], int tot);
void sortingrank(struct student s[], int tot);

int main()
{
	struct student s[30];
	int i, tot, menu, process, process2;
	tot = 25 + rand() % 6; // ���� �Է� ��
	
	process = 0; // �Է��� �� ���� �ϱ� ���� ���� ����
	process2 = 0; // ���� ó�� �� ���� �ϱ� ���� ���� ����
	srand((unsigned)time(NULL));
	while (1)
	{
		printf("1. �ڷ��Է� \n");
		printf("2. �ڷ�ó�� \n");
		printf("3. ��ȣ�� \n");
		printf("4. ������ ���\n");
		printf("0. ���� \n");
		printf(" ���ϴ� ��ȣ��? ");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1:
			if (process == 0) {
				printf("���ο� �ڷ� �Է�\n");
				process+=1;
				inputdata(s, tot); break;
			}
			else
				printf("�̹� �ڷᰡ �ֽ��ϴ�"); break;
		case 2: 
			if (process2 == 0)
			{
				printf("�ڷḦ ó���մϴ�.\n\n");
				processranking(s, tot, process);
				process2 += 1; break;
			}
			else {
				printf("�̹� �ڷ�ó���� �߽��ϴ�~\n\n"); break;
			}

		case 3: 
			if (process == 0 ) {
				printf("�ڷ���� �Է��Ͻÿ�~~\n"); break;
			}
			else {
				printf("��ȣ������ ����մϴ�.\n");
				sortingno(s, tot);
				printdata(s, tot); break;
			}
			
		case 4:
			if (process == 0) {
				printf("�ڷ���� �Է��Ͻÿ�~~\n"); break;
			}
			else {
				printf("���������� ����մϴ�.\n");
				sortingrank(s, tot);
				printdata(s, tot); break;
			}

		case 0: return 0;

		}
		menu = _getch();
		system("cls");
	}

	return 0;
}

//���� �Է� �Լ�
void inputdata(struct student s[], int tot)
{
	int i;

	for (i = 0; i < tot; i++) {
		s[i].no = i + 1;
		s[i].sub1 = rand() % 101;
		s[i].sub2 = rand() % 101;
		s[i].sub3 = rand() % 101;
		s[i].sum = s[i].sub1 + s[i].sub2 + s[i].sub3;
		s[i].ave = s[i].sum / 3.0;
		s[i].rank = 1;
	}
	printf("�ڷ� �Է� �ϼ�\n");
}

//����Ʈ �Լ�
void printdata(struct student s[], int tot) {
	int i;
	printf("��ȣ ����1 ����2 ����3 �հ� ���   ����\n");
	for (i = 0; i < tot; i++)
		printf("%3d  %3d  %4d %5d %5d %6.2f %4d\n", s[i].no, s[i].sub1, s[i].sub2, s[i].sub3, s[i].sum, s[i].ave, s[i].rank);

}

//���� ó�� �Լ�
void processranking(struct student s[], int tot, int process) {
		for (int i = 0; i < tot; i++) {
			for (int j = 0; j < tot; j++) {
				if (s[i].sum < s[j].sum)
					s[i].rank += 1;
			}
		}
	
}

//�������� �̿��Ͽ� ��ȣ ����� �����ϱ�
void sortingno(struct student s[],int tot) {
	struct student temp[1];
	for (int i = 1; i < tot; i++) {
		temp[0] = s[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (s[j].no > temp[0].no)
			{
				while (j < i) {
					s[i] = s[i - 1];
					i--;
				}
				s[j] = temp[0];
			}
		}

	}
}

//�������� �̿��Ͽ� ���� ����� �����ϱ�
void sortingrank(struct student s[], int tot) {
	struct student temp[1];
	for (int i = 1; i < tot; i++) {
		temp[0] = s[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (s[j].rank > temp[0].rank)
			{
				while (j < i) {
					s[i] = s[i - 1];
					i--;
				}
				s[j] = temp[0];
			}
		}
	}
}