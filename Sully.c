#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main () {
	int		fd;int ret_access;int i = 5;pid_t pid0;pid_t pid1;char *binary_name = NULL;char *args0[5];char *args1[2];char *filename = NULL;pid_t tpid = -2;int child_status;
	char *str="#include <stdio.h>%c#include <fcntl.h>%c#include <string.h>%c#include <unistd.h>%c#include <stdlib.h>%c#include <sys/types.h>%c#include <sys/wait.h>%cint main () {%c	int		fd;int ret_access;int i = %d;pid_t pid0;pid_t pid1;char *binary_name = NULL;char *args0[5];char *args1[2];char *filename = NULL;pid_t tpid = -2;int child_status;%c	char *str=%c%s%c;%c	filename = malloc(10);sprintf(filename, %cSully_%cd.c%c, i);%c	if ( (ret_access = access( filename, F_OK ) ) != -1 ) {i--;sprintf(filename, %cSully_%cd.c%c, i);}perror(%caccess%c);%c	fd = open (filename, O_RDWR | O_CREAT | O_TRUNC, 0644);printf(%cfd : %cd%cn%c, fd);%c	if (fd > 0) {int rrt = dprintf(fd, str, 10, 10, 10, 10, 10, 10, 10, 10, i, 10, 34, str, 34,10, 34, 37, 34, 10, 34, 37, 34, 34, 34, 10, 34, 37, 92,34, 10, 34, 37, 37, 92, 34, 10, 34, 37, 34, 34, 34, 34, 34, 10, 10, 34, 34, 10, 10, 34, 37, 92, 34, 34, 34, 10, 10);printf(%cdprintf ret : %cd, in %cs%cn%c, rrt, filename);}%c	if (i > 0) {binary_name = (char*)malloc(sizeof(char) * 8);sprintf(binary_name,%cSully_%cd%c, i);		args0[0] = %cclang-3.5%c;args0[1] = filename;args0[2] = %c-o%c;args0[3] = binary_name;%c		args0[4] = NULL;args1[0] = binary_name;args1[1] = NULL;pid0 = fork();%c		if (pid0 == 0) {execvp(args0[0], args0);perror(%cexecvp0%c);}else {while (tpid!=pid0){tpid = wait(&child_status);}}%c		pid1 = fork();%c		if (pid1 == 0) {printf(%cfile to exec : %cs%cn%c, args1[0]);execv(args1[0], args1);perror(%cexecvp1%c);} else {while (tpid!=pid1){tpid = wait(&child_status);}}%c	}%c	return (0);}";
	filename = malloc(10);sprintf(filename, "Sully_%d.c", i);
	if ( (ret_access = access( filename, F_OK ) ) != -1 ) {i--;sprintf(filename, "Sully_%d.c", i);}perror("access");
	fd = open (filename, O_RDWR | O_CREAT | O_TRUNC, 0644);printf("fd : %d\n", fd);
	if (fd > 0) {int rrt = dprintf(fd, str, 10, 10, 10, 10, 10, 10, 10, 10, i, 10, 34, str, 34,10, 34, 37, 34, 10, 34, 37, 34, 34, 34, 10, 34, 37, 92,34, 10, 34, 37, 37, 92, 34, 10, 34, 37, 34, 34, 34, 34, 34, 10, 10, 34, 34, 10, 10, 34, 37, 92, 34, 34, 34, 10, 10);printf("dprintf ret : %d, in %s\n", rrt, filename);}
	if (i > 0) {binary_name = (char*)malloc(sizeof(char) * 8);sprintf(binary_name,"Sully_%d", i);		args0[0] = "clang-3.5";args0[1] = filename;args0[2] = "-o";args0[3] = binary_name;
		args0[4] = NULL;args1[0] = binary_name;args1[1] = NULL;pid0 = fork();
		if (pid0 == 0) {execvp(args0[0], args0);perror("execvp0");}else {while (tpid!=pid0){tpid = wait(&child_status);}}
		pid1 = fork();
		if (pid1 == 0) {printf("file to exec : %s\n", args1[0]);execv(args1[0], args1);perror("execvp1");} else {while (tpid!=pid1){tpid = wait(&child_status);}}
	}
	return (0);}