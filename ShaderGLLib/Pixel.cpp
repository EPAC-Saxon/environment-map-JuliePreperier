#include "Pixel.h"
#include <string>
#include <stdexcept>
#include <gl/glew.h>

namespace sgl {

	int ConvertToGLType(const PixelElementSize pixel_element_size)
	{
		switch (pixel_element_size) {
		case sgl::PixelElementSize::BYTE:
			return GL_UNSIGNED_BYTE;
		case sgl::PixelElementSize::SHORT:
			return GL_UNSIGNED_SHORT;
		case sgl::PixelElementSize::LONG:
			return GL_FLOAT;
		}
	}

	int ConvertToGLType(const PixelStructure pixel_structure)
	{
		switch (pixel_structure) {
		case sgl::PixelStructure::GREY:
			return GL_RED;
		case sgl::PixelStructure::GREY_ALPHA:
			return GL_RG;
		case sgl::PixelStructure::RGB:
			return GL_RGB;
		case sgl::PixelStructure::RGB_ALPHA:
			return GL_RGBA;
		}
	}

	int ConvertToGLType(
		const PixelElementSize pixel_element_size, 
		const PixelStructure pixel_structure)
	{
		switch (pixel_element_size) {
		case sgl::PixelElementSize::BYTE:
			switch (pixel_structure) {
			case sgl::PixelStructure::GREY:
				return GL_R8;
			case sgl::PixelStructure::GREY_ALPHA:
				return GL_RG8;
			case sgl::PixelStructure::RGB:
				return GL_RGB8;
			case sgl::PixelStructure::RGB_ALPHA:
				return GL_RGBA8;
			}
		case sgl::PixelElementSize::SHORT:
			switch (pixel_structure) {
			case sgl::PixelStructure::GREY:
				return GL_R16;
			case sgl::PixelStructure::GREY_ALPHA:
				return GL_RG16;
			case sgl::PixelStructure::RGB:
				return GL_RGB16;
			case sgl::PixelStructure::RGB_ALPHA:
				return GL_RGBA16;
			}
		case sgl::PixelElementSize::LONG:
			switch (pixel_structure) {
			case sgl::PixelStructure::GREY:
				return GL_R32F;
			case sgl::PixelStructure::GREY_ALPHA:
				return GL_RG32F;
			case sgl::PixelStructure::RGB:
				return GL_RGB32F;
			case sgl::PixelStructure::RGB_ALPHA:
				return GL_RGBA32F;
			}
		}
	}

} // End namespace sgl.