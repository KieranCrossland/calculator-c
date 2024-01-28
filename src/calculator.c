#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <signal.h>

#define VERSION 0.4
#define NAME "calculator-c"
#define REPO_URL "https:/github.com/kierancrossland/calculator-c"

void catch_int(int sig_num) {
    signal(SIGINT, catch_int);
    printf("\n\nCaught CTRL-C SIGINT\n");
    fflush(stdout);	
	exit(0);

}

int main(int argc, char *argv[]) {

    if (argc > 1) {
        if (strcmp(argv[1],"-v") == 0) {
		printf("%s %.1f\n",NAME, VERSION);
			return 0;
		}
		if (strcmp(argv[1],"-r") == 0) {
			#ifdef __APPLE__
			system("open "REPO_URL);
			#endif
			#ifdef _WIN32
			system("start "REPO_URL);
			#else
			system("xdg-open "REPO_URL);
			#endif
			return 0;
		} 
		if (strcmp(argv[1],"-h") == 0) {
			help_arg();
			return 0;
		}
		else {
			printf("Error! Invalid argument \"%s\" ",argv[1]);
			help_arg();
			return 1;
		}
}
	calculator();
}
int help_arg() {
	printf("Avaliable arguments:\n");
	printf("  -v\tPrints the version information\n");
	printf("  -r\tOpens the program's Git repository\n");
	printf("  -h\tShows arguments\n");
}

void calculator() {
	signal(SIGINT, catch_int); 

	char operator[1];	
	int num1; 		
	int num2;

	while (true) {
		printf("Enter expression: ");
		scanf("%d",&num1);
		scanf("%s",operator);
		scanf("%d",&num2);
		
		printf("%d %s %d ",num1,operator,num2);

		if (num2 == 0 && operator[0] == '/') {
			printf("cannot divide by 0.\n");
			break;
		}
		switch (operator[0]) {
			case '+':
				printf("= %d\n", num1 + num2);
				break;
			case '-':
				printf("= %d\n", num1 - num2);
				break;
			case '/':
				printf("= %d\n", num1 / num2);
				break;
			case '*':
				printf("= %d\n", num1 * num2);
				break;
		}
	}
}
