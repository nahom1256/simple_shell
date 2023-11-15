#ifndef _NASHELL_H_
#define _NASHELL_H_

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/* Global */
extern char **enviroment;
/* program name */
char *nahomname;
/* history */
int history;

/**
 * struct nalist_s - A new struct type 
 * @dir: path.
 * @next: pointer
 */
typedef struct list_s
{
  char *ndir;
  struct list_s *next;
} list_t;

/**
 * struct nabuiltin_s - A new struct type
 * @nahomname: name
 * @n: pointer
 */
typedef struct nabuiltin_s
{
  int (*n)(char **argv, char **front);
  char *nahomname;
} nabuiltin_t;

/**
 * struct ahomelias_s - A new struct
 * @nahomname: name
 * @navalue: value
 * @next: pointer
 */
typedef struct alias_s
{
  char *nahomname;
  char *navalue;
  struct alias_s *next;
} alias_t;

/*  aliases linked list */
alias_t *aliases;

/* IH */
void nahomhandle (char **nline, ssize_t read);
void nahomreplacement(char **args, int *ret);
char *naget_args(char *nline, int *ret);
int nacall_args(char **args, char **front, int *ret);
int narun_args(char **args, char **front, int *ret);
int nahandle_args(int *ret);
int nacheck_args(char **args);
void nafree_args(char(char **args, char **front);
char **nareplace_aliases(char **args);

/* MH */
ssize_t _getnaline(char **nalineptr, size_t *f, FILE *nahomstream);
void *_narealloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_nastrtok(char *nline, char *ndelim);
char *get_location(char *command);
list_t *get_path_dir(char *napath);
int naexecute(char **args, char **front);
void ee_list(list_t *nahead);
char *_itoa(int num);

/* B */
int (*get_nabuiltin(char *command))(char **args, char **front);
int nahom_exit(char **args, char **front);
int nahom_env(char **args, char __attribute__((__unused__)) **front);
int nahom_setenv(char **args, char __attribute__((__unused__)) **front);
int nahom_unsetenv(char **args, char __attribute__((__unused__)) **front);
int nahom_cd(char **args, char __attribute__((__unused__)) **front);
int nahom_alias(char **args, char __attribute__((__unused__)) **front);
int nahom_help(char **args, char __attribute__((__unused__)) **front);

/* SF */
int nastrlen(const char *d);
char *nastrcat(char *est, const char *src);
char *nastrncat(char *est, const char *src, size_t f);
char *nastrcpy(char *est, const char *src);
char *nastrchr(char *d, char c);
int nastrspn(char *d, char *accept);
int nastrcmp(char *p, char *o);
int nastrncmp(const char *p, const char *o, size_t f);

/* EH */
int na_error(char **args, int eryr);
char *naerrorenv(char **args);
char *naerrora(char **args);
char *naerrorexit(char **args);
char *naerrorcd(char **args);
char *naerrorsyntax(char **args);
char *naerrorb(char **args);
char *naerrorc(char **args);

/* BH */
char **_copyna(void);
void free_nahom(void);
char **_getnahom(const char *var);

/* LH */
alias_t *add_alias_end(alias_t **head, char *name, char *value);
void free_alias_list(alias_t *head);
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

void helpna_all(void);
void helpna_alias(void);
void helpna_cd(void);
void helpna_exit(void);
void helpna_help(void);
void helpna_env(void);
void helpna_setenv(void);
void helpna_unsetenv(void);
void helpna_history(void);

int proc_file_commands(char *file_path, int *exe_ret);
#endif /* _NASHELL_H_ */
