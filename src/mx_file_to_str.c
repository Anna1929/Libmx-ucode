#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
	int len = 0;
	char c;
	int string_read = 0;
	
	if (!file) return NULL;
	int f = open(file, O_RDONLY);
	if (f < 0) return NULL;
	
	while (read(f, &c, 1)) {
		len++;
	}
	close(f);
	
	f = open(file, O_RDONLY);
	if (f < 0) return NULL;
	if (len == 0) return NULL;
	
	char *p = mx_strnew(len);
	string_read = read(f, p, len);
	close(f);
	return p;
}
	
	
