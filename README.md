﻿这是一个用来练习C++的项目。

大概是在文件中记录Character和VoiceActress两种Person（类），可以增删文件内容的东西。

极其简陋。开始还想做图形界面的想想还是算了，还有更有意义的东西要做。

所有Characters会存为一个链表。VoiceActresses也是。

理论上来说，VoiceActress类里面的成员有很多个Character变量，应该把每个VoiceActress的所有Character存为链表，方便文件读写也方便增删节点。

但是我的本意是尝试两个并列的类同时由同一个基类派生而来，进而可以使用虚函数（读取moe_rate）或者模板（构建链表）什么的……

所以还是把每个VoiceActress的所有Characters带上中间点逗号空格一并存为一个std::string算了

将来程序运行时可能会使用Nagato Yuki的第一人称。嗯，外星人的文档记录什么的……（别中二了好不好啦

（没办法的事情把……C++这么麻烦，不这样恐怕没办法把这个项目写完……

（毕竟是一边追掟上今日子一边写的……（（世界上有Gakki这样的天使真是让人想离开二次元甚至离开代码

（作为补偿把里面的Nagato Yuki的moe_rate设置为很大很大就好了。（（如果计算机能存inf就更好了

（不要问我没有右括号这种语言习惯是哪里学来的

（凡是有左括号的都可以当作没看见