
#pragma once


#include <reflectionzeug/type/AbstractPropertyArray.h>


namespace reflectionzeug
{


/**
*  @brief
*    Implementation for array types
*/
template <typename T, size_t Size>
class TypedArray : public AbstractPropertyArray<T, Size>
{
public:
    template <typename... Args>
    TypedArray(Args&&... args);

    virtual ~TypedArray();

    virtual void accept(AbstractVisitor * visitor) override;
};


} // namespace reflectionzeug


#include <reflectionzeug/type/TypedArray.hpp>
