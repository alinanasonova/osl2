#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

static void pf(size_t lvl, const char *t, const char *name)
{
    while(lvl--)
	printf(" ");
    printf("%s: %s\n", t, name);
}

int sss(size_t lvl, const char *dname)
{
    struct stat st;
    struct dirent *ent;
    DIR *d;
    int c = 0;
    char n[PATH_MAX + 1];
    d = opendir(dname);
    while(d && (ent = readdir(d))){
	if(!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
	    continue;
	sprintf(n, "%s/%s", dname, ent->d_name);
	stat(n, &st);
	if(S_ISDIR(st.st_mode)){
	    c += sss(lvl + 1, n);
	} else {
	    pf(lvl + 1, "file", n);
	    c += st.st_size;
	}
    }
    if (d) closedir(d);
    return c;
}

int main(int argc, char *argv[])
{
    if (argc == 1){
	printf ("./l2 -h\n");
	exit(1);
    }
    
    DIR *opendir(const char *name);
    struct dirent *pdir;
    DIR *pd, *pd1;
    struct stat st;
    int count = 0;
    
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
	case 's':
	    if(argc < 3){
		printf("./l2 -s <директория>\n");
		break;
	    }
	    //printf("%s\n\n", argv[2]);
	    printf("%d\n", sss(0, argv[2]));
	    break;
    }
}