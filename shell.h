#ifndef SHELL_H
#define SHELL_H

/*****LIBRARY FUNCTION****/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define BUFSIZE 1000
#define DELIM "\a\t\r\n"

/** command type **/
#define INTERNAL_CMD 1
#define EXTERNAL_CMD 2
#define PATH_CMD 3
#define INVALID_CMD -1

/* declaring variable */
extern char **environ;
typedef struct internal_func
{
	char *cmd_name;
	void (*func)(char **command);
} map_func;

/** builtin command **/
void change_dir(char **);
void dis_env(char **);
void quit(char **);

/** SHELL UTILITES FUNCTION **/
void ctrl_C(int);
char *_getline(void);
char **tokenize(char *, const char *);
void shell_execute(char **, int);
int check_command(char *);
void execute(char **, int);


/** helper function **/
int printer(char *, int);
void (*get_func(char *))(char **);

/** STRING FUNCTION **/
int _strlen(char *);
int _strcmp(char*, char *);

/** shell memory management **/
void *_realloc(void *, int, int);

/** shell environment **/
char *_getenv(char *);
#endif
