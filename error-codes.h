#ifndef _ERROR_CODES_H
#define _ERROR_CODES_H

#define SUCCESS -1

#define MALLOC_FAILURE 0
#define NULL_POINTER_FAILURE 1

const static char *error_messages[] = {
			"MALLOC_FAILURE: Failed memory allocation with 'malloc()'", \
			"NULL_POINTER_FAILURE: Invalid operation on null pointer attempted",
};

#define error_message((error_code)) (error_messages[(error_code)])

#endif
