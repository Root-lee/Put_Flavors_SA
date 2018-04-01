#include "Server.h"

///Server构造函数，参数为内存大小和CPU大小
Server::Server(int mem, int cpu) :total_mem(mem), total_cpu(cpu) {
	free_cpu = cpu;  //初始化时剩余CPU等于总CPU
	free_mem = mem;  //初始化时剩余内存等于总内存
}
///放置虚拟机函数，参数为虚拟机对象，返回值为是否放置成功
///首先检查剩余CPU和内存是否足够放置该虚拟机
///如果能够放下虚拟机，则将虚拟机放入服务器，并更新服务器可用内存和可用CPU，并返回true
///如果剩余内存和CPU不足以放下该虚拟机，则返回false
bool Server::put_flavor(Flavor flavor) {
	if (free_cpu >= flavor.cpu && free_mem >= flavor.mem) {
		free_cpu -= flavor.cpu;
		free_mem -= flavor.mem;
		flavors.push_back(flavor);
		return true;
	}
	return false;
}

///获取服务器CPU使用率
double Server::get_cpu_usage_rate() {
	return 1 － free_cpu / static_cast<double>(total_cpu);
}
///获取服务器内存使用率
double Server::get_mem_usage_rate() {
	return 1 － free_mem / static_cast<double>(total_mem);
}
