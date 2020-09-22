#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1 | (argv[0] == "-h" || "--help")){
	printf ("Авторы: Александр Шихалев\n\tАлина Насонова\n\tГригорий Голомидов\nВсе доступные аргументы:\n\t-m - Перемещение файла\n\t-c - Копирование файла\n\t-d - удаление файла\n\t-s - Подсчет общего размера указанной директории\n\t-l - Отображение всех файлов в указанной директории\n\t-p - Отображение всех процессов из файловой системы procfs");
	printf ("Краткое описание проекта:\n\tПроект позволяет управлять файловой системой\n");
	printf ("Примеры запуска:\n\t./l2 -m <путь к файлу> <пункт назначения файла\n");
	printf ("\t./l2 -c <путь к файлу> <пункт назначениф файла>\n\t./l2 -d <путь к файлу>");
	printf ("\n\t./l2 -s <директория>\n\t./l2 -l <директория>\n");
    }
}