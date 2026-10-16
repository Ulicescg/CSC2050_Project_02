#include <stdio.h>

int main(int argc, char *argv[]) {
	int ch;
	int lines = 0;
        int wrdCount = 0;
        int chCount = 0;
	
	if (argc < 2) {
		while((ch = fgetc(stdin)) != EOF) {
			chCount += 1;
			if (ch == '\n') {
                        	lines += 1;
                	}

                	if (ch == ' ' || ch == '\n' ) {
                        	wrdCount += 1;
                	}
		}

		printf("      %d       %d      %d\n", lines, wrdCount, chCount);
		return 0;
	}

	char *filename = argv[1];
	FILE *fp = fopen(filename, "r");
	
	if (fp == NULL) {
		printf("file not open");
		return 0;
	}

	ch = fgetc(fp);
	while(ch != EOF) {
		ch = fgetc(fp);
		chCount += 1;
		if (ch == '\n') {
			lines += 1;
		}

		if (ch == ' ' || ch == '\n' ) {
			wrdCount += 1;
		}
	}
	
	fclose(fp);	
	printf("%d %d %d %s\n", lines, wrdCount, chCount, filename);
	
	return 0;

}
