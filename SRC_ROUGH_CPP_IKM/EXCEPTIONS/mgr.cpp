#include <iostream>
#include <exception>
#include "def.h"

using namespace std;

int main()
{
	void
			*argsCatchDefault[1],
			*argsCatchLiteral[1],
			*argsCatchActual[1],
			
			*argsThrowLiteral[1],
			*argsThrowActualStandard[2],
			*argsThrowActualCustom[2];

	int
			argsUndefThrowCatch;

	char
			*catchLiteral,
			*catchActual,

			*throwLiteral,
			*throwActual;

	const bool
			isStandard = true,
			isNotStandard = false;
	
	customException 
			testCustomExceptionDefault,
			testCustomExceptionLiteral((char*)DEFS_THROWSPC_LITERAL),
			testCustomExceptionActual((char*)DEFS_THROWSPC_ACTUAL);
	
	bad_alloc
			standardExceptionBadAlloc;

	argsUndefThrowCatch = 25;

	catchLiteral = (char*)DEFS_THROWDEF_LITERALCATCH;
	catchActual = (char*)DEFS_THROWDEF_ACTUALCATCH;

	throwLiteral = (char*)DEFS_THROWDEF_LITERALTHROW;
	throwActual = (char*)DEFS_THROWDEF_ACTUALTHROW;

	argsCatchLiteral[0] = (void *)catchLiteral;
	
	argsCatchActual[0] = (void *)catchActual;
	
	argsThrowLiteral[0] = (void *)throwLiteral;
	
	argsThrowActualStandard[0] = (void *)&isStandard;
	argsThrowActualStandard[1] = (void *)throwActual;

	argsThrowActualCustom[0] = (void *)&isNotStandard;
	argsThrowActualCustom[1] = (void *)throwActual;

	runThrowThenCatch((void *)&throwInFuncLiteral, argsThrowLiteral, (void *)&catchThrowLiteral, argsCatchLiteral, DEFS_THROWFN_ISLITERAL);
	runThrowThenCatch((void *)&throwInFuncActual, argsThrowActualStandard, (void *)&catchThrowActual, argsCatchActual, DEFS_THROWFN_ISACTUAL);
	runThrowThenCatch((void *)&throwInFuncActual, argsThrowActualCustom, (void *)&catchThrowActual, argsCatchActual, DEFS_THROWFN_ISACTUAL);

	runThrowThenCatch<void **>((void *)&throwInFuncLiteral, argsThrowLiteral, (void *)&catchThrowLiteral, argsCatchLiteral);
	runThrowThenCatch<void **>((void *)&throwInFuncActual, argsThrowActualStandard, (void *)&catchThrowActual, argsCatchActual);
	runThrowThenCatch<void **>((void *)&throwInFuncActual, argsThrowActualCustom, (void *)&catchThrowActual, argsCatchActual);

	return 0;
}
