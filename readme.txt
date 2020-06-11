【问题描述】班级和团队管理信息系统

某学院建有若干学生班级和篮球队、ACM集训队等若干团队，招收了很多学生，每个学生可加入某个自然班，也可以自由加入多个团队，为该学院编写简单信息管理系统，请设计学生类、班级或团队类，每个学生信息对应一个学生实体，用智能指针表示班级、团队与学生间的关系。系统可按指令添加学生、创建班级、将指定学生加入指定班级或团队，指令有三种：添加学生指令：append 学生姓名；添加的学生学号从10000开始递增，互不相同；创建班级或团队指令：create class 班级名 或 create team 团队名；指定学生加入班级或团队指令：join class 班级名 学号 或 join team 团队名 学号。最后，输出所有学生名单、各班级学生名单、各团队学生名单，学生名单按添加或加入顺序显示。程序不可存在内存泄漏，不可预先假定学生人数、班级数、团队数等信息。假定所有指令和参数都是有效的。

【输入形式】系统以指令形式添加学生、创建班级、将指定学生加入指定班级或团队。学生姓名、班级名称、团队名称字符串内不含空格等特殊字符。
【输出形式】各学生名单中，每个学生输出信息占1行，含学号和名字，用空格分开，每份学生名单后有一空行。
【样例输入】

append tom

append smith

append zhang

append wang

append liu

create class 30321

create class 30322

create team acmer

create team football

join   class 30321 10000

join   class 30322 10001

join   class 30321 10002

join   class 30322 10003

join   class 30322 10004

join   team acmer 10001

join   team acmer 10002

join   team  football 10002

join   team football   10003

join   team acmer    10004

append sun

join  class 30321   10005

join  team football 10005

【样例输出】

student list:

10000 tom

10001 smith

10002 zhang

10003 wang

10004 liu

10005 sun



class 30321:

10000 tom

10002 zhang

10005 sun



class 30322:

10001 smith

10003 wang

10004 liu



acmer team:

10001 smith

10002 zhang

10004 liu



football team:

10002 zhang

10003 wang

10005 sun


【样例说明】
【评分标准】

