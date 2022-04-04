#include "main.h"

int main(void) {
  int keyCode = 0, subMenuKeyCode = 0;
  char line[IN_BUFF_LEN * 2];

  do {
    system("clear");
    cout << "LinkedList manager ver. " << APP_VERSION << "\n\n";
    cout << MSG_SELETC_ACTION;
    cout << "  1. Показать список\n";
    cout << "  2. Добавить элемент в список\n";
    cout << "  3. Редактировать элемент\n";
    cout << "  4. Удалить элемент\n";
    cout << "  5. Сохранить список в файл\n";
    cout << "  6. Загрузить список из файла\n";
    cout << "  7. Статистика\n";
    cout << "ESC. Выход\n";
    keyCode = getch();

    switch(keyCode) {
      case MENU_1:
        system("clear");
        showList();
        getch();
        break;
      case MENU_2:
        system("clear");
        cout << "Добавление нового элемента.\n\n";
        addItem();
        getch();
        break;
      case MENU_3:
        system("clear");
        cout << "Редактирование элемента.\n\n";
        editItem();
        getch();
        break;
      case MENU_4:
        system("clear");
        cout << "Удаление элемента.\n\n";
        removeItem();
        break;
      case MENU_5:
        system("clear");
        if (isListEmpty()) {
          cout << "Сохранять нечего.\n";
        } else {
          cout << "Сохранение данных в файл.\n\n";
          getFilePath(line);
          saveToFile(line);
        }
        getch();
        break;
      case MENU_6:
        system("clear");
        cout << "Загрузка данных из файла.\n\n";
        getFilePath(line);
        loadFromFile(line);
        break;
      case MENU_7:
        system("clear");
        if (isListEmpty()) {
          getch();
          break;
        }

        cout << "Статистика.\n\n";
        cout << MSG_SELETC_ACTION;
        cout << "  1. Вывести список производителей (сортировка по алфавиту)\n";
        cout << "  2. Вывести список производителей (сортировка по кол-ву карт)\n";
        cout << "  3. Вывести все карты в заданном ценовом диапазоне\n";
        cout << "  4. Расчитать соотношение производителей ГП\n";
        cout << "  5. Определить самую дорогую и самую дешевую карту в списке\n";
        cout << STR_MENU_ESC;
        subMenuKeyCode = getch();

        switch (subMenuKeyCode) {
          case MENU_1:
            system("clear");
            showVendorList(SORT_MNEMONIC);
            getch();
            break;
          case MENU_2:
            system("clear");
            showVendorList(SORT_COUNT);
            getch();
            break;
          case MENU_3:
            system("clear");
            uint32_t from, to;
            cout << "Вывод всех карт в заданном ценовом диапазоне\n";
            cout << "  Введите минимальную цену: ";
            cin >> from;
            cout << "  Введите максимальную цену: ";
            cin >> to;
            cout << endl;
            getch();

            if (from > to)
              cout << "Некорректно задан ценовой диапазон.\n";
            else
              showPriceInterval(from, to);
            getch();
            break;
          case MENU_4:
            system("clear");
            showGPUVendorRatio();
            getch();
            break;
          case MENU_5:
            system("clear");
            showMinMaxPrice();
            getch();
            break;
        }
        break;
      case MENU_EXIT:
        cout << "\b\b";
        break;
    }
  } while(keyCode != MENU_EXIT);  
  return 0;
}



/* ######## LIST UTILS ##################################################################### */

bool isListEmpty() {
  if (catalog.isEmpty()) {
    cout << "Список пуст.\n";
    return true;
  } else
    return false;
}

void showList() {
  if (!isListEmpty()) {
    VideoAdapter* adapter;
    catalog.moveToFirst();

    cout << endl << LIST_HEADER << LIST_DIVIDER;
    do {
      adapter = catalog.getCurrent();
      printf(LIST_FORMAT, adapter->getId(), adapter->getVendor(), adapter->getModel(),
        adapter->getGPUVendor(), adapter->getGPUModel(), adapter->getVRAMSize(), adapter->getPrice());
    } while (catalog.next());
    cout << LIST_DIVIDER;
  }
}

