
#pragma once


#include <reflectionzeug/base/Color.h>
#include <reflectionzeug/AbstractTyped.h>
#include <reflectionzeug/AbstractColorInterface.h>


namespace reflectionzeug
{


/**
*  @brief
*    Implementation for type Color
*/
class TypedColor : public AbstractTyped<Color>, public AbstractColorInterface
{
public:
    template <typename... Args>
    TypedColor(Args&&... args);

    virtual ~TypedColor();

    virtual Color toColor() const override;
    virtual bool fromColor(const Color & color) override;

    virtual void accept(AbstractVisitor * visitor) override;
};


} // namespace reflectionzeug


#include <reflectionzeug/TypedColor.hpp>
