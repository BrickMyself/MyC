#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define ROW 3
#define COL 3
void	init_board(char board[ROW][COL],int row,int col)//��ʼ������
{
	int i,j;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			board[i][j]=' ';
		}
	}
}
void	print_board( char board[ROW][COL],int row, int col)//��ӡ����
{
    int i;
    for (i=0; i<row ; i++)
    {
        printf("  %c | %c | %c  \n",board[i][0],board[i][1],board[i][2]);
        if (i != row - 1)
            printf(" ---|---|--- \n");
    }    
	printf("\n");
}

void play_game(char board[ROW][COL],int row, int col)//�������
{
	int x,y;
	while(1)
	{
	printf("�������>:���������꣺");
	scanf("%d %d",&x,&y);
	
	if(x<=row&&y<=col)
	{

	
		if(board[x-1][y-1]==' ')
	
		board[x-1][y-1]='*';
		break;
		 
	 }
         else printf("λ�ò�����");
	}
}
void computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	int z = 0;
	printf("������!\n\n");
	z = check_tic(board, row, col);
 
	while (0 == z)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			z = 1;
			break;
		}
	}
}
 
	

char judge_tic(char board[ROW][COL], int row, int col, int k) 
{
	int i = 0;
	int j = 0;
	while (0 == k)
	{
		for (i = 0; i < row; i++)  //�ж�����ں������Ƿ��Ӯ
		{
			if ((board[i][0] == board[i][1])
				&& (board[i][1] == '*')
				&& (board[i][2] == ' '))
			{
				board[i][2] = '#';
				k = 1;
				break;
			}
 
			if ((board[i][0] == board[i][2])
				&& (board[i][0] == '*')
				&& (board[i][1] == ' '))
			{
				board[i][1] = '#';
				k = 1;
				break;
			}
 
			if ((board[i][1] == board[i][2])
				&& (board[i][1] == '*')
				&& (board[i][0] == ' '))
			{
				board[i][0] = '#';
				k = 1;
				break;
			}
		}
 
		if (k != 0)
			break;
 
		for (j = 0; j < col; j++)  //�ж�������������Ƿ��Ӯ
		{
			if ((board[0][j] == board[1][j])
				&& (board[1][j] == '*')
				&& (board[2][j] == ' '))
			{
				board[2][j] = '#';
				k = 1;
				break;
			}
 
			if ((board[0][j] == board[2][j])
				&& (board[2][j] == '*')
				&& (board[1][j] == ' '))
			{
				board[1][j] = '#';
				k = 1;
				break;
			}
 
			if ((board[1][j] == board[2][j])
				&& (board[2][j] == '*')
				&& (board[0][j] == ' '))
			{
				board[0][j] = '#';
				k = 1;
				break;
			}
		}
		break;
	}
 
	while (0 == k)  //�ж�����ڶԽ������Ƿ��Ӯ
	{
		if ((board[0][0] == board[1][1])
			&& (board[1][1] == '*')
			&& (board[2][2] == ' '))
		{
			board[2][2] = '#';
			k = 1;
			break;
		}
 
		if ((board[0][0] == board[2][2])
			&& (board[2][2] == '*')
			&& (board[1][1] == ' '))
		{
			board[1][1] = '#';
			k = 1;
			break;
		}
 
		if ((board[1][1] == board[2][2])
			&& (board[1][1] == '*')
			&& (board[0][0] == ' '))
		{
			board[0][0] = '#';
			k = 1;
			break;
		}
 
		if ((board[0][2] == board[1][1])
			&& (board[0][2] == '*')
			&& (board[2][0] == ' '))
		{
			board[2][0] = '#';
			k = 1;
			break;
		}
 
		if ((board[0][2] == board[2][0])
			&& (board[2][0] == '*')
			&& (board[1][1] == ' '))
		{
			board[1][1] = '#';
			k = 1;
			break;
		}
 
		if ((board[1][1] == board[2][0])
			&& (board[2][0] == '*')
			&& (board[0][2] == ' '))
		{
			board[0][2] = '#';
			k = 1;
			break;
		}
		break;
	}
	return k;
}
 
//�����ж��Ƿ����ʤ��
 
