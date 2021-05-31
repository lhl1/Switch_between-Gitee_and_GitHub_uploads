# Switch_between-Gitee_and_GitHub_uploads

### 原理如同两杯水的交换，需要通过第三者实现





![img](https://lhl1.ml/photo/%E5%88%87%E6%8D%A2.png)



放在如下目录即可，每次需要用时即可切换
Github服务器在美国，国内访问可能会出现问题，Gitee则为国内网站，访问速度快，但每次修改需要重新部署

```none
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
```



![img](https://lhl1.ml/photo/%E5%88%87%E6%8D%A21.png)
