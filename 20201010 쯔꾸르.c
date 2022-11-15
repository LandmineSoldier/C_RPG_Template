#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>

#pragma warning(disable:4996)

#define MAP_MAXSIZE_X 45
#define MAP_MAXSIZE_Y 45

int MID_X = 16; //중앙 정렬
int MID_Y = 10; //중앙 정렬

#define TRUE 1
#define FALSE 0


struct entity {
	int x, y;
	int isMove;
	int entitySizeX, entitySizeY;
	int hasKey;
	int hisMapPos;
	int mapChanged;
};

int testMap[MAP_MAXSIZE_Y][MAP_MAXSIZE_X] = { 0, };

int theRoom[MAP_MAXSIZE_Y][MAP_MAXSIZE_X] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int tempMap[MAP_MAXSIZE_Y][MAP_MAXSIZE_X] = { 0, };

int playerImage[2][1] = {
	{1},
	{1}
};

enum colorName
{
	BLACK,
	D_BLUE,
	D_GREEN,
	D_SKYBLUE,
	D_RED,
	D_VIOLET,
	D_YELLOW,
	GRAY,
	D_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};
enum mapName
{
	TESTMAP,
	THEROOM,
};

void color(int bgColor, int textColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bgColor * 16 + textColor);
}

int gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView(int show) // 입력 커서 제거
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void printEntity(struct entity* Entity, int isPlayer)
{
	for (int i = Entity->entitySizeY - 1; i >= 0; i--)
	{
		for (int j = 0; j < Entity->entitySizeX; j++)
		{
			gotoxy((Entity->x + j + MID_X) * 2, Entity->y - i + MID_Y);

			if (isPlayer == TRUE)
			{
				switch (playerImage[i][j])
				{
				case 0:
					color(WHITE, WHITE);
					break;
				case 1:
					color(D_GREEN, GREEN);
					i == 1 ?
						puts("유") :
						puts("저");
					break;
				}
				//puts("  ");
			}
		}
	}
}
void playerMoveControl(struct entity* player, int isMove, int nowMap[][MAP_MAXSIZE_X])
{

	memcpy(theRoom, nowMap, sizeof(nowMap));
	switch (isMove)
	{
	case 'w':
		if (player->y > 1 && nowMap[player->y - 2][player->x] != 1)
		{
			if (nowMap[player->y - 2][player->x] == 2)
			{
				if (player->hasKey == 1)
				{
					nowMap[player->y - 2][player->x] = 0;
					player->y--;
					player->hasKey = 0;
				}
				else
				{
					gotoxy((MAP_MAXSIZE_X / 2 - 5 + MID_X) * 2, MAP_MAXSIZE_Y + 1 + MID_Y);
					color(BLACK, WHITE);
					puts("열쇠가 필요합니다.");
				}
			}
			else
				player->y--;
		}
		break;
	case 'a':
		if (player->x > 0 && (nowMap[player->y][player->x - 1] != 1 && nowMap[player->y - 1][player->x - 1] != 1))
		{
			if (nowMap[player->y][player->x - 1] == 2 && nowMap[player->y - 1][player->x - 1] == 2)
			{
				if (player->hasKey == 1)
				{
					nowMap[player->y - 1][player->x - 1] = 0;
					nowMap[player->y][player->x - 1] = 0;
					player->x--;
					player->hasKey = 0;
				}
				else
				{
					gotoxy((MAP_MAXSIZE_X / 2 - 5 + MID_X) * 2, MAP_MAXSIZE_Y + 1 + MID_Y);
					color(BLACK, WHITE);
					puts("열쇠가 필요합니다.");
				}
			}
			else
				player->x--;
		}
		break;
	case 's':
		if (player->y < MAP_MAXSIZE_Y - 1 && nowMap[player->y + 1][player->x] != 1)
		{
			if (nowMap[player->y + 1][player->x] == 2)
			{
				if (player->hasKey == 1)
				{
					nowMap[player->y + 1][player->x] = 0;
					player->y++;
					player->hasKey = 0;
				}
				else
				{
					gotoxy((MAP_MAXSIZE_X / 2 - 5 + MID_X) * 2, MAP_MAXSIZE_Y + 1 + MID_Y);
					color(BLACK, WHITE);
					puts("열쇠가 필요합니다.");
				}
			}
			else
				player->y++;
		}
		break;
	case 'd':
		if (player->x < MAP_MAXSIZE_X - 1 && (nowMap[player->y][player->x + 1] != 1 && nowMap[player->y - 1][player->x + 1] != 1))
		{
			if (nowMap[player->y][player->x + 1] == 2 && nowMap[player->y - 1][player->x + 1] == 2)
			{
				if (player->hasKey == 1)
				{
					nowMap[player->y - 1][player->x + 1] = 0;
					nowMap[player->y][player->x + 1] = 0;
					player->x++;
					player->hasKey = 0;
				}
				else
				{
					gotoxy((MAP_MAXSIZE_X / 2 - 5 + MID_X) * 2, MAP_MAXSIZE_Y + 1 + MID_Y);
					color(BLACK, WHITE);
					puts("열쇠가 필요합니다.");
				}
			}
			else
				player->x++;
		}
		break;
	case 27: //esc
		exit(1); //escape from this game
	case 'e':
		player->hasKey = 1;
		gotoxy((MAP_MAXSIZE_X / 2 - 5 + MID_X) * 2, MAP_MAXSIZE_Y + 1 + MID_Y);
		color(BLACK, WHITE);
		puts("                    ");
		break;
	case 'f':
		player->hasKey = 0;
		break;
	case 48: //numpad 0
		player->hisMapPos = TESTMAP;
		player->mapChanged = TRUE;
		break;
	case 49: //numpad 1
		player->hisMapPos = THEROOM;
		player->mapChanged = TRUE;
		break;
	}
}

