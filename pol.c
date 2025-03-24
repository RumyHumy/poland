#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// U T I L

void PrintStringArray(char** arr, char* sep) {
	for (char** ptr = arr; *ptr; ptr++)
		printf("%s%s", *ptr, *(ptr+1) ? sep : "");
}

#define ALLOC_CHECK(var) \
	if (!var) { printf("Out of memory."); exit(1); }

// G L O B A L

char ordmap[255];

// T O K E N S

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

// E X P R E S S I O N S

typedef struct ExpNode ExpNode;
struct ExpNode {
	char* value;
	ExpNode* left;
	ExpNode* right;
};

typedef struct ExpTree ExpTree;
struct ExpTree {
	char** toks;
	ExpNode* root;
};

ExpTree ExpTreeAlloc(char* str) {
	char** infix = ToksAlloc(str);
	PrintStringArray(infix, ", ");

	ExpTree exp;
	return exp;
}

void ExpTreeFree(ExpTree exp) {
	//free(exp.toks[0]);
	//free(exp.toks);
	// TODO: Tree free
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
		printf("./pol \"a+b*c\"\n");
		exit(1);
	}

	ExpTree exp = ExpTreeAlloc(argv[1]);
	ExpTreeFree(exp);

	return 0;
}
