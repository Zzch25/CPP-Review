/*
 *
 */

#ifndef DEFS
#define DEFS

class constCorrectness
{
	public:
		constCorrectness();
		int& varyByKeyword(int &in); 
		const int& varyByKeyword(const int &in) const;
		void demonstrateAccess();
		void demonstrateAccess() const;
		int pubVar;
		volatile int pubVarVolatile;
		const int pubVarConst = 5;
		mutable int pubVarMutable;
};

const int& doNotModify(const int &in);
void improper_string_notconst(char * in);

#endif
