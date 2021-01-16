#include <iostream>
#include <string>
#include <cstdlib>
 
int main(int argc, char *argv[])
{
	std::string oldName, hName,eName,tName;
#ifdef _WIN32
	oldName = "C:\\Temp\\blog\\_config.yml";
	eName = "C:\\Temp\\blog\\_confige.yml";
	hName = "C:\\Temp\\blog\\_configh.yml";
	tName= "C:\\Temp\\blog\\_configt.yml";
#endif
 
	if (!rename(eName.c_str(), tName.c_str()))
	{
		std::cout << "    准备更改为Gitee模式"<< std::endl;
		if (!rename(oldName.c_str(), hName.c_str()))
			std::cout << "    副本更改为Github模式"<< std::endl;
		else std::cout << "    副本更改为Github模式失败！"<< std::endl;
		
		if (!rename(tName.c_str(), oldName.c_str()))
		std::cout << "    更改为Gitee模式成功！"<< std::endl;
		else std::cout << "    rename error "<< std::endl;
	}
	else
	{
		std::cout << "    rename error或更改为Github模式 "<< std::endl;
		if (!rename(hName.c_str(), tName.c_str()))
		std::cout << "    准备更改为Github模式"<< std::endl;
		else std::cout << "rename error "<< std::endl;
		if (!rename(oldName.c_str(), eName.c_str()))
			std::cout << "    副本更改为Gitee模式"<< std::endl;
		else std::cout << "    副本更改为Gitee模式失败！"<< std::endl;
		
		if (!rename(tName.c_str(), oldName.c_str()))
		std::cout << "    更改为Github模式成功！"<< std::endl;
		else std::cout << "rename error "<< std::endl;
	}
 	system("pause");
	return 0;
}