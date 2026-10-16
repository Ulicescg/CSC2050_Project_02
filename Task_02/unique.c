#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	char *buffer = NULL;
	ssize_t bytes_read = 0;
	size_t buffer_size = 0;
	char *temp = NULL;

	if (argc < 2) {
		while((bytes_read = getline(&buffer, &buffer_size, stdin)) != -1) {
                	if (temp == NULL || strcmp(buffer, temp) != 0) {
                                printf("%s", buffer);
				free(temp);
				temp = buffer;
                        } else { 
				free(buffer);
			}

			buffer = NULL;
			buffer_size = 0;

                }
		free(buffer);
		free(temp);
                return 0;
	}

	char *filename = argv[1];
        FILE *fp = fopen(filename, "r");

        if (fp == NULL) {
                printf("file not open");
                return 0;
        }

	while((bytes_read = getline(&buffer, &buffer_size, fp)) != -1) {
		if (temp == NULL || strcmp(buffer, temp) != 0) {
                	printf("%s", buffer);
			free(temp);
                        temp = buffer;
                } else {
			free(buffer);
		}

                buffer = NULL;
                buffer_size = 0;
	}
        	free(buffer);
		free(temp);;
		fclose(fp);
		return 0;
}