void addItem() {
  VideoAdapter *adapter = new VideoAdapter();
  adapter->setId(globalId++);
  cout << "Введите параметры\n";
  fillAdapterData(adapter);
  catalog.add(adapter);
  cout << "Готово\n";
  getch();
}

void editItem() {
  if (isListEmpty())  {
    cout << "Реадктировать нечего.\n";
    return;
  }

  uint32_t id;
  cout << "Введите id элемента для редактирования: ";
  cin >> id;
  getch();

  bool found = false;
  catalog.moveToFirst();
  VideoAdapter *adapter;
  do {
    adapter = catalog.getCurrent();
    if (adapter->getId() == id) {
      found = true;
      break;
    }
  } while (catalog.next());

  if (!found) {
    cout << MSG_NOT_FOUND;
    return;
  }

  char key;
  cout << "Возможные поля для редактирования:\n";
  cout << "  1." << STR_VENDOR << "(" << adapter->getVendor() << ")\n";
  cout << "  2." << STR_MODEL << "(" << adapter->getModel() << ")\n";
  cout << "  3." << STR_GPU_VENDOR << "(" << adapter->getGPUVendor() << ")\n";
  cout << "  4." << STR_GPU_MODEL << "(" << adapter->getGPUModel() << ")\n";
  cout << "  5." << STR_VRAM_SIZE << "(" << adapter->getVRAMSize() << ")\n";
  cout << "  6." << STR_PRICE << "(" << adapter->getPrice() << ")\n";
  cout << "  7.  Все поля\n";
  cout << "Выбеирите поле: ";
  key = getch();
  cout << "\n";

  uint32_t num;
  char line[IN_BUFF_LEN];
  if (key >= MENU_1 && key <= MENU_6)
    cout << "Введите новое значение поля:\n";
  switch (key) {
    case MENU_1:
      cout << STR_VENDOR;
      cin.getline(line, IN_BUFF_LEN);
      adapter->setVendor(line);
      break;
    case MENU_2:
      cout << STR_MODEL;
      cin.getline(line, IN_BUFF_LEN);
      adapter->setModel(line);
      break;
    case MENU_3:
      cout << STR_GPU_VENDOR;
      cin.getline(line, IN_BUFF_LEN);
      adapter->setGPUVendor(line);
      break;
    case MENU_4:
      cout << STR_GPU_MODEL;
      cin.getline(line, IN_BUFF_LEN);
      adapter->setGPUModel(line);
      break;
    case MENU_5:
      cout << STR_VRAM_SIZE;
      cin >> num;
      getch();
      adapter->setVRAMSize(num);
      break;
    case MENU_6:
      cout << STR_PRICE;
      cin >> num;
      getch();
      adapter->setPrice(num);
      break;
    case MENU_7:
      cout << "Введите новые значения полей:\n";
      fillAdapterData(adapter);
      getch();
      break;
    default:
      cout << MSG_UNKNOWN_CMD;
      return;
      break;
  }
  cout << "Изменения сохранены.\n";
}

