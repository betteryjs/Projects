doxygen -g Doxygen.config

$ vi Doxygen.config          # 修改配置文件
RECURSIVE              = YES
$ doxygen Doxygen.config     # 根据代码生成文档

    



Gaphor，一个使用 GTK+ 用 Python 编写的 GPL 建模工具（因此可以在安装了 Python 和 GTK+ 的 *nix、MacOS 和 Windows 上运行）。目前 [2007 年 6 月]，它支持类、组件、动作/活动和用例图，“很快”会出现序列图和协作图。该工具强调绘制 UML 图，而不是应用程序生成。

pip install gaphor
gaphor

Umbrello，一个看起来很有趣的 GPL 建模工具，虽然我只是用它做了一个简短的试用。在（需要）KDE 和 Linux 下运行。还支持 C++ 和 Java 的代码生成和逆向工程（代码到 UML）。他们的宏伟目标是“与其他 KDE 开发工具实现深度集成，打造独一无二的开发平台”。
Astade旨在帮助从 UML 模型自动生成 C++ 源代码。它意味着实用而不是研究导向。目前，它可以作为 GCC 的前端。截至 2005 年 11 月，它的开发还处于早期阶段。有一个适用于 MS-Windows 的安装程序，或者您可以自己在 Linux 下编译源代码。
FUJABA（不太可能的首字母缩写词代表 Forward Unto Java And Back Again），支持 Java 系统的逆向工程和代码生成。它是一个研究系统（在 LGPL 下发布），支持 UML 类和行为图。免责声明：一些过去和现在的 FUJABA 项目成员是我的好朋友（Hi Jens、Albert、Jörg）。****