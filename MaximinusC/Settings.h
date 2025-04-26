#define BUFFER_SIZE 257 //размер буфера для чтения файла конфигурации
// 257=128(имя параметра)+128(значение)+1(знак равенства)


#define COMMENT_SYMBOL ';' //с этого символа начинается комментарий в файле конфигурации
#define COMMENT_SEPARATOR '=' //этим символом разделяются наименование и значение параметра

const int SettingsCount = 4;//для контроля числа прочитанных параметров

struct Settings
{
	int InfoMaxRandomValue;// максимальное значение Info в случайном списке
	int ListDefaultLength;
	int ListElementDefaultInfo;
	char ArrayRandomValues;
	//double USDRUB;
	//char* UserName;
};

void WriteSetting(char* settingComment, char* settingName, char* settingValue, FILE* fp)
{
	/*;Длина списка по умолчанию
      ListDefaultLength=9*/;
	fputc(COMMENT_SYMBOL, fp);
	fputs(settingComment, fp);
	fputc('\n', fp);
	fputs(settingName, fp);
	fputc(COMMENT_SEPARATOR, fp);
	fputs(settingValue, fp);
	fputc('\n', fp);
}

int ParseSettingString(char* string, char* name, char* value) {
	if (string[0] == COMMENT_SYMBOL) return 0;//комментарий пропускаем
	char* ch = name; //сначала читаем в переменную name
	int j = 0; //порядковый номер прочитанного символа
	for (int i = 0; i < strlen(string); i++, j++)
	{
		if (string[i] == COMMENT_SEPARATOR)
		{ //если дочитали до разделителя
			ch[j] = '\0'; //завершаем переменную name
			ch = value; //теперь будем читать в переменную value
			j = -1; //обнуляем номер символа
			continue;
		}
		else if (string[i] == '\n')
		{ //если дочитали до конца
			ch[j] = '\0'; //завершаем переменную value
			break;//выходим из цикла
		}
		else
			ch[j] = string[i];	//пишем символ в текущую переменную	 
	}
	return 1;
}

void SettingsCreate()
{
	printf("Файл конфигурации будет восстановлен со значениями по умолчанию.\nПрежняя версия (если она была) - см. options.bak\n");
	const char* filename = "options.dat";
	FILE* fp = fopen(filename, "r");
	if (fp)
	{
		fclose(fp);
		rename(filename, "options.bak");
	}
	fp = fopen(filename, "w"); //текстовый файл открывается для записи. 
	//Если файл ранее существовал, то он пересоздается и записывается заново
	if (fp == NULL)
	{
		printf("Ой всё сломалось!!!\nНе могу создать файл конфигурации.");
		_fcloseall();
		_exit(1);
	}
	fputc(COMMENT_SYMBOL, fp);
	fputs("Файл конфигурации программы Maximinus\n", fp);
	fputc(COMMENT_SYMBOL, fp);
	fputs("Внимание! Длина любого параметра не должна превышать 128 символов!\n", fp);
	WriteSetting("Случайная генерация массива", "ArrayRandomValues", "1", fp);
	WriteSetting("Длина списка по умолчанию", "ListDefaultLength", "9", fp);
	WriteSetting("Значение элемента списка по умолчанию", "ListElementDefaultInfo", "0", fp);
	WriteSetting("Максимальное значение случайного элемента списка по умолчанию", "InfoMaxRandomValue", "99", fp);
	fclose(fp);
}
struct Settings * SettingsRead()
{
	struct Settings * ret = (struct Settings*) malloc(sizeof (struct Settings));
	FILE* fp;
	int cnt; //счётчик прочитанных параметров
TRYAGAIN:
	cnt = 0;
	//пытаемся открыть файл конфигурации
	fp = fopen("options.dat", "r");
	if (fp == NULL)
	{
		//если его нет - создаём и начинаем сначала
		printf("Файл конфигурации не найден\n");
		SettingsCreate();
		goto TRYAGAIN;
	}
	/* Пример записи параметра
	;intSetting - комментарий
	intSetting=1 */
	char buffer[BUFFER_SIZE]; //сюда читаем строку из файла
	char settingName[BUFFER_SIZE / 2 - 1]; // сюда помещаем имя переменной
	char settingValue[BUFFER_SIZE / 2 - 1];// сюда значение
	while ((fgets(buffer, 257, fp)) != NULL)//читаем строку в буфер
	{
		//передаём буфер в функцию ParseSettingString. Она парсит его и 
		//помещает имя и значение параметра в переменные settingName и settingValue соответственно
		if (ParseSettingString(buffer, settingName, settingValue) == 1)
		{ //ParseSettingString вернула 1 - значит не комментарий
			//конвертируем полученную строку settingValue

			char* end;/* нужна функциям strtol и strtod
			сюда передаётся адрес первого непотребного символа
			*/
			if (strcmp(settingName, "ListDefaultLength") == 0) //просто так строки не сравнить
			{
				ret->ListDefaultLength = strtol(settingValue, &end, 10);//10 - значит десятичная система
				if (end == settingValue) {//то есть строка начинается с непотребства. Ни одной цифры не удалось прочитать
					printf("Не читается значение параметра ListDefaultLength %s\n", settingValue);
					SettingsCreate();
					goto TRYAGAIN; //без goto здесь никак - два цикла (проверка наличия файла и проверка его читаемости)
				}
				cnt++;
			}
			if (strcmp(settingName, "ListElementDefaultInfo") == 0) //просто так строки не сравнить
			{
				ret->ListElementDefaultInfo = strtol(settingValue, &end, 10);//10 - значит десятичная система
				if (end == settingValue) {//Ни одной цифры не удалось прочитать
					printf("Не читается значение параметра ListElementDefaultInfo %s\n", settingValue);
					SettingsCreate();
					goto TRYAGAIN; 
				}
				cnt++;
			}
			if (strcmp(settingName, "InfoMaxRandomValue") == 0) //просто так строки не сравнить
			{
				ret->InfoMaxRandomValue = strtol(settingValue, &end, 10);//10 - значит десятичная система
				if (end == settingValue) {//Ни одной цифры не удалось прочитать
					printf("Не читается значение параметра InfoMaxRandomValue %s\n", settingValue);
					SettingsCreate();
					goto TRYAGAIN; 
				}
				cnt++;
			}
			if (strcmp(settingName, "ArrayRandomValues") == 0) //просто так строки не сравнить
			{
				ret->ArrayRandomValues = strtol(settingValue, &end, 10);//10 - значит десятичная система
				if (end == settingValue) {//Ни одной цифры не удалось прочитать
					printf("Не читается значение параметра ArrayRandomValues %s\n", settingValue);
					SettingsCreate();
					goto TRYAGAIN;
				}
				cnt++;
			}
		}
	}
	if (cnt != SettingsCount) {
		printf("Прочитаны не все параметры\n");
		SettingsCreate();
		goto TRYAGAIN;
	}
	fclose(fp);
	return ret;
}
