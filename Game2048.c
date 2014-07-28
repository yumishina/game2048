# include <stdio.h>
# include <termios.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>

int matrix [4][4] = 
					{
					 { 0, 0, 0, 0 },
					 { 0, 0, 0, 0 },
					 { 0, 0, 0, 0 },
					 { 0, 0, 0, 0 }
					};


void displeyMatrix() //Функция отрисовки матрицы
{
	int row, column;
	printf("┌──────┬──────┬──────┬──────┐\n");

	for (row = 0; row < 4; row++)
	{
		for(column = 0; column < 4; column++)
			if ( matrix[row][column] == 0)
			{
				printf("│      ");
			}
			else printf("│%5i ", matrix[row][column]);
		printf("│");
		printf("\n");
		if ( row < 3)
		{
			printf("├──────┼──────┼──────┼──────┤\n");
		}
	}

	printf("└──────┴──────┴──────┴──────┘\n");
	printf("\n");
}

//int randomNumber() //Функция генерирования случайных чисел 2 и 4
void randomNumber()
{
	int random, i, j, *randNumber;
	srand(time(NULL));
	random = 2 + rand() % 4;
	if ( random == 3 || random == 5)
	{
		random = 2;
	}
	i = rand() % 4;
	j = rand() % 4;
	while (matrix[i][j] != 0)
	{
		i = rand() % 4;
		j = rand() % 4;
	}	
	matrix[i][j] = random;
	

}

bool shifting_rightwards () // Функция сдвига ВПРАВО
 {
 	int i,j,k;
 	bool shift = false; // не было сдвига
 	for(i = 0; i < 4; i++)
 	{
 		for(k = 0; k < 4; k++)
 		{
 			for(j = 0; j < 3; j++ )
 			{
 				if ( (matrix[i][j] != 0) && (matrix[i][j+1] == 0) )
 				{
 					matrix[i][j+1] = matrix[i][j];
 					matrix[i][j] = 0;
 					shift = true;
 				}
 			}
 		}
 	}
 	return shift;
 }


bool summElements_rightwards() //Функция ссумирования элементов sВПРАВО
{
	int i, j;
	bool summ = false; // не было сумирования
	bool shift = shifting_rightwards(); // проверка был ли сдвиг
	for (i = 0; i < 4; i++)
	{
		for ( j = 3; j >= 1; j-- )
		{
			if ( matrix[i][j] != 0 && matrix[i][j]  == matrix[i][j-1] )
			{
				matrix[i][j] = matrix[i][j] + matrix[i][j-1];
				matrix[i][j-1] = 0;
				summ = true;
			}
		}
	}
	shifting_rightwards();
	return shift == true || summ == true;
}

bool shifting_leftwards () // Функция сдвига ВЛЕВО
 {
 	int i,j,k;
 	bool shift = false; //нет сдвига
 	for(i = 0; i < 4; i++)
 	{
 		for(k = 0; k < 4; k++)
 		{
 			for( j = 3; j >= 1; j-- ) 
 			{
 				if ( (matrix[i][j] != 0) && (matrix[i][j-1] == 0) )
 				{
 					matrix[i][j-1] = matrix[i][j];
 					matrix[i][j] = 0;
 					shift = true;
 				}
 			}	
 		}
 	}
 	return shift;
 }

bool summElements_leftwards() //Функция ссумирования элементов ВЛЕВО
{
	int i, j;
	bool summ = false; // нет суммирования
	bool shift = shifting_leftwards(); //  был ли сдвиг
	for (i = 0; i < 4; i++)
	{
		
		for ( j = 0; j < 3; j++ )
		{
			if ( matrix[i][j] != 0 && matrix[i][j] == matrix[i][j+1] )
			{
				matrix[i][j] = matrix[i][j] + matrix[i][j+1];
				matrix[i][j+1] = 0;
				summ = true;
			}
		}
	}
	shifting_leftwards();
	return shift == true || summ == true;
}

bool shifting_upwards () // Функция сдвига ВВЕРХ
 {
 	int i,j,k;
 	bool shift = false;
 	for(k = 0; k < 4; k++)
 	{
 		for(i = 3; i>=1; i-- )
 		{
 			for( j = 0; j < 4; j++ ) 
 			{
 				if ( (matrix[i][j] != 0) && (matrix[i-1][j] == 0) )
 				{
 					matrix[i-1][j] = matrix[i][j];
 					matrix[i][j] = 0;
 					shift = true;					
 				}
 			}
 		}
 	}
 	return shift;
 }


