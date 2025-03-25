#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// U T I L

void PrintString(char* str, int n) {
	for (int i = 0; i < n; i++)
		printf("%c", str[i]);
}

void PrintStringArrayN(char** arr, char* sep, int n) {
	for (int i = 0; i < n; i++)
		printf("'%s'%s", arr[i], i != n-1 ? sep : " ");
}

void PrintStringArray(char** arr, char* sep) {
	for (char** ptr = arr; *ptr; ptr++)
		printf("'%s'%s", *ptr, *(ptr+1) ? sep : " ");
}

#define ALLOC_CHECK(var) \
	if (!var) { printf("Out of memory."); exit(1); }

// G L O B A L

char ordmap[255];

// T O K E N S

char** ToksAlloc(char* str) {
	// Extended string with separators
	int len = strlen(str);
	char* estr = calloc(len*2+1, sizeof(char));
	ALLOC_CHECK(estr)
	char** toks = calloc(len+1, sizeof(char*));
	ALLOC_CHECK(toks)
	toks[0] = estr;
	int j = 0;
	int t = 1;
	for (char* ptr = str; *ptr; ptr++) {
		estr[j++] = *ptr;
		if (ordmap[*ptr] || ordmap[*(ptr+1)]) {
			estr[j++] = '\0';
			if (*(ptr+1) != '\0')
				toks[t++] = estr+j;
		}
	}
	// Write tokens in an array
	//printf("%d %d\n", j, t);
	estr = (char*)realloc(estr, j*sizeof(char));
	ALLOC_CHECK(estr)
	toks = (char**)realloc(toks, (t+1)*sizeof(char*));
	ALLOC_CHECK(toks)
	//PrintString(estr, j);
	//printf("\n");
	//PrintStringArrayN(toks, ", ", t+1);
	//printf("\n");
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
	ExpTree exp;
	exp.toks = ToksAlloc(str);
	exp.root = NULL;
	PrintStringArray(exp.toks, ", ");
	printf("\n");

	// Constructing tree
	//char** ops;
	//ALLOC_CHECK(ops)
	//ExpNode** nodes;
	//ALLOC_CHECK(ops)
	
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
