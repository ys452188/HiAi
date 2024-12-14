#termux
echo "By黄 相涵(硫酸铜很好吃)"
#安装所需模块
pkg install clang libc++
#编译
g++ -std=c++17 -fuse-ld=lld -w -o main.exe main.cpp -lc++ -DANDROID_PLATFORM=android-21
#赋予文件可执行权限
ls
chmod +x main.exe
