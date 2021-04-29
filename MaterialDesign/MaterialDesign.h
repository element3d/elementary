
#ifndef MaterialDesign_H_
#define MaterialDesign_H_

#include <e3.h>
#include <functional>
#include <map>
#include "MDColors.h"

struct E3_EXPORT MDTheme 
{
	EMDColorScheme ColorScheme;
	glm::vec4 ColorPrimary;
};

class E3_EXPORT MaterialDesign 
{
	typedef std::function<void(const MDTheme*)> OnThemeChangeCallback;
public:
	static void SetColorPrimary(const glm::vec4& color);
	static glm::vec4 GetColorPrimary();

	static void SetColorScheme(EMDColorScheme colorScheme);
	static EMDColorScheme GetColorScheme();
	static glm::vec4 GetColorFromScheme(const std::string name);

public:
	static int AddOnThemeChangeCallback(OnThemeChangeCallback c);
	static void RemoveOnThemeChangeCallback(int id);
private:
	static MDTheme sTheme;
	static int sId;
	static std::map<int, OnThemeChangeCallback> sOnThemeChangeCallbacks;
};

#endif // MaterialDesign_H_

