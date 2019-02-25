#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sehahn <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/23 20:14:36 by sehahn        #+#    #+#                  #
#    Updated: 2019/02/23 20:14:38 by sehahn        ########   odam.nl          #
#                                                                              #
#******************************************************************************#

all:
	gcc -Wall -Werror -Wextra -c *.c
	gcc -o eval_expr *.o

clean: 
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f eval_expr

re: fclean all
