#ifndef _MAIN_H_
#define _MAIN_H_ 1

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <inttypes.h>
#include "LinkedList.h"
#include "VideoAdapter.h"
#include "TController.h"

using namespace std;

const char *APP_VERSION = "1.2";

const char *MSG_NOT_FOUND =     "Не найдено элементов, удовлетворяющих запросу.\n";
const char *MSG_UNKNOWN_CMD =   "Некоррректная команда!\n";
const char *MSG_ENTER_PATH =    "Введите путь и имя файла: ";
const char *MSG_SELETC_ACTION = "Выберите действие:\n";

const char *STR_MENU_ESC =    "ESC. Назад\n";

const char *STR_VENDOR =      "  Производитель:  ";
const char *STR_MODEL  =      "  Модель:         ";
const char *STR_GPU_VENDOR =  "  Произв. ГП:     ";
const char *STR_GPU_MODEL =   "  Модель ГП:      ";
const char *STR_VRAM_SIZE =   "  Объем ОЗУ (Мб): ";
const char *STR_PRICE =       "  Цена (руб):     ";

const char *LIST_HEADER =   "  id | Производитель | Модель                   | произв. ГП | Модель ГП    | ОЗУ   | цена  \n";
const char *LIST_DIVIDER =  " ----|---------------|--------------------------|------------|--------------|-------|-------\n";
const char *LIST_FORMAT =   "  %2d | %-13s | %-24s | %-10s | %-12s | %-5d | %-5d \n";

const char *TEST_FILE = "./catalog.db";
const int IN_BUFF_LEN = 50;

const int MENU_1 =    49;
const int MENU_2 =    50;
const int MENU_3 =    51;
const int MENU_4 =    52;
const int MENU_5 =    53;
const int MENU_6 =    54;
const int MENU_7 =    55;
const int MENU_8 =    56;
const int MENU_EXIT = 27;

enum sortMode { SORT_COUNT, SORT_MNEMONIC };

uint32_t globalId = 0;
LinkedList<VideoAdapter> catalog;
TController terminal;

bool isListEmpty();
void showList();
void addItem();
void editItem();
void removeItem();
void saveToFile(const char *fileName);
void loadFromFile(const char *fileName);
void fillAdapterData(VideoAdapter *adapter);

void showVendorList(sortMode mode);
void showPriceInterval(uint32_t from, uint32_t to);
void showGPUVendorRatio();
void showMinMaxPrice();

int arraySearch(char *str, char **arr, size_t arrLength);
void getFilePath(char *buff);
void stringToFile(char* str, FILE *fp);
char *stringFromFile(char* buff, FILE *fp);
char getch();

#endif /* _MAIN_H__ */
