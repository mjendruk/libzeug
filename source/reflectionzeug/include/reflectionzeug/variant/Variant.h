
#pragma once


#include <string>
#include <vector>
#include <map>

#include <reflectionzeug/reflectionzeug_api.h>


namespace reflectionzeug
{


class AbstractAccessor;
class Variant;


/**
*  @brief
*    Variant array (analog to a JSON array)
*/
using VariantArray = std::vector<Variant>;

/**
*  @brief
*    Variant map (analog to a JSON object)
*/
using VariantMap = std::map<std::string, Variant>;


/**
*  @brief
*    Variant typed value
*
*    A Variant can be used to store and pass arbitrary typed values in a uniform manner.
*
*    To create a Variant from the list of supported primitive data types, use one of the
*    available constructors. To create a Variant from another data type, use the static
*    function fromValue().
*
*    The type of the stored value can be determined by type() or hasType<Type>().
*    To access the value of a variant, call value<Type>(). If the given data type does not
*    match the stored type, the value may be converted. Note that this only works for the
*    supported primitive data types. To check if a type can be converted, use canConvert<Type>().
*
*    VariantArray and VariantMap can be used to store collections or hierarchies of variants.
*    For simplified usage, use the convenience functions array() or map() to create such variants,
*    and asArray() or asMap() to access their data. These composite variants will automatically
*    be interpreted as JSON arrays or objects within scriptzeug and can be serialized by the
*    JSON tool class.
*/
class REFLECTIONZEUG_API Variant
{
public:
    /**
    *  @brief
    *    Create a variant from an arbitrary typed value
    *
    *  @param[in] value
    *    Value
    *
    *  @return
    *    Variant instance
    */
    template <typename ValueType>
    static Variant fromValue(const ValueType & value);

    /**
    *  @brief
    *    Create an empty or specifically sized variant array
    *
    *  @param count
    *    The initial size of the array
    *
    *  @return
    *    Variant instance
    */
    static Variant array();
    static Variant array(size_t count);

    /**
    *  @brief
    *    Create an empty variant map
    *
    *  @return
    *    Variant instance
    */
    static Variant map();


public:
    //@{
    /**
    *  @brief
    *    Constructor for an empty value
    */
    Variant();

    /**
    *  @brief
    *    Copy constructor
    *
    *  @param[in] variant
    *    Variant whose value will be copied
    */
    Variant(const Variant & variant);
    //@}

    /**
    *  @brief
    *    Constructor for a primitive data type
    *
    *  @param[in] value
    *    Primitive value
    */
    //@{
    Variant(bool value);
    Variant(char value);
    Variant(unsigned char value);
    Variant(short value);
    Variant(unsigned short value);
    Variant(int value);
    Variant(unsigned int value);
    Variant(long value);
    Variant(unsigned long value);
    Variant(long long value);
    Variant(unsigned long long value);
    Variant(float value);
    Variant(double value);
    Variant(const char * value);
    Variant(const std::string & value);
    Variant(const std::vector<std::string> & value);
    Variant(const VariantArray & array);
    Variant(const VariantMap & map);
    //@}

    //@{
    /**
    *  @brief
    *    Destructor
    */
    virtual ~Variant();

    /**
    *  @brief
    *    Copy operator
    *
    *  @param[in] variant
    *    Variant whose value will be copied
    *
    *  @return
    *    Variant
    */
    Variant & operator=(const Variant & variant);

    /**
    *  @brief
    *    Check if variant is empty
    *
    *  @return
    *    'true' if variant does not contain a value, else 'false'
    */
    bool isNull() const;

    /**
    *  @brief
    *    Check if variant contains an array
    *
    *  @return
    *    'true' if variant has type VariantArray, else 'false'
    */
    bool isArray() const;

    /**
    *  @brief
    *    Check if variant contains a map
    *
    *  @return
    *    'true' if variant has type VariantMap, else 'false'
    */
    bool isMap() const;

    /**
    *  @brief
    *    Get type of variant value
    *
    *  @return
    *    Type id
    */
    const std::type_info & type() const;

    /**
    *  @brief
    *    Check type of variant value
    *
    *  @return
    *    'true' if variant value has the template type ValueType, else 'false'
    */
    template <typename ValueType>
    bool hasType() const;

    /**
    *  @brief
    *    Check if variant type can be converted
    *
    *  @return
    *    'true' if variant can be converted into type ValueType, else 'false'.
    *
    *  @remarks
    *    Conversion is only supported for the following primitive data types:
    *      bool, char, unsigned char, short, unsigned short, int, unsigned int,
    *      long, unsigned long, long long, unsigned long long, float, double,
    *      std::string
    */
    template <typename ValueType>
    bool canConvert() const;

    /**
    *  @brief
    *    Get stored value
    *
    *  @param[in] defaultValue
    *    Default value that is returned if the value cannot be returned or converted
    *
    *  @return
    *    Stored value of type ValueType, or defaultValue if type does not match and cannot be converted
    */
    template <typename ValueType>
    ValueType value(const ValueType & defaultValue = ValueType()) const;

    //@{
    /**
    *  @brief
    *    Get pointer to the stored value
    *
    *  @return
    *    Pointer to stored value of type ValueType, or nullptr if type does not match and cannot be converted
    */
    template <typename ValueType>
    ValueType * ptr();
    template <typename ValueType>
    const ValueType * ptr() const;
    //@}

    //@{
    /**
    *  @brief
    *    Get pointer to the stored VariantArray
    *
    *  @return
    *    Pointer to VariantArray, or nullptr if the variant does not contain a variant array
    *
    *  @remarks
    *    Does the same as calling \code variant.ptr<VariantArray>() \endcode
    */
    VariantArray * asArray();
    const VariantArray * asArray() const;
    //@}

    //@{
    /**
    *  @brief
    *    Get pointer to the stored VariantMap
    *
    *  @return
    *    Pointer to VariantMap, or nullptr if the variant does not contain a variant map
    *
    *  @remarks
    *    Does the same as calling \code variant.ptr<VariantMap>() \endcode
    */
    VariantMap * asMap();
    const VariantMap * asMap() const;
    //@}

    //@{
    /**
    *  @brief
    *    Get JSON representation of variant
    *
    *  @return
    *    JSON representation
    *
    *  @see
    *    SerializerJSON
    */
    std::string toJSON() const;
    //@}


protected:
    AbstractAccessor * m_accessor;    ///< Value accessor, can be nullptr
};


} // namespace reflectionzeug


#include <reflectionzeug/variant/Variant.hpp>
