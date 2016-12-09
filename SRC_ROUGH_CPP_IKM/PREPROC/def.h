/*
 *
 */

#ifndef DEFS
#define DEFS

//Another very simple section, basic examples

#define MACROINT	1
#define MACROFLT	1.0
#define MACROSTR	"A " "REALLLY "	\
						"SPLIT STRING!\n"
#define MACROARRAYTRANSFERABLETORUNTIMEARRAY 1,2,3

#define MACRO_MIN(x,y) (((x)<(y))?x:y)
#define MACRO_MAX(x,y) (((x)>(y))?x:y)

#define ADDQUOTATIONS(x) #x
#define CONCATSTRINGS(x,y) x ## y

#ifndef CANT_REENTER_POST_DEFINE
#define CANT_REENTER_POST_DEFINE
#endif

#define CANENTER 1
#define HASDEF

#endif
