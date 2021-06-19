# Unix-Network-Programming-Volume22
Interprocess Communications, bases on Second Edition. 
进程间通信的相关实现,本实验在`Ubuntu 20.04`,`gcc 9.30`,`CMake 3.16.3`环境下进行编程。
## Labs
本仓库主要对以下几个内容进行实践: 
- 使用`条件变量`+`互斥锁`实现读写锁  
- 生产者&消费者问题
    - 单生产者&单消费者
    - 多生产者&单消费者
    - 多生产者&多消费者
    - 多缓冲区的处理
- 信号量问题
    - FIFO实现信号量
    - 内存映射IO实现信号量
- 使用内存映射I/O实现Posix消息队列  

## 安装项目依赖
该项目将依赖安装在仓库之外，采取CMake对项目依赖进行管理。  
```sh
# I current in path ~/.Project,so I assume you are same to me.
# download source code 
wget http://www.kohala.com/start/unpv22e/unpv22e.tar.gz
tar -xvf unpv22e.tar.gz

cd unpv22e # current you are in path: ~/.Project/unpv22e

./configure    # try to figure out all implementation differences
#将config.h中如下三行注释掉，否则下一步make时会报错
# #define	uint8_t unsigned char				/* <sys/types.h> */
# #define	uint16_t unsigned short				/* <sys/types.h> */
# #define	uint32_t unsigned int				/* <sys/types.h> */

cd lib         # build the basic library that all programs need
make           # use "gmake" everywhere on BSD/OS systems

# build and test a simple program
cd ../pipe   
make pipeconf
./pipeconf /tmp
```
完成后环境即已配置好，以后在仓库中添加对其依赖即可。仓库与依赖的路径关系为:
```sh
.
├── Unix-Network-Programming-V2
├── unpv22e
```
