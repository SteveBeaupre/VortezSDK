#ifdef _EXP_FUNC 
#undef _EXP_FUNC
#endif

//#define COMPILE_AS_DLL

// Redefine them...
#ifndef COMPILE_AS_DLL
	#define _EXP_FUNC 
#else
	#define _EXP_FUNC  __declspec(dllexport)
#endif
