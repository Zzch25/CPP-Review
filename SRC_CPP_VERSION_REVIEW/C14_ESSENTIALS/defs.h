/*
 *
 *
 */

#ifndef DEFS_ROOT
#define DEFS_ROOT

/*RETURN*TYPE*DEDUCTION***************/

//Double is now inferred
auto aFuncForReturnTypeDeduction0(int in)
{
	return 1.0;
}

//Not going to float
//Double is inferred but the compiler will inform of the improper syntax
/*
auto aFuncForReturnTypeDeduction1(int in)
{
	if(in < 0)
		return 1.0;
	return 2;	
}
*/

/*GENERIC*LAMBDAS*********************/


/*INITIALIZED*LAMBDA*CAPTURES*********/


/*BINARY*LITERALS*&*DIGIT*SEPARATORS**/


/*DEPRECIATED*************************/

//Both generate compiler warnings

class [[deprecated]] obsoleted0 {};
class [[deprecated("A custom message")]] obsoleted1 {};

/*OTHER*******************************/
	
//A template variable

template <typename T>
struct pi
{
	static constexpr T pi_def = T(3.14);
};

template <typename T>
	constexpr T pi<T>::pi_def;

//Not a good example, but the main call makes it known at compilation
constexpr int funcCE(int in)
{
	if(in == 1)
		return 2*2;
	else
		return 0;
}

#endif
