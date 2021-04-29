#ifndef __MD_COLORS__
#define __MD_COLORS__

#include <e3.h>
#include <glm/glm.hpp>
#include <map>
#include <string>

enum class EMDColorScheme
{
	Red,
	DeepPurple,
	Grey
};

namespace MDColors
{
	class E3_EXPORT Red
	{
	public:
		static glm::vec4 Get(const std::string& name);
		static glm::vec4 Get();
		static glm::vec4 GetAccent();
	};

	class E3_EXPORT DeepPurple
	{
	public:
		static glm::vec4 Get(const std::string& name);
		static glm::vec4 Get();
		static glm::vec4 GetAccent();
	};

	class E3_EXPORT Grey
	{
	public:
		static glm::vec4 Get(const std::string& name);
		static glm::vec4 Get();
	};
}
#endif // __MD_COLORS__
