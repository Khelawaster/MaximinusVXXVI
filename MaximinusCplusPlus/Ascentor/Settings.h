#define BUFFER_SIZE 257 //������ ������ ��� ������ ����� ������������
// 257=128(��� ���������)+128(��������)+1(���� ���������)


#define COMMENT_SYMBOL ';' //� ����� ������� ���������� ����������� � ����� ������������
#define COMMENT_SEPARATOR '=' //���� �������� ����������� ������������ � �������� ���������

const int SettingsCount = 4;//��� �������� ����� ����������� ����������

struct Settings
{
	int InfoMaxRandomValue;// ������������ �������� Info � ��������� ������
	int ListDefaultLength;
	int ListElementDefaultInfo;
	char ArrayRandomValues;
	//double USDRUB;
	//char* UserName;
};

void WriteSetting(char* settingComment, char* settingName, char* settingValue, FILE* fp)
{
	/*;����� ������ �� ���������
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
	if (string[0] == COMMENT_SYMBOL) return 0;//����������� ����������
	char* ch = name; //������� ������ � ���������� name
	int j = 0; //���������� ����� ������������ �������
	for (int i = 0; i < strlen(string); i++, j++)
	{
		if (string[i] == COMMENT_SEPARATOR)
		{ //���� �������� �� �����������
			ch[j] = '\0'; //��������� ���������� name
			ch = value; //������ ����� ������ � ���������� value
			j = -1; //�������� ����� �������
			continue;
		}
		else if (string[i] == '\n')
		{ //���� �������� �� �����
			ch[j] = '\0'; //��������� ���������� value
			break;//������� �� �����
		}
		else
			ch[j] = string[i];	//����� ������ � ������� ����������	 
	}
	return 1;
}

void SettingsCreate()
{
	printf("���� ������������ ����� ������������ �� ���������� �� ���������.\n������� ������ (���� ��� ����) - ��. options.bak\n");
	const char* filename = "options.dat";
	FILE* fp = fopen(filename, "r");
	if (fp)
	{
		fclose(fp);
		rename(filename, "options.bak");
	}
	fp = fopen(filename, "w"); //��������� ���� ����������� ��� ������. 
	//���� ���� ����� �����������, �� �� ������������� � ������������ ������
	if (fp == NULL)
	{
		printf("�� �� ���������!!!\n�� ���� ������� ���� ������������.");
		_fcloseall();
		_exit(1);
	}
	fputc(COMMENT_SYMBOL, fp);
	fputs("���� ������������ ��������� Maximinus\n", fp);
	fputc(COMMENT_SYMBOL, fp);
	fputs("��������! ����� ������ ��������� �� ������ ��������� 128 ��������!\n", fp);
	WriteSetting("��������� ��������� �������", "ArrayRandomValues", "1", fp);
	WriteSetting("����� ������ �� ���������", "ListDefaultLength", "9", fp);
	WriteSetting("�������� �������� ������ �� ���������", "ListElementDefaultInfo", "0", fp);
	WriteSetting("������������ �������� ���������� �������� ������ �� ���������", "InfoMaxRandomValue", "99", fp);
	fclose(fp);
}
struct Settings * SettingsRead()
{
	struct Settings * ret = (struct Settings*) malloc(sizeof (struct Settings));
	FILE* fp;
	int cnt; //������� ����������� ����������
TRYAGAIN:
	cnt = 0;
	//�������� ������� ���� ������������
	fp = fopen("options.dat", "r");
	if (fp == NULL)
	{
		//���� ��� ��� - ������ � �������� �������
		printf("���� ������������ �� ������\n");
		SettingsCreate();
		goto TRYAGAIN;
	}
	/* ������ ������ ���������
	;intSetting - �����������
	intSetting=1 */
	char buffer[BUFFER_SIZE]; //���� ������ ������ �� �����
	char settingName[BUFFER_SIZE / 2 - 1]; // ���� �������� ��� ����������
	char settingValue[BUFFER_SIZE / 2 - 1];// ���� ��������
	while ((fgets(buffer, 257, fp)) != NULL)//������ ������ � �����
	{
		//������� ����� � ������� ParseSettingString. ��� ������ ��� � 
		//�������� ��� � �������� ��������� � ���������� settingName � settingValue ��������������
		if (ParseSettingString(buffer, settingName, settingValue) == 1)
		{ //ParseSettingString ������� 1 - ������ �� �����������
			//������������ ���������� ������ settingValue

			char* end;/* ����� �������� strtol � strtod
			���� ��������� ����� ������� ������������ �������
			*/
			if (strcmp(settingName, "ListDefaultLength") == 0) //������ ��� ������ �� ��������
			{
				ret->ListDefaultLength = strtol(settingValue, &end, 10);//10 - ������ ���������� �������
				if (end == settingValue) {//�� ���� ������ ���������� � ������������. �� ����� ����� �� ������� ���������
					printf("�� �������� �������� ��������� ListDefaultLength %s\n", settingValue);
					SettingsCreate();
					goto TRYAGAIN; //��� goto ����� ����� - ��� ����� (�������� ������� ����� � �������� ��� ����������)
				}
				cnt++;
			}
			if (strcmp(settingName, "ListElementDefaultInfo") == 0) //������ ��� ������ �� ��������
			{
				ret->ListElementDefaultInfo = strtol(settingValue, &end, 10);//10 - ������ ���������� �������
				if (end == settingValue) {//�� ����� ����� �� ������� ���������
					printf("�� �������� �������� ��������� ListElementDefaultInfo %s\n", settingValue);
					SettingsCreate();
					goto TRYAGAIN; 
				}
				cnt++;
			}
			if (strcmp(settingName, "InfoMaxRandomValue") == 0) //������ ��� ������ �� ��������
			{
				ret->InfoMaxRandomValue = strtol(settingValue, &end, 10);//10 - ������ ���������� �������
				if (end == settingValue) {//�� ����� ����� �� ������� ���������
					printf("�� �������� �������� ��������� InfoMaxRandomValue %s\n", settingValue);
					SettingsCreate();
					goto TRYAGAIN; 
				}
				cnt++;
			}
			if (strcmp(settingName, "ArrayRandomValues") == 0) //������ ��� ������ �� ��������
			{
				ret->ArrayRandomValues = strtol(settingValue, &end, 10);//10 - ������ ���������� �������
				if (end == settingValue) {//�� ����� ����� �� ������� ���������
					printf("�� �������� �������� ��������� ArrayRandomValues %s\n", settingValue);
					SettingsCreate();
					goto TRYAGAIN;
				}
				cnt++;
			}
		}
	}
	if (cnt != SettingsCount) {
		printf("��������� �� ��� ���������\n");
		SettingsCreate();
		goto TRYAGAIN;
	}
	fclose(fp);
	return ret;
}
