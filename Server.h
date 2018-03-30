#ifndef __SERVER_H__
#define __SERVER_H__

#include <string>
#include <vector>

//Flavor类，描述虚拟机信息：名称 内存 CPU
struct Flavor {
	std::string name;
	int mem;
	int cpu;
	Flavor(std::string _name,int _mem, int _cpu):
		name(_name),mem(_mem),cpu(_cpu){}
	Flavor() {

	}
};

//Server类，描述物理服务器信息：总内存 总CPU 可用内存 可用CPU 已存放的虚拟机列表
class Server {
public:
	std::vector<Flavor> flavors;  //物理服务器已存放虚拟机列表
	///Server构造函数，参数为内存大小和CPU大小
	Server(int mem, int cpu);
	///放置虚拟机函数，参数为虚拟机对象，返回值为是否放置成功
	bool put_flavor(Flavor flavor);
	///获取服务器CPU使用率
	double get_cpu_usage_rate();
	///获取服务器内存使用率
	double get_mem_usage_rate();
private:
	int total_mem;  // 物理服务器总内存
	int total_cpu;  // 物理服务器总CPU
	int free_mem;   // 物理服务器剩余可用内存
	int free_cpu;   // 物理服务器剩余可用CPU
};
#endif  //__SERVER_H__