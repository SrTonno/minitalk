include colors.mk
###############################################################################
#                                              FILES                          #
###############################################################################
CCLIENT		= client.c
OCLIENT	=	${CCLIENT:.c=.o}

CSERVER		= server.c
OSERVER	=	${CSERVER:.c=.o}

CCLIENTB		= client_str.c
OCLIENTB	=	${CCLIENTB:.c=.o}

CSERVERB		= server_str.c
OSERVERB	=	${CSERVERB:.c=.o}

CLIBFT		= \
			libft/lib/ft_atoi.c libft/lib/ft_bzero.c libft/lib/ft_calloc.c \
			libft/lib/ft_isalnum.c libft/lib/ft_isalpha.c libft/lib/ft_isascii.c \
			libft/lib/ft_isdigit.c libft/lib/ft_isprint.c libft/lib/ft_memchr.c \
			libft/lib/ft_memcmp.c libft/lib/ft_memcpy.c libft/lib/ft_memmove.c \
			libft/lib/ft_memset.c libft/lib/ft_strchr.c libft/lib/ft_strdup.c \
			libft/lib/ft_strlcat.c libft/lib/ft_strlcpy.c libft/lib/ft_strlen.c \
			libft/lib/ft_strncmp.c libft/lib/ft_strnstr.c libft/lib/ft_strrchr.c \
			libft/lib/ft_tolower.c libft/lib/ft_toupper.c libft/lib/ft_substr.c \
			libft/lib/ft_strjoin.c libft/lib/ft_strtrim.c libft/lib/ft_putchar_fd.c \
			libft/lib/ft_putstr_fd.c libft/lib/ft_putendl_fd.c libft/lib/ft_putnbr_fd.c \
			libft/lib/ft_itoa.c libft/lib/ft_strmapi.c libft/lib/ft_striteri.c \
			libft/lib/ft_split.c libft/lib/ft_lstnew_bonus.c \
			libft/lib/ft_lstadd_front_bonus.c libft/lib/ft_lstsize_bonus.c \
			libft/lib/ft_lstlast_bonus.c libft/lib/ft_lstadd_back_bonus.c \
			libft/lib/ft_lstdelone_bonus.c libft/lib/ft_lstclear_bonus.c \
			libft/lib/ft_lstiter_bonus.c libft/lib/ft_lstmap_bonus.c \

OLIBFT	=	${CLIBFT:.c=.o}

CPRINTF		= \
			libft/printf/ft_printf.c \
			libft/printf/utils/ft_selectoption.c libft/printf/utils/ft_strchrp.c \
			libft/printf/utils/ft_putstr.c libft/printf/ft_options/ft_c.c \
			libft/printf/ft_options/ft_di.c libft/printf/ft_options/ft_u.c \
			libft/printf/ft_options/ft_s.c libft/printf/ft_options/ft_x.c \
			libft/printf/ft_options/ft_p.c \
			\

OPRINTF	=	${CPRINTF:.c=.o}

CGNL		= \
			libft/gnl/get_next_line.c libft/gnl/get_next_line_utils.c \
			libft/gnl/get_next_line_bonus.c
OGNL	=	${CGNL:.c=.o}

###############################################################################
#                                              SETTINGS                       #
###############################################################################
SERVER = server
CLIENT = client

NLIBRARY= libft.a

CC = clang
CFLAGS = -Wall -Werror -Wextra
OPGRAFIC = -lmlx -framework OpenGL -framework AppKit
FSANITIZE = -fsanitize=address -g

AR = ar
ARFLAGS = -rcs
RM = rm -f

LIBFT = $(OLIBFT) $(OPRINTF) $(OGNL)

###############################################################################

ifdef WITH_BONUS
	OBJS_CLIENT = ${OCLIENTB}
	OBJS_SERVER = ${OSERVERB}
else
	OBJS_CLIENT = ${OCLIENT}
	OBJS_SERVER = ${OSERVER}
endif

###############################################################################
#                                              OPTIONS                        #
###############################################################################
all: ${CLIENT} ${SERVER}

${CLIENT}: ${NLIBRARY} ${OBJS_CLIENT}
	@${CC} ${CFLAGS} $^ ${NLIBRARY} ${FSANITIZE} -o $@
	@echo "Created ${CLIENT}."

${SERVER}: ${NLIBRARY} ${OBJS_SERVER}
	@${CC} ${CFLAGS} $^ ${NLIBRARY} ${FSANITIZE} -o $@
	@echo "Created ${SERVER}."

$(NLIBRARY): $(LIBFT)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "Created LIBFT."

bonus:
	@make WITH_BONUS=1

git: fclean
	@echo "\t${BIPurple}>>Push To Git<<${NoColor}"
	@git add . ;
	@read -p "Name the commit: " commit ;\
	git commit -m "$$commit" ;\
	git push origin master ;

normi:
	@echo "${BICyan}>>Check Files with ${BIRed}ERROR${BICyan} norminette<<${NoColor}"
	@norminette -R CheckForbiddenSourceHeader | grep Error! | grep -v tester

.c.o:
		 @${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

###############################################################################
clean:
		@${RM} ${OSERVER} ${OSERVERB} ${OCLIENT} ${OCLIENTB} ${LIBFT}
		@echo "Delete .o."

fclean: clean
		@${RM} ${NLIBRARY} ${SERVER} ${NAME}
		@echo "Delete libft.a, client and server."
bre:	fclean@make WITH_BONUS=1
re: fclean all
help:
	@echo "${UGreen}Options of MakeFile:${NoColor}"
	@echo "Used: make [options]"
	@echo "\t${BICyan}Default:${NoColor} Created '${NAME}'"
	@echo "\t${IRed}clean:${NoColor} Delete '.o'."
	@echo "\t${BIRed}fclean:${NoColor} Delete'.o', '${NLIBRARY}'"
	@echo "\t${BICyan}re:${NoColor} Delete '.o', '${NLIBRARY}', '${NAME}' and creates '${NAME}'"
	@echo "\t${BIPurple}git:${NoColor} Push to git."
	@echo "\t${BICyan}normi:${NoColor} Check file with Error the norminette."
	@echo "MakeFile by ${UBlue}tvillare${NoColor}."

.PHONY = all clean fclean re help normi git bre
