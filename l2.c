#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
    if (argc == 1){
	printf ("./l2 -h\n");
	exit(1);
    }
    DIR *opendir(const char *name);
    struct dirent *pdir;
    DIR *pd, *pd1;
    char *opt = argv[1];
    if(opt[1] == '-')
	opt[1] = 'h';
    switch(opt[1]){
	//default:
	case 'h':
	    printf ("Авторы: Александр Шихалев\n\tАлина Насонова\n\tГригорий Голомидов\nВсе доступные аргументы:\n\t-m - Перемещение файла\n\t-c - Копирование файла\n\t-d - удаление файла\n\t-s - Подсчет общего размера указанной директории\n\t-l - Отображение всех файлов в указанной директории\n\t-p - Отображение всех процессов из файловой системы procfs");
	    printf ("Краткое описание проекта:\n\tПроект позволяет управлять файловой системой\n");
	    printf ("Примеры запуска:\n\t./l2 -m <путь к файлу> <пункт назначения файла\n");
	    printf ("\t./l2 -c <путь к файлу> <пункт назначениф файла>\n\t./l2 -d <путь к файлу>");
	    printf ("\n\t./l2 -s <директория>\n\t./l2 -l <директория>\n");
	    break;
	case 'l':
	    if(argc < 3){
		printf("./l2 -l <директория>\n");
		break;
	    }
	    pd = opendir(argv[2]);
	    while ((pdir = (readdir(pd))) != NULL){
		printf("%s\n", pdir->d_name);
	    }
	    closedir(pd);
	    break;
    }
}