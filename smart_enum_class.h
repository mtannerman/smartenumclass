#define EXPAND(x) x
#define CONCAT_EXPAND(a,b) CONCAT(a,b)
#define CONCAT(a, b) a ## b
#define VFUNC(func, ...) EXPAND(CONCAT_EXPAND(func, ARG_COUNT(__VA_ARGS__)) (__VA_ARGS__))
#define ARG_COUNT(...) EXPAND(ARG_POS(__VA_ARGS__,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1))
#define ARG_POS(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,_14,_15,_16,_17,_18,_19,_20,N, ...) N

#define CREATE_STATIC_CTOR_1(className, enumName) static className enumName(){ return className(CONCAT(className,_Enum)::enumName);} 
#define CREATE_STATIC_CTOR_2(className, enumName, ...) CREATE_STATIC_CTOR_1(className, enumName) CREATE_STATIC_CTOR_1(className, __VA_ARGS__) 
#define CREATE_STATIC_CTOR_3(className, enumName, ...) CREATE_STATIC_CTOR_1(className, enumName) CREATE_STATIC_CTOR_2(className, __VA_ARGS__) 
#define CREATE_STATIC_CTOR_4(className, enumName, ...) CREATE_STATIC_CTOR_1(className, enumName) CREATE_STATIC_CTOR_3(className, __VA_ARGS__) 
#define CREATE_STATIC_CTOR_5(className, enumName, ...) CREATE_STATIC_CTOR_1(className, enumName) CREATE_STATIC_CTOR_4(className, __VA_ARGS__) 
#define CREATE_STATIC_CTOR_6(className, enumName, ...) CREATE_STATIC_CTOR_1(className, enumName) CREATE_STATIC_CTOR_5(className, __VA_ARGS__) 
#define CREATE_STATIC_CTOR_7(className, enumName, ...) CREATE_STATIC_CTOR_1(className, enumName) CREATE_STATIC_CTOR_6(className, __VA_ARGS__) 
#define CREATE_STATIC_CTOR_8(className, enumName, ...) CREATE_STATIC_CTOR_1(className, enumName) CREATE_STATIC_CTOR_7(className, __VA_ARGS__) 

#define CREATE_IS_BOOLEAN_1(className, enumName) bool CONCAT(Is,enumName)() const { return state == CONCAT(className,_Enum)::enumName; }
#define CREATE_IS_BOOLEAN_2(className, enumName, ...) CREATE_IS_BOOLEAN_1(className, enumName) CREATE_IS_BOOLEAN_1(className, __VA_ARGS__)
#define CREATE_IS_BOOLEAN_3(className, enumName, ...) CREATE_IS_BOOLEAN_1(className, enumName) CREATE_IS_BOOLEAN_2(className, __VA_ARGS__)
#define CREATE_IS_BOOLEAN_4(className, enumName, ...) CREATE_IS_BOOLEAN_1(className, enumName) CREATE_IS_BOOLEAN_3(className, __VA_ARGS__)
#define CREATE_IS_BOOLEAN_5(className, enumName, ...) CREATE_IS_BOOLEAN_1(className, enumName) CREATE_IS_BOOLEAN_4(className, __VA_ARGS__)
#define CREATE_IS_BOOLEAN_6(className, enumName, ...) CREATE_IS_BOOLEAN_1(className, enumName) CREATE_IS_BOOLEAN_5(className, __VA_ARGS__)
#define CREATE_IS_BOOLEAN_7(className, enumName, ...) CREATE_IS_BOOLEAN_1(className, enumName) CREATE_IS_BOOLEAN_6(className, __VA_ARGS__)
#define CREATE_IS_BOOLEAN_8(className, enumName, ...) CREATE_IS_BOOLEAN_1(className, enumName) CREATE_IS_BOOLEAN_7(className, __VA_ARGS__)

#define TO_STRING_LINE_1(className, enumName) case CONCAT(className,_Enum)::enumName: return #enumName;
#define TO_STRING_LINE_2(className, enumName, ...) TO_STRING_LINE_1(className, enumName) TO_STRING_LINE_1(className, __VA_ARGS__)
#define TO_STRING_LINE_3(className, enumName, ...) TO_STRING_LINE_1(className, enumName) TO_STRING_LINE_2(className, __VA_ARGS__)
#define TO_STRING_LINE_4(className, enumName, ...) TO_STRING_LINE_1(className, enumName) TO_STRING_LINE_3(className, __VA_ARGS__)
#define TO_STRING_LINE_5(className, enumName, ...) TO_STRING_LINE_1(className, enumName) TO_STRING_LINE_4(className, __VA_ARGS__)
#define TO_STRING_LINE_6(className, enumName, ...) TO_STRING_LINE_1(className, enumName) TO_STRING_LINE_5(className, __VA_ARGS__)
#define TO_STRING_LINE_7(className, enumName, ...) TO_STRING_LINE_1(className, enumName) TO_STRING_LINE_6(className, __VA_ARGS__)
#define TO_STRING_LINE_8(className, enumName, ...) TO_STRING_LINE_1(className, enumName) TO_STRING_LINE_7(className, __VA_ARGS__)

#define SMART_ENUM_CLASS(className, ...) enum class CONCAT(className,_Enum) { __VA_ARGS__ };\
struct className {\
className (){}\
className (const CONCAT(className,_Enum) state) : state(state) {}\
CONCAT(className,_Enum) state;\
CONCAT_EXPAND(CREATE_STATIC_CTOR_,ARG_COUNT(__VA_ARGS__))(className, __VA_ARGS__) \
CONCAT_EXPAND(CREATE_IS_BOOLEAN_,ARG_COUNT(__VA_ARGS__))(className, __VA_ARGS__) \
operator int() const { return int(state); } \
static const std::vector<className>& All() { static const auto all = std::vector<className>(); return all; }\
std::string ToString() const { switch(state) { CONCAT_EXPAND(TO_STRING_LINE_,ARG_COUNT(__VA_ARGS__))(className, __VA_ARGS__)  } return ""; } \
};\
 
#include <vector>
#include <string>

SMART_ENUM_CLASS(aa, i, f, g, h, e)
auto b = aa::e().ToString()[0];