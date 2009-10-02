#ifndef LMACROS_H
#define LMACROS_H

# define LMAX (lifelines-1)
# define CMAX (lifecols-1)

# define SLEEP 250000000 /* Quarter of a second */
# define ALIVE(y, x) (CELL((y), (x))==1)?1:0
# define COORD(y, x) ((y)*lifecols+(x))
# define ICOLS 30
# define ILINES LINES
# define ASIZE (lifecols*lifelines)
# define SIZE (ASIZE*sizeof(int))
# define CPR(y, x) (cells[COORD((y),(x))] = 1)
# define BCPR(y, x) (buffer[COORD((y),(x))] = 1)
# define ABCPR(y, x) (buffer[COORD((y),(x))] = 0)
# define COPYB memcpy(cells, buffer, SIZE)
# define COPYC memcpy(buffer, cells, SIZE)
# define CELL(y, x) (cells[ COORD( (y), (x) ) ] )
# define debugc(fmt, x, s) fprintf(stdout, "%s:%d %s=" fmt ": %s\n", __FILE__, __LINE__, #x, (x), (s))
# define debug(fmt, x) debugc(fmt, x, "")
#define true 1
#define false 0

#endif
