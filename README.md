# Nom - Non-Blocking IO + IO mulitipling 
#说明
1.Nom 体现了现代 C++两大风格， 事件回调和采用智能指针进行资源管理。
开发技术： linux 网络编程， C++。
编写了基本的设施库， 封装了互斥锁、 条件变量、 线程池等 posix 组件， 参与编写网络设施库，
包含 Socket API 和基本服务器模型的封装， 以及异常类， 定时器的封装， 同时编写了相关的测
试用例。
2.Nom的不足之处
对错误处理比较粗糙，没有一个比较规范的日志。
没有提供缓冲区，不应该让用户执行read操作
3.下一步计划
  为每一个TcpConnection 配置一个output buffer/ input buffer 
  Buffer设计
  1）一块连续的内存
  2）size() 可以自动增长

源码分析：
1）NonCopyable、Copyable 表示对象是否可以复制赋值
2）Exception相比标准库的exception，增加了打印栈痕迹的功能
3）ThreadPool
   MutexLock、Condition、Thread、ThreadPool 均采用RAII技术。
4）定时器
  采用timerfd，可以将fd加入IO复用模型来模拟定时器触发事件
5）TcpServer
  Tcp协议是一种流模式。故Rio 封装 readn readline writen 来防止粘包
  Socket InetAddress 封装socket操作，sockaddr_in结构体
  TcpConnection采用shared_ptr管理其生命周期
  PollPoller封装Poll模型 map<int,TcpConnectionPtr>实现从文件描述符到Tcp连接的映射
  

  
  
