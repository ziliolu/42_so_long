#include "so_long.h"

int main(int argc, char **argv)
{
	if(args_validation(argc, argv) != 1)
		return(-1);

	t_root root;

	init_structs(&root, argv[1]);
	//verify_flood_fill(&root);

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
	
