/*
 *
 */

#ifndef DEFS
#define DEFS

class base
{
	friend class childD;

	public:
		base();
		virtual ~base();
		virtual void funcA();
		virtual void funcB();
		class heeha
		{
			public:
				heeha();
				~heeha();
				heehaRun();
		};
		heeha heehaInst;
	protected:
		int protVar;
	private:
		int privVar;	
};

class childA: public base
{
	public:
		childA();
		virtual ~childA();
		virtual void funcA();
		virtual void funcB();	
};

class childB: public base
{
	public:
		childB();
		virtual ~childB();
		virtual void funcA();
};

class childC: public childB
{
	public:
		childC();
		virtual ~childC();
		virtual void funcB();
};

class childD: public base
{
	public:
		childD();
		~childD();
		void accessProt();
		void accessPriv();
};

class childE: base::heeha //c11
{
	public:
		childE();
		~childE();
		void runheeha();
};

#endif
