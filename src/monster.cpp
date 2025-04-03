#include "monster.h"
#include "utilities.h"
std::vector<Monster> generate_campaign(){

    return {
        {
            "左值守卫",
            LVALUE_CASE,
            2,
            {
                {
                    "以下哪个是左值? ",
                    {"x","x+1","3","std::move(x)"},
                    0,
                    1,
                    generate_sha256("左值基础题")
                },
                {
                    "表达式&x有效的条件是?",
                    {"X是右值","x是常量","x是左值","x是临时对象"},
                    2,
                    3,
                    generate_sha256("取地址验证题")                   
                }
            }
        }
    };
}
