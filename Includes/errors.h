#ifndef PRINTF_ERRORS_H
#define PRINTF_ERRORS_H

# define ERROR_MALLOC_FAILED "MALLOC SDF"
# define ERROR_CHARSET_INVALID "charset invalid"
# define ERROR_OPEN_FAILED "Could not open file"
# define ERROR_EMPTY_FILE "File is empty"
# define ERROR_NOT_4_ELEMS "Piece doesn't have exactly 4 elems"
# define ERROR_MALFORMED_PIECE "Piece is malformed"
# define ERROR_DISJOINT_ELEMS "Piece has disjoint elements"
# define ERROR_INVALID_CHARACTER "Piece has invalid characters"


void		exit_with_msg(const char *message);


#endif
