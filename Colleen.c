#include <stdio.h>
void	yo() {int i = 0; while (i < 4) i++;}
/* Pffff */
int		main() {
	char	*str="#include <stdio.h>%cvoid	yo() {int i = 0; while (i < 4) i++;}%c/* Pffff */%cint		main() {%c	char	*str=%c%s%c;%c	/* Heyyy */%c	yo();%c	printf(str, 10, 10, 10, 10, 34, str, 34, 10, 10, 10, 10);%c}";
	/* Heyyy */
	yo();
	printf(str, 10, 10, 10, 10, 34, str, 34, 10, 10, 10, 10);
}