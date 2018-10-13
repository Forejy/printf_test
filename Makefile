NAME = libftprintf.a

SRCS += Sources/Auxiliary_Functions/numbers_functions.c
SRCS += Sources/Auxiliary_Functions/numbers_functions_double.c
SRCS += Sources/Print_Final_Result/annex_functions.c
SRCS += Sources/Print_Final_Result/compute_functions.c
SRCS += Sources/Print_Final_Result/print_and_compute_final_result.c
SRCS += Sources/Auxiliary_Functions/print_pointer_address.c
SRCS += Sources/Auxiliary_Functions/strings_functions.c
SRCS += Sources/Auxiliary_Functions/bonus.c
SRCS += Sources/Handlers/handlers.c
SRCS += Sources/Handlers/handle_colors.c
SRCS += Sources/Handlers/handle_conversions.c
SRCS += Sources/Handlers/handle_conversions_2.c
SRCS += Sources/Handlers/test_conv_champs_prec.c
SRCS += Sources/Print_Unicode/convert_dec_to_bin_utf8.c
SRCS += Sources/Print_Unicode/create_and_print_t_bin_list.c
SRCS += Sources/Print_Unicode/print_unicode.c
SRCS += Sources/Print_Unicode/print_wchar_t.c
SRCS += Sources/Print_Unicode/auxiliary_functions_for_unicode.c
SRCS += Sources/errors.c
SRCS += Sources/printf.c

INCLUDES += Includes/Auxiliary_Functions/numbers_functions.h
INCLUDES += Includes/Auxiliary_Functions/numbers_functions_double.h
INCLUDES += Sources/Print_Final_Result/annex_functions.h
INCLUDES += Sources/Print_Final_Result/compute_functions.h
INCLUDES += Sources/Print_Final_Result/print_and_compute_final_result.h
INCLUDES += Includes/Auxiliary_Functions/print_pointer_address.h
INCLUDES += Includes/Auxiliary_Functions/strings_functions.h
INCLUDES += Includes/Auxiliary_Functions/bonus.h
INCLUDES += Includes/Handlers/handlers.h
INCLUDES += Includes/Handlers/handle_colors.h
INCLUDES += Includes/Handlers/handle_conversions.h
INCLUDES += Includes/Handlers/handle_conversions_2.h
INCLUDES += Includes/Handlers/test_conv_champs_prec.h
INCLUDES += Includes/Print_Unicode/convert_dec_to_bin_utf8.h
INCLUDES += Includes/Print_Unicode/create_and_print_t_bin_list.h
INCLUDES += Includes/Print_Unicode/print_unicode.h
INCLUDES += Includes/Print_Unicode/print_wchar_t.h
INCLUDES += Includes/Print_Unicode/auxiliary_functions_for_unicode.h
INCLUDES += Includes/errors.h
INCLUDES += Includes/printf.h

OBJS += Sources/Auxiliary_Functions/numbers_functions.o
OBJS += Sources/Auxiliary_Functions/numbers_functions_double.o
OBJS += Sources/Print_Final_Result/annex_functions.o
OBJS += Sources/Print_Final_Result/compute_functions.o
OBJS += Sources/Print_Final_Result/print_and_compute_final_result.o
OBJS += Sources/Auxiliary_Functions/print_pointer_address.o
OBJS += Sources/Auxiliary_Functions/strings_functions.o
OBJS += Sources/Auxiliary_Functions/bonus.o  
OBJS += Sources/Handlers/handlers.o
OBJS += Sources/Handlers/handle_colors.o
OBJS += Sources/Handlers/handle_conversions.o
OBJS += Sources/Handlers/handle_conversions_2.o
OBJS += Sources/Handlers/test_conv_champs_prec.o
OBJS += Sources/Print_Unicode/convert_dec_to_bin_utf8.o
OBJS += Sources/Print_Unicode/create_and_print_t_bin_list.o
OBJS += Sources/Print_Unicode/print_unicode.o
OBJS += Sources/Print_Unicode/print_wchar_t.o
OBJS += Sources/Print_Unicode/auxiliary_functions_for_unicode.o
OBJS += Sources/errors.o
OBJS += Sources/printf.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

objects :
	mkdir objects

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
