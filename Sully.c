#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main () {
	int	fd;
	int	j = 5;
	char	*tmp_s = "Sully_";
	char	*tmp_ext = ".c";
	char	*filename;
	char	*str = "";
	// Sully_X.c

	filename = malloc(10);
	while (j) {
		char	num = 48 + j;
		int i = j;
		filename = strncat(tmp_s, &num, 1);
		filename = strcat(filename, tmp_ext);
		if( access( filename, F_OK ) != -1 ) {    
		} else {
			fd = open (filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
			if (fd > 0) {
				dprintf(fd, "blabla %d", j);
			}
		}
		j--;
	}
	// if (strncmp ("Sully_"))
	
	return (0);
}