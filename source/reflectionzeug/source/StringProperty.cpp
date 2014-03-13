
#include <reflectionzeug/StringProperty.h>

namespace reflectionzeug
{

StringProperty::StringProperty(const std::string & name,
    const std::string & value)
:   ValuePropertyInterface(name)
,   ValueProperty<std::string>(name, value)
{
}

StringProperty::StringProperty(const std::string & name, 
    const std::function<std::string ()> & getter,
    const std::function<void(const std::string &)> & setter)
:   ValuePropertyInterface(name)
,   ValueProperty<std::string>(name, getter, setter)
{
}
    
bool StringProperty::hasChoices() const
{
    return !m_choices.empty();
}
 
const std::vector<std::string> & StringProperty::choices() const
{
    return m_choices;
}
 
void StringProperty::clearChoices()
{
    m_choices.clear();
}
 
void StringProperty::setChoices(const std::vector<std::string> & choices)
{
    m_choices = choices;
}
 
void StringProperty::addChoice(const std::string & string)
{
    m_choices.push_back(string);
}
    
std::string StringProperty::toString() const
{
    return this->value();
}

bool StringProperty::fromString(const std::string & string)
{
    this->setValue(string);
    return true;
}
    
} // namespace reflectionzeug