bool summElements_upwards() //Функция ссумирования элементов ВВЕРХ
{
	int i, j;
	bool summ = false; // нет суммирования
	bool shift = shifting_upwards();
	for ( j = 0; j < 4; j++)
	{
		for ( i = 0; i < 3; i++ )
		{
			if ( matrix[i][j] != 0 && matrix[i][j] == matrix[i+1][j] )
			{
				matrix[i][j] = matrix[i][j] + matrix[i+1][j];
				matrix[i+1][j] = 0;
				summ = true;
			}
		}
	}
	shifting_upwards();
	return shift == true || summ == true;
}

bool shifting_downwards () // Функция сдвига ВНИЗ
 {
 	int i,j,k;
 	bool shift = false; // нет сдвига
 	for(k = 0; k < 4; k++)
 	{
 		for(i = 0; i < 3; i++ )
 		{
 			for( j = 0; j < 4; j++ ) 
 			{
 				if ( (matrix[i][j] != 0) && (matrix[i+1][j] == 0) )
 				{
 					matrix[i+1][j] = matrix[i][j];
 					matrix[i][j] = 0;
 					shift = true;					
 				}
 			}
 		}
 	}
 	return shift;
 }


bool summElements_downwards() //Функция ссумирования элементов ВНИЗ
{
	int i, j;
	bool summ = false; //нет суммирования
	bool shift = shifting_downwards();
	for ( j = 0; j < 4; j++ )
	{
		for ( i = 3; i >= 1; i-- )
		{
			if ( matrix[i][j] != 0 && matrix[i][j] == matrix[i-1][j] )
			{
				matrix[i][j] = matrix[i][j] + matrix[i-1][j];
				matrix[i-1][j] = 0;
				summ = true;
			}
		}
	}
	shifting_downwards();
	return shift == true || summ == true;
}

bool hasMoves() // Функция проверки на отсутствие ходов и сумма  == 2048
{
	bool flag = false; //нет ходов
	int i,j;

	for (i = 0; i < 4; i++) //проверка есть ли в матрице элемент = 2048
	{
		for ( j = 0; j < 4; j++)
		{
			if ( matrix[i][j] == 2048)
			{
				printf("You're a genius!\n");
				break;	
			}
		}
	}
	for (i = 0; i < 4; i++) //проверка есть ли в матрице 0
	{
		for ( j = 0; j < 4; j++)
		{
			if ( matrix[i][j] == 0)
			{
				 return true;
			}
		}
	}

	 for( i = 0; i < 3; i++)
	 {
	 	for( j = 0; j < 3; j ++)
	 	{
	 		if ( ( matrix[i][j] == matrix[i][j+1] ) || ( matrix[i][j] == matrix[i+1][j] ) || ( matrix[i+1][j] == matrix[i+1][j+1]) || (matrix[i][j+1] == matrix[i+1][j+1]))
	 		{
	 			return true;	
	 		}
	 	}
	 }
	 
 	return false;
}


int getch ( void ) //Функция нажатия клавиш
{
	int ch;
	struct termios oldt, newt;
	tcgetattr ( STDIN_FILENO, &oldt );
	newt = oldt;
	newt.c_lflag &= ~( ICANON | ECHO );
	tcsetattr ( STDIN_FILENO, TCSANOW, &newt );
	ch = getchar();
	tcsetattr ( STDIN_FILENO, TCSANOW, &oldt );

	return ch;
}


int main()
{
	int key = 0;  

	randomNumber(); // генерируем случайное число
	randomNumber();

	displeyMatrix();

	printf("Input: \n"); 
	
	while ( key != 10 && hasMoves() == true )
	{
		key = getch();
		if (key == '\033') 
		{
			getch();
			key = getch();
		}

		switch (key)
		{
			case 65:
			system("clear");
			printf("Вверх\n");
			if ( summElements_upwards() == true)
				randomNumber();
			displeyMatrix();
			break;

			case 66:
			system("clear");
			printf("Вниз\n");
			if ( summElements_downwards() == true)
				randomNumber();
			displeyMatrix();
			break;

			case 67:
			system("clear");
			printf("Вправо\n");
			if ( summElements_rightwards() == true )
				randomNumber();
			displeyMatrix();
			break;

			case 68:
			system("clear");
			printf("Влево\n");
			if ( summElements_leftwards() ==  true )
				randomNumber();
			displeyMatrix();
			break;

			case 10:
			system("clear");
			printf("Выход\n");
			break; 
		}
	}
	if (hasMoves() == false) // не срабатывает
	{
		printf("Game over\n");
	}	
	return 0;
}

