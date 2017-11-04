#ifndef _ERROR_CODES_H
#define _ERROR_CODES_H

#define SUCCESS (-1)

#define MALLOC_ERROR 0
#define NULL_POINTER_ERROR 1
#define DIVISION_BY_ZERO_ERROR 2

const static char *error_messages[] = {
			"MALLOC_ERROR: Failed memory allocation with 'malloc()'", \
			"NULL_POINTER_ERROR: Invalid operation on null pointer attempted", \
			"DIVISION_BY_ZERO_ERROR: Attempting to divide by 0",
};

#define error_message(error_code) (error_messages[(error_code)])

#endif
