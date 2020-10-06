#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv){
	if(argc == 1){
		char c;

		scanf("%c", &c);

		if(isalpha(c)){
			printf("sim\n");
		}
		else{
			printf("não\n");
		}
	}

	else{
		printf("%d\n", argc);

		for(int i = 0; i < argc; i++){
			printf("%d ", atoi(argv[i]));
		}
		printf("\n");

		if(argc > 3){
			char test = argv[2][0];

			if(isalpha(test)){
				printf("sim\n");
			}

			else{
				printf("não\n");
			}
		}
	}

	return 0;
}
