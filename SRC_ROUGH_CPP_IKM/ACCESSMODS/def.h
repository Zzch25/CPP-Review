/*
 *
 */

#ifndef DEFS
#define DEFS

//Quick note, friend functions are not inherited

class baseAccess
{
	//Private
	friend void friendFuncDef();
	
	public:
		baseAccess();
		friend void friendFuncShared();
		friend void friendFuncPub();
		void pubFunc();
		int pubVar;
	protected:
		friend void friendFuncPro();
		void proFunc();
		int proVar;
	private:
		friend class baseFriendAccess;
		friend void friendFuncPri();
		void priFunc();
		int priVar;
};

class baseShareAccess
{
	public:
		baseShareAccess();
		friend void friendFuncShared();
	private:
		int priVar;
};

class baseFriendAccess //Already from private, demo full access
{
	public:
		void demoAccess();
};

class childAccess0 : public baseAccess
{
	public:
		baseAccess toAccess;
		void demoAccess();
};

class childAccess1 : protected baseAccess
{
	public:
		baseAccess toAccess;
		void demoAccess();
};

//same as private
class childAccess2 : baseAccess
{
	public:
		baseAccess toAccess;
		void demoAccess();
};

void friendFuncShared();
void friendFuncPub();
void friendFuncPro();
void friendFuncPri();

#endif
