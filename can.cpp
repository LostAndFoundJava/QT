#include "can.h"
#include <stdio.h>
//#include <sys/ioctl.h>         /* 定义 ioctl 函数原型 */
//#include <arpa/inet.h>
//#include <net/if.h>           /* 套接字本地接口  */
//#include <linux/socket.h>     /* sockaddr/AF_CAN  */
//#include <linux/can.h>       /* canid_t/can_err_mask_t/can_frame/CAN_RAW/sockaddr_can/can_filter  */
//#include <linux/can/error.h>
//#include <linux/can/raw.h>   /* SOL_CAN_RAW/CAN_RAW_FILTER  */
#include <fcntl.h>          /* 定义 open,creat 等函数原型,创建文件权限的符号常量 S_IRUSR 等 */
#include <unistd.h>         /* 定义 read,write,close,lseek,fsync,进程相关等函数原型 */
#include <stdlib.h>
#include <string.h>
#include <errno.h>         /* 与全局变量 errno 相关的定义 */
#include <time.h>
//#include <sys/socket.h>     /*  网络套接字接口 socket bind send recv sendto recvfrom函数   */
#include <sys/types.h>     /*  基本系统数据类型  */
//#include <sys/shm.h>       /* 共享内存  */
//#include <sys/uio.h>      /*  矢量IO  */
#include <QProcess>
#ifndef AF_CAN
#define AF_CAN 29
#endif
#ifndef PF_CAN
#define PF_CAN AF_CAN
#endif



can::can()
{
   can_init();
}

void can::can_init(){/*
    //QProcess *poc=new QProcess;
    //poc->start("/cantest/config.sh");

    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame,revframe;
    int s;
    int ret;

    s = socket(PF_CAN,SOCK_RAW,CAN_RAW);
    if(s<0){
        perror("socket PF_CAN failed");
        exit(1);
    }
    strcpy(ifr.ifr_name,"can0");
    if(ioctl(s,SIOCGIFINDEX,&ifr)<0){
        perror("ioctl failed");
        exit(1);
    }
    addr.can.family=PF_CAN;
    addr.can.ifindex=ifr.ifr_ifindex;
    if(bind(canfd,(struct sockaddr*)&addr,sizeof(addr))<0){
        perror("bind failed");
        exit(1);
    }

    if(1){
        struct can_filter filter[2];
        filter[0].can_id = 0x200 | CAN_EFF_FLAG;
        filter[0].can_mask=0xFFF;

        filter[1].can_id = 0x20F | CAN_EFF_FLAG;
        filter[1].can_mask = 0xFFF;

        if(setsockopt(s,SOL_CAN_RAW,CAN_RAW_FILTER,&filter,sizeof(filter))<0){
            perror("setsockopt failed");
            exit(1);
        }
    }*/
}

void can::can_send(){/*
    //读数据
    ret=read(s,&revframe,sizeof(revframe));
    if(ret<sizeof(revframe)){
        perror("CAN device error");
        exit(-1);
    }

    if(revframe.can_id & CAN_ERR_FLAG){  //设备错误
        perror("CAN device error");
        continue；
    }*/
}

void can::can_receive(){/*
    //写数据
    ret=write(s,&revframe,sizeof(revframe));
    if(ret<0){
        perror("write failed");
        exit(-1);
    }*/
}
