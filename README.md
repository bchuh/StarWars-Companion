# StarWars-Companion
A computer vision project that detect, classify Star Wars characters and show their info.
+ This is a group project of course *Software Project Management* @ Macau University of Science and Technology
-----------
## This is the sprint 1 of development
+ ### To all group members: Please prevent editing files uploaded by other team members!! 
+ #### 所有组员： 请不要修改其他组员上传的文件，因为这会导致他人<code>git pull</code>冲突
+ ### To all group members: Files of different modules should be put in different folders.
+ #### 所有组员： 不同模块的文件请存在不同的文件夹下，不要和其他模块混在一起。跨模块调用时使用 \#include "..\example.h"
+ #### 整个项目只能有一个.pro文件，除了前端同学，其他人不要把.pro传上来。
+ #### 目录参考结构： 
```
dev
│   README.md
│   ...    
│
└───Camera_module
│   │   file011.h
│   │   file012.cpp
│   │
└───Frontend
│   │   file011.h
│   │   file012.cpp
│   │
└───Deep_learning_module
│    │   file111.h
│    │   file112.cpp
│    │   ...
│   
└───Database
    │   file021.h
    │   file022.cpp
    |   ...
```
#### github如何拉取到本地开发？
1. 用visual studio克隆存储库，在界面切换到dev分支，然后开发。
+ 提交前，先commit提交本地，再pull。这样可以防止代码被远端覆盖。
+ 想要提交时，填对提交的描述，如“增加了数据库查询功能”。
+ 提交完pull远端，解决冲突（重要，如果有的话要解决，否则你写的代码会被远端覆盖，但如果大家不改别人的代码就问题不大）。
+ pull完再push，完成！

2. 用qt creator的入口也能添加github仓库，具体百度
3. 或者用Github Destop也可以可视化的pull和push。
