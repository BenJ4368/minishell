k0r3p14 15h00-18h30

# MINISHELL NOTES
## makefile
	classique, contient la libft.
	ne pas oublier de changer la commande des sources par la liste des sources en dure.
	-fsanitize=leak
	***passage sur Linux, les code couleurs de mon makefile doivent changer, et je lance desormais make -s, pour ne pas avoir de message non voulu.
## minishell.h
	include libft, ft_printf, gnl
	include des bibli standart C au besoin, mais bcp sont deja dans les .h de libft
	structure data (structure principale)
# Cheminement
## Prompt rapide et recup ligne de commande
	Pour le moment, je veux juste un programme qui m'affiche
	un prompt simple et recup ce que je lui donne en ligne de commande.
	je fait donc un main, sans argument parce que j'en a pas besoin pour le moment. je ft_printf mon prompt, et j'appel gnl sur l'entree standart stdin (donc gnl(0)).
	Je stock le retour de gnl dans un char *, et je remplace le dernier char (qui est un \n) par un \0.
	je met tout ca dans un while(1) pour que minishell ne s'arrete pas et me rendent le prompt.
	Pour verifier, je printf ce que je viens de stocker.
	apres avoir print, je free pour eviter les leaks.
	si mon programme me renvoi exactement ce que j'ai ecrit, et me rend le prompt, on est bon.
## Recup des variables d'env
	Je sais que je vais avoir besoin des variables d'env plus tard, alors je fait en sorte de les recup tout de suite. Je les recup grace au main(int, char**, char **env), je les compte, malloc en fonction (dans une structure pour ma part) et je strdup pour en faire une copie parfaite.
	Pour verfier, je printf ce double tableau que je viens donc de creer. Je peux comparer avec les 'vraies' var env en tapant 'env' dans un autre terminale. Si elles sont biens prints, et si je n'ai pas de segfault, on est bon.
	Je creer directement une fonction qui va free ce double tableau a la fin de l'execution de minishel, pour eviter les leaks.
## Amelioration du prompt
	Dans le prompt, il faut que j'affiche le nom d'utilisateur et le repertoire courant.
	Je me sert de la fonction getenv("USER") pour obtenir le nom de l'utilisateur. le repertoire courant est obtenable via la fonction getcwd() (cwd = current working directory).
	getcwd() prend un buffer et une longueur en argument. j'initialise un buffer temporaire a 100 char pour etre large, et eviter les leaks.
	system(leaks minishell) pour tester les leaks. Aucune.
	Apres quelques recherche sur la fonction readline(), je decide de l'utiliser parce qu'elle permet beaucoup de choses.
	j'ajoute des includes dans le .h, et un flag dans la compilation du makefile pour utiliser readline().
	Ne trouvant pas comment (avec readline) print un prompt qui contient des variables, je print le prompt avec printf, et ne donne rien a readline.
	Je teste; Je met un break dans mon while(1) de sorte a stopper minishell apres que je lui ai ecrit une seule ligne. Si minishell ne s'arrete pas, -fsanitize n'affiche rien. Je lance minishell, verfie mon promt, ecrit une ligne, et vois la reponse de system(leaks) ET -fsanitize. pas le leaks.
	Je teste ensuite sans le break, pour voir si minishell me rend bien le prompt.
## Lexer
	J'ai un prompt fonctionnel, qui recupere sans leaks les lignes de commandes que je lui donne.
	Il me faut maintenant analyser ces lignes que je lui passe.

	
