#include "MDColors.h"

glm::vec4 MDColors::Red::Get(const std::string& name)
{
	if ("50" == name) return glm::vec4(255, 235, 238, 255);  // #ffebee
	if ("100" == name) return glm::vec4(255, 205, 210, 255); // #ffcdd2
	if ("200" == name) return glm::vec4(239, 154, 154, 255); // #ef9a9a
	if ("300" == name) return glm::vec4(229, 115, 115, 255); // #e57373
	if ("400" == name) return glm::vec4(239, 83, 80, 255); // #ef5350
	if ("500" == name) return glm::vec4(244, 67, 54, 255); // #f44336
	if ("600" == name) return glm::vec4(229, 57, 53, 255); // #e53935
	if ("700" == name) return glm::vec4(211, 47, 47, 255); // #d32f2f
	if ("800" == name) return glm::vec4(198, 40, 40, 255); // #c62828
	if ("900" == name) return glm::vec4(183, 28, 28, 255); // #b71c1c

	if ("A100" == name) return glm::vec4(255, 138, 128, 255); // #ff8a80
	if ("A200" == name) return glm::vec4(255, 82, 82, 255); // #ff5252
	if ("A400" == name) return glm::vec4(255, 23, 68, 255); // #ff1744
	if ("A700" == name) return glm::vec4(213, 0, 0, 255); // #d50000
	return glm::vec4(244, 67, 54, 255); // #f44336
}

glm::vec4 MDColors::Red::Get() 
{
	return Get("500");
}

glm::vec4 MDColors::Red::GetAccent()
{
	return Get("A200");
}

// DeepPurple
glm::vec4 MDColors::DeepPurple::Get(const std::string& name)
{
	if ("50" == name) return glm::vec4(237, 231, 246, 255);  // #ede7f6
	if ("100" == name) return glm::vec4(209, 196, 233, 255); // #d1c4e9
	if ("200" == name) return glm::vec4(179, 157, 219, 255); // #b39ddb
	if ("300" == name) return glm::vec4(149, 117, 205, 255); // #9575cd
	if ("400" == name) return glm::vec4(126, 87, 194, 255); // #7e57c2
	if ("500" == name) return glm::vec4(103, 58, 183, 255); // #673ab7
	if ("600" == name) return glm::vec4(94, 53, 177, 255); // #5e35b1
	if ("700" == name) return glm::vec4(81, 45, 168, 255); // #512da8
	if ("800" == name) return glm::vec4(69, 39, 160, 255); // #4527a0
	if ("900" == name) return glm::vec4(49, 27, 146, 255); // #311b92

	if ("A100" == name) return glm::vec4(179, 56, 255, 255); // #b338ff
	if ("A200" == name) return glm::vec4(124, 77, 255, 255); // #7c4dff
	if ("A400" == name) return glm::vec4(101, 31, 255, 255); // #651fff
	if ("A700" == name) return glm::vec4(98, 0, 234, 255); // #6200ea
	return glm::vec4(103, 58, 183, 255); // #673ab7
}

glm::vec4 MDColors::DeepPurple::Get()
{
	return Get("500");
}

glm::vec4 MDColors::DeepPurple::GetAccent()
{
	return Get("A200");
}

// Grey
glm::vec4 MDColors::Grey::Get(const std::string& name)
{
	if ("50" == name) return glm::vec4(250, 250, 250, 255);  // #fafafa
	if ("100" == name) return glm::vec4(245, 245, 245, 255); // #f5f5f5
	if ("200" == name) return glm::vec4(238, 238, 238, 255); // #eeeeee
	if ("300" == name) return glm::vec4(224, 224, 224, 255); // #e0e0e0
	if ("350" == name) return glm::vec4(214, 214, 214, 255); // #d6d6d6
	if ("400" == name) return glm::vec4(189, 189, 189, 255); // #bdbdbd
	if ("500" == name) return glm::vec4(158, 158, 158, 255); // #9e9e9e
	if ("600" == name) return glm::vec4(117, 117, 117, 255); // #757575
	if ("700" == name) return glm::vec4(97, 97, 97, 255); // #616161
	if ("800" == name) return glm::vec4(66, 66, 66, 255); // #424242
	if ("850" == name) return glm::vec4(48, 48, 48, 255); // #303030
	if ("900" == name) return glm::vec4(33, 33, 33, 255); // #212121

	return glm::vec4(158, 158, 158, 255); // #9e9e9e
}

glm::vec4 MDColors::Grey::Get()
{
	return Get("500");
}