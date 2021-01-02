# if defined(__APPLE__)
#  include "key_macos.h"
#  include "../mlx/minilibx-macos/mlx.h"
#  define SO "MACOS"
# else
#  include "key_linux.h"
#  include "../mlx/minilibx-linux/mlx.h"
#  define SO "LINUX"
# endif