int check_tic(char board[ROW][COL], int row, int col) 
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (0 == k)
	{
		for (i = 0; i < row; i++)
		{
			if ((board[i][0] == board[i][1])
				&& (board[i][1] == '#')
				&& (board[i][2] == ' '))
			{
				board[i][2] = '#';
				k = 1;
				break;
			}
 
			if ((board[i][0] == board[i][2])
				&& (board[i][0] == '#')
				&& (board[i][1] == ' '))
			{
				board[i][1] = '#';
				k = 1;
				break;
			}
 
			if ((board[i][1] == board[i][2])
				&& (board[i][1] == '#')
				&& (board[i][0] == ' '))
			{
				board[i][0] = '#';
				k = 1;
				break;
			}
		}
		if (k != 0)
			break;
		for (j = 0; j < col; j++)
		{
			if ((board[0][j] == board[1][j])
				&& (board[1][j] == '#')
				&& (board[2][j] == ' '))
			{
				board[2][j] = '#';
				k = 1;
				break;
			}
 
			if ((board[0][j] == board[2][j])
				&& (board[2][j] == '#')
				&& (board[1][j] == ' '))
			{
				board[1][j] = '#';
				k = 1;
				break;
			}
 
			if ((board[1][j] ==board[2][j])
				&& (board[2][j] == '#')
				&& (board[0][j] == ' '))
			{
				board[0][j] = '#';
				k = 1;
				break;
			}
		}
		break;
	}
 
	while (0 == k)
	{
		if ((board[0][0] == board[1][1])
			&& (board[1][1] == '#')
			&& (board[2][2] == ' '))
		{
			board[2][2] = '#';
			k = 1;
			break;
		}
 
		if ((board[0][0] == board[2][2])
			&& (board[2][2] == '#')
			&& (board[1][1] == ' '))
		{
			board[1][1] = '#';
			k = 1;
			break;
		}
 
		if ((board[1][1] == board[2][2])
			&& (board[1][1] == '#')
			&& (board[0][0] == ' '))
		{
			board[0][0] = '#';
			k = 1;
			break;
		}
 
		if ((board[0][2] ==board[1][1])
			&& (board[0][2] == '#')
			&& (board[2][0] == ' '))
		{
			board[2][0] = '#';
			k = 1;
			break;
		}
 
		if ((board[0][2] ==board[2][0])
			&& (board[2][0] == '#')
			&& (board[1][1] == ' '))
		{
			board[1][1] = '#';
			k = 1;
			break;
		}
 
		if ((board[1][1] == board[2][0])
			&& (board[2][0] == '#')
			&& (board[0][2] == ' '))
		{
			board[0][2] = '#';
			k = 1;
			break;
		}
		break;
	}
	k = judge_tic(board, row, col, k);
	return k;
}

char	chick_win(char board[ROW][COL],int row, int col)//�ж���Ӯ
{
	int i;
	for(i=0; i<row; i++)
	{
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&(board[i][1]!=' '))
			return board[i][1];
	}
	  for (i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
            return board[1][i];
    }
	    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
        return board[1][1];
    else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
        return board[1][1];
    else if (is_full(board, row, col))
        return 'p';
    return 0;
}
static int is_full(char board[ROW][COL], int row, int col)//�ж������Ƿ�����
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
   return 1;
}

void	game()//��Ϸģ��
{
    char ret;
	int set;
	char  board[ROW][COL];
    init_board(board,ROW,COL);//��ʼ��
	print_board(board,ROW,COL);//��ӡ����
	while(1)
	{
	play_game(board,ROW,COL);//�������
	print_board(board,ROW,COL);//��ӡ����				
	set=is_full(board,ROW, COL);//�ж���
	ret=chick_win(board, ROW, COL);//�ж�Ӯ	
		if(ret=='*')
		{
			printf("��ϲ��Ӯ��\n");
			break;
		}
		if(ret=='#')
		{
			printf("����Ӯ\n");
			break;
		}
		if(ret=='p')
		{
			printf("ƽ��\n");
			break;
		}	
    computer_move(board,ROW,COL);
	print_board(board,ROW,COL);//��ӡ����
	set=is_full(board,ROW, COL);//�ж���
	ret=chick_win(board, ROW, COL);//�ж�Ӯ
	if(ret=='*')
		{
			printf("��ϲ��Ӯ��\n");
			break;
		}
		if(ret=='#')
		{
			printf("����Ӯ\n");
			break;
		}
		if(ret=='p')
		{
			printf("ƽ��\n");
			break;
		}

	}
	}

void menu()//�˵�
{
	system("color b4");
    system("mode con: cols=78 lines=35");
	printf("\t\t********************\n");
	printf("\t\t*****  1.play ******\n");
	printf("\t\t*****  0.exit ******\n");
	printf("\t\t********************\n");
}

int main()//������
{
	int input;
	srand((unsigned int)time(NULL));//���������	
	do 
	{	
	menu();
	printf("������Ϸ�����룺1\n");
	scanf("%d",&input);
	switch(input)
	
	{
	case 1: 
		game();
		break;
	case 2:
		printf("�˳���Ϸ");
		break;
		}
	system("pause");
	}
	while(input);
		return 0;
}
