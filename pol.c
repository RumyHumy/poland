#include <stdio.h>
#include <stdlib.h>

char ordmap[255];

char** ToksAlloc(char* str) {
	char** toks;
	char* estr;
	
	int tcount = 0;
	for (char* ptr = str; *ptr; ptr++) {
		if (ordmap[*ptr])
			tcount
	}
}

char* ToksPrint(char** toks) {
	for (; *toks[i]; toks++) {
		printf("%s ", toks[i]);
	}
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

	if (argc != 2) {
		if (argc < 2)
			printf("Not enough arguments.\n");
		else
			printf("Too much arguments.\n");
		printf("./pol \"a+b*c\"");
		exit(1);
	}

	char** infix = ToksAlloc(argv[1]);
	ToksPrint();
	ToksFree(infix);

	return 0;
}
