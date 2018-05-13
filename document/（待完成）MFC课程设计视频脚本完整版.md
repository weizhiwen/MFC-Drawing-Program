# MFC 课程设计视频脚本

## 第一讲（分析课程设计)

（形式：屏幕录制桌面，老师自我介绍）

同学们，大家好，我是本套 MFC 课程设计视频的讲解老师——刘波涛，大家可以叫我刘老师。

### 1. 为什么会有这套视频

（形式：屏幕录制桌面，老师聊聊本套视频的目的）

这是大家在学完《C语言》和《C++ 面向对象编程》两门课程之后的第一个课程设计，在往年课程设计指导中，老师发现很多同学对于课程设计比较迷茫，简言之，就是不知道做什么。

而一些基础比较好的同学，能做出来部分程序，但不清楚程序内部的运行原理。

所以老师决定出一套讲解 MFC 课程设计的视频，其目的不只是教大家完成本次的课程设计，相信对你以后的课程设计也会有指导作用。

### 2. 解读课设任务书

（形式：屏幕录制打开的任务书，老师解读文档）

在收到课程设计任务书后，我们要根据任务书上的要求来完成课程设计，下面老师就带领大家解读本次课程设计的任务书。 

需要重点关注 **课程设计的要求** ，（鼠标移到 课程设计的功能要求，一边解读，一边鼠标跟随）本次课程设计是要求我们编制一个简单的图形编辑系统。

这个系统都有什么功能呢？可以添加、修改和删除图形元素，绘制下面这幅示例图中的图形。（鼠标放在示例图上）

大家可以看看这张图上的六种图形，有正方形 Square、矩形 Rectangle、正三角形 Triangle、圆形 Circle、椭圆形 Ellipse、文本 Text。

![六种图形](../视频脚本/images/六种图形.png)

通过对课程设计的要求分析，我们可以得出我们要做的是一个绘图程序，绘制正方形，圆形，文本等六种图形，功能是绘制新的图形，修改已有的图形，删除已有的图形。

具体怎么绘制，修改和删除呢？同学们，我们接着往下看。（鼠标接着图片下面的文字移动）

绘制一个图形，我们可以先找到图形的原点，也就是图形的中心点（鼠标指一指图上的点）。

如果绘制的图形是正方形，那么只要再给出正方形的边长，我们就可以确定这个正方形了。

另外还有图形的填充需要我们考虑，用什么模式填充，这里呢？就涉及到绘图的具体细节了。

我们在绘图的时候呢，在确定要绘图的位置之后，还需要确定图形画成什么模样，图形的边框是虚线还是实线？图形内是实心填充还是阴影填充？大家可以在纸上画一画想一想。

通过上面的讲解，我们已经知道了绘制图形需要一些参数，比如边长，边框类型，填充类型等等。

我们怎么输入这些参数呢？

我们之前写的程序都是Win32应用程序，比如刚开始学习编程时在控制台窗口输出的 “Hello，World！”，正式宣告我们踏入编程世界的大门，程序的输入输出都是在控制台中完成的。

而本次的课设，要求我们在一个参数对话框中来完成我们的参数输入，大家可以看一下任务书中的示例图。（鼠标指向图元属性对话框示例图）

![图元属性对话框示例图](../视频脚本/images/图元属性对话框示例图.png)

系统的功能是创建，修改，删除图形，具体的程序和用户的交互逻辑是按住 Ctrl键 + 点击鼠标左键来创建图形，鼠标左键双击编辑修改图形，鼠标右键双击删除图形。

关于图形类的设计，后面我们会专门有一讲来说。

任务书下面是一些辅助代码和一些安排说明，大家先看一看。

第二讲（创建 MFC 应用程序）

（形式：VS 实际操作演示）

1. 创建 MFC 应用程序

这一讲，我们将创建我们的 MFC 应用程序

首先打开我们的开发工具，Vistual Studio 2010（边说边打开），同学们在电脑上装 VS2010 之后的版本都可以。

为了我们操作方便，我们先把我们的 VS2010 的某些视图调出来，打开 VS2010 上面的视图选项栏（边说边操作），找到资源视图、属性窗口、工具箱，把它们放在合适的地方，我习惯停靠在右边，解决方案资源管理器我习惯放在左边。



下面我们就来新建一个项目（边说边操作），点击 文件 —> 新建 —> 项目，使用 Visual C++ 模版中的 MFC 模版，选择 MFC应用程序，输入解决方案名称和项目名称。



点击确定，下面我们就使用 MFC 的应用程序向导来创建我们的 MFC 应用程序。

MFC 应用程序向导，可以帮助我们快速搭建 MFC 应用程序所需的框架文件，我们通过它，可以更改 MFC 应用向导默认的项目设置。



点击下一步（边说边操作），根据我们的课程设计任务书上的要求，我们的应用程序类型是单个文档类型，我们改一下。

注意这个 文档/视图结构支持 需要选中，因为视图是我们绘图的地方，文档是我们存放图形的地方。

单文档和多文档的区别，这里简单说一下。

先来说一下多文档程序，来看我们的 VS IDE，我们可以同时打开多个文件，鼠标点击切换到不同的文件编辑。（边讲解变演示）



而单文档程序单个程序只能打开一个文件，操作一个文件，Windows 系统自带的记事本程序就是单文档程序。

很明显，单文档程序要相对简单些。

Unicode 库是选择代码的字符集编码，Unicode 是国际化的编码，默认选中。

项目类型默认就是 MFC 标准，关于 MFC 的使用呢？有两种，一种是 在共享 DLL 中使用 MFC，另一种是 在静态库中使用 MFC。

这两种有什么区别呢？

在共享 DLL 中使用是在你运行 exe 程序时链接系统中的 DLL，也就是动态的链接，如果系统中没有所需的 DLL文件，程序就会运行失败。

而在静态库中使用 MFC，是将程序所需的 DLL 文件放在项目目录下，不管系统中有没有程序所需的 DLL文件，程序都可以正常运行，这是一种静态链接。

很显然，动态链接方式程序的体积要小于静态链接方式的程序。

我们在这里就选择动态链接的方式吧。



点击下一步（边说边操作），因为我们选择的是单个文档类型，就不需要复合文档支持了，再次点击下一步。

文档模版属性，我们来看一下，主框架标题的名称和我们项目的名称一样，文档类型的名称也是，我们不需要改什么，直接点击下一步。



数据库支持，我们的项目用不到数据库，所以我们的数据库支持选无，点击下一步。

用户界面功能，主框架样式，我们可以看一下，有粗框架，最大最小化框，最大最小化，这些同学们可以看一看，使用默认的设置即可，点击下一步。



高级功能，有打印和打印预览，可以将我们绘制的图形打印出来，Activex 控件在这里我们用不到，可以不选择，点击下一步。



最后一步，生成的类，这里我们可以看到生成了四个类，CDrawingView，CDrawingApp，CDrawingDoc，CMainFrame。

其实应用程序还帮我们创建了一个说明本程序的关于对话框类，CAboutDlg，这个类在 Drawing.cpp 文件中，我们在后面会详细讲解这个对话框类。

在下面我们可以清楚的看到这四个类对应的 类名，基类，.h 头文件 和 .cpp 源文件。

CDrawingView 的基类，默认是 CView 基类，我们可以选择带垂直和水平滚动条的 CScrollView 类，它是从 CView 类继承过来的。



这里，老师先简单的说说这四个类的功能。（一边鼠标点击某个类，一边讲解）

CDrawingView 类，是负责程序界面上的图像改变的，我们将来的绘图就和这个类有关系。

CDrawingApp 类，是整个 MFC 应用程序的入口和开始文件，我们运行程序时，将先运行这个类中的开始方法。

CDrawingDoc 类，是负责存储程序界面上的图像信息的，这个类中有可以将对象序列化成二进制的方法，我们可以用这个方法实现保存操作，反过来，也可将序列化后的二进制文件中的信息恢复成具体的图形对象。

CMainFrame 类，是定义整个应用程序窗口框架的，前面我们使用类向导的过程中，有一步是选择 用户界面功能 的，这个就和这个类有关。

点击完成，我们的 MFC 应用程序就已经创建完成了，现在我们就可以点击运行程序，我们会看到有一个 Windows 窗口程序的样子。

到现在，我们并没有写一行代码，这是我们用应用程序向导创建出来的 MFC应用程序，但它没有任何的功能，我们的任务就是给这个半成品的应用程序添加我们想要的功能。

## 第二讲（创建 MFC 应用程序）

（形式：VS 实际操作演示）

### 1. 创建 MFC 应用程序

这一讲，我们将创建我们的 MFC 应用程序

首先打开我们的开发工具，Vistual Studio 2010（边说边打开），同学们在电脑上装 VS2010 之后的版本都可以。

为了我们操作方便，我们先把我们的 VS2010 的某些视图调出来，打开 VS2010 上面的视图选项栏（边说边操作），找到**资源视图**、**属性窗口**、**工具箱**，把它们放在合适的地方，我习惯停靠在右边，**解决方案资源管理器**我习惯放在左边。

![调出视图](../视频脚本/images/调出视图.png)

下面我们就来新建一个项目（边说边操作），点击 **文件** —> **新建** —> **项目**，使用 **Visual C++ 模版**中的 **MFC** 模版，选择 **MFC应用程序**，输入**解决方案名称**和**项目名称**。

