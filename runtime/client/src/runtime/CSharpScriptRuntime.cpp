#include <Log.h>
#include "CSharpScriptRuntime.h"
#include "CSharpResourceImpl.h"
#include "natives.h"

CSharpScriptRuntime::CSharpScriptRuntime(alt::ICore* core) : core(core), clr(core)
{
    Log::Info << "CSharp runtime initialized" << Log::Endl;
}

alt::IResource::Impl* CSharpScriptRuntime::CreateImpl(alt::IResource* resource)
{
    InitNatives();
    return new CSharpResourceImpl(this, resource, core);
}

void CSharpScriptRuntime::DestroyImpl(alt::IResource::Impl* impl) {}