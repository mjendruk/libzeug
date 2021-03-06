#pragma once


#include <string>

#include <reflectionzeug/variant/Variant.h>

#include <scriptzeug/scriptzeug_api.h>


namespace reflectionzeug {
    class PropertyGroup;
}


namespace scriptzeug
{


class ScriptContext;


/** \brief Base class for backend specific scripting contexts
 */
class SCRIPTZEUG_API AbstractScriptContext
{
public:
    AbstractScriptContext(ScriptContext * scriptContext);
    virtual ~AbstractScriptContext();

    virtual void registerObject(reflectionzeug::PropertyGroup * obj) = 0;
    virtual void unregisterObject(reflectionzeug::PropertyGroup * obj) = 0;
    virtual reflectionzeug::Variant evaluate(const std::string & code) = 0;

protected:
	ScriptContext * m_scriptContext; ///< Script context holding this backend
};


} // namespace scriptzeug
