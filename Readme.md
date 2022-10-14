操作系统PV：
// 1. 1个生产者、1个消费者，缓冲区为1
// 两个同步动作：1.放入、2.取出，分别对应两个同步信号量
// 信号量：先做的动作+1，后做的动作-1，从这个角度考虑初始值
empty=1 // 空格子数量，初始值1
full=0 // 满格子数量，初始值0

productor codes:
while(true) {
  product codes... // 非同步
  p(empty) // 再放入，什么东西-1了？答：空了的格子，
  buffer_in...
  V(full) // 先放入，什么东西+1了？答：满了的格子，最开始有几个满的？0个
}

customer codes:
while(true) {
  P(full) // 再取出，什么东西-1了？答：满了的格子
  buffer_out...
  V(empty) // 先取出，什么东西+1了？答：空了的格子，初始有1个
  use...
}

// 2. 1个生产者，1个消费者，(环形)缓冲区为n
// 每次生产1个、取出1个后，即用完了，已用缓冲区指针均向后+1，因为是环形

full=0 // 初始信号量，满格子的数量
empty=n // 初始信号量，空格子的数量
*in // 缓冲区队列指针，在哪个格子放入商品
*out // 缓冲区队列指针，在哪个格子取出商品
mutex = 1; // 互斥信号量

productor codes:
while(true) {
  product codes... // 非同步

  V(empty)
  // ******* 临界区互斥访问 begin ********/
  P(mutex)
  buffer_in...
  in = (in + 1) % n // 放完了，用完了，+1
  V(mutex)
  // ******* 临界区互斥访问 end ********/
  V(full)
}

customer codes:
while(true) {
  P(full)
  // ******* 临界区互斥访问 begin ********/
  P(mutex)
  buffer_out...
  out = (out+1) % n
  V(mutex)
  // ******* 临界区互斥访问 end ********/
  V(empty)

  use... // 非同步
}




// 读-写
var rw=1 // 对互斥区的访问锁
var count = 0 // reader count
var count_mutex = 1; // 互斥访问count变量
var w = 1; // 解决写饥饿
// PV(w) 实现公平的先来先服务，不会让写进程饿死，也叫写优先，或叫读写公平法

writer() {
  while(1) {
    P(w)

    P(rw) // 写之前加锁
    write...
    V(rw) // 写之后解锁

    V(w)
  }
}

reader() {
  while(1) {
    P(w)

    P(count_mutex)
    if (count == 0) {
      P(rw)
    }
    count++
    V(count_mutex)

    V(w)

    read...

    P(count_mutex)
    count--
    if (count == 0) {
      V(rw)
    }
    V(count_mutex)

  }
}

