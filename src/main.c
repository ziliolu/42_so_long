#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_root	root;

	if(args_validation(argc, argv) != 1)
		return(-1);
	init_structs(&root, argv[1]);
	game_init(root);
	mlx_loop(root.mlx.mlx_ptr);
}

//animacao dos personagens 

/* static int count = 0;
 if (count < FPS)
	RETURN(0)
else 
	mlx_loop_hook(render)
	funcao render
		subtitui a imagem atual do player por uma nova em outra posicao
*/
	
