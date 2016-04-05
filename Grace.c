#include <stdio.h>
#include <fcntl.h>
#define	MM int main
#define FF "Grace_kid.c"
#define RR return

MM () {
	int		fd;
	char	*str = "#include <stdio.h>%c#include <fcntl.h>%c#define	MM int main%c#define FF %cGrace_kid.c%c%c#define RR return%c%cMM () {%c	int		fd;%c	char	*str = %c%s%c;%c%c	fd = open (FF, O_RDWR | O_CREAT | O_TRUNC, 0644);%c	if (fd > 0) {%c		dprintf(fd, str, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 34, str, 34 , 10, 10, 10, 10, 10, 10, 10, 10);%c	}%c	/* HEYYYY */%c	RR (0);%c}";

	fd = open (FF, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd > 0) {
		dprintf(fd, str, 10, 10, 10, 34, 34, 10, 10, 10, 10, 10, 34, str, 34 , 10, 10, 10, 10, 10, 10, 10, 10);
	}
	/* HEYYYY */
	RR (0);
}