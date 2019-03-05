# 1.OSI五层模型

应用层(应用,表示,会话):TFTP,DNS,FTP,SMTP,HTTP
传输层:TCP,UDP
网络层:IP,ARP,ICMP
链路层:IEEE
物理层:IEEE

# 2.TCP

## 1.三次握手:

1.客户端向服务端发送连接请求(发送一个试探性的标志字符给服务器）
  SYN=1,Sep=x
2.服务器端接受到请求后告知客户端可以连接
  SYN=1,ACK=x+1,Sep=y
3.再次告知服务器客户端已经收到回复，下面要开始发送具体消息
  ACK=y+1,Sep=z

## 2.四次挥手:

1.主动方发送报文告知被动方要断开连接
  fin=1,Ack=z,Sep=x
2.被动方返回报文告知主动方已经接受到你的请求
  Ack=x+1,Seq=z
3.被动方会再次发送报文表示已经准备就绪可以断开
  fin=1,Ack=x,Sep=y
4.主动方断开连接告知被动方
  Ack=y,sep=x

## 3.TCP服务端操作步骤

1.s=socket(AF_INET,SOCK_STREAM,proto=0)
2.s.bind((ip,port))
3.s.listen(5)
4.connfd, addr=s.accept()
5.消息的收发
  data=connfd.recv(buffer)
  connfd.send(data) connfd.sendall(data)
6.connfd.close() s.close()

## 4.tcp客户端流程:

1.创建流式套接字
2.发起连接请求:connect((ip,port))
3.收发信息
4.关闭套接字

## 5.TCP应用之http传输

# 3.UDP

## 1.UDP数据报套接字服务器

1.创建数据报套接字
  s = socket(AF_INET, SOCK_DGRAM)
2.绑定本地IP和端口
3.收发消息
  data,addr=s.recvfrom(BUFFERSIZE)
  s.sendto(data,addr)
4.关闭套接字

## 2.udp 客户端

1.创建数据报套接字
2.消息收发
3.关闭套接字

## 3.udp应用之广播

s.setsockopt(SOL_SOCKET,SO_BROADCAST,1)

## 4.端口立即复用

s.setsockopt(SOL_SOCKET,SO_REUSEADDR,1)

# 4.IO多路复用

## 1.select

r,w,x = select(rlist,wlist,xlist[,timeout])

## 2.poll

1.创建poll对象
  p = select.poll()
2.加入关注的IO
  p.register(s)
  p.unregister(s)
3.使用poll函数进行监控
  events = p.poll()
4.处理发生的IO事件
5.poll IO 事件
  1.POLLIN rlist
  2.POLLOUT wlist
  3.POLLUP 断开连接
  4.POLLERR xlist
  5.POLLPRI 紧急处理
  6.POLLVAL 无效的数据

## 3.epoll

与poll几乎一致 支持水平和边缘触发 其他只支持水平触发

# 5.进程

## 进程是操作系统资源分配的最小单位

## 三态/五态

就绪态 运行(执行)态 等待(阻塞,睡眠)态
新建 就绪 执行 等待/阻塞 终止



## 孤儿进程

## 僵尸进程

1.父进程先退(不好控制)
2.让父进程处理子进程的退出
  os.wait()
  os.waitpid(pid,option)
3.使用信号处理
4.创建二级子进程
  1.父进程创建子进程后等待子进程退出
  2.子进程创建二级子进程后马上退出,二级子进程成为孤儿
  3.让父进程和二级子进程处理事件
优先级从高到低:-20~19
p = multiprocessing.Process(target=th1,args=(),kwargs={})
  1.p.start() 启动子进程
  2.p.join([timeout]) 阻塞等待回收相应的子进程
  3.p.name 进程名称
  4.p.pid 创建的进程的PID号
  5.p.is_alive() 进程状态 返回True or False
  6.p.daemon = True

os.fork()创建一个新进程
  失败返回一个负数 成功:1.返回0 2.正整数(子进程的PID)
os.getpid() os.getppid() os._exit(status)

## 进程池

1.创建
  pool=multiprocessing.Pool(数量)
2.加入等待队列
  pool.apply_async(func,args=(),kwds={})
  pool.map(func, iterable)
3.执行等待事件
  pool.apply()
4.关闭
  pool.close()
  pool.join()

# 6.进程间通信

## 1.磁盘交互

## 2.套接字

## 3.管道

1.fd1,fd2=multiprocessing.Pipe(duplex=True)
2.fd1.recv()
3.fd2.send(data)

## 4.消息队列

1.q=multiprocessing.Queue(maxsize = 0)
2.q.put(obj, block=True, timeout=None)
3.q.full() 判断消息队列是否已满
4.q.qsize() 消息队列内的数量
5.q.get(block=True, timeout=None)
6.q.empty() 判断是否为空
7.q.close()

## 5.共享内存

1.obj = multiprocessing.Value(typecode_or_type,obj)
2.obj = multiprocessing.Array(ctype,obj)

## 6.信号

1.发送信号
  os.kill(pid,sig) signal.alarm(sec)
2.信号处理
  signal.pause()
  signal.signal(signum,SIG_DFL/SIG_IGN/func)

## 7.信号量

1.sem=multiprocessing.Semaphore(num)
2.sem.acquire() 将信号量减一
3.sem.release() 将信号量加一

# 7.同步和互斥

## 1.同步:

同步是一种合作关系,为完成某种任务而建立的多个进程或者线程之间的协调调用,次序等待,传递消息告知资源占用情况,这种协调可能是由于阻塞达成的

## 2.互斥:

互斥是一种制约关系，当一个进程或者线程进入到临界区后会进行加锁操作,此时其他进程(线程)无法进入临界区,只有当该进程(线程)使用后进行解锁,其他人才可以使用,这种技术往往是通过阻塞或是加锁完成

## 3.进程间同步互斥方法

lock = multiprocessing.Lock()
lock.acquire() 上锁
lock.release() 解锁

## 4.Event事件

e = multiprocessing.Event()
e.wait([timeout]) 提供阻塞
e.set() 设置
e.clear() 清除设置
e.is_set() 判断是否被设置

# 8.线程

## 计算机核心分配的最小单位

## 线程属性和方法

t=threading.Tread(target=None,name=None,args=(), kwargs=None)
  1.t.start()     启动一个线程
  2.t.is_alive()  查看一个线程的状态
  3.t.name        查看线程的名称
  4.t.join([sec]) 阻塞等待回收线程
  5.threading.currentThread() 得到线程对象
  6.threading.currentThread().getName()获取线程名称
  7.t.daemon=True 主线程执行结束其他线程也会结束
  8.t.setDaemon(True)
  9.t.isDaemon() 返回True或是False
  10.t.setName(name) 为线程设置名称 任意均可

# 9.线程的通信

## 1.全局变量进行通信

## 2.线程间的同步和互斥

1.线程事件 threading.Event
2.线程锁 threading.Lock
3.条件变量 Condition
  1.con=threading.Condition()
  2.con.acquire() 加锁
  3.con.release() 解锁
  4.con.wait() 先解锁再等待通知,接到后再加锁
  5.con.notify() 发送通知

# 10.并发与并行

## 1.并发

1.同时处理多个请求,但是内核采用轮询时间片的方式逐个访问,某一时间点实际只处理一个任务
2.IO多路复用,协程,循环服务器,单线程

## 2.并行

1.使用多个内核,同时使用多个任务
2.多进程,多线程

# 11.服务器类

1.class Server(ForkingTCPServer):pass
  ThreadingTCPServer ThreadingUDPServer
  ForkingUDPServer
2.class Handler(StreamRequestHandler):
                DatagramRequestHandler
      def handle(self):pass
3.使用创建的服务器类来生产服务器
  server = Server((ip,端口号),Handler)
4.运行服务器
  server.serve_forever()