void removeItem() {
  if (isListEmpty())  {
    cout << "Удалять нечего.\n";
    getch();
    return;
  }

  char key;
  char line[IN_BUFF_LEN];
  uint32_t num;
  bool isValid = false;

  cout << "Возможнные критерии для поиска и удаления:\n";
  cout << "  1. id\n";
  cout << "  2. Модель\n";
  cout << STR_MENU_ESC;
  do {
    cout << "Выберите критерий: ";
    key = getch();
    cout << "\n";
    switch (key) {
      case MENU_1:
        isValid = true;
        cout << "Введите id: ";
        cin >> num;
        getch();
        break;
      case MENU_2:
        isValid = true;
        cout << "Введите модель: ";
        cin.getline(line, IN_BUFF_LEN);
        break;
      case MENU_EXIT:
        return;
        break;
      default:
        cout << MSG_UNKNOWN_CMD;
        break;
    }
  } while (!isValid);

  int count = 0;
  VideoAdapter *adapter;
  catalog.moveToFirst();
  do {
    adapter = catalog.getCurrent();
    switch (key) {
      case MENU_1:
        if (adapter->getId() == num) {
          catalog.removeCurrent();
          catalog.prev();
          count++;
        }
        break;
      case MENU_2:
        if (strcmp(adapter->getModel(), line) == 0) {
          catalog.removeCurrent();
          catalog.prev();
          count++;
        }
        break;
    }
  } while (catalog.next());

  if (count > 0)
    cout << "Удалено элементов: " << count << endl;
  else
    cout << MSG_NOT_FOUND;
  getch();
}

void saveToFile(const char *fileName) {
  FILE *fp = fopen(fileName, "wb");
  if (!fp) {
    cout << "Не удалось открыть файл: " << fileName << "\n";
    return;
  }

  uint32_t num;
  VideoAdapter* adapter;
  catalog.moveToFirst();
  do {
    adapter = catalog.getCurrent();
    num = adapter->getId();
    fwrite(&num, 1, sizeof(num), fp);
    stringToFile(adapter->getVendor(), fp);
    stringToFile(adapter->getModel(), fp);
    stringToFile(adapter->getGPUVendor(), fp);
    stringToFile(adapter->getGPUModel(), fp);
    num = adapter->getVRAMSize();
    fwrite(&num, 1, sizeof(num), fp);
    num = adapter->getPrice();
    fwrite(&num, 1, sizeof(num), fp);
  } while (catalog.next());

  fclose(fp);
  cout << "Сохранено в " << fileName << endl;
}

void loadFromFile(const char *fileName) {
  FILE *fp = fopen(fileName, "rb");
  if (!fp) {
    cout << "Не удалось открыть файл: " << fileName << "\n";
    getch();
    return;
  }

  bool append = false;
  uint32_t num, id;
  char buff[IN_BUFF_LEN];
  VideoAdapter* adapter;
  int count = 0;

  if (!catalog.isEmpty()) {
    char key;
    cout << "Список не пуст. Вы можете:\n";
    cout << "  1. Добавить элементы из файла в список\n";
    cout << "  2. Очистить список и перезаполнить его из файла\n";
    cout << STR_MENU_ESC;
    do {
      cout << "Выберите действие: ";
      key = getch();
      cout << "\n";
      switch (key) {
        case MENU_1:
          append = true;
          catalog.moveToLast();
          globalId = catalog.getCurrent()->getId() + 1;
          break;
        case MENU_2:
          globalId = 0;
          append = false;
          catalog.clear();
          break;
        case MENU_EXIT:
          return;
          break;
        default:
          cout << "Некоррректная команда!\n";
          break;
      }
    } while (key != MENU_1 && key != MENU_2);
  }

  int numBytes;
  while (!feof(fp)) {
    adapter = new VideoAdapter();
    numBytes = fread(&id, 1, sizeof(id), fp);
    if (numBytes < 4) break;
    if (append)
      adapter->setId(globalId++);
    else {
      adapter->setId(id);
    }
    adapter->setVendor(stringFromFile(buff, fp));
    adapter->setModel(stringFromFile(buff, fp));
    adapter->setGPUVendor(stringFromFile(buff, fp));
    adapter->setGPUModel(stringFromFile(buff, fp));
    fread(&num, 1, sizeof(num), fp);
    adapter->setVRAMSize(num);
    fread(&num, 1, sizeof(num), fp);
    adapter->setPrice(num);
    catalog.add(adapter);
    count++;
  }

  if (!append && count > 0)
    globalId = id + 1;
  fclose(fp);
  printf("Загружено из %s\nЭлементов: %d\n", fileName, count);
  getch();
}

