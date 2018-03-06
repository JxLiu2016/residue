#ifndef SAMPLE_LOG_EX
#define SAMPLE_LOG_EX

#include <residue/extensions.h>

class Simple : public residue::LogExtension {
public:
	Simple() : LogExtension("simple") 
	{}
	
	virtual ~Simple() = default;

	virtual residue::Extension::Result execute(void*) override;
};

#endif