![创建MFC应用程序](../视频脚本/images/创建MFC应用程序.png)

点击确定，下面我们就使用 MFC 的应用程序向导来创建我们的 MFC 应用程序。

MFC 应用程序向导，可以帮助我们快速搭建 MFC 应用程序所需的框架文件，我们通过它，可以更改 MFC 应用向导默认的项目设置。

![应用向导1](../视频脚本/images/应用向导1.png)

点击下一步（边说边操作），根据我们的课程设计任务书上的要求，我们的**应用程序类型**是**单个文档**类型，我们改一下。

注意这个 **文档/视图结构支持** 需要选中，因为视图是我们绘图的地方，文档是我们存放图形的地方。

单文档和多文档的区别，这里简单说一下。

先来说一下多文档程序，来看我们的 VS IDE，我们可以同时打开多个文件，鼠标点击切换到不同的文件编辑。（边讲解变演示）

![多文档举例](../视频脚本/images/多文档举例.png)

而单文档程序单个程序只能打开一个文件，操作一个文件，Windows 系统自带的记事本程序就是单文档程序。

很明显，单文档程序要相对简单些。

Unicode 库是选择代码的字符集编码，Unicode 是国际化的编码，默认选中。

**项目类型**默认就是 **MFC 标准**，关于 MFC 的使用呢？有两种，一种是 **在共享 DLL 中使用 MFC**，另一种是 **在静态库中使用 MFC**。

这两种有什么区别呢？

在共享 DLL 中使用是在你运行 exe 程序时链接系统中的 DLL，也就是动态的链接，如果系统中没有所需的 DLL文件，程序就会运行失败。

而在静态库中使用 MFC，是将程序所需的 DLL 文件放在项目目录下，不管系统中有没有程序所需的 DLL文件，程序都可以正常运行，这是一种静态链接。

很显然，动态链接方式程序的体积要小于静态链接方式的程序。

我们在这里就选择动态链接的方式吧。

![应用向导2](../视频脚本/images/应用向导2.png)

点击下一步（边说边操作），因为我们选择的是单个文档类型，就不需要**复合文档支持**了，再次点击下一步。

文档模版属性，我们来看一下，主框架标题的名称和我们项目的名称一样，文档类型的名称也是，我们不需要改什么，直接点击下一步。

![应用向导3](../视频脚本/images/应用向导3.png)

**数据库支持**，我们的项目用不到数据库，所以我们的**数据库支持**选无，点击下一步。

**用户界面功能**，主框架样式，我们可以看一下，有粗框架，最大最小化框，最大最小化，这些同学们可以看一看，使用默认的设置即可，点击下一步。

![应用向导4](../视频脚本/images/应用向导4.png)

**高级功能**，有**打印和打印预览**，可以将我们绘制的图形打印出来，**Activex 控件**在这里我们用不到，可以不选择，点击下一步。

![应用向导5](../视频脚本/images/应用向导5.png)

最后一步，**生成的类**，这里我们可以看到生成了四个类，**CDrawingView**，**CDrawingApp**，**CDrawingDoc**，**CMainFrame**。

其实应用程序还帮我们创建了一个说明本程序的关于对话框类，**CAboutDlg**，这个类在 Drawing.cpp 文件中，我们在后面会详细讲解这个对话框类。

在下面我们可以清楚的看到这四个类对应的 **类名**，**基类**，**.h 头文件** 和 **.cpp 源文件**。

CDrawingView 的基类，默认是 CView 基类，我们可以选择带垂直和水平滚动条的 CScrollView 类，它是从 CView 类继承过来的。

![应用向导6](../视频脚本/images/应用向导6.png)

这里，老师先简单的说说这四个类的功能。（一边鼠标点击某个类，一边讲解）

CDrawingView 类，是负责程序界面上的图像改变的，我们将来的绘图就和这个类有关系。

CDrawingApp 类，是整个 MFC 应用程序的入口和开始文件，我们运行程序时，将先运行这个类中的开始方法。

CDrawingDoc 类，是负责存储程序界面上的图像信息的，这个类中有可以将对象序列化成二进制的方法，我们可以用这个方法实现保存操作，反过来，也可将序列化后的二进制文件中的信息恢复成具体的图形对象。

CMainFrame 类，是定义整个应用程序窗口框架的，前面我们使用类向导的过程中，有一步是选择 **用户界面功能** 的，这个就和这个类有关。

点击完成，我们的 MFC 应用程序就已经创建完成了，现在我们就可以点击运行程序，我们会看到有一个 Windows 窗口程序的样子。

到现在，我们并没有写一行代码，这是我们用应用程序向导创建出来的 MFC应用程序，但它没有任何的功能，我们的任务就是给这个半成品的应用程序添加我们想要的功能。

## 第三讲（类的设计和编写）

### 1. 类的设计

(形式：根据课程设计任务书讲解)

经过前面课程中的分析，我们知道我们要做一个绘制图形的 MFC 应用程序，下面我们来分析这个应用程序所需的图形类。

我们要用面向对象的思想来看我们这个应用程序，我们要在计算机中绘制某个图形，我们是不是可以把这个图形看成一个对象，这个对象有什么特点，就是我们类中的成员变量，或者说是属性，我们对这个对象的操作就是类中的成员函数、或者说是方法。

那么下面我们的任务就是分析出图形·类的属性和方法。

我们先来分析类所需要的属性，我们在前面需求分析里，知道我们要绘制正方形，矩形，圆形，椭圆形，正三角形，文本六种类型的图形。

打开我们的课程设计任务书，我们先来看一看这些图形的特点。（根据图片上的图形分析属性）

![六种图形](../视频脚本/images/六种图形.png)

找到这张图，我们找找各个图形的相同点和不同点。

每个图形都有一个中心点，边框的样式，填充的样式，中心点是我们绘图的依据点。

而正方形有边长，矩形有长宽，圆形有半径，椭圆形有长半径和短半径，正三角形也有边长，文本有文本的内容和文本倾斜的角度。

这些就是我们需要的属性，我们再来看看每个类所需要的方法。

既然我们要绘制图形，绘图的方法啊，肯定少不了啦，我们想要修改图形，那么重新绘制图形的方法也需要，另外还有删除图形和保存图形的方法我们也需要。

同学们此时是否已经在脑海中有类设计的想法了呢？课程设计任务书上，也提供了类设计的方案，但这种设计有没有不足之处呢？大家先想一想。

![类设计示例图.png](../视频脚本/images/类设计示例图.png)

通过上面的分析，我们找到了图形之间的相同点，也发现了图形之间的差异，我们类的设计其实就是抽出这些异同点。

### 2. 绘图原理

（形式：鼠标移动到所讲之处）

我们要想在电脑中绘制我们的图形，我们就需要对在电脑绘图的原理有一个基本的了解。

先来看看平时我们是怎么在纸上画图的，我们肯定要先准备笔和纸，先后确定画的位置和图形的模样，我们就可以开始画了。

在 Windows 系统中，我们看到的每一个图像都是绘制出来的，绘制过程和平时画图类似。

大致的步骤为：获取设备环境，设置坐标映射，创建绘图工具，调用绘图函数绘图。

显示器、打印机都是设备环境，显示器有大有小，分辨率也有高低，硬件环境很复杂。

而我们编程人员，并不需要关注太多底层的信息，我们使用这些设备要通过操作系统来间接调用，Windows 系统为我们封装了绘制图形的相关函数，我们只需要学会使用他们。

前面说到 MFC 是对 WIndows API 函数的一种封装，MFC 中当然也封装了有和绘图相关的类。

设备环境类 CDC，用于设置绘图的属性（例如边框类型和填充类型）和绘制图形。

绘图对象类 CBrush，CFont，Cpen等，根据设备环境类的设置绘制具体的图形。

和我们在纸上画图一样，我们知道了图形怎么画，还要给要画的图形定个位置，也就是图形坐标。

在 Windows 坐标系中，X 轴正方向向右，Y轴正方向向下。

Windows 坐标系分为逻辑坐标系和设备坐标系两种，这是两种不同的记录位置的方式。

设备坐标系要考虑物理设备具体的大小，以物理设备的一个像素点位单位设置坐标的单位长度。

而逻辑坐标系不考虑物理设备的具体大小，也是我们我们写程序时绘制图形采用的坐标系，而图形在绘制时，Windows 在把逻辑坐标转换为设备坐标。

