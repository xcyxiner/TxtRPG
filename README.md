# 文字游戏
C text rpg

参考地址
https://zh.cppreference.com/w/c/language

# 编译运行

```
make clean

make

./build/crpg
```

# 依赖

```
apt-get install libssl-dev 

```

#运行效果

```
=== C++知识大冒险 ===

输入角色名: xcyxiner

===xcyxiner ===
生命值: 100
敏捷1
知识等级:
 左值:Lv.0
 右值:Lv.0
 函数指示器:Lv.0
 类型转换:Lv.0
=====================

遭遇 左值守卫！知识对决开始！

=== 题目 [1星] ===
以下哪个是左值?
1) std::move(x)
2) 3
3) x+1
4) x
选择答案 (1-4): 4
正确！获得 12 经验！

=== 题目 [3星] ===
表达式&x有效的条件是?
1) x是常量
2) X是右值
3) x是左值
4) x是临时对象
选择答案 (1-4): 3
正确！获得 32 经验！

===xcyxiner ===
生命值: 100
敏捷1
知识等级:
 左值:Lv.44
 右值:Lv.0
 函数指示器:Lv.0
 类型转换:Lv.0
=====================

=== 战斗记录 ===
Q0 [√]2.7s (难度:1)
Q1 [√]2.7s (难度:3)

恭喜通关！最终状态：
===xcyxiner ===
生命值: 100
敏捷1
知识等级:
 左值:Lv.44
 右值:Lv.0
 函数指示器:Lv.0
 类型转换:Lv.0
=====================

```
