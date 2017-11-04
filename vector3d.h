#ifndef _VECTOR3D_H
#define _VECTOR3D_H

#include <stdbool.h>

struct Vector3D {
	float x;
	float y;
	float z;
};

// Constructor, destructor
int vector3d_create(float x, float y, float z, struct Vector3D *output_vector);
void vector3d_destroy(struct Vector3D *input_vector);

// Get direction, not magnitude
int vector3d_normalise(struct Vector3D *input_output_vector);

// Get perpendicular vector, i.e. normal
int vector3d_cross_product(struct Vector3D *input_vector1, struct Vector3D *input_vector2, struct Vector3D *output_vector);

// Useful for calculating diffuse light
int vector3d_dot_product(struct Vector3D *input_vector1, struct Vector3D *input_vector2, float *output_value);

int vector3d_length(struct Vector3D *input_vector, float *output_length);

int vector3d_change_all_coordinates(struct Vector3D *input_vector, float x, float y, float z);
int vector3d_copy_vector(struct Vector3D *source_vector, struct Vector3D *destination_vector);

int vector3d_change_x_coordinate(struct Vector3D *input_vector, float x);
int vector3d_change_y_coordinate(struct Vector3D *input_vector, float y);
int vector3d_change_z_coordinate(struct Vector3D *input_vector, float z);

int vector3d_add(struct Vector3D *input_vector1, struct Vector3D *input_vector2, struct Vector3D *output_vector);
int vector3d_subtract(struct Vector3D *input_vector1, struct Vector3D *input_vector2, struct Vector3D *output_vector);
int vector3d_multiply(struct Vector3D *input_vector1, float constant, struct Vector3D *output_vector);
int vector3d_divide(struct Vector3D *input_vector1, float constant, struct Vector3D *output_vector);

int vector3d_is_equal(struct Vector3D *input_vector1, struct Vector3D *input_vector2, bool *is_equal);
void vector3d_print_coordinates(struct Vector3D *input_vector);

#endif
