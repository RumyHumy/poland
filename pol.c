#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOC_CHECK(var) \
	if (!var) { printf("Out of memory."); exit(1); }

char ordmap[255];

char** ToksAlloc(char* str) {
	int len = strlen(str);
	char* estr = calloc(len*2, sizeof(char));
	ALLOC_CHECK(estr)
	char** toks = calloc(len+1, sizeof(char*));
	ALLOC_CHECK(toks)
	toks[0] = estr;
	int j = 0;
	int t = 1;
	for (char* ptr = str; *ptr; ptr++) {
		estr[j++] = *ptr;
		if (ordmap[*(ptr+1)]) {
			estr[j++] = '\0';
		} else if (ordmap[*ptr]) {
			toks[t++] = estr+j-1;
			estr[j++] = '\0';
			if (*(ptr+1) != '\0')
				toks[t++] = estr+j;
		}
	}
	return toks;
}

void ToksFree(char** toks) {
	free(toks[0]);
	free(toks);
}

int main(int argc, char* argv[]) {

	ordmap['+'] = 1;
	ordmap['-'] = 1;
	ordmap['*'] = 2;
	ordmap['/'] = 2;
	ordmap['^'] = 3;
	ordmap['('] = -1;
	ordmap[')'] = -1;

	if (argc != 2) {
		if (argc < 2)
			printf("Not enough arguments.\n");
		else
			printf("Too much arguments.\n");
		printf("./pol \"a+b*c\"");
		exit(1);
	}

	char** infix = ToksAlloc(argv[1]);
	for (char** ptr = infix; *ptr; ptr++)
		printf("%s\n", *ptr);
	ToksFree(infix);

	return 0;
}
