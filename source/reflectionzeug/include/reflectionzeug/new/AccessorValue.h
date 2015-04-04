
#pragma once


#include <reflectionzeug/new/Accessor.h>


namespace reflectionzeug
{


/**
*  @brief
*    Accessor (read/write) storing the direct value
*/
template <typename Type>
class AccessorValue : public Accessor<Type>
{
public:
    AccessorValue();
    AccessorValue(const Type & defaultValue);
    virtual ~AccessorValue();

    virtual Type get() const override;
    virtual void set(const Type & value) override;


protected:
    Type m_value;
};


/**
*  @brief
*    Accessor (read-only) storing the direct value
*/
template <typename Type>
class AccessorValue<const Type> : public Accessor<const Type>
{
public:
    AccessorValue();
    AccessorValue(const Type & defaultValue);
    virtual ~AccessorValue();

    virtual Type get() const override;


protected:
    Type m_value;
};


} // namespace reflectionzeug


#include <reflectionzeug/new/AccessorValue.hpp>
