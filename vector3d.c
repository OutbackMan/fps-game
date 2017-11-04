#include "vector3d.h"
#include "error-codes.h"

#include <stdlib.h>

int vector3d_create(const float x, const float y, const float z, struct Vector3D *output_vector)
{
	output_vector = malloc(sizeof(struct Vector3D));
	
	if (output_vector == NULL) {
		return MALLOC_FAILURE;
	} else {
		output_vector->x = x;
		output_vector->y = y;
		output_vector->z = z;

		return SUCCESS;
	}
}

void vector3d_destroy(struct Vector3D *input_vector)
{
	free(input_vector);

	input_vector = NULL;
}

int vector3d_dot_product(struct Vector3D *input_vector1, struct Vector3D *input_vector2, float *output_value)
{
	if (input_vector1 == NULL || input_vector2 == NULL) {
		return NULL_POINTER_FAILURE;	
	} else {
		*output_value = (input_vector1->x * input_vector2->x) +
		               (input_vector1->y * input_vector2->y) +
			       (input_vector1->z * input_vector2->z);
		
		return SUCCESS;
	}
}