void fillAdapterData(VideoAdapter *adapter) {
  char line[IN_BUFF_LEN];
  uint32_t num;

  cout << STR_VENDOR;
  cin.getline(line, IN_BUFF_LEN);
  adapter->setVendor(line);
  cout << STR_MODEL;
  cin.getline(line, IN_BUFF_LEN);
  adapter->setModel(line);
  cout << STR_GPU_VENDOR;
  cin.getline(line, IN_BUFF_LEN);
  adapter->setGPUVendor(line);
  cout << STR_GPU_MODEL;
  cin.getline(line, IN_BUFF_LEN);
  adapter->setGPUModel(line);
  cout << STR_VRAM_SIZE;
  cin >> num;
  adapter->setVRAMSize(num);
  cout << STR_PRICE;
  cin >> num;
  adapter->setPrice(num);
}



/* ######## LIST STATISTICS ################################################################ */

void showVendorList(sortMode mode) {
  int vendorCount = 0, index;
  VideoAdapter *adapter;
  char *vendor;

  size_t buffSize = catalog.getSize();
  char *vendorNames[buffSize], charBuffer[IN_BUFF_LEN];
  uint32_t vendorItems[buffSize], intBuffer;
  for (size_t i = 0; i < buffSize; i++) {
    vendorNames[i] = new char[IN_BUFF_LEN];
    vendorItems[i] = 0;
  }

  catalog.moveToFirst();
  do {
    adapter = catalog.getCurrent();
    vendor = adapter->getVendor();
    if ((index = arraySearch(vendor, vendorNames, buffSize)) < 0) {
      strcpy(vendorNames[vendorCount], vendor);
      vendorItems[vendorCount++] = 1;
    } else
      vendorItems[index]++;
  } while (catalog.next());

  bool sorted = false;
  switch (mode) {
    case SORT_COUNT:
      while(!sorted) {
        sorted = true;
        for(int i = 0; i < vendorCount - 1; i++) {
          if(vendorItems[i] < vendorItems[i + 1]) {
            sorted = false;
            strcpy(charBuffer, vendorNames[i]);
            strcpy(vendorNames[i], vendorNames[i + 1]);
            strcpy(vendorNames[i + 1], charBuffer);

            intBuffer = vendorItems[i];
            vendorItems[i] = vendorItems[i + 1];
            vendorItems[i + 1] = intBuffer;
          } 
        }
      }
      break;
    case SORT_MNEMONIC:
      while(!sorted) {
        sorted = true;
        for(int i = 0; i < vendorCount - 1; i++) {
          if(strcmp(vendorNames[i], vendorNames[i + 1]) > 0) {
            sorted = false;
            strcpy(charBuffer, vendorNames[i]);
            strcpy(vendorNames[i], vendorNames[i + 1]);
            strcpy(vendorNames[i + 1], charBuffer);

            intBuffer = vendorItems[i];
            vendorItems[i] = vendorItems[i + 1];
            vendorItems[i + 1] = intBuffer;
          } 
        }
      }
      break;
  }

  cout << "Список производителей карт:\n\n";
  switch (mode) {
    case SORT_COUNT:
      cout << "  Произв.    | Кол-во ▼     \n";
      break;
    case SORT_MNEMONIC:
      cout << "  Произв. ▲  | Кол-во        \n";
      break;
  }
  cout << " ------------|---------------\n";
  for (int i = 0; i < vendorCount; i++) {
    printf("  %-10s | %3d  (%.2f%%)\n", vendorNames[i],
      vendorItems[i], (double) vendorItems[i] / (double) buffSize * 100.0);
  }

  for (size_t i = 0; i < buffSize; i++)
    delete[] vendorNames[i];
}

