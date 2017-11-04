#include "vector3d.h"
#include "error-codes.h"

#include <stdio.h>

int main(int argc, char **argv)
{
	struct Vector3D *vec = NULL;

	if (vector3d_create(1.0, 2.0, 3.0, vec) == SUCCESS) {
			vector3d_print_coordinates(vec);

			vector3d_destroy(vec);
	}

	
	return 0;
}
