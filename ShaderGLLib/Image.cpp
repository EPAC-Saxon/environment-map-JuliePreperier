#include "Image.h"
#include <algorithm>
#include <fstream>
#include <vector>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace sgl {

	Image::Image(
		const std::string& file, 
		const PixelElementSize pixel_element_size /*= PixelElementSize::BYTE*/, 
		const PixelStructure pixel_structure /*= PixelStructure::RGB_ALPHA*/) :
		pixel_element_size_(pixel_element_size),
		pixel_structure_(pixel_structure)
	{
		int width;
		int height;
		int channel_size;
		int desired_channel = static_cast<int>(GetPixelStructure());

		switch (pixel_element_size_) {
		case sgl::PixelElementSize::BYTE:
			image_ = stbi_load(file.c_str(), &width, &height, &channel_size, desired_channel);
			break;
		case sgl::PixelElementSize::SHORT:
			image_ = stbi_load_16(file.c_str(), &width, &height, &channel_size, desired_channel);
			break;
		case sgl::PixelElementSize::LONG:
			image_ = stbi_loadf(file.c_str(), &width, &height, &channel_size, desired_channel);
			break;
		}

		if (image_ == NULL) {
			throw std::runtime_error("Image null");
		}

		size_ = std::make_pair(width, height);
	}

	Image::~Image()
	{
		stbi_image_free(image_);
	}

}	// End namespace sgl.
