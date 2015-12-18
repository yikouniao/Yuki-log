简介
====
这是一个用来练习C++的项目。  
设定大概是Yuki用来记录Character和VoiceActress两种Person（类），可以修改、增删文件内容的东西。  
文件按一定格式以文本形式把Person们的信息存为*.dat，文件存放在dat文件夹中。  
作者： yikouniao ( github.com/yikouniao )  
工程地址： github.com/yikouniao/Yuki-log.git  

下一步
------
已完成，暂时没有改进的打算。

扯
--
极其简陋。开始还想做图形界面的想想还是算了，目前还有更有意义的东西要做。所以是控制台版本的。由于使用了conio.h，可能只有Windows下才能使用。  
所有Characters会存为一个链表。VoiceActresses也是。  
理论上来说，VoiceActress类里面的成员有很多个Character::name_字符串，应该把每个Character的所有name_存为链表，方便文件读写也方便增删节点。  
想想还是把name_带上中间顿号一并存为一个std::string算了。  
程序运行时可能会使用Nagato Yuki的第一人称。嗯，外星人的文档记录什么的……（别中二了好不好啦  
会玩一些凉宫系列里面的梗，键入Enter什么的。  
作为补偿把里面Nagato Yuki的moe_rate_设置为很大很大就好了。（如果计算机能存inf就更好了  

运行方法
========
编译成可执行文件。  
打开后会有文字提示如何操作。