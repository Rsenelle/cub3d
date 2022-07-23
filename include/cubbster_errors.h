//
// Created by dedelmir on 20.06.22.
//

#ifndef CUBBSTER_CUBBSTER_ERRORS_H
#define CUBBSTER_CUBBSTER_ERRORS_H

# define INVALID_ARG_COUNT "Usage : ./cubbster <filename.cub>"
# define INVALID_FILENAME "No such file."
# define EMPTY_FILE "No data found. Exiting."
# define INVALID_ROW_WIDTH "Found wrong line length. Exiting."
# define MEMORY_ERROR "Couldn't allocate memory. Exiting."
# define INVALID_NUMERIC_DATA "The map contains non-color data or non-integer values. \
Exiting."
# define INVALID_EXTENSION ".cub extension expected."

# define MAP_INITIALIZATION_FAILED "Couldn't find actual version of mlx library. \
Sure you turn necessary files in the project directory."
# define IMG_INITIALIZATION_FAILED "Couldn't get image."

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

void	put_error(char *str);

#endif
