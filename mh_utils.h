#ifndef __MH_UTILS_H
#define __MH_UTILS_H

#include <stdio.h>
#include <errno.h>

enum log_location {
	CMDLINE,
	LOGFILE,
};

/*
 * ANSI color codes
 */
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define KORANGE "\x1B[38;5;52m"

#define log(...) (fprintf(stdout, __VA_ARGS__))
#define log_info(...) (fprintf(stdout, KBLU "INFO:\t" KNRM __VA_ARGS__))
#define log_warn(...) (fprintf(stdout, KORANGE "WARN:\t" KNRM __VA_ARGS__))
#define log_err(...)							\
	do {								\
		fprintf(stderr, KRED "ERROR:\t" KNRM  __VA_ARGS__);	\
		fprintf(stderr, "\terrno: %s\n", strerror(errno));	\
		exit(EXIT_FAILURE);					\
	}								\
	while (0)


/**
 * @brief Reverses a string in place
 * @param seq The character sequence to be reversed
 */
void reverse(char *seq);

#endif