void mapBackup(struct entity* Entity, int direction, int nowMap[][MAP_MAXSIZE_X])
{
	for (int i = Entity->entitySizeY - 1; i >= 0; i--)
	{
		for (int j = 0; j < Entity->entitySizeX; j++)
		{
			gotoxy((Entity->x + j + MID_X) * 2, Entity->y - i + MID_Y);
			switch (nowMap[Entity->y - i][Entity->x + j])
			{
			case 0:
				color(D_GRAY, GRAY);
				break;
			case 1:
				color(D_YELLOW, BLACK);
				break;
			case 2:
				color(WHITE, WHITE);
				break;
			}
			puts("  ");
		}
	}
}
void printMap(int nowMap[][MAP_MAXSIZE_X], int col, int row)
{
	for (int i = 0; i < row;i++)
	{
		for (int j = 0; j < col; j++)
		{
			gotoxy((j + MID_X) * 2, i + MID_Y);

			switch (nowMap[i][j])
			{
			case 0:
				color(D_GRAY, GRAY);
				break;
			case 1:
				color(D_YELLOW, BLACK);
				break;
			case 2:
				color(WHITE, WHITE);
				break;
			}
			puts("  ");
		}
	}
}


void checkObject()//checking PressurePlate(발판), Items(key, food, etc..), pushingOBJ, etc..
{

}

void fullScreen()
{
	//int width = GetSystemMetrics(SM_CXSCREEN);
	//int height = GetSystemMetrics(SM_CXSCREEN);

	//HWND hwnd = CreateWindow(szWindowClass, szTitle, WS_EX_TOPMOST | WS_POPUP,
	//	0, 0, width, height, NULL, NULL, hInstance, NULL);

	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

int main(void)
{
	struct entity player;
	int nowMap[MAP_MAXSIZE_Y][MAP_MAXSIZE_X] = { 0, };

	player.hasKey = 0;
	player.hisMapPos = THEROOM;
	player.mapChanged = FALSE;

	fullScreen();
	Sleep(250);
	CursorView(0);

	player.entitySizeX = 1;
	player.entitySizeY = 2;
	player.x = 4;//(MAP_MAXSIZE_X - 1) / 2;
	player.y = (MAP_MAXSIZE_Y - 1) / 2;


	switch (player.hisMapPos)
	{
	case TESTMAP:
		memcpy(nowMap, testMap, sizeof(testMap));
		break;
	case THEROOM:
		memcpy(nowMap, theRoom, sizeof(theRoom));
		break;
	}

	printMap(nowMap,
		MAP_MAXSIZE_X,
		MAP_MAXSIZE_Y);

	/*player printing*/
	printEntity(&player, TRUE);
	while (1)
	{
		if (kbhit()) //키보드가 눌러졌는가 확인
		{
			switch (player.hisMapPos) //맵의 변화점을 실제 저장소에도 변경함
			{
			case TESTMAP:
				memcpy(testMap, nowMap, sizeof(testMap));
				break;
			case THEROOM:
				memcpy(theRoom, nowMap, sizeof(theRoom));
				break;
			}

			player.isMove = getch();

			/*erase player afterImage*/
			mapBackup(&player, player.isMove, nowMap);

			playerMoveControl(&player, player.isMove, nowMap); //다른 명령키값도 여기서 체크중
			if (player.mapChanged == TRUE)
			{
				color(BLACK, BLACK);
				system("cls");

				switch (player.hisMapPos)
				{
				case TESTMAP:
					memcpy(nowMap, testMap, sizeof(testMap));
					break;
				case THEROOM:
					memcpy(nowMap, theRoom, sizeof(theRoom));
					break;
				}

				printMap(nowMap,
					MAP_MAXSIZE_X,
					MAP_MAXSIZE_Y);

				player.mapChanged = FALSE;
			}

			/*printing player*/
			printEntity(&player, TRUE);
		}
	}
}