/*
 *
 */

#ifndef DEFS
#define DEFS

class base
{
	friend void friendFuncInit();
	friend void friendFuncNoInit();
	friend class friendClassDefined0;
	friend class friendClassDefined1;
	friend class friendClassInitialized0;
	friend class friendClassInitialized1;	

	public:
		base(); //JUMP constructor causes double init
		base(bool setSharedInt); /*Utter paranoia*/
		~base();	
		bool compareBasePtr();
		static void setSkipDoubleInit(bool enabled){skipDoubleInit = enabled;}
		class insideBase
		{
			public:
				insideBase();
				~insideBase();
				void stateLiveliness();
		};
		insideBase testInsideBase;
		int sharedInt;	
	private:	
		static bool skipDoubleInit;
		base *takeDoubleInit;
};

class childOfBase: public base
{
	public:
		childOfBase();
		~childOfBase();
	private:
		void uniqueFunction(); //more paranoia
};

class childOfChildOfBase: public childOfBase
{
	public:
		childOfChildOfBase();
		~childOfChildOfBase();
	private:
		void uniqueFunction(); //more paranoia
};

class friendClassDefined0
{
	public:
		base testBase;
		friendClassDefined0();
		~friendClassDefined0();
};

/*Curiosity regarding the compiler. Silly, but I'm paranoid*/
class friendClassDefined1
{
	public:
		friendClassDefined1();
		~friendClassDefined1();
		base testBase;
};

class friendClassInitialized0
{
	public:
		friendClassInitialized0();
		~friendClassInitialized0();
};

/*Again paranoia*/
class friendClassInitialized1
{
	public:
		friendClassInitialized1();
		~friendClassInitialized1();
		void initBase();
};

void friendFuncInit();
void friendFuncNoInit();

#endif