关于绘图的相关知识，同学们可以在CSDN看看这篇文章，[MFC GDI 绘图基础](http://blog.csdn.net/phunxm/article/details/5083119)。（打开该链接）

### 3. 类的编写

经过前面类的设计和绘图原理的讲解，下面我们正式开始类的编写。

我们先按照课程设计任务书上的设计方法，编写我们的类，也就是我们编写一个基类，其他图形类继承该类。

基类中的属性肯定是所有图形子类共有的属性，我们来想想都有哪些？

**绘图位置的坐标点X、Y，边框的颜色、线型、宽度，填充的颜色，类型**。

那么同学们再想一想，公共的方法都有哪些？

绘图的方法，修改图形的方法，删除图形的方法，还有保存的方法。

既然我们要编写类，就有想到具体的写法，比如各个属性的类型选用什么，方法大致怎么实现。

这里我们并不要求绘制图形时位置多么精准，所以我们这里的坐标使用 int 类型即可。

颜色，我们使用 MFC 中的数据类型 COLORREF，边框的线性、宽度、填充的类型我们也都使用 int 类型。

所以到目前为止，我们类的具体属性设计就为：（在VS中编写该类，取名为 WShape）

```c++
int OrgX; //逻辑坐标 X
int OrgY; //逻辑坐标 Y
COLORREF BorderColor; //边框颜色
int BorderType; //边框线型（实线，虚线，虚点线）
int BorderWidth; //边框宽度
COLORREF FillColor; //填充颜色
int FillType; //填充类型（实心，双对角， 十字交叉）
```

再来看看我们的方法，我们绘图时需要知道绘图的位置，然后再根据对象属性的具体内容绘制图形。

绘制好了图形，如果我们想修改，首先是要找要修改的图形，如果是我们想找的图形，我们再对它的属性重新设置，然后再次绘制即可，这样修改方法，需要一个匹配对应函数和修改属性的函数。

删除图形的方法，也需要先找到要删除的图形，在进行删除操作，我们在这里也需要用到匹配对应函数，删除图形其实就是销毁该图形对象，不需要在用其他的函数了。

为了降低难度，我们这里的修改属性只修改图形类中的共有属性，也就是基类中的属性，这样我们只需要在基类中实现一次该方法，所有的子类继承后，都可以调用该方法。

但是这种方法很明显存在缺陷，因为子类中的独有属性是不能修改的，大家能想到更好的方法吗?

有的同学可能会想到使用重载，基类中声明各个图形类的修改属性方法，因为每个图形类的独有属性是不一样的。

我们每新建一个图形子类，都需要在基类中添加对应的修改函数，这样确实可以解决问题，但是这并不是最好的解决方法。

类的设计涉及到软件开发中的设计模式，设计软件最好的原则是 **高内聚，低耦合**。

高内聚就是将一个功分成不可再分割的单个方法，比如我们这里修改图形的功能，是由图形匹配的方法，修改图形属性的方法，重新绘制图形的方法组成的。

图形匹配的方法又被删除功能所用，这样代码重用性就提高了。

低耦合就是要尽量降低各个类之间的关联，继承虽然可以解决问题，但是继承也不是万能的，如果继承的层次很深，那么要进行修改时，很可能就会 **牵一发而动全身**，给我们的代码维护带来很大难度。

**高内聚，低耦合**，这六个字可以说是软件设计的精髓，大家可以上网百度，查找相关的介绍。

保存的方法有些复杂，并且我们首先要知道，MFC 中怎么实现保存操作的。

MFC 的中的基本类 CObject 中有序列化函数 Serialize() 专门是针对对象保存的，我们可以让图形类的基类继承该类，然后在子类中实现序列化函数。

但是要想使用序列化函数，还需要声明和实现序列化的方法，这样该类才能被序列化。

序列化包括将具体的对象保存成二进制文件，也可称为是保存文件操作；还有将二进制文件中的对象信息读取出来，可称为读取文件。

但是我们想把对象保存起来，还需要知道对象的类型，便于区分各个对象的类型，所以我们还需要在基类的属性中加上图形的类型。

图形的类型是有限的，这里我们可以用枚举类型来表示图形的类型。

为了便于子类的继承，我们把基类的共有属性和共有方法都用 **public** 修饰符修饰。

综上所述我们的基类最终为：（在VS中继续编写代码）

```c++
enum ElementType {SQUARE, RECTANGLE, CIRCLE, ELLIPSE, TRIANGLE, TEXT};
class WShape:public CObject
{
public:
	ElementType Type; //图元类型
	int OrgX; //逻辑坐标 X
	int OrgY; //逻辑坐标 Y
	COLORREF BorderColor; //边框颜色
	int BorderType; //边框线型（实线，虚线，虚点线）
	int BorderWidth; //边框宽度
	COLORREF FillColor; //填充颜色
	int FillType; //填充类型（实心，双对角， 十字交叉）
public:
	WShape();
	virtual void Draw(CDC* pDC) = 0; // 绘制图元函数
	virtual bool IsMatched(CPoint pnt) = 0; // 判断鼠标点是否落在图形内
	virtual void Serialize(CArchive& ar) = 0; // 序列化函数
	void SetAttribute(int orgX, int orgY, COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType); //修改图形属性表函数
	virtual ~WShape();
};
```

在 .cpp 文件中，实现 SetAttribute() 函数（在VS中继续编写代码）

```c++
void WShape::SetAttribute(int orgX, int orgY, COLORREF borderColor, int borderType, int borderWidth, COLORREF fillColor, int fillType)
{
	OrgX = orgX;
	OrgY = orgY;
	BorderColor = borderColor;
	BorderType = borderType;
	BorderWidth = borderWidth;
	FillColor = fillColor;
	FillType = fillType;
}
```



我们这个基类是一个抽象类，共有的方法也都是抽象方法，具体的实现是在继承它的子类中实现的。

下面老师就带着大家实现正方形图形类的实现。

正方形类相比于基类，独有的属性是边长，基类中的抽象方法我们都要实现，

所以我们的正方形就可以这样写：（在VS中编写该类，取名为 WSquare）

```c++
#include "WShape.h"

class WSquare :public WShape
{
private:
	int Width; //正方形的边长
public:
	WSquare();
	WSquare(int orgX, int orgY, int width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	~WSquare();
};
```

在前面我们说到序列化是要在子类中声明和实现的，所以我们要在子类中的头文件中加上声明该类支持序列化的语句 `	DECLARE_SERIAL(WSquare); //声明类WSquare是支持序列化` 。（边讲解边加上）

加上后的正方形类代码：

```c++
#include "WShape.h"
class WSquare :public WShape
{
private:
	int Width; //正方形的边长
public:
	WSquare();
	WSquare(int orgX, int orgY, int width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor);
	void Draw(CDC*pDC);
	bool IsMatched(CPoint pnt);
	void Serialize(CArchive& ar);
	~WSquare();
	DECLARE_SERIAL(WSquare); //声明类WSquare是支持序列化
};
```

在 .cpp 文件中，实现这些方法。（在VS中继续编写代码）

我们在头文件中声明了序列化，在源文件中，还需要写实现序列化的语句 `IMPLEMENT_SERIAL(WSquare, CObject, 1)` 。（边讲解便加上）

先来看看无参的默认构造函数，我们怎么写。

我们可以给正方形对象默认的属性值，比如边长是多少，边款的粗细是多少，什么颜色等，这都是可以的。

老师这里只初始化必须要有的属性——对象的类型，其他的就不写了。（边讲解边写上）

```c++
WSquare::WSquare()
{
	Type = (ElementType)0;
}
```

为了方便我们创建对象，我们可以创建一个有参的构造函数，参数就是对象的所有属性，这个应该难不倒同学们。（边讲解边写上）

```c++
WSquare::WSquare(int orgX, int orgY, int width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)0;
	OrgX = orgX;
	OrgY = orgY;
	Width = width;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}
```

接下来，老师带着大家编写图形的绘图函数。

在前面，我们讲绘图原理时，老师提到绘图需要画笔和刷子，这里就不得不提MFC中封装的两个类了，Cpen 和 CBrush，Cpen是负责绘制图形的边框的，CBrush是负责图形的填充的，是不是类名起的还挺形象的。

我们还需要一个设备环境类，用来设置要绘制图形的位置，MFC中对应的类为 CDC，我们可以使用该对象的指针指向设备环境对象。

在绘制完一个图形时，我们还需要保存原画笔和原刷子，以便下次绘制图形时使用。（边讲解边写）

```c++
void WSquare::Draw(CDC*pDC)
{
	//创建画笔及用来保存原画笔的指针
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	//创建刷子及用来保存原刷子的指针
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//绘制图形
	pDC->Rectangle(OrgX - Width / 2, OrgY + Width / 2, OrgX + Width / 2, OrgY - Width / 2);

	//使用当前画笔和刷子
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}
```

关于图形匹配函数的编写呢？其实就是判断鼠标的位置是否在图形中，我们肯定是要得到鼠标的坐标了，MFC中封装了鼠标坐标的类，Cpoint。

鼠标位置是否在图形中，就是鼠标坐标是否在图形区域内，MFC 中有个关于图形设备接口（GDI）区域的类 Cpoint，它是专门处理图像区域信息的类。

我们先用该类创造出一个正方形区域，然后用该类中判断坐标点是否在图形中函数来判断。（边讲解边写）

```c++
bool WSquare::IsMatched(CPoint pnt)
{
	CRgn rgn;
	rgn.CreateRectRgn(OrgX - Width / 2, OrgY - Width / 2, OrgX + Width / 2, OrgY + Width / 2);
	BOOL flag = rgn.PtInRegion(pnt);
	if (flag)
		return true;
	else
		return false;

}
```

对于判断坐标点是否落在正方形图形中，还是比较简单的，而对于椭圆形，文本，会有些复杂，但是大致的思路，同学们一定要知道，可以上网查查，网上都有讲解的。

最后我们来编写序列化函数，序列化的步骤是固定的，大家学会了正方形图形的序列化，对于其他对象可以举一反三。

序列化我们要用到 MFC 中的 CArchive 类，我们可以先看看该类的用法，打开浏览器，搜索 **MFC CArchive**，我们就看看百度百科对它的介绍吧。（[网址链接](https://baike.baidu.com/item/CArchive)）（大致浏览一下）

CArchive 对象提供了一个类型安全缓冲机制，用于将可序列化对象写入 CFile 对象，也就是写到文件中，或者从文件中读取可序列化对象。

CArchive 类，我们可以简单的理解为既可以将对象保存到文件中，又可以将文件中的内容读取出来还原成对象。

所以序列化要考虑是保存操作还是读取操作，通过 IsStoring() 函数的布尔值来判断。（边讲解边写）

void WSquare::Serialize(CArchive& ar)
{

```
if (ar.IsStoring())
{
	//保存文件
	ar << (WORD)Type;
	ar << OrgX << OrgY;
	ar << BorderColor << BorderType << BorderWidth;
	ar << FillColor << FillType;
	ar << Width;
}
else
{
	//读取文件
	WORD w;
	ar >> w;
	Type = (ElementType)w;
	ar >> OrgX >> OrgY;
	ar >> BorderColor >> BorderType >> BorderWidth;
	ar >> FillColor >> FillType;
	ar >> Width;
}
```

}

最终，源文件的函数实现就为：（带着同学们大致浏览一下）

```c++
#include "WSquare.h"

IMPLEMENT_SERIAL(WSquare, CObject, 1)

WSquare::WSquare()
{
	Type = (ElementType)0;
}

WSquare::WSquare(int orgX, int orgY, int width, int borderWidth, int borderType, COLORREF borderColor, int fillType, COLORREF fillColor)
{
	Type = (ElementType)0;
	OrgX = orgX;
	OrgY = orgY;
	Width = width;
	BorderWidth = borderWidth;
	BorderType = borderType;
	BorderColor = borderColor;
	FillType = fillType;
	FillColor = fillColor;
}

void WSquare::Draw(CDC*pDC)
{
	//创建画笔及用来保存原画笔的指针
	CPen pen, *pOldPen;
	pen.CreatePen(BorderType, BorderWidth, BorderColor);
	pOldPen = (CPen*)pDC->SelectObject(&pen);

	//创建刷子及用来保存原刷子的指针
	CBrush brush, *pOldBrush;
	brush.CreateHatchBrush(FillType, FillColor);
	pOldBrush = (CBrush*)pDC->SelectObject(&brush);

	//绘制图形
	pDC->Rectangle(OrgX - Width / 2, OrgY + Width / 2, OrgX + Width / 2, OrgY - Width / 2);

	//使用当前画笔和刷子
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

bool WSquare::IsMatched(CPoint pnt)
{
	CRgn rgn;
	rgn.CreateRectRgn(OrgX - Width / 2, OrgY - Width / 2, OrgX + Width / 2, OrgY + Width / 2);
	BOOL flag = rgn.PtInRegion(pnt);
	if (flag)
		return true;
	else
		return false;

}

void WSquare::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		//保存文件
		ar << (WORD)Type;
		ar << OrgX << OrgY;
		ar << BorderColor << BorderType << BorderWidth;
		ar << FillColor << FillType;
		ar << Width;
	}
	else
	{
		//读取文件
		WORD w;
		ar >> w;
		Type = (ElementType)w;
		ar >> OrgX >> OrgY;
		ar >> BorderColor >> BorderType >> BorderWidth;
		ar >> FillColor >> FillType;
		ar >> Width;
	}
}

WSquare::~WSquare()
{
}

```

 剩下的五个图形类呢，由同学们自己来编写，你对老师上面所讲的这些理解明白后，相信对其他的类也有思路了。

遇到问题，比如某个函数你不会实现，同学们可以在网上查查资料，网络是我们最快捷的老师，好好利用，搜索资料也是我们要培养的重要能力，当然同学们也可以互相交流讨论，请教老师。

同学们，我们下讲再见。

## 第四讲 (对话框的创建和使用)

### 1. 关于对话框

（形式：在VS中实际操作，边讲边演示）

同学们，经过前面第四讲图形类的准备，我们下面就开始整个绘图程序的逻辑编写了。

在课程设计任务书中（边说边打开课程设计任务书），要求当按下键盘上的Ctrl键并单击鼠标左键时创建图元，图形的创建由参数对话框来编辑，以鼠标左击时的坐标位置为基点创建图形。

![课设要求1](../视频脚本/images/课设要求1.png)

并且在课设任务书的下面，还给出了参数对话框的示例图（鼠标找到示例图）

![属性对话框示例图](../视频脚本/images/图元属性对话框示例图.png)

我们在这个对话框中输入图形的相关参数，将这个对话框界面上的值再赋给图形对象对应的成员变量，调用绘图函数就可以把图形绘制出来了，所以我们首先要来创建一个类似的图元属性对话框。

之前我们用MFC程序应用向导创建完程序之后，就可以运行整个程序了，应用向导已经帮我们默认创建了一个关于这个应用程序的对话框，在哪里呢？带着大家来看一看。

我们把程序运行起来后（老师运行程序），在程序的**帮助**选项卡中点击**关于**选项，会就看到弹出弹出一个关于Drawing的对话框。

![关于对话框](../视频脚本/images/关于对话框.png)

这个对话框是在哪里定义呢？我们打开Drawing.cpp文件（边说边打开），就可以看到这个关于对话框的代码，我们发现这个对话框有对应的类 CAboutDlg，公有继承自 CDialogEx 类。

![关于对话框的代码](../视频脚本/images/关于对话框的代码.png)

我们还可以在资源视图中的 Dialog 对话框资源中更加直观的看到这个对话框对象，点击IDD_ABOUTBOX ，左边就会出现一个很直观的对话框模型图。

![关于对话框的资源视图](../视频脚本/images/关于对话框的资源视图.png)

我们可以直接用鼠标对这个对话框模型图操作，比如可以拖动上面确定按钮的位置，还可以在右边属性视图中，看到对这个关于对话框更加详细的属性。

![关于对话框的属性视图](../视频脚本/images/关于对话框的属性视图.png)

我们先来看两个地方，一个是**Caption**，英文翻译过来就是标题的意思，后面的属性值可以改变关于对话框的标题，我们可以试试。（试着修改Caption属性的值，演示一下）

另一个是**ID**，它是对话框的资源标识，同学们可以看成是资源对象的地址。

好比一个地方，根据不同的取名方法，可以给它取不同的名字，比如说北京，我们可以叫它北京市，但也可以说是中国的首都，这两种说法都是指向的同一个地方。

这点在后面还会讲，大家先有个概念。

其他的属性，同学们可以自己查查，都是什么意思，这里老师就不细讲了。

看完了关于对话框，我们怎样创建图形属性参数的对话框呢？

### 2. 创建新的对话框

对话框对象也是由对话框类创建的，我们想创建一个图形属性对话框，自然也是要有一个对话框类啦！

创建对话框类，我们可以借助类向导，选中我们的**Drawing**项目，右键找到**类向导**。

![打开类向导](../视频脚本/images/打开类向导.png)

选择我们的Drawing项目（边说边坐），点击类名下拉框，我们看到我们这个项目中的所有类，下面还可以看到类的基类，资源标识符，类在哪个文件中实现，类中的成员函数等。

我们后面的很多操作都要借助这个类向导完成。

![MFC类向导](../视频脚本/images/MFC类向导.png)

我们先用类向导创建图形对话框类，点击添加类，输入新对话框的类名，我们这里就叫 AttributeDlg吧（边说边写）。

同学们呢，还记得前面我们看的关于对话框的基类吗，没错，就是 CDialogEx（边说边选择 CDialogEx），对话框 ID我们就用默认的不改了。

![创建对话框类](../视频脚本/images/创建对话框类.png)

点击完成，我们的图形对话框类就创建好了，我们可以看到 MFC 类向导帮我们创建了头文件 AttributeDlg.h 和源文件 AttributeDlg.cpp。

我们再到资源视图中 Dialog 资源看一看，有个我们刚刚创建的对话框资源，点击，可以看到一个初始的对话框，点击预览按钮，就可以看到对话框运行起来的模样。

![初始图形对话框](../视频脚本/images/初始图形对话框.png)

课程设计任务书中，给我们一个对话框的参考图，我们可以仿着这个图来做。（边说边打开示例图）

![对话框上的控件](../视频脚本/images/对话框上的控件.png)

这个界面上的这些东西，我们称之为控件，这个示例图上是由不同类型的控件组成的界面。

我们先来认识一下这些控件（边看着示例图边讲解），图上的 **图元类型**、**原点X**、**宽度**、**线宽**、**填充风格** 等这些都是用的 **静态文本框控件**，**静态文本框控件** 用来放一些说明性的文字。

**图元类型** 后面的是 **下拉框控件**（用鼠标指指），可以下拉选择不同的选项，后面我们会将控件的相关使用。

下面这个是 **文本编辑框控件**（用鼠标指指），可以在这里面输入值，相信大家在网页登录都见过**文本编辑框**。

**静态文本框** 和 **文本域框** 外面是 **控件组合框**（用鼠标指指），把相关的多个控件包围起来，好看一点。

用来选择线色的这个是 **颜色选择框**（用鼠标指指），可以选择不同的颜色，我们在后面还会介绍另外一种颜色选择框。

用来选择线型和填充风格的这些是 **列表框**，和 **下拉框 **相比，内容显示的更多。

最下面的这两个确定和取消按钮，同学们应该都知道，这是按钮控件。

下面老师就带着大家搭建出我们的对话框界面，使用我们上面的控件。

打开我们的工具箱视图，这里面由我们要用的各种控件。（边说边打开，介绍一下红字标出的控件）

![工具箱中的控件](../视频脚本/images/工具箱中的控件.png)

Button：普通的按钮控件，这个大家平时见的很多了。

Check Box：单选框，比如我们在选择性别的时候，用的就是单选框，也就是说只能选一个。

Edit Control：文本编辑框，比如我们输入用户名和密码的时候用的就是文本编辑框。

Combo Box：下拉框，可以下拉选择不同的内容，比如我们选择院系的时候可以用这个。

List Box：列表框，选项直接显示出来，便于选择。

Group Box：控件组框，包围多个同组的控件。

Radio Button：复选框，可以选择多个选项，比如我们人的爱好可以有很多，我们就可以用这个。

Static Text：静态文本框，常用来显示说明性的文字。

Picture Control：图片控件，用来图片的显示。

List Control：列表控件，可以用来做表格或者带滚动条的文字列表。

Tree Control：树形控件，可以用来以树形结构显示文件夹的包含关系。

Tab Control：选项卡，可以在一个页面切换不同的选项，显示不同的内容，在网页上很常见。

MFC ColorButton Control：MFC 颜色控件，可以用来选择不同的颜色。

我们学习 MFC 中的这些控件，不管对于学习网页编写还是其他编程语言的图形界面上的控件都有帮助，它们之间这点都是相通的。

只要我们分清这些控件，把相应的控件拖到界面上，来搭建我们的对话框界面。（实际操作演示）

首先是我们的图元类型，是一个静态文本框，后面是一个下拉框，控件的各个属性是在属性视图更改的，我们可以把静态文本的内容改一改，也就是改控件的 Caption 属性，在前面我们也说过。

下拉框中的内容，我们直接用代码添加，包括下面的列表框也是。

形状参数中，我们要把用户输入的项都考虑到，原点X，原点Y，宽度，高度，文本，文本角度都要有，后面我们还会根据用户的选择让一些控件隐藏或者显示。

因为我们除了绘制文本时才需要用到文本和文本角度，在其他时候，我们就可以把这几项隐藏，这就提高了软件用户的体验性。

边框风格，包括线宽，线色，边框类型，边框类型我们用下拉框或者列表框都是可以的。

填充风格和边框风格很相像，就不多说了。

老师搭建的图形界面是这样的。（展示我们搭建对话框界面）

![搭建好的对话框](../视频脚本/images/搭建好的对话框.png)

我们搭建好了对话框，我们可以预览一下，但此时我们的下拉框、边框类型、填充类型里面都还没内容。

打开对话框类的源文件，找到 OnInitDialog() 函数，在这个函数中完成对话框界面显示的初始化。

我们先来初始化下拉框中的内容，每个控件也都是一个对象，是包含在对话框这个大对象中的小对象，对话框控件对应的 MFC 类为 CComboBox。

我们使用指针指向这个下拉框对象，还记得我们在前面说的资源标识符吗？我们想要得到对话框可以使用这个资源标识符，找到下拉框对象，从而对下拉框操作。

我们创建的这个下拉框的资源标识符去哪里看呢？

打开我们对话框构建界面，在属性视图的 ID 后面就是这个控件的资源标识符。

![下拉框的资源标识符](../视频脚本/images/下拉框的资源标识符.png)

为了方便我们的使用，我们常把控件的 ID 值修改为有意义的名称。

老师这里已经修改过了，修改完后，我们可以在头文件 Resource.h 文件中查看所有的资源标识符。（打开 Resource.h 文件）

我们可以看到在这个文件中由很多的宏定义，宏名称就是资源标识符，后面的数字是具体的编号，它们是一一对应的关系。

有时候我们在属性视图中修改完后，在 Resource.h 文件中看，会发现，一个编号对应两个资源标识符。

这是因为在用属性视图我们修改 ID 后，并没有把原来的资源标识符删除，需要我们手动删除。

对我们需要使用的控件修改其 ID 值，但一般静态文本框我们只是显示一下文字，所以静态文本框的 ID，我们可以不修改。

但文本编辑框，列表框，颜色选择框，我们在后面都要使用，所以最好都修改一下 ID 值。

我们使用 GetDlgItem() 函数（边讲解边写代码），参数为控件的资源标识符，我们就可以找到具体的控件对象，然后使用指针调用控件对象中的值。

我们使用 InsertString() 函数来向下拉框中按照固定的顺序插入对象，和数组下标类似，从 0 号开始。

为了提高用户体验性，我们可以把正方形选项作为第一个选项，也就是默认选项。

列表框对应的 MFC 类是 CListBox，与下拉框的添加内容类似，我们也用 InsertString() 函数插入内容，默认第一个选项被选择。

因为我们默认的图形选项是正方形，所以为了提高用户体验性，可以把文本输入框和文本角度框隐藏，当选项是文本时，再把这些控件显示。

得到文本输入框对象后，使用 ShowWindow() 函数，参数为 SW_HIDE 时隐藏，参数为 SW_SHOW 时显示。

```c++
// 初始化下拉列表中的内容
CComboBox* pComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_SHAPE_TYPE);
pComboBox->InsertString(0, L"正方形");
pComboBox->InsertString(1, L"矩形");
pComboBox->InsertString(2, L"圆形");
pComboBox->InsertString(3, L"椭圆形");
pComboBox->InsertString(4, L"正三角形");
pComboBox->InsertString(5, L"文本");
pComboBox->SetCurSel(0); // 将第一个作为默认选项

// 初始化列表框中的内容
CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST_BORDER_TYPE);
pListBox->InsertString(0, L"SOLID");
pListBox->InsertString(1, L"DASH");
pListBox->InsertString(2, L"DASHDOT");
pListBox->SetCurSel(0);

pListBox = (CListBox*)GetDlgItem(IDC_LIST_FILL_TYPE);
pListBox->InsertString(0, L"SOLID");
pListBox->InsertString(1, L"BDIALOGAL");
pListBox->InsertString(2, L"CROSS");
pListBox->SetCurSel(0);

// 隐藏文本输入框和文本角度框
CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TEXT);
pStatic->ShowWindow(SW_HIDE);
CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEXT);
pEdit->ShowWindow(SW_HIDE);

pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TEXT_ANGLE);
pStatic->ShowWindow(SW_HIDE);
pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEXT_ANGLE);
pEdit->ShowWindow(SW_HIDE);
```

接着我们来处理当选择文本时的显示，打开界面构建图（操作演示），选中下拉框控件，右键选择添加事件处理程序，选择第一个消息类型，添加编辑，也可以双击下拉框控件直接进行事件处理函数的编写。

![给图元类型添加事件处理程序](../视频脚本/images/给图元类型添加事件处理程序.png)

我们想要根据下拉框选择的选项来改变界面上控件的显示，那么我们如何获取下拉框选项的返回的值呢？

我们可以想添加下拉框内容那样，先用资源标识符获取到下拉框对象，然后调用 GetCurSel() 函数就可以得到下拉框选项。

注意这个函数返回的我们选择选项的序号值，就是我们插入内容时序号值。

这里我们换种方法，我们除了资源标识符，还可以直接使用变量来获取，也就是给下拉框对象起个名字，而不是一直用它的 ID 来叫它。

还是在界面构建下，选中下拉框控件，右键选择添加变量。



![下拉框添加变量](../视频脚本/images/下拉框添加变量.png)

在添加成员变量向导中，填写变量名，在类别一项，可选项有 Control 和 Value。

选择 Control 类别，则变量就是控件类别的，可以直接用该变量调用该控件的函数，下拉框控件我们就添加 Control 类别的变量。

而选择 Value 类别，变量就是值类别的，可以直接获得该变量的值内容。

比如文本输入框，添加一个值类别的变量，就可以来获取这个控件的值。

一个控件是可以既有 Control 类别，又有 Value 类别的变量名的，就像一个地方可以有两个名字，北京，首都。

![添加成员变量向导](../视频脚本/images/添加成员变量向导.png)

在使用添加成员变量向导之后，我们来看看都帮我们做了什么工作，打开对话框类的头文件和源文件。

我们可以看到头文件中多了我们刚才添加的变量定义，在源文件的 DoDataExchange() 函数内增加了 ID 值和变量名的绑定函数 DDX_Control()，这个函数是绑定 Control 类别的变量和资源标识符的，还有 DDX_Text() 函数是绑定 Value 类别的变量和资源标识符的。

现在我们使用下拉框 Control 类别的变量来获取下来框的下拉选项序号。（边说边写代码）

```c++
// 点击下拉框消息的处理函数
void AttributeDialog::OnCbnSelchangeComboShapeType()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = shapeType.GetCurSel(); // 根据用户选项调整界面
	if (index == 5)
	{
		// 显示文本输入框和文本角度框
		CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TEXT);
		pStatic->ShowWindow(SW_SHOW);
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEXT);
		pEdit->ShowWindow(SW_SHOW);

		pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TEXT_ANGLE);
		pStatic->ShowWindow(SW_SHOW);
		pEdit = (CEdit*)GetDlgItem(IDC_EDIT_TEXT_ANGLE);
		pEdit->ShowWindow(SW_SHOW);
	}
}
```

因为预览对话框，对话框的初始化是无法看到，所以还要在后面的实际运行中看到效果，下一讲，我们开始处理程序的交互逻辑。

# 第五讲（程序的执行流程）

## 1. 显示对话框

在第四讲中，老师讲解了对话框的创建和使用，本讲将带着大家理解程序的整个执行过程。

首先同学们要理解 **消息** 这一概念，在Windows中，鼠标的移动，键盘的输入，都是一种消息，应用程序根据这些消息来执行相应的处理程序。

比如说你打开 QQ 的聊天页面，在消息栏中输入一些你想发送的消息，然后点击发送按钮，聊天消息就被发送给了对方。

这里你用键盘输入的文字，和点击发送按钮其实对于 QQ 这个应用程序来说都是消息。

QQ 应用程序根据这些消息来调用相关的函数为你处理事情，或者称之为 **事件**，比如说你的消息被发送了，消息记录中出现了你发的消息，这都是事情处理的结果。

整个 Windows 系统都是消息驱动，事件处理的，MFC 是基于 Windows 系统的，当然也是有消息产生，有事件处理的。

我们来想一想绘图程序的整个输入输出逻辑，（边讲解边运行程序）当鼠标左键单击程序的，并按下键盘上的 Ctrl 键时，弹出我们的图元属性对话框。

![程序对应的区域](../视频脚本/images/程序对应的区域.png)

用户在往对话框输入值后，程序根据这些值来绘制具体的图形。

（边讲解边在运行的程序上比划）我们画图的区域是由 DrawingView 文件控制的，而整个程序框架上的控件是由 MainFrm 文件控制的。

我们要在画图区域操作，就要在 DrawingView 文件中添加代码，和我们在对话框上的事件处理一样，打开类向导。

![类向导处理消息](../视频脚本/images/类向导处理消息.png)

在消息一项中找到鼠标左键单击的消息名，添加处理程序，这样在消息产生后，程序就可以对这个消息做出相应的操作，比如弹出我们的对话框。

消息都是以 WM 作为前缀开头，因为是 Window Message 窗口消息嘛，鼠标左键按下的消息是 WM_LBUTTONDOWN，添加处理程序。

通过上面的操作，我们来看看类向导为我们做了什么，打开 DrawingView.h 文件，可以看到新增的消息映射函数，`afx_msg void OnLButtonDown(UINT nFlags，CPoint point)`，这个函数来处理我们鼠标左键按下的消息。

所谓映射就是一一对应的关系，一个消息只能对应一个处理函数，而一个处理函数也只能处理一个消息。

![自定义的消息映射函数](../视频脚本/images/自定义的消息映射函数.png)

我们在函数实现中完成弹出对话框的操作。

在使用框架时，很重要的能力是模仿，看看框架中的示例程序，能够更好的帮助我们理解和使用框架。

如果我们把关于对话框的显示弄明白了，显示我们自己创建的对话框也自然没有问题。

打开 Drawing.cpp 文件，找到 OnAppAbout() 函数，这里面的代码就是让关于对话框显示出来的。

![关于对话框的显示](../视频脚本/images/关于对话框的显示.png)

仿着这个来写我们对话框的显示，找到刚才的消息处理函数，使用我们的对话框类 AttributeDialog，创建对话框对象，调用 DoModal() 函数就可以让对话框显示出来了。（边讲解边写代码）

```c++
// 按下鼠标左键的消息响应函数
void CDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	AttributeDialog dialog;
	dialog.DoModal();
}
```

我们再来运行程序，在程序中单击鼠标左键，对话框就可以显示出来了。

不过课程设计任务书上还要求按下 Ctrl 键，这个也好办，我们只需要在按下鼠标左键时，判断 Ctrl 键是否也被按下。

消息映射函数中的参数 nFlags 是无符号长整型，无法直接和键盘按键消息 16 进制数对比，需要先与 MK_CONTROL 做相与逻辑运算后再和 MK_CONTROL 比较判断真假。

```c++
// 按下鼠标左键的消息响应函数
void CDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if ((nFlags&MK_CONTROL) == MK_CONTROL)
	{
		AttributeDialog dialog;
		dialog.DoModal();
	}
}
```

我们的对话框可以显示了，我们下一步是要得到在对话框输入的值。

打开我们创建的对话框类 AttributeDialog 的源文件，（边说边打开 AttributeDialog.cpp 文件），在 DoDataExchange() 函数中，实现对话框界面和变量的绑定。

也就是说，通过界面输入的值会赋值给对应的变量。

我们在前面根据用户的选项来改变对话框界面的显示时，已经添加了一个下拉框对应的 Control 类别的变量 shapeType。（找到 OnCbnSelchangeComboShapeType() 函数）

我们根据这个变量使用 GetCurSel() 函数来获取用户选择的选项序号，而不是直接获取用户选择的值。

对于文本编辑框，我们可以直接使用 Value 类别的变量获取输入的值，还是在类向导中给控件添加变量，比如我们给原点X 后面的文本编辑框添加一个 Value 类别的变量。（演示一下）

![给控件添加变量示例](../视频脚本/images/给控件添加变量示例.png)

这样用户输入的原点X 的值就会赋给文本编辑框控件对应的 Value 类别的变量，实现了界面值到变量值的传递。

MFC 中 Value 类别的变量类型有 int 类型和 CString 类型，分别和 C++ 中的 int 类型和 String 类型对应。

![控件变量类型](../视频脚本/images/控件变量类型.png)

根据文本编辑框输入值的类型来决定对应 Value 类别控件变量的类型。

对于文本编辑框来说，我们只需要绑定 Value 类别的控件变量即可，而对于下拉框，列表框，颜色选择框，我们要用 Control 类别的控件变量获取选择的值。

根据我们所需的值，同学们自己添加相应的控件变量。

可以在 AttributeDialog.h 文件中看到我们添加的控件变量。

![自定义的控件变量](../视频脚本/images/自定义的控件变量.png)

同学们再想一想，我们什么时候获取控件变量的值呢？

用户输入完毕后，选择图元的类型，在按下图元属性对话框上的确定按钮后，对话框消失，我们就无法知道对话框界面上输入的值了。

所以我们要在**对话框消失之前**，用户**按下确认按钮之后**获取对话框界面上的值。

我们就需要编写处理按下确认按钮消息的处理函数，可以在对话框编辑界面双击确定按钮进入按钮点击函数的编写。

![处理确定按钮消息](../视频脚本/images/处理确定按钮消息.png)

`CDialogEx::OnOK();`这一句是调用对话框父类 CDialogEx 的 OnOK() 函数，更新对话框界面上的值到对应的控件变量中。

所以我们添加的代码要写到这一句的后面，而不能写到这一句代码之前，否则就无法获得最新的对话框界面的值。

下面我们来编写我们的 OnBnClickedOk() 函数。（边说边写）

我们要获取图形类型的选项，因为我们要靠这个来决定绘制正方形还是矩形还是其他的图形。

我们还要获取变量类型的选项值，填充类型的选项值，边框颜色的值，填充颜色的值。

为了方便记录图形类型的选项，边框类型的选项，填充类型的选项，我们可以在头文件中自定义三个变量 comboxIndex，borderTypeIndex，filltypeIndex分别来记录。

![自定义变量记录选项的值](../视频脚本/images/自定义变量记录选项的值.png)

```c++
void AttributeDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	comboxIndex = shapeType.GetCurSel(); // 获取图形类型选项值
	borderTypeIndex = borderType.GetCurSel(); // 获取边框类型选项值
	filltypeIndex = fillType.GetCurSel(); // 获取填充类型选项值
	borderColor = borderColorButton.GetColor(); // 获取边框颜色值
	fillColor = fillColorButton.GetColor(); // 获取填充颜色值
}
```

获取界面上的值之后，我们就可以根据这些值来绘制我们的图形了。

回到 DrawingView.cpp 文件的 OnLButtonDown() 函数，（鼠标指到这里）我们创建对话框对象，并使对话框已经显示了。

这里要获取鼠标的位置，涉及到设备坐标转换成逻辑坐标（DP->LP）的问题，课程设计任务书中已经给出了代码。（鼠标指到这里）

![设备坐标转换为逻辑坐标](../视频脚本/images/设备坐标转换为逻辑坐标.png)

我们可以在**对话框显示之前**获取逻辑坐标，然后当**对话框显示之后**让鼠标的坐标位置显示出来。（边写代码边讲解）

根据对话框的 DoModal() 函数的返回值，我们可以知道对话框界面上的确定按钮是否被按下，进而获取我们想要的值。

我们获取值时不管绘制的是什么图形，要把界面上所有的值都获取到，不同的图形使用的值也不同，各取所用。

根据用户选择的图形类型，我们来绘制相关的函数，我们可以用一个 switch 语句来做。

按照我们设置的图形序号，是 0 就绘制正方形，是 1 就绘制矩形，是 2 就绘制圆形，是 3 就绘制椭圆形，是 4 就绘制正三角形，是 5 就绘制文本。

![下拉列表初始化内容](../视频脚本/images/下拉列表初始化内容.png)

```c++
// 按下鼠标左键的消息响应函数
void CDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// 设备坐标转换成逻辑坐标（DP->LP）
	CClientDC dc(this);
	CPoint pntLogical = point;
	OnPrepareDC(&dc);
	dc.DPtoLP(&pntLogical);

	// 判断在鼠标左键按下的同时，Ctrl键是否按下
	if ((nFlags&MK_CONTROL) == MK_CONTROL)
	{
		AttributeDialog dialog; // 创建对话框对象
		// 在对话框显示之前获取逻辑坐标
		dialog.orgX = pntLogical.x;
		dialog.orgY = pntLogical.y;
		// 对话框的返回值是否是IDOK
		if(dialog.DoModal() == IDOK)
		{
			//获取图形的属性
			int orgX = dialog.orgX;
			int orgY = dialog.orgY;
			int width = dialog.width;
			int height = dialog.height;
			CString textContent = dialog.textContent;
			int textAngle = dialog.textAngle;
			int borderWidth = dialog.borderWidth;
			int borderType = dialog.borderTypeIndex;
			COLORREF borderColor = dialog.borderColor;
			int fillType = dialog.filltypeIndex;
			int fillColor = dialog.fillColor;
			int comboxIndex = dialog.comboxIndex;
			switch(comboxIndex)
			{
			case 0:
				{
					// 正方形
					WSquare *p = new WSquare(orgX, orgY, width, borderWidth, borderType, borderColor, fillType, fillColor);
					// 绘制正方形
				}
             ...
		}
	} 
}
```

绘制图形，肯定是调用图形对象中的绘图函数啦，但是我们还要在每个 case 语句中传入设备指针 CDC* pDC。

用心的同学可能已经发现 DrawingView.cpp 文件有一个 OnDraw() 函数，（鼠标指到这里），这个函数是绘制程序的整个 View 界面的，而每个图形中的 Draw() 函数只是这个 OnDraw() 函数绘制的一小部分。

每个图形的绘图函数要受这个 OnDraw() 函数的调控，我们还可以看到这个函数中有 CDrawingDoc 类的对象，这是我们整个程序的数据文档存储对象。

![全局的绘图函数](../视频脚本/images/全局的绘图函数.png)

我们应该把我们绘制的图形都保存到这个文档对象中，然后在这个 OnDraw() 函数逐一绘制，刷新界面就可以看到绘制的图形，这就是绘图的整个流程。

现在我们再打开 DrawingDoc.h 和 DrawingDoc.cpp 文件，既然我们要保存绘制的图形，就需要一个集合对象来保存这些图形对象。

这里我们使用数组来保存，也便于图形对象的存取，我们在DrawingDoc的头文件中加上 `CObArray shapeArray; // 图元数组`。

所以在 case 语句中，我们只需要将图形对象保存到文档对象CDrawingDoc的数组中，然后再 OnDraw() 函数中取出，执行绘图函数 Draw()，刷新界面即可。

下面继续 OnLButtonDown() 函数的编写，我们要使用文档对象的数组，就需要获得这个对象，和 OnDraw() 函数中的写法一样 `CDrawingDoc *pDoc = GetDocument();`。（边讲解边写代码）

所以正方形的代码就是：

```c++
case 0:
{
    // 正方形
    WSquare *p = new WSquare(orgX, orgY, width, borderWidth, borderType, borderColor, fillType, fillColor);
    pDoc->shapeArray.Add(p);
    break;
}
```

其他图形的写法类似，同学们自己完成。

```c++
if ((nFlags&MK_CONTROL) == MK_CONTROL)
	{
		AttributeDialog dialog; // 创建对话框对象
		// 在对话框显示之前获取逻辑坐标
		dialog.orgX = pntLogical.x;
		dialog.orgY = pntLogical.y;
		// 对话框的返回值是否是IDOK
		if(dialog.DoModal() == IDOK)
		{
			//获取图形的属性
			int orgX = dialog.orgX;
			int orgY = dialog.orgY;
			int width = dialog.width;
			int height = dialog.height;
			CString textContent = dialog.textContent;
			int textAngle = dialog.textAngle;
			int borderWidth = dialog.borderWidth;
			int borderType = dialog.borderTypeIndex;
			COLORREF borderColor = dialog.borderColor;
			int fillType = dialog.filltypeIndex;
			int fillColor = dialog.fillColor;
			int comboxIndex = dialog.comboxIndex;
			switch(comboxIndex)
			{
			case 0:
				{
					// 正方形
					WSquare *p = new WSquare(orgX, orgY, width, borderWidth, borderType, borderColor, fillType, fillColor);
					pDoc->shapeArray.Add(p);
					break;
				}
             ...
             }
			Invalidate();//刷新窗口
		}
	} 
```

在 switch 语句之后，我们调用 Invalidate() 函数刷新整个程序窗口，这个刷新函数会调用 OnDraw() 函数，我们接着来编写 OnDraw() 函数。（边讲解边写代码）

我们可以得到图形数组中的对象数量，遍历数组，利用多态性，使用图形基类的父类指针指向数组中的每个图形对象，调用子类中的 Draw() 函数，这样就完成了整个图形的绘制了。

```c++
void CDrawingView::OnDraw(CDC* pDC)
{
	CDrawingDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int count = pDoc->shapeArray.GetCount();
	if(count > 0)
	{
		WShape *p = NULL;
		for(int i = 0; i < count; i++)
		{
			p = (WShape*)pDoc->shapeArray[i];
			p->Draw(pDC);
		}
	}
}
```

每次程序界面刷新，我们创建的图形都会重新绘制一遍，因为计算机的速度很快，我们很难感受到这种图形绘制的过程，感觉像是新图形在原来已经绘制好的图形基础上添加上去的一样。

至此图形绘制的功能就已经完成了，下面我们来完成剩余的功能。

当只按下鼠标左键而没有按下 Ctrl 键时，我们要判断，鼠标是否落在了已经绘制的图形内（运行程序，绘制图形，举例说明）。

判断鼠标是否落在了已有的图形当中，需要使用数组中图形对象的 IsMatched() 函数一一调用。（边讲解边写代码）

如果鼠标落在了某一个图形内，为了更好的用户体验性，我们可以把被选中的图形的参数显示在对话框的相应位置。

和绘制图形一样，在确定按钮按下后，改变图形的属性值，刷新窗口，重新绘制整个界面。

```c++
// 判断鼠标的落点是否在图元内，修改操作
else 
{
    //未按下Ctrl键时左击，则逐个比较，看是否命中图元
    WShape *p = NULL;
    int count = pDoc->shapeArray.GetCount();
    for (int i = 0; i < count; i++)
    {
        p = (WShape*)pDoc->shapeArray[i];
        if (p->IsMatched(pntLogical))
        {
            //修改图元属性，从图元属性值里面取值赋值给对话框的变量
            AttributeDialog dialog;
            dialog.orgX = p->OrgX;
            dialog.orgY = p->OrgY;
            dialog.borderColor = p->BorderColor;
            dialog.borderWidth = p->BorderWidth;
            dialog.borderTypeIndex = p->BorderType;

            if (dialog.DoModal() == IDOK)
            {
                //利用改了以后对话框中图元的属性更新到文档图元数组的对象中
                p->OrgX = dialog.orgX;
                p->OrgY = dialog.orgY;

                p->BorderColor = dialog.borderColor;
                p->BorderWidth = dialog.borderWidth;
                p->BorderType = dialog.borderTypeIndex;

                p->FillColor = dialog.fillColor;
                p->FillType = dialog.filltypeIndex;

                p->SetAttribute(p->OrgX, p->OrgY, p->BorderColor, p->BorderType, p->BorderWidth, p->FillColor, p->FillType);
            }
            Invalidate();//刷新窗口
        }
    }
}
```

图形的删除功能，同学们想一想该如何实现呢？

课程设计任务书上要求鼠标右键双击某个图形，删除某个图形。

图形对象保存在一个数组中，我们只要把要删除的图形对象从数组中移除，然后刷新窗口，重新绘制剩下的图形，给人的印象就是删除了某个图形。

和图形修改功能类似，删除图形也要先判断是哪个图形，也是使用图形对象的 IsMatched() 函数逐个比对。

找到想要删除的图形后，为了做的用户体验性更好一点，可以使用简单消息对话框函数 AfxMessageBox()，让用户再次确认是否要删除图形。

消息对话框函数 AfxMessageBox() 的第一个参数是要显示的文本内容，第二个参数决定对话框上的按钮，比如我们只想有确定和取消按钮，就可以将第二个参数设为 MB_OKCANCEL。

根据对话框函数的返回值，来判断用户是否真的要删除，同学们可在网上搜索这个消息对话框函数的其他参数，推荐大家去微软官方的文档中心查询，网址 https://msdn.microsoft.com/zh-cn/library/。（打开网址）

![微软类库API](../视频脚本/images/微软类库API.png)

在搜索栏输入我们要查询的函数，比如就是这个消息对话框函数 AfxMessageBox() 吧，我们可以在这里找到这个函数的详细介绍。（带着同学们浏览一下网页）

![AfxMessageBox函数的介绍](../视频脚本/images/AfxMessageBox函数的介绍.png)

下面老师带着大家看一下这个 OnRButtonDblClk() 函数，数组中有删除某个元素的函数 RemoveAt() ，参数为要删除的元素的下标。

（编写代码）

```c++
void CDrawingView::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDrawingDoc *pDoc = GetDocument();

	CClientDC dc(this);
	CPoint pntLogical = point;
	OnPrepareDC(&dc);
	dc.DPtoLP(&pntLogical);//DP->LP进行转换 

	WShape* p;
	int count = pDoc->shapeArray.GetCount();
	for (int i = 0; i < count; i++)
	{
		p = (WShape*)pDoc->shapeArray[i];
		if (p->IsMatched(pntLogical))
		{
			int value = AfxMessageBox(L"你是否要删除？", MB_OKCANCEL);
			if(value == IDOK)
				pDoc->shapeArray.RemoveAt(i);
		}
	}
	Invalidate();//刷新窗口
}
```

图形的保存功能看起来很难，其实只需要很少的代码。

（打开 DrawingDoc.cpp 文件鼠标指到 Serialize() 函数）这个函数是整个程序的序列化函数，整个程序的的序列化操作都在这个函数中完成。

我们直接使用图形数组对象中的 Serialize() 函数，即可完成数组中每个图形对象的序列化，所以代码只要这一句 `shapeArray.Serialize(ar);`。（边讲解边写上）

CArchive类在前面类的设计时讲过，它是负责向文件中读写的类，使用它来完成保存文件和打开文件等操作。

```c++
// CDrawingDoc 序列化
void CDrawingDoc::Serialize(CArchive& ar)
{
	shapeArray.Serialize(ar);
}
```

到目前为止，我们的程序就算基本完成了。

同学们可以运行一下，看看有没有问题，这里老师就不带着大家运行了。

下面我们总结一下整个程序的执行流程。

我们这是一个绘图程序，程序的主类 CDrawingApp 负责整个绘图程序的启动和初始化，这个类是整个程序的司令官。

CMainFrame 类只是负责程序的主框架窗口，窗口上的工具栏，状态栏等都是该类管理的。

CDrawingView 类负责 View 界面的用户交互，处理界面上的消息，显示程序的数据对象，来完成整个程序的功能。

CDrawingDoc 类负责整个程序的数据存储，序列化操作就是典型的数据存取。

本次课程设计的程序是典型的 MFC 应用程序，程序的各个类各司其职，共同完成整个程序具有的功能。

写一个程序要处理的两大问题：

1.数据对象是什么，也可以说是数据模型，本程序的数据对象是图形对象，数据封装成对象存储。

2.数据对象怎么展示，也就是程序的界面，PC端的程序可以是 Windows 程序界面，也可以是基于浏览器的网页，在手机上可以是安卓界面，界面不同，处理的繁易也有区别，但是处理的逻辑大同小异。

不管再复杂的程序，核心都是解决这两个问题。

下一讲，老师将针对往年同学在课程设计中犯得错误做出总结和讲解，避免你们这一届的同学再犯。

## 第六讲（一些常见的错误）

### 1. 四个概念的辨别

（形式：屏幕录制浏览器，打开这几个概念的维基百科，边浏览边讲解）

网址：

- [C++](https://zh.wikipedia.org/wiki/C%2B%2B)


- [VC++](https://zh.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B)


- [Vistual Studio](https://zh.wikipedia.org/wiki/Microsoft_Visual_Studio)
- [MFC](https://zh.wikipedia.org/wiki/MFC_(%E5%BE%AE%E8%BB%9F))

一些同学在学完 C++，现在来做 MFC应用程序的课程设计，对于 C++，VC++，Visual Studio，MFC 这几个概念就出现了认识混乱，老师在这里有必要给大家辨别一下。

C++：这是一门编程语言，就像其他的编程语言，如长久不衰的 Java，现在最火的 Python，语言对于我们来说只是个表达思想的工具，我们也可以用 C++ 做网站，做软件。

VC++：全称是 Microsoft Visual C++，是微软公司的 C++ 开发工具。

简单的来说，这是一种 C++ 的编译工具，但并不是只有编译功能，还有编辑和除错等功能。

C++ 的源程序 .cpp文件，使用 VC++ 编译工具编译生成目标程序 .obj 文件，最后和 VC++ 中的相关库链接，生成可执行程序 .exe。

C++ 编译器并不止 VC++ 这一种，我们使用的 Vistual Studio 内置的就是 VC++ 编译器。

还有跨平台的 GCC 编译器，这个 Linux 平台用的比较多，Mac 系统下是 Clang 编译器，他们主要是在一些 C++标准的支持上有所不同。

关于这几种编译器的区别，同学们可上网进一步的了解。

Vistual Studio：这是 Windows 平台下常用的 C++ 集成开发环境，简称为 IDE。

它包含了软件开发所需的大部分工具，如代码管理工具，调试工具等等，我们平时的使用只发挥了 Vistual Studio 的很少功能。

我们在这里面写程序，在这里面运行就可以看到程序运行的结果，IDE帮我们做了很多事，可以提高我们的效率，但 IDE 也只是个写程序的工具，不能离开IDE就变得不会写代码了。

可以写 C++ 的 IDE 也不止 Vistual Studio 一个，还有开源的 Code:Blocks，C++ 版的 Eclipse，Qt Creator，Jetbrain 公司的 CLion 等等。

本次课设我们就使用 Vistual Studio 来写，老师使用的 Vistual Studio 2010，同学们用 这个版本或者更新的版本都是可以的，不要再使用 VC++6.0 这个老掉牙的IDE了。

MFC：全称是 Microsoft Foundation Classes，翻译过来是 **微软基础类库**，这是用 C++ 语言封装 Windows API 的一个框架。

Windows API 就是和 Windows 操作系统打交道的相关函数，这些函数都是基于面向过程的， 我们可以直接使用 C语言就可调用这些函数来编写 Windows应用程序。

MFC 经过 C++ 语言的封装，是基于面向对象的，我们使用 MFC 这个框架 更容易编写 Windows 程序。

框架，同学们可以认为是一个半成品，框架只是一些操作的封装，我们使用框架编写程序，可大大提高我们的编程效率，帮助我们更好的完成工作。

相信通过上面的讲解，同学们应该能够区分 C++，VC++，Vistual Studio，MFC 这几个概念了，大家课下也可以上网查阅资料，更深层次的了解。

### 2. 面向对象编程

（形式：打开各个图形类头文件和源文件）

本次课程设计我们使用 C++ 作为我们的编程语言，采用面向对象的编程思想，但是很多同学还不能较好理解面向对象中的核心思想。

面向对象的三大特性：**封装，继承，多态**，相信同学们背都会背，但要想真正的理解，需要在编程中体会，理解才会加深。

下面老师结合本次课程设计，再来捋一捋这三个特性在本次课程设计中的运用。

要想封装类，首先要根据我们的需要设计类，经过我们的分析，我们把图形的原点，边长，边框类型，填充类型等属性作为类的成员变量做了封装。

绘图的方法，序列化的方法和匹配的方法等作为类的成员函数封装在类中。

但是在封装时，一些同学经常会因为乱用 public，protected，private 这三个访问限定符而在编译时出错。

封装的思想，我们可以在C语言的结构体找到相似点，结构体中也可以封装属性，不同的是C语言的结构体不能直接封装方法，并且也没有访问限定符。

把一个类封装到什么程度，就需要使用访问限定符来做限制。

不考虑继承，protected 和 private 限制的属性和方法是不能直接使用对象访问的，而要使用该类中 public 修饰的方法来访问。

前面老师为了方便访问类中属性，把基类中的属性都设置为了 public 访问限制符，少写了获取属性值的 get 方法和设置属性值的 set 方法，大家知道就好。

C++ 的继承相比其他高级语言更复杂，如 Java，Python，其中一点就是 C++ 在继承时还要使用限制符，相信这也是大家有时候难以理解的原因。

我们在编写图形类使用了继承，正方形类和矩形类等都继承图元基类，继承的目的是想更好的代码复用，因为六种图形类中有相似的地方，这时我们就使用了继承来减少重复代码。

我们使用 public 继承，所以继承后基类中访问限制属性 public 不发生改变，这也是我们常用的继承方式。

继承是可以减少我们的代码量，但也会增加类之间的耦合性，如果基类设计的不好，那么继承它的后代子类都多少会受到影响，这就是继承带来的坏处。

多态增加了代码的灵活性，在图形数组的遍历后，我们使用基类指针来访问每一个图形子类对象中的方法，相信大家感受到了多态的使用了吧。

本次课程设计中对面向对象编程的使用，大家一定要掌握，这算是很基本和很典型的面向对象的使用。

大家已经在 C语言中学习了面向过程编程，又在 C++ 面向对象编程，老师给大家抛出一个问题，面向对象相比面向过程编程是更好的编程方式吗？

大家可以在接下来的学习中思考这个问题，如果你能对这个问题说出自己的见解，编程水平就已经有提高了。

### 3. 使用 MFC 框架

（形式：打开 DrawingView.cpp 文件）

使用 MFC 框架编写绘图程序，有一个很典型的错误，老师给大家讲一讲。

第一个是在 OnLButtonDown() 函数 switch 部分根据选项来绘图时，（指针指到这里）有些同学直接在 case 语句中使用绘图函数，所以每个 case 语句中都写了大量重复的绘图代码。

这些同学是对 DrawingDoc 文件保存图形对象的作用不理解，也可以说对单文档的 MFC 应用程序工作流程不明白。

还有一个错误当时让老师帮他解决，老师也是 Debug 调试了半天才发现，这是一个使用图形属性对话框的逻辑错误。

我们在前面讲到，要在**对话框消失之前**，用户**按下确认按钮之后**获取对话框界面上的值。

而这个同学是在获取对话框界面上的值时，对话框类中却没有他要获取的值的变量，结果在对话框消失之后，他使用对话框对象得到界面上的值一直报空指针异常，他自己也找不出是哪里的错误。

对话框都消失了，界面上的值就是未知的了，所以他这样做当然会出错啦！

这两个错误是都很有代表性的错误，希望同学们吸取他们的教训，不要再犯类似的错误。





