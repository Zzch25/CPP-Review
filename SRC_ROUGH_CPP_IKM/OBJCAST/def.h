/*
 *
 */

#ifndef DEFS
#define DEFS

class base
{
	public:
		base();
		~base();
		void pubFunc();
		void basePubFunc();
		int pubVar;
		int pubVarBase;
	protected:
		void proFunc();
		void baseProFunc();
		int proVar;
		int proVarBase;
	private:
		void priFunc();
		void basePriFunc();
		int priVar;
		int priVarBase;
};

class child: public base
{
	public:
		child();
		~child();
		void pubFunc();
		void childPubFunc();
		int pubVar;
		int pubVarChild;
	protected:
		void proFunc();
		void childProFunc();
		int proVar;
		int proVarChild;
	private:
		void priFunc();
		void childPriFunc();
		int priVar;
		int priVarChild;
};

class base_virt
{
	public:
		base_virt();
		virtual ~base_virt();
		void pubFunc();
		virtual void pubFuncVirt();
		void basePubFunc();
		virtual void basePubFuncVirt();
		int pubVar;
		int pubVarBase;
	protected:
		void proFunc();
		virtual void proFuncVirt();
		void baseProFunc();
		virtual void baseProFuncVirt();
		int proVar;
		int proVarBase;
	private:
		void priFunc();
		virtual void priFuncVirt();
		void basePriFunc();
		virtual void basePriFuncVirt();
		int priVar;
		int priVarBase;
};

class child_virt: public base_virt
{
	public:
		child_virt();
		virtual ~child_virt();
		void pubFunc();
		virtual void pubFuncVirt();
		void childPubFunc();
		virtual void childPubFuncVirt();
		int pubVar;
		int pubVarChild;
	protected:
		void proFunc();
		virtual void proFuncVirt();
		void childProFunc();
		virtual void childProFuncVirt();
		int proVar;
		int proVarChild;
	private:
		void priFunc();
		virtual void priFuncVirt();
		void childPriFunc();
		virtual void childPriFuncVirt();
		int priVar;
		int priVarChild;
};

#endif