void showPriceInterval(uint32_t from, uint32_t to) {
  bool found = false, headerShown = false;
  VideoAdapter* adapter;
  uint32_t price;

  catalog.moveToFirst();
  do {
    adapter = catalog.getCurrent();
    price = adapter->getPrice();

    if (price >= from && price <= to) {
      found = true;
      if (!headerShown) {
        cout << LIST_HEADER << LIST_DIVIDER;
        headerShown = true;
      }
      printf(LIST_FORMAT, adapter->getId(), adapter->getVendor(), adapter->getModel(),
        adapter->getGPUVendor(), adapter->getGPUModel(), adapter->getVRAMSize(), price);
    }
  } while (catalog.next());
  cout << (found ? LIST_DIVIDER : MSG_NOT_FOUND);
}

void showGPUVendorRatio() {
  int vendorCount = 0, index;
  VideoAdapter *adapter;
  char *vendor;

  size_t buffSize = catalog.getSize();
  char *vendorNames[buffSize];
  uint32_t vendorItems[buffSize];
  for (size_t i = 0; i < buffSize; i++) {
    vendorNames[i] = new char[IN_BUFF_LEN];
    vendorItems[i] = 0;
  }

  catalog.moveToFirst();
  do {
    adapter = catalog.getCurrent();
    vendor = adapter->getGPUVendor();
    if ((index = arraySearch(vendor, vendorNames, buffSize)) < 0) {
      strcpy(vendorNames[vendorCount], vendor);
      vendorItems[vendorCount++] = 1;
    } else
      vendorItems[index]++;
  } while (catalog.next());

  cout << "Cоотношение производителей ГП:\n\n";
  cout << "  Произв.    | Доля          \n";
  cout << " ------------|---------------\n";
  for (int i = 0; i < vendorCount; i++) {
    printf("  %-10s | %6.2f%% (%d)\n", vendorNames[i],
      (double) vendorItems[i] / (double) buffSize * 100.0, vendorItems[i]);
  }

  for (size_t i = 0; i < buffSize; i++)
    delete[] vendorNames[i];
}

void showMinMaxPrice() {
  VideoAdapter *adapter, *minAdapter, *maxAdapter;
  uint32_t price, minPrice, maxPrice;

  catalog.moveToFirst();
  adapter = catalog.getCurrent();
  minPrice = maxPrice = adapter->getPrice();
  minAdapter = maxAdapter = adapter;

  do {
    adapter = catalog.getCurrent();
    price = adapter->getPrice();
    if (price > maxPrice) {
      maxAdapter = adapter;
      maxPrice = price;
    } else if (price < minPrice) {
      minAdapter = adapter;
      minPrice = price;
    }
  } while (catalog.next());

  printf("\n  Mинимальная цена:  %6d руб    [%d] %s %s\n", minPrice,
    minAdapter->getId(), minAdapter->getVendor(), minAdapter->getModel());
  printf("  Максимальная цена: %6d руб    [%d] %s %s\n", maxPrice,
    maxAdapter->getId(), maxAdapter->getVendor(), maxAdapter->getModel());
}



/* ######## GENERIC UTILS ################################################################## */

int arraySearch(char *str, char **arr, size_t arrLength) {
  for (size_t i = 0; i < arrLength; i++)
    if (strcmp(str, arr[i]) == 0) return i;
  return -1;
}

void getFilePath(char *buff) {
  cout << MSG_ENTER_PATH;
  cin.getline(buff, IN_BUFF_LEN * 2);
  if (strlen(buff) == 0)
    memcpy(buff, TEST_FILE, strlen(TEST_FILE)+1);
}

void stringToFile(char* str, FILE *fp) {
  int len = strlen(str);
  fwrite(&len, 1, sizeof(len), fp);
  fwrite(str, 1, len, fp);
}

char *stringFromFile(char* buff, FILE *fp) {
  int len;
  fread(&len, 1, sizeof(len), fp);
  fread(buff, 1, len, fp);
  buff[len] = 0x00;
  return buff;
}

char getch() {
  terminal.setMode(TController::MODE_RAW);
  char keyCode = cin.get();
  terminal.setMode(TController::MODE_DEFAULT);
  return keyCode;
}
