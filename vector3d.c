#include "vector3d.h"
#include "error-codes.h"

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int vector3d_create(const float x, const float y, const float z, struct Vector3D *output_vector)
{
	output_vector = malloc(sizeof(struct Vector3D));
	
	if (output_vector == NULL) {
		return MALLOC_ERROR;
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
	if (input_vector1 == NULL || input_vector2 == NULL || output_value == NULL) {
		return NULL_POINTER_ERROR;	
	} else {
		*output_value = (input_vector1->x * input_vector2->x) +
		                (input_vector1->y * input_vector2->y) +
			            (input_vector1->z * input_vector2->z);
		
		return SUCCESS;
	}
}

int vector3d_length(struct Vector3D *input_vector, float *output_length)
{
	if (input_vector == NULL || output_length == NULL) {
		return NULL_POINTER_ERROR;
	} else {
		*output_length = sqrt((input_vector->x * input_vector->x) +
							  (input_vector->y * input_vector->y) +
							  (input_vector->z * input_vector->z));
		
		return SUCCESS;
	}
}

int vector3d_normalise(struct Vector3D *input_output_vector)
{
	float vector_length;
	
	vector3d_length(input_output_vector, &vector_length);

	if (vector_length == 0) {
		return DIVISION_BY_ZERO_ERROR;
	} else {
		input_output_vector->x /= vector_length;	
		input_output_vector->y /= vector_length;	
		input_output_vector->z /= vector_length;	

		return SUCCESS;
	}
}

int vector3d_change_all_coordinates(struct Vector3D *input_vector, const float x, const float y, const float z)
{
	if (input_vector == NULL) {
		return NULL_POINTER_ERROR;
	} else {
		input_vector->x = x;	
		input_vector->y = y;	
		input_vector->z = z;	

		return SUCCESS;
	}
}

int vector3d_copy_vector(struct Vector3D *source_vector, struct Vector3D *destination_vector)
{
	if (source_vector == NULL || destination_vector == NULL) {
		return NULL_POINTER_ERROR;
	} else {
		destination_vector->x = source_vector->x;	
		destination_vector->y = source_vector->y;	
		destination_vector->z = source_vector->z;	

		return SUCCESS;
	}
}

int vector3d_change_x_coordinate(struct Vector3D *input_vector, const float x)
{
	if (input_vector == NULL) {
		return NULL_POINTER_ERROR;
	} else {
		input_vector->x = x;	

		return SUCCESS;
	}
}

int vector3d_change_y_coordinate(struct Vector3D *input_vector, const float y)
{
	if (input_vector == NULL) {
		return NULL_POINTER_ERROR;
	} else {
		input_vector->y = y;	

		return SUCCESS;
	}
}

int vector3d_change_z_coordinate(struct Vector3D *input_vector, const float z)
{
	if (input_vector == NULL) {
		return NULL_POINTER_ERROR;
	} else {
		input_vector->z = z;	

		return SUCCESS;
	}
}


int vector3d_add(struct Vector3D *input_vector1, struct Vector3D *input_vector2, struct Vector3D *output_vector)
{
	if (input_vector1 == NULL || input_vector2 == NULL || output_vector == NULL) {
		return NULL_POINTER_ERROR;
	} else {
		vector3d_create(input_vector1->x + input_vector2->x,
						input_vector1->y + input_vector2->y,
						input_vector1->z + input_vector2->z,
						output_vector);

		return SUCCESS;
	}
}

int vector3d_subtract(struct Vector3D *input_vector1, struct Vector3D *input_vector2, struct Vector3D *output_vector)
{
	if (input_vector1 == NULL || input_vector2 == NULL || output_vector == NULL) {
		return NULL_POINTER_ERROR;
	} else {
		vector3d_create(input_vector1->x - input_vector2->x,
						input_vector1->y - input_vector2->y,
						input_vector1->z - input_vector2->z,
						output_vector);

		return SUCCESS;
	}
}

int vector3d_multiply(struct Vector3D *input_vector, const float constant, struct Vector3D *output_vector)
{
	if (input_vector == NULL || output_vector == NULL) {
		return NULL_POINTER_ERROR;
	} else {
		vector3d_create(constant * input_vector->x,
						constant * input_vector->y,
						constant * input_vector->z,
						output_vector);

		return SUCCESS;
	}
}

int vector3d_divide(struct Vector3D *input_vector, const float constant, struct Vector3D *output_vector)
{
	if (constant == 0) {
		return DIVISION_BY_ZERO_ERROR;
	} else if (input_vector == NULL || output_vector == NULL) {
		return NULL_POINTER_ERROR;
	} else {
		vector3d_create(input_vector->x / constant,
						input_vector->y / constant,
						input_vector->z / constant,
						output_vector);

		return SUCCESS;
	}
}

int vector3d_is_equal(struct Vector3D *input_vector1, struct Vector3D *input_vector2, bool *is_equal)
{
	if (input_vector1 == NULL || input_vector2 == NULL || is_equal == NULL) {
		return NULL_POINTER_ERROR;
	} else {
		*is_equal = (input_vector1->x == input_vector2->x) &&
					(input_vector1->y == input_vector2->y) &&
					(input_vector1->z == input_vector2->z);
		
		return SUCCESS;
	}
}

void vector3d_print_coordinates(struct Vector3D *input_vector)
{
	if (input_vector == NULL) {
		puts(" X:NULL, Y:NULL, Z:NULL ");
	} else {
		printf(" X:%f, Y:%f, Z:%f \n", input_vector->x, input_vector->y, input_vector->z);
	}
}

