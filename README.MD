# 说明
Magick4J是对ImageMagick 7.0 的JNI封装库，封装了ImageMagick大部分的接口。

#安装
## 依赖
1. 安装jdk 11
2. 安装ImageMagick 7, 从github下载7.1.0-32的代码，在编译安装之前需要先安装依赖库，ubuntu 下运行以下指令。然后编译安装 ImageMagick 7.

 ```
 sudo apt install tcl-dev libpng-dev libjpeg-dev libgs-dev libbz2-dev libfreetype-dev libtiff-dev

 ```


安装过程如下：

```
 ./configure --with-bzlib=yes --with-fontconfig=yes --with-freetype=yes --with-gslib=yes
            --with-gvc=yes --with-jpeg=yes --with-jp2=yes --with-png=yes --with-tiff=yes --disable-openmp
 make
 sudo make install
 
```

## 编译 Magick4J.so，基于cmake，因此需要实现安装cmake
jni 本身是c代码也需要编译安装。jni 工程下的jni文件夹，然后执行如下命令, 执行过程中需要输入sudo 密码。

```
    sh build.sh
```

最终Magick4J.so会被安装到/usr/local/lib下。

## jar打包
调用mvn打包发布即